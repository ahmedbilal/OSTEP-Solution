#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

/* If you want to debug, uncomment the commented code lines */


int main(int argc, char * argv[])
{
    if (argc < 4)
    {
        printf("./va2pa {address_space_size} {page_size} {virtual_address in hex}");
        exit(EXIT_FAILURE);
    }
    char * end;
    int address_space_size = strtol(argv[1], &end, 10);
    int page_size = strtol(argv[2], &end, 10);
    int virtual_address = strtol(argv[3], &end, 16);

    int number_of_offset_bits = log2(page_size);
    //printf("Number of Offset Bits = %d\n", number_of_offset_bits);
    
    int number_of_vpn_bits = log2(address_space_size / page_size);
    //printf("Number of VPN Bits = %d\n", number_of_vpn_bits);

    int offset_mask = pow(2, number_of_offset_bits) - 1;
    //printf("Offset Mask = %d\n", offset_mask);
    
    int vpn_mask = 0;

    int offset = virtual_address & offset_mask;

    for (int i = 0; i < number_of_vpn_bits; i++)
    {
        vpn_mask += pow(2, number_of_offset_bits + number_of_vpn_bits - 1 - i);
    }
    //printf("VPN Mask = %d\n", vpn_mask);

    int vpn = (virtual_address & vpn_mask) >> number_of_offset_bits;

    //printf("Offset = %d\n", offset);
    //printf("VPN = %d\n", vpn);

    int ppn;
    printf("Input Value of %dth element of page table (in hex): ", vpn);
    scanf("%x", &ppn);
    
    ppn = ppn << number_of_offset_bits;

    printf("Physical Address = 0x%x\n", ppn | offset);

    exit(EXIT_SUCCESS);
}