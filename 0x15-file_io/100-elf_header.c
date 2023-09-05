#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
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
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		printf(index == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
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
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
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
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	} else
	{
		printf("\n");
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	const char *osabi_str = "unknown";

	switch (e_ident[EI_OSABI])
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
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	const char *type_str;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	e_type >>= 8;

	printf(" Type: ");

	type_str = "unknown";
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
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("Error: Can't close file descriptor");
		exit(98);
	}
}

/**
 * main - Reads and displays information from the header of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

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
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
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
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
