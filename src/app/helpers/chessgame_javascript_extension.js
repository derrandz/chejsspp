	
	mergeInto(LibraryManager.library, {
	  send_board: function(board) {
	  	
	  	socket.on("connect", function(){
	  		socket.emit("message", {
	  			message_content: Pointer_stringify(board),	
	  		});
	  		console.log("Sent board: " + Pointer_stringify(board));
	  	}); 
	  },

	  receive_board: function(_string_dest_in_c){

	  	socket.on("connect", function(){
	  		socket.on("message", function(message){
	  			
	  			var buffer = Module._malloc(message.message_content.length + 1);
		        Module.writeStringToMemory(message.message_content, buffer);
		        setValue(_string_dest_in_c, buffer, '*');
		        console.log("Board received");
		        return true;
	  		});
	  	});
	  	console.log("Did not receive any board");
		var response_str = "__null__";
		var buffer       = Module._malloc(response_str.length + 1);

        Module.writeStringToMemory(response_str, buffer);
        setValue(_string_dest_in_c, buffer, '*');
 		
 		return false;
  	  },
	});