#include<stdio.h>
#include<elf.h>

int main(int argc, char **argv){
 FILE *f = fopen(argv[1], "rb");
    Elf64_Ehdr ehdr;
    fread(&ehdr, 1, sizeof(ehdr), f);

    printf("Entry point: 0x%lx\n", ehdr.e_entry);
    printf("PH offset: 0x%lx\n", ehdr.e_phoff);
    printf("SH offset: 0x%lx\n", ehdr.e_shoff);

    // Program Headers
    fseek(f, ehdr.e_phoff, SEEK_SET);
    for (int i = 0; i < ehdr.e_phnum; i++) {
        Elf64_Phdr ph;
        fread(&ph, 1, sizeof(ph), f);
        printf("PH[%d] type = %d, vaddr = 0x%lx\n", i, ph.p_type, ph.p_vaddr);
    }

    // Section Headers
    fseek(f, ehdr.e_shoff, SEEK_SET);
    for (int i = 0; i < ehdr.e_shnum; i++) {
        Elf64_Shdr sh;
        fread(&sh, 1, sizeof(sh), f);
        printf("SH[%d] addr = 0x%lx size = %lx\n", i, sh.sh_addr, sh.sh_size);
    }
}