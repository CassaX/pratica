#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/io.h>
#define DELAY do { mdelay(1); if (++delay > 10) break; } while(0);

MODULE_LICENSE("GPL");

static void beep_on(void)
{
    long delay = 0;
    int i = 0;
	while(i < 300){
        outb(255,0x61);
    DELAY
        outb(0,0x61);
        i++;
    }
	
}

static void beep_off(void)
{
	outb(0,0x61);	
}

static int test_beep_init(void)
{
        pr_info("%s: In init\n", __func__);
	    beep_on();
	return 0;
}

static void test_beep_exit(void)
{
        pr_info("%s: In exit\n", __func__);
	    beep_off();
}

module_init(test_beep_init);
module_exit(test_beep_exit);