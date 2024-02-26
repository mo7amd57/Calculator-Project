

#include "main.h"


int main(void)
{
	DIO_InitDirection();
	LCD_init();
	KEYPAD_Init();
	
	u8 str[20]={0};
	s32 numarr[10]={0};
	u8 numsize=0;
	u8 opparr[10]={0};
	u8 oppsize=0;
	u8 i=0;
	s32 Res=0;
	u8 index=NOT_FOUND;
	u8 flag1=0,flag2=0;
	u8 key=NO_KEY;

	while(1)
	{
		key=KEYPAD_GetKey();
		
		if (key!=NO_KEY)
		{
			
			if (key!=DELETE )
			{
				LCD_WriteChar2(LCD1,key);
				
				if (key==EQUAL)
				{
					flag1=1;
				}
				
				
				if (flag1==0)
				{
					if (flag2==0) // press delete or first solve
					{
						str[i]=key;
						i++;
					}
					else  // complete after first solve
					{
						LCD_ClearDisplay(LCD1);
						if (key==PLUS || key==MINUSE || key==MULTI || key==DIVID)
						{
							LCD_WriteNumber(LCD1,Res);
							Number_To_String(str,Res,&i);
							LCD_WriteChar(LCD1,key);
							str[i]=key;
							i++;
							
						}
						else
						{
								LCD_WriteChar(LCD1,key);
								str[i]=key;
								i++;
						}
						
	
						flag2=0;
					}
					
				}
				else  // user press equal
				{
					str[i]='\0';
					CALC_StringDivid(str,numarr,opparr,&numsize,&oppsize);
					
					index=CALC_Search_MUL_OR_DIV(opparr,oppsize);
					
					if (index==NOT_FOUND)
					{
						while(oppsize!=0)
						{
							Res=CalCulator(numarr[0],numarr[1],opparr[0]);
							numarr[0]=Res;
							CALC_NumIndex_Delete(numarr,&numsize,1);
							CALC_OPPIndex_Delete(opparr,&oppsize,0);
						}
						
					}
					else
					{
						while(index!=NOT_FOUND)
						{
							index=CALC_Search_MUL_OR_DIV(opparr,oppsize);
							Res=CalCulator(numarr[index],numarr[index+1],opparr[index]);
							numarr[index]=Res;
							CALC_NumIndex_Delete(numarr,&numsize,index+1);
							CALC_OPPIndex_Delete(opparr,&oppsize,index);
						}
						while(oppsize!=0)
						{
							Res=CalCulator(numarr[0],numarr[1],opparr[0]);
							numarr[0]=Res;
							CALC_NumIndex_Delete(numarr,&numsize,1);
							CALC_OPPIndex_Delete(opparr,&oppsize,0);
						}
						
					}
					
					if (oppsize<=0)
					{
						LCD_SetCursor(LCD1,Line2,Cell_1);
						LCD_WriteNumber(LCD1,numarr[0]);
						Res=numarr[0];
						flag2=1;
						flag1=0;
						i=0;
						index=NOT_FOUND;
					}
					
				}
				
			}
			else
			{
				LCD_ClearDisplay(LCD1);
				i=0;
				index=NOT_FOUND;
				Res=0;
				flag1=0;
				flag2=0;
			}
			
			
			
			
			
			
			
			
		}
		
	}
}

