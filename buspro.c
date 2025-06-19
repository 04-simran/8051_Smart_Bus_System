#include<reg51.h>

//char stops[][10]={"Stop 1","Stop 2","Stop 3","Stop 4","Stop 5"};
int i,distance[]={50,40,30,20,10};
int currentstop=0;
int stopno[1];
sbit rs=P0^5;
sbit rw=P0^6;
sbit en=P0^7;
#define data_line P2

sbit r0=P3^0;
sbit r1=P3^1;
sbit r2=P3^2;
sbit r3=P3^3;
sbit c0=P3^4;
sbit c1=P3^5;
sbit c2=P3^6;
sbit c3=P3^7;

sbit in1=P1^1;
sbit in2=P1^2;

sbit led1=P1^3;
sbit led2=P1^4;
sbit led3=P1^6;

void lcd_init(void);
void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_string(unsigned char *);
void delay(int);
void motor_on(void);
void motor_of(void);



void main()
{
	unsigned char str[14]="WELCOME TO BUS";
	unsigned char str1[15]="Enter the Bus";
	lcd_init();
	lcd_string(str);
	delay(50);
	lcd_cmd(0Xc0);
	lcd_string(str1);
	delay(50);
	lcd_cmd(0X01);
	led1=0;
	led2=1;
	led3=0;
	while(1)
	{
		r0=0;
		r1=r2=1;
		if(c0==0)
		{
			lcd_data('1');
			stopno[i]=1;
			delay(100);
			if(led2==1)
			{
			delay(100);
			motor_on();
				delay(200);
				motor_of();
			}
	 }
		r0=0;
		r1=r2=1;
		if(c1==0)
		{
			lcd_data('2');
			stopno[i]=2;
			delay(50);
			if(led2==1)
			{
			motor_on();
				delay(500);
				motor_of();

			}
		}
		r0=0;
		r1=r2=1;
		if(c2==0)
		{
			lcd_data('3');
			stopno[i]=3;
			delay(50);
			if(led2==1)
			{
			motor_on();
				delay(500);
				motor_of();
			}
		}
				r1=0;
		r0=r2=1;
		if(c0==0)
		{
			lcd_data('4');
			stopno[i]=4;
			delay(50);
			if(led2==1)
			{
			motor_on();
				delay(500);
				motor_of();
			}
		}
				r1=0;
		r0=r2=1;
		/*if(c1==0)
		{
			lcd_data('5');
			stopno[i]=5;
			delay(50);
		  if(led1==1)
			{
			motor_on();
			}
	
		}*/
		r1=0;
		r0=r2=1;
		if(c2==0)
		{
			lcd_data('6');
			delay(50);
			if(led1==1)
			{
			motor_on();
			}
		}
				r2=0;
		r1=r0=1;
		if(c0==0)
		{
			lcd_data('7');
			delay(50);
			if(led1==1)
			{
			motor_on();
			}
		}
    r2=0;
		r1=r0=1;
		if(c1==0)
		{
			lcd_data('8');
			delay(50);
			if(led1==1)
			{
			motor_on();
			}
			
		}
		r2=0;
		r1=r0=1;
		if(c2==0)
		{
			lcd_data('9');
			delay(50);
			if(led1==1)
			{
			motor_on();
			}
		}
		delay(200);
		
	/*while(currentstop<stopno[i])
	{
		lcd_cmd(0x01);
		//lcd_string("CURRENT STOP");
		//lcd_cmd(0xc0);
		lcd_string(stops[currentstop]);
		lcd_cmd(0xc0);
		lcd_string("Dist");
		lcd_data(distance[currentstop]/10+'0');
		lcd_data(distance[currentstop]%10+'0');
		lcd_string("km");
		
		delay(3000);
		currentstop++;*/
		if(currentstop==stopno[i])
		{
			delay(100);
			lcd_cmd(0x01);
			lcd_cmd(0X80);
			lcd_string("Arrived");
			led3=1;
		}
		
	}
		}
	}
void lcd_init(void)
{
	lcd_cmd(0x30);
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned char c)
{
	data_line=c;
	rs=0;
	rw=0;
	en=1;
	delay(50);
	en=0;
}
void lcd_data(unsigned char c)
{
	data_line=c;
	rs=1;
	rw=0;
	en=1;
	delay(50);
	en=0;
}
void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<300;j++);
	}
}
void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
		p++;
	}
}

void motor_on(void)
{
	in1=1;
	in2=0;
}
void motor_of(void)
{
	in1=0;
	in2=0;
}