#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("A simple Linux module");
MODULE_VERSION("0.01");


static int day = 0;
static struct tasklet_struct my_tasklet;


void my_tasklet_handler(unsigned long flag)
{
    printk(KERN_INFO "Tasklet received parameter from user: %d\n", day);
}


static int __init my_tasklet_init(void)
{
    printk(KERN_INFO "Initializing my_tasklet module\n");
    tasklet_init(&my_tasklet, my_tasklet_handler, 0); 
    tasklet_schedule(&my_tasklet); 
    return 0;
}


static void __exit my_tasklet_exit(void)
{
    tasklet_kill(&my_tasklet);
    printk(KERN_INFO "Exiting my_tasklet module\n");
}


module_param(day, int, 0);
module_init(my_tasklet_init);
module_exit(my_tasklet_exit);