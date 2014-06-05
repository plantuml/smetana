package h;
import core.*;
import core.annotation.*;

// 699jo8yc758stjo0e1bggt6bk

public class glCompMouse {
}

// typedef struct _glCompMouse {
// 	glCompMouseStatus status;
// 	glMouseButtonType t;
// 	glCompPoint initPos; /*current mouse pos,*/
// 	glCompPoint pos; /*current mouse pos,*/
// 	glCompPoint finalPos; /*current mouse pos,*/
// 	glCompPoint GLpos;/*3d converted opengl position*/
// 	glCompPoint GLinitPos;/*mouse button down pos*/
// 	glCompPoint GLfinalPos;/*mouse button up pos*/
// 
// 	GLfloat dragX, dragY;/*GLpos - GLinitpos*/
// 	glCompObj *clickedObj;
// 	glCompCallBacks callbacks;
// 	glCompCallBacks functions;
// 	int down;
// 
// 
//     } glCompMouse;