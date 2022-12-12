# Executing Your Assembly's Code
- Managed assemblies contain both `metadata` and `IL`
- IL is a `CPU-independent` machine language created by Microsoft
<br>
<br>

## Execution of managed EXE

<figure align="left">
    <img src="Calling_a_method.jpg" style="height: 500px;"/>
    <figcaption align="left">
    </figcaption>
</figure>

1. CLR detects `all of the types` that are referenced by *`Main`*'s code.
1. CLR `allocate` an internal data structure that is used to manage access to the referenced types.
1. This internal data structure `contains an entry for each method` defined by the `Console` type.
1. Each entry `holds the address` where the method’s implementation can be found.
1. When initializing this structure, the CLR sets each entry to an internal, undocumented function contained inside the CLR itself. (`JITCompiler`, Just-in time Compiler)
1. When Main makes its first call to WriteLine, the `JITCompiler function` is called.
1. The JITCompiler function is responsible for compiling a method’s `IL code into native CPU instructions`.
    - JITCompiler function knows what method is being called and what type defines this method.
    - The JITCompiler function then searches the defining assembly’s metadata for the called method’s IL.
    - JITCompiler next verifies and compiles the IL code into native CPU instructions.
    - The native CPU instructions are saved in a dynamically allocated block of memory.
    - JITCompiler goes back to the entry for the called method in the type’s internal data structure created by the CLR.
    - JITCompiler replaces the reference that called it in the first place with the address of the block of memory containing the native CPU instructions it just compiled.
    - the JITCompiler function jumps to the code in the memory block.

1. Main now calls WriteLine a second time.
1. The call goes directly to the block of memory, skipping the JITCompiler function entirely.
1. After the WriteLine method executes, it returns to Main.

<figure align="left">
    <img src="Calling_a_method_secondtime.jpg" style="height: 500px;"/>
    <figcaption align="left">
    </figcaption>
</figure>