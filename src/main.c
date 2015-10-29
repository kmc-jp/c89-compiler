#include <llvm-c/Core.h>
#include "utility.h"

int main(int argc, char *argv[]) {
  LLVMModuleRef module = LLVMModuleCreateWithName("kmc89_module");
  /* int main() { return 0; } */
  LLVMTypeRef main_type = LLVMFunctionType(LLVMInt32Type(), NULL, 0, false);
  LLVMValueRef main_func = LLVMAddFunction(module, "main", main_type);
  LLVMBasicBlockRef main_entry = LLVMAppendBasicBlock(main_func, "main_entry");
  LLVMBuilderRef builder = LLVMCreateBuilder();
  LLVMPositionBuilderAtEnd(builder, main_entry);
  LLVMValueRef return_value = LLVMConstInt(LLVMInt32Type(), 0, false);
  LLVMBuildRet(builder, return_value);
  LLVMDisposeBuilder(builder);
  LLVMDisposeModule(module);
  return 0;
}
