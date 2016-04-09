#ifndef _JAVASCRIPT_API_H_INCLUDED_
#define _JAVASCRIPT_API_H_INCLUDED_

namespace javascript_api
{

  extern "C" 
  {
    extern void send_board(const char* flat_board);
    extern bool receive_board(char** _string_dest);
  }
  
} 

#endif // _JAVASCRIPT_API_H_INCLUDED_