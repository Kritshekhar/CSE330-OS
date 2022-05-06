#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/mm_types.h>
#include <linux/sched.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");

static int  pid = 0;
module_param(pid, int, 0);

int enter_code_init(void) {
    struct task_struct *task;
    //task->mm->mmap
    for_each_process(task) {
        if(task->pid == pid) {
            //do this
            struct mm_struct *vmaList;
            vmaList = task->mm->mmap;

            unsigned long addrStart;
            pgd_t *pgd;
            p4d_t *p4d; 
            pmd_t *pmd;
            pud_t *pud;
            pte_t *ptep, pte;

            while(vmaList != null) {

                for(addrStart = vmaList->vm_start; addrStart < vmaList->vm_end; addr += PAGE_SIZE ) {
                    //
                    pgd = pgd_offset(vmaList, addrStart);
                    if(pgd_none(*pgd) || pgd_bad(*pgd)) {
                        //this is if it is bad or does not exist
                    }

                    p4d = p4d_offset(pgd, addrStart);
                    if(p4d_none(*p4d) || p4d_bad(*p4d)) {
                        //bad or not exist
                    }

                    pud = pud_offset(p4d, addrStart);
                    if(pud_none(*pud) || pud_bad(*pud)) {
                        //bad not exist
                    }

                    pmd = pmd_offset(pud, addrStart);
                    if(pmd_none(*pmd) || pmd_bad(*pmd)) {
                        //bad not exist
                    }

                    ptep = pte_offset_map(pmd, addrStart);
                    if(!ptep) {
                        //is if pte does not exist
                    }
                    pte = *ptep;
                }

                vmaList = ->vmaList->vm_next;
            }
            



        }
    }
}

void the_code_exit(void) {

}

module_init(enter_code_init);
module_exit(the_code_exit);
