ViRUS: Virtual Function Replacement Under Stress

=========

ViRUS is a strategy for polymorphic implementation of shared libraries. Each function in a ViRUS library features multiple implementations with variable quality and cost (processing time, energy). Applications using the polymorphic library are linked with a small monitoring library that periodically polls system sensors (e.g. temperature, power) and consults application policy to determine when each of the multiple versions should be used. Further details can be found in the USENIX HotPower paper [ViRUS: Virtual Function Replacement Under Stress](https://www.usenix.org/conference/hotpower14/workshop-program/presentation/wanner).

Included in the repository are a polymorphic mathematical function library, a subset of Parsec benchmarks modified to use the ViRUS math library, and supporting data for the USENIX HotPower paper. This implementation of ViRUS is dependent on sensors provided by [VarEMU](https://github.com/nesl/varemu). The Linux kernel and disk image provided in the VarEMU repository supports ViRUS. 
