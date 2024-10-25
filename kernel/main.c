#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"

void main() {
    // Basic initialization without paging or interrupt handling
    consoleinit();
    printfinit();
    printf("\nxv6 kernel is booting\n");
    
    // Initialize subsystems (without paging, PLIC, or traps)
    kinit();      // physical page allocator

    //kvminit(); //alllocate kernel pages for processes

    procinit();   // process table

    binit();      // buffer cache
    iinit();      // inode table
    fileinit();   // file table
    virtio_disk_init();

    userinit(); // first user process 
    virtualdisk_process();
    inituart_process(); //interrupts by software to answer uart 

    // Start cooperative scheduler
    scheduler();
}
