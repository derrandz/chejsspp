	
	mergeInto(LibraryManager.library, {
	  send_board: function(board) {
	  	
	  	socket.on("connect", function(){

	  		socket.emit('game_request_sender_pipeline', {
                board: Pointer_stringify(board),
			});

	  		console.log("Sent board: " + Pointer_stringify(board));
	  	}); 
	  },

	  receive_board: function(_string_dest_in_c){

	  	socket.on("connect", function(){
	  		socket.on('game_request_receiver_pipeline' , function (message)
			{
	  			var buffer = Module._malloc(message.board.length + 1);
		        Module.writeStringToMemory(message.board, buffer);
		        setValue(_string_dest_in_c, buffer, '*');
		        console.log("Board received");
		        return true;
	  		});
	  	});

		var response_str = "__null__";
		var buffer       = Module._malloc(response_str.length + 1);

        Module.writeStringToMemory(response_str, buffer);
        setValue(_string_dest_in_c, buffer, '*');
 		
 		return false;
  	  },
	});