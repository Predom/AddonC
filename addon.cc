#define NAPI_VERSION 5
#include <node_api.h>
#include <iostream>

//Documentação importante N-api types

//de C para N-API

  //napi_status napi_create_object(napi_env env, napi_value* result) env = envoirment, result = js object

  //napi_status napi_create_int64(napi_env env, int64_t value, napi_value* result) function to create js number from int64

  //napi_status napi_create_double(napi_env env, double value, napi_value* result) function to create js number frojm double type

  //napi_status napi_create_string_utf8(napi_env env, const char* str, size_t length, napi_value* result) cria string utf8 de string em C (ponteiro pra array de char com length)

//de N-API para C

  //napi_status napi_get_value_int64(napi_env env, napi_value value, int64_t* result) //cria um int64 a partir de um js number

  //napi_status napi_get_value_double(napi_env env, napi_value value, double* result) //cria um double a partir de um js number



  //status = napi_set_named_property(env, obj, "myProp", value); //setar elemento

  //napi_status napi_get_element(napi_env env, napi_value object, uint32_t index, napi_value* result); //acessar elemento


namespace demo {

napi_value Method(napi_env env, napi_callback_info info) {


  napi_value obj, value;
  napi_status status;
  int64_t numero;
  size_t argc=1;

  napi_get_cb_info(env, info, &argc,&obj, NULL, NULL);

  //status = napi_create_object(env,&obj);
  std::cin >> numero;
  status = napi_create_int64(env, numero, &value);
  //if(status!=napi_ok)return status;

  status = napi_set_named_property(env,obj,"numero",value);

  return obj;
}




napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
