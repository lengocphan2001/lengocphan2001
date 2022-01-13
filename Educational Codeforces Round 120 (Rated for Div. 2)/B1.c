#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0){
    	if (b == 0){
    		if (c == 0)
    			printf("VO SO NGHIEM!");	
    		else printf("VO NGHIEM!");
    	} 
    	else{
    		printf("X1=%0.3f", -c/(float)b);
    	}
    }else{
    	float delta = b*b - 4*a*c;
    	if (delta < 0){
    		printf("VO NGHIEM!");
    	}else if (delta == 0){
    		printf("X1=X2=%0.3f", -b/(float)2*a);
    	}else {
    		printf("X1=%0.3f", (-b+sqrt(delta))/(float)2*a);
    		printf("\nX2=%0.3f", (-b-sqrt(delta))/(float)2*a);
    	}
    }
    
    
}