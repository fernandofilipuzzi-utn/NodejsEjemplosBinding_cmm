#include <nan.h>

   NAN_METHOD(Sumar) {
     if (info.Length() < 2) {
       Nan::ThrowTypeError("Wrong number of arguments");
       return;
     }

     if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
       Nan::ThrowTypeError("Both arguments should be numbers");
       return;
     }

     double arg0 = info[0]->NumberValue();
     double arg1 = info[1]->NumberValue();
     v8::Local<v8::Number> result = Nan::New(arg0 + arg1);

     info.GetReturnValue().Set(result);
   }

   NAN_MODULE_INIT(Init) {
     Nan::Set(target, Nan::New("sumar").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Sumar)).ToLocalChecked());
   }

   NODE_MODULE(mi_modulo, Init)
