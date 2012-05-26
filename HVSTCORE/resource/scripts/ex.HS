//This is a basic script file

mass = 50;

//define an event
onRoomStart:
 
    dialog fweh:
      msgBox "I like turtles." disp; //msgBox is the function, "I like turtles" and disp are parameters
      msgBox "Meh" disp;
      msgBox "Now there's no box!" invis;
	end dialog
end event //end the event - similar to if end if

onRoomEnd
    dialog meh:
      msgBox "Oh shi-" disp;
	end dialog
end event
   