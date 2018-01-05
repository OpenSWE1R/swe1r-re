**Make sure you understand how to build OpenSWE1R first, by reading the .**

## CMake options

OpenSWE1R exposes options through CMake which you can set during setup.

Using the command line interface, you can configure your build using `cmake -D<option1>=<value1> -D<option2>=<value2> ..` (Example: `cmake -DUSE_VM=ON ..`).

You'll have to build again after this re-configuration. See [[Build Instructions]]


**List of currently exposed CMake options**:

* **`USE_VM`** *- Accepted values: `OFF` (default), `ON`*
  
  Specifies wether the CPU will be virtualized instead of using Unicorn-Engine.
  
  This option currently only works on Linux ([Issue #71](https://github.com/OpenSWE1R/openswe1r/issues/71)).
  When it is turned on, KVM will be used for virtualization. So make sure you have CPU-Virtualization enabled in your BIOS (typically AMD-V or VT-x) and Kernel (KVM).
  
  As the virtual machine will require a BIOS, [follow the instructions in uc_kvm_loader.asm](https://github.com/OpenSWE1R/openswe1r/blob/master/uc_kvm_loader.asm). You'll need [nasm](http://www.nasm.us/) to do that.
  Opposed to most other build commands, this command has to be ran from the projects root directory.

  Using KVM will improve performance a lot.
  However, most of the debugging and tracing options in OpenSWE1R will not work anymore, so this is not recommended during development.

## Optional features

### Multiplayer

ENet is an optional dependency. If ENet is found during compilation, the Multiplayer option becomes enabled automatically.