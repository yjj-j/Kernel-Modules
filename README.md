# Kernel-Modules

## "Hello Word" module

- To make the module, run: 

    ```properties
    make
    ```

- To install the module:

    ```properties
    sudo insmod hello.ko
    ```

- To remove the module: 

    ```properties
    sudo rmmod hello.ko
    ```

- To view printk: 

    ```properties
    dmesg | tail
    ```
