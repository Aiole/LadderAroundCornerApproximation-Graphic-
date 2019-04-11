#include "T_tools.c"

int pic()
{
  int i=0,ch = 0, temptemp, k,flag, aboveflag,f,a;
  double m[2];
  double n[2];
  double xi[100];
  double yi[100];
  char str[100];
  double ladder[2];
  double x,y,xhi,xlo,yhi,ylo,dif,hi,lo,slope,b,ladderlen,inc,cornerx,cornery;
  double deg,estdeg,xmean,ymean,ysum,xsum,xdif,ydif,numsumt,densumt,wid,high
    ,numsum,densum,cornerlen,tempx,tempy, laddertemp;
  G_rgb(0,0,0) ; G_clear() ;
  G_rgb(1,0,0);
  sprintf(str,"(Tx,Ty) = (%.2lf, %.2lf)    Tr = %.2lf",Tx,Ty,Tr) ;
  G_draw_string(str, Px - 200, Py + Pr - 25) ;
  G_rgb(0.5,0.5,0.5) ;
  T_grid(1.0);
  G_rgb(0.2,0.85,0) ;
  G_fill_rectangle(0, 0, 50, 50);
  G_rgb(0,0.3,1) ;
  T_line(Tx-Tr,0,  Tx+Tr,0) ; // x-axis
  T_line(0,Ty-Tr,  0,Ty+Tr) ; // y-axis
  G_rgb(1,0.3,0.5);
  G_draw_string("Graph", 0,20) ;
  x = Tx - Tr ;
  /*
  while (x <= Tx + Tr) {
    G_rgb(0,.3,1) ;
    y=sin(x);
    x = x + 0.001*Tr ;
    T_point(x,y) ;
    G_rgb(1,1,1) ;
    y=pow(2,x);
    x = x + 0.001*Tr ;
    T_point(x,y) ;
  }
  */

  G_rgb(1,1,0) ;
 // T_point(Tx,Ty) ; // plot the theoretical center 
                 // (which aligns with the pysical center)
 
  

   G_rgb(0,1,0.5);
   ladderlen = 100;
  


   i = 0;
   inc=0;
   cornerx = 200 * (sqrt(((6 * 6) + (6 * 6))) /
	     sqrt(((800 * 800) + (700 * 700))));
   cornery = 500 * (sqrt(((6 * 6) + (6 * 6))) /
	     sqrt(((800 * 800) + (700 * 700))));
   cornerlen = sqrt((cornerx * cornerx) + (cornery * cornery));
   ladderlen = ladderlen * (sqrt(((6 * 6) + (6 * 6))) /
	     sqrt(((800 * 800) + (700 * 700))));
   y= (ladderlen * cornery) / cornerlen;
   x= (ladderlen * cornerx) / cornerlen;
   cornerx -= 3;
   cornery -= 3;
   x -= 3;
   y -= 3;


   
   lo = 1;
   hi = 10;
   while(f<1000){
     ladderlen = (lo + hi)/2 ;
     y= (ladderlen * (cornery + 3)) / cornerlen;
     x= (ladderlen * (cornerx + 3)) / cornerlen;
     x -= 3;
     y -= 3;
     inc = 0;
     flag = 0;
     i=0;
   while(i<3000){
     //k = G_wait_key() ;
     G_display_image();
     usleep(15000);
    G_rgb(0,0,0) ; G_clear() ;
    G_rgb(.8, .8, .8) ;
    wid = 200 * (3.0/4.0);
    high = 500 * (6.0/7.0);
    G_fill_rectangle(0, 0, (cornerx + 3) * 100.0, (cornery + 3) * 100);
    G_fill_rectangle(0, (cornery + 3) * 100, 600, 100.0 * 120.0 * (sqrt(((6 * 6) + (6 * 6))) /
	     sqrt(((800 * 800) + (700 * 700)))));
    G_rgb(0,.3,1) ;//blue
    T_line(-3,inc - 3,cornerx,cornery);
    G_rgb(1,1,0.3);//yellow
    sprintf(str,"x = %lf y = %lf inc = %lf"
	    ,x, y, inc) ;
    G_draw_string(str, Px - 300, Py + Pr - 70) ;
    T_line(-3,inc - 3,x,y); 
    inc = inc +.01*Tr;
    x+=3;
    y+=3;
    x = ((cornerx + 3) * ladderlen)/sqrt( ((cornerx + 3) * (cornerx + 3)) +
		   ( ((cornery + 3) - inc) * ((cornery + 3) - inc) ) );
    y = ( (x/(cornerx + 3)) * ((cornery + 3) - inc) ) + inc;
    x-=3;
    y-=3;
    i++;

     if(y >= ((620 * (sqrt(((6 * 6) + (6 * 6))) /
		     sqrt(((800 * 800) + (700 * 700)))))) - 3){
    G_rgb(1,0,0.5);
    sprintf(str,"Failed :(");
    G_draw_string(str, Px - 100, Py + Pr - 250) ;
    G_fill_circle(100 * (x+3), 100 * (y+3), 30);
    flag = 1;
    G_display_image();
    usleep(150000);
    break;
     }


     if(inc > (cornery + 3)){
      G_rgb(0,1,0.5);
    sprintf(str,"Passed :)");
    G_draw_string(str, Px - 100, Py + Pr - 250);
     G_fill_circle(100 * (x+3), 100 * (y+3), 30);
     G_display_image();
     usleep(150000);
      break;
    }
     
  
   }
   
   printf("%lf\n", ladderlen * (sqrt(((800 * 800) + (700 * 700))/
				((6 * 6) + (6 * 6)))));
   printf("did it fail? %d\n", flag);
     
   
   if(flag){
     hi = ladderlen;
     
   }
   else{
     lo = ladderlen;
        }
   
  
 
    
   f++;
   
   }

   printf("final: %lf\n",ladderlen * (sqrt(((800 * 800) + (700 * 700))/
				    ((6 * 6) + (6 * 6)))));
   
}




int main(){
  double m[2];
  double n[2];
  double n1, n2;
  int i;
  Px = 300;  Py = 300;  Pr = 300 ;
  Tx = 0 ;  Ty = 0 ;  Tr = 3 ;

  double screen_size = 2*Pr + 1 ;
  G_init_graphics(screen_size, screen_size) ;
  int k ;



  
  while (0 == 0) {
    pic() ;
    k = G_wait_key() ;
    

    if (k == 'q') {
      break ;
    } else if (k == 65361) {
      // left arrow
      Tx -= 0.01*Tr ;
    } else if (k == 65362) {
      // up arrow
      Ty += 0.01*Tr ;
    } else if (k == 65363) {
      // right arrow
      Tx += 0.01*Tr ;
    } else if (k == 65364) {
      // down arrow
       Ty -= 0.01*Tr ;
    } else if (k == 'i') {
      Tr *= 0.98 ;
    } else if (k == 'o') {
      Tr /= 0.98 ;
    }

  }


}
