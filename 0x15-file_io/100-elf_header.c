#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_header_info(Elf64_Ehdr *header);
void close_elf(int elf);

/**
 * main - Entry point of the program. Reads and displays information
 * from the header of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to command-line arguments.
 * Return: 0 on success, 1 on incorrect usage, and 98 on failure.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}

	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	print_header_info(header);

	free(header);
	close_elf(o);
	return (0);
}

/**
 * check_elf - Checks if a file is an ELF file based on the ELF magic numbers.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file, it exits with code 98.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != ELFMAG0 || e_ident[1] != ELFMAG1 ||
	e_ident[2] != ELFMAG2 || e_ident[3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_header_info - Prints various information from an ELF header.
 * @header: A pointer to the ELF header structure.
 * Description: Prints magic numbers, class, data encoding, version, OS/ABI,
 * ABI version, type, and entry point address from the ELF header.
 */
void print_header_info(Elf64_Ehdr *header)
{
	int index;
	const char *osabi_str;
	const char *type_str;
	unsigned int e_type = header->e_type;

	printf("ELF Header:\n");

	/* Print magic numbers */
	printf(" Magic: ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", header->e_ident[index]);
		printf(index == EI_NIDENT - 1 ? "\n" : " ");
	}

	/* Print class */
	printf(" Class: ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("unknown\n");
		break;
	}

	/* Print data */
	printf(" Data: ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("unknown\n");
		break;
	}

	/* Print version */
	printf(" Version: %d", header->e_ident[EI_VERSION]);
	if (header->e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	} else
	{
		printf("\n");
	}

	/* Print OS/ABI */
	printf(" OS/ABI: ");

	osabi_str = "unknown";
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		osabi_str = "UNIX - System V";
		break;
	case ELFOSABI_HPUX:
		osabi_str = "UNIX - HP-UX";
		break;
	case ELFOSABI_NETBSD:
		osabi_str = "UNIX - NetBSD";
		break;
	case ELFOSABI_LINUX:
		osabi_str = "UNIX - Linux";
		break;
	case ELFOSABI_SOLARIS:
		osabi_str = "UNIX - Solaris";
		break;
	case ELFOSABI_IRIX:
		osabi_str = "UNIX - IRIX";
		break;
	case ELFOSABI_FREEBSD:
		osabi_str = "UNIX - FreeBSD";
		break;
	case ELFOSABI_TRU64:
		osabi_str = "UNIX - TRU64";
		break;
	case ELFOSABI_ARM:
		osabi_str = "ARM";
		break;
	case ELFOSABI_STANDALONE:
		osabi_str = "Standalone App";
		break;
	}
	printf("%s\n", osabi_str);

	/* Print ABI Version */
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	/* Print Type */
	printf(" Type: ");

	type_str = "unknown";
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}
	switch (e_type)
	{
	case ET_NONE:
		type_str = "NONE (None)";
		break;
	case ET_REL:
		type_str = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		type_str = "EXEC (Executable file)";
		break;
	case ET_DYN:
		type_str = "DYN (Shared object file)";
		break;
	case ET_CORE:
		type_str = "CORE (Core file)";
		break;
	}
	printf("%s\n", type_str);

	/* Print Entry Point */
	printf(" Entry point address: ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)header->e_entry);
	} else
	{
		printf("%#lx\n", header->e_entry);
	}
}

/**
 * close_elf - Closes an open ELF file descriptor.
 * @elf: The file descriptor of the ELF file to be closed.
 * Description: If the file cannot be closed, it exits with code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("Error: Can't close file descriptor");
		exit(98);
	}
}

