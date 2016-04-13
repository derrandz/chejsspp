#ifndef _JAVASCRIPT_API_H_INCLUDED_
#define _JAVASCRIPT_API_H_INCLUDED_

#include <emscripten.h>

namespace javascript_api
{

  extern "C" 
  {
    extern void send_board(char* flat_board);

    extern void receive_board(
                              void (*succes_callback_pointer)(void*,  char*), 
                              void (*failure_callback_pointer)(void*,  char*), 
                              void* viewptr,  
                              char* flat_validated_configuration
                            );

    EMSCRIPTEN_KEEPALIVE 
    extern void callback_invoker(
                                  void (*callback_pointer)(void*,  char**), 
                                  void* viewptr,  
                                  char* valid_flat_board)
    {
    	void (*_ptr_cast_callback_pointer)(void*,  char*) = (void(*)(void*,  char*))callback_pointer; // force cast.
    	(*_ptr_cast_callback_pointer)(viewptr, valid_flat_board);
    }
  }
  
} 

#endif // _JAVASCRIPT_API_H_INCLUDED_