
//  Microsoft (R) .NET Framework IL Disassembler.  Version 4.8.3928.0
//  Copyright (c) Microsoft Corporation.  All rights reserved.



// Metadata version: v4.0.30319
.assembly extern System.Runtime
{
  .publickeytoken = (B0 3F 5F 7F 11 D5 0A 3A )                         // .?_....:
  .ver 10:0:0:0
}
.assembly extern System.Console
{
  .publickeytoken = (B0 3F 5F 7F 11 D5 0A 3A )                         // .?_....:
  .ver 10:0:0:0
}
.assembly Bai2
{
  .custom instance void [System.Runtime]System.Runtime.CompilerServices.CompilationRelaxationsAttribute::.ctor(int32) = ( 01 00 08 00 00 00 00 00 ) 
  .custom instance void [System.Runtime]System.Runtime.CompilerServices.RuntimeCompatibilityAttribute::.ctor() = ( 01 00 01 00 54 02 16 57 72 61 70 4E 6F 6E 45 78   // ....T..WrapNonEx
                                                                                                                   63 65 70 74 69 6F 6E 54 68 72 6F 77 73 01 )       // ceptionThrows.

  // --- The following custom attribute is added automatically, do not uncomment -------
  //  .custom instance void [System.Runtime]System.Diagnostics.DebuggableAttribute::.ctor(valuetype [System.Runtime]System.Diagnostics.DebuggableAttribute/DebuggingModes) = ( 01 00 07 01 00 00 00 00 ) 

  .custom instance void [System.Runtime]System.Runtime.Versioning.TargetFrameworkAttribute::.ctor(string) = ( 01 00 19 2E 4E 45 54 43 6F 72 65 41 70 70 2C 56   // ....NETCoreApp,V
                                                                                                              65 72 73 69 6F 6E 3D 76 31 30 2E 30 01 00 54 0E   // ersion=v10.0..T.
                                                                                                              14 46 72 61 6D 65 77 6F 72 6B 44 69 73 70 6C 61   // .FrameworkDispla
                                                                                                              79 4E 61 6D 65 09 2E 4E 45 54 20 31 30 2E 30 )    // yName..NET 10.0
  .custom instance void [System.Runtime]System.Reflection.AssemblyCompanyAttribute::.ctor(string) = ( 01 00 04 42 61 69 32 00 00 )                      // ...Bai2..
  .custom instance void [System.Runtime]System.Reflection.AssemblyConfigurationAttribute::.ctor(string) = ( 01 00 05 44 65 62 75 67 00 00 )                   // ...Debug..
  .custom instance void [System.Runtime]System.Reflection.AssemblyFileVersionAttribute::.ctor(string) = ( 01 00 07 31 2E 30 2E 30 2E 30 00 00 )             // ...1.0.0.0..
  .custom instance void [System.Runtime]System.Reflection.AssemblyInformationalVersionAttribute::.ctor(string) = ( 01 00 2E 31 2E 30 2E 30 2B 31 39 35 32 62 64 39   // ...1.0.0+1952bd9
                                                                                                                   66 32 65 35 39 37 30 64 64 63 39 64 30 66 63 36   // f2e5970ddc9d0fc6
                                                                                                                   63 61 61 62 61 39 39 32 32 65 39 37 31 66 61 35   // caaba9922e971fa5
                                                                                                                   30 00 00 )                                        // 0..
  .custom instance void [System.Runtime]System.Reflection.AssemblyProductAttribute::.ctor(string) = ( 01 00 04 42 61 69 32 00 00 )                      // ...Bai2..
  .custom instance void [System.Runtime]System.Reflection.AssemblyTitleAttribute::.ctor(string) = ( 01 00 04 42 61 69 32 00 00 )                      // ...Bai2..
  .hash algorithm 0x00008004
  .ver 1:0:0:0
}
.module Bai2.dll
// MVID: {D3B3B997-89DF-4D3A-95BD-22B5B291234D}
.custom instance void [System.Runtime]System.Runtime.CompilerServices.RefSafetyRulesAttribute::.ctor(int32) = ( 01 00 0B 00 00 00 00 00 ) 
.imagebase 0x00400000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003       // WINDOWS_CUI
.corflags 0x00000001    //  ILONLY
// Image base: 0x04C80000


// =============== CLASS MEMBERS DECLARATION ===================

.class private auto ansi beforefieldinit Bai1.NhapTen
       extends [System.Runtime]System.Object
{
  .method public hidebysig static void  Main(string[] args) cil managed
  {
    .entrypoint
    .custom instance void [System.Runtime]System.Runtime.CompilerServices.NullableContextAttribute::.ctor(uint8) = ( 01 00 01 00 00 ) 
    // Code size       36 (0x24)
    .maxstack  2
    .locals init (string V_0)
    IL_0000:  nop
    IL_0001:  ldstr      "Nhap ho ten cua ban: "
    IL_0006:  call       void [System.Console]System.Console::Write(string)
    IL_000b:  nop
    IL_000c:  call       string [System.Console]System.Console::ReadLine()
    IL_0011:  stloc.0
    IL_0012:  ldstr      "Chao ban "
    IL_0017:  ldloc.0
    IL_0018:  call       string [System.Runtime]System.String::Concat(string,
                                                                      string)
    IL_001d:  call       void [System.Console]System.Console::Write(string)
    IL_0022:  nop
    IL_0023:  ret
  } // end of method NhapTen::Main

  .method public hidebysig specialname rtspecialname 
          instance void  .ctor() cil managed
  {
    // Code size       8 (0x8)
    .maxstack  8
    IL_0000:  ldarg.0
    IL_0001:  call       instance void [System.Runtime]System.Object::.ctor()
    IL_0006:  nop
    IL_0007:  ret
  } // end of method NhapTen::.ctor

} // end of class Bai1.NhapTen


// =============================================================

// *********** DISASSEMBLY COMPLETE ***********************
// WARNING: Created Win32 resource file C:\Users\ASUS\source\repos\Repos-from-pc\CSharp\Tuan2\Tuan2.1\Bai2\bin\Debug\net10.0\Bai1.res
