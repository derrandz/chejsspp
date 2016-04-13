
	mergeInto(LibraryManager.library, {
	  send_board: function(board) {
  		socket.emit('game_request_sender_pipeline', {
            board: Pointer_stringify(board),
		});
  		console.log("Sent board.");
	  },

	  receive_board: function(success_callback_pointer, failure_callback_pointer, viewptr, flat_validated_configuration){
	  	
		socket.on('game_request_receiver_pipeline' , function (message)
		{
			var str = String(message.board);
  			var buffer = Module._malloc(str.length + 1);
	        Module.writeStringToMemory(str, buffer);
	        console.log("address in js:" + buffer);
	        Module.ccall('callback_invoker', 'void', ['number','number','number'], [success_callback_pointer, viewptr, buffer]);
	        return;
  		});

        Module.ccall('callback_invoker', 'void', ['number','number','number'], [failure_callback_pointer, viewptr, flat_validated_configuration]);
  	  }
	});