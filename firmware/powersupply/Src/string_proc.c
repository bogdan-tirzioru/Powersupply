#include "string_proc.h"
void ConvertZecimalToAsci(T_SWORD sw_ADCT0,T_UBYTE ub_lenght,T_UBYTE *s_Response)
{
    T_UBYTE ub_index = ub_lenght-1;
    T_UBYTE ub_intpart = 0;
    T_UWORD uw_fracpart = 0;
    /*remove sign from number */
    if (sw_ADCT0 & 0x8000)
    {
        /*if there is negative number them print sign*/
        s_Response[ub_index] = '-';
        ub_index--;
        sw_ADCT0 = (~sw_ADCT0) +1;
    }
    /*extract integer part from q fixed point*/
    ub_intpart = sw_ADCT0 >>4;
    /*lowest number from digital representation of int part*/
    s_Response[ub_index-1] = (ub_intpart % 10) +'0';
    ub_intpart = ub_intpart /10 + '0';
    
    /*highiest mnumber from digital represantion of int part*/
    s_Response[ub_index] = ub_intpart;
    ub_index =ub_index -2;
    /*print point*/
    s_Response[ub_index] = '.';
    ub_index--; 
    /*remove int part*/
    uw_fracpart = sw_ADCT0 & 0x000f;
    /*bring frac part to a integer number in order to perform computation*/
    uw_fracpart = uw_fracpart * 625 / 100;
    /*copy to buffer numbers */
    s_Response[ub_index-1] = uw_fracpart % 10 + '0';
    uw_fracpart = uw_fracpart /10;
    s_Response[ub_index] = uw_fracpart % 10 + '0';
}
void ConvertHexToAsci32(T_ULONG lul_data_read,T_UBYTE *s_Response)
{
    T_ULONG lul_tempdata = lul_data_read;
    T_UBYTE lub_index =0;
    T_UBYTE lub_tempdata1 = 0;
    for (lub_index = 8;lub_index >= 1;lub_index--)
    {
       lub_tempdata1 = lul_tempdata & 0x0f;
       if (lub_tempdata1 > 9)
       {
        s_Response[lub_index+1] =  lub_tempdata1 - 10 + 'A';
       }
       else
       {
        s_Response[lub_index+1] =  lub_tempdata1 +'0';
       }
       lul_tempdata = lul_tempdata >> 4;
    }
}


/*extract address from a string of 8 ascii*/
T_ULONG ExtractAdrressReq(T_UBYTE s_Request[10])
{
    T_ULONG lul_address = 0;
    T_UBYTE lub_index = 0;
    T_UBYTE lub_temp = 0;
    /*32 bit address is stored into 8 chars*/
    for (lub_index = 2 ;lub_index < 10; lub_index++)
    {
        /*load char into temporary variable*/
        lub_temp = s_Request[lub_index];
        /*if numerical add to address computed so far*/
        if( lub_temp >='0' && lub_temp<='9')
        {
            lul_address = lul_address + (s_Request[lub_index]-'0');
        }
        else
        {
            /*take into consideration hexa notation of address*/
            if(lub_temp >='a' && lub_temp<='f')
            {
                lul_address = lul_address + (s_Request[lub_index]-'a')+10;
            }
            else
            {
                if(lub_temp >='A' && lub_temp<='F')
                {
                    lul_address = lul_address + (s_Request[lub_index]-'A')+10;
                }
                else
                {
                }
            }
        }
        
        if (lub_index < 9)
        {
            lul_address = lul_address << 4;
        }
    }
    return lul_address;
}

