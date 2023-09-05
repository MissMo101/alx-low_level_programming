#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		perror("Error reading ELF header");
		close(fd);
		return (1);
	}

	/* Check for ELF magic numbers */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	header.e_ident[EI_MAG1] != ELFMAG1 ||
	header.e_ident[EI_MAG2] != ELFMAG2 ||
	header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (1);
	}

	printf("ELF Header:\n");
	printf("  Magic: %02x %02x %02x %02x\n", header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
	printf("  Class: %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version: %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI: UNIX - System V\n");
	printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type: ");
	switch (header.e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", header.e_type);
		break;
	}

	printf("  Entry point address: %#lx\n", (unsigned long)header.e_entry);

	close(fd);
	return (0);
}
