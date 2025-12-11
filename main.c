#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/TimeDelay.h"

void Printdata(unsigned char data);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
void lcd_string(char *str,unsigned char len);
void lcd_init(void);

// RS = PD0
// RW = PD1
// EN = PD2

// D0 = PA7
// D1 = PA6
// D2 = PA5
// D3 = PB4
// D4 = PE5
// D5 = PE4
// D6 = PB1
// D7 = PB0

int main()
{
    // Clock of PORTA, PORTB, PORTD, PORTE
    SYSCTL_RCGCGPIO_R |= (1<<0) | (1<<1) | (1<<3) | (1<<4);
    // Digitalise the datapins and config pins
    GPIO_PORTA_DEN_R |= (1<<5) | (1<<6) | (1<<7);
    GPIO_PORTB_DEN_R |= (1<<0) | (1<<1) | (1<<4);
    GPIO_PORTD_DEN_R |= (1<<0) | (1<<1) | (1<<2);
    GPIO_PORTE_DEN_R |= (1<<4) | (1<<5);
    // Direction of datapins and config pins -> Output Pins
    GPIO_PORTA_DIR_R |= (1<<5) | (1<<6) | (1<<7);
    GPIO_PORTB_DIR_R |= (1<<0) | (1<<1) | (1<<4);
    GPIO_PORTD_DIR_R |= (1<<0) | (1<<1) | (1<<2);
    GPIO_PORTE_DIR_R |= (1<<4) | (1<<5);
    delay(10000);
    lcd_init();
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("Sathiskumar",11);
    lcd_cmd(0xC3);
    lcd_string("Presents",8);
    delay(10000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("S",1);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SU",2);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUP",3);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPE",4);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPER",5);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERS",6);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERST",7);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTA",8);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC7);
    lcd_string("R",1);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC6);
    lcd_string("R A",3);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC5);
    lcd_string("R A J",5);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC4);
    lcd_string("R A J I",7);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC3);
    lcd_string("R A J I N",9);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x83);
    lcd_string("SUPERSTAR",9);
    lcd_cmd(0xC2);
    lcd_string("R A J I N I",11);
    delay(10000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC8);
    lcd_string("T",1);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC7);
    lcd_string("T H",3);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC6);
    lcd_string("T H A",5);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC5);
    lcd_string("T H A L",7);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC4);
    lcd_string("T H A L A",9);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC3);
    lcd_string("T H A L A I",11);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC2);
    lcd_string("T H A L A I V",13);
    delay(1000000);
    lcd_cmd(0x01);
    lcd_cmd(0x82);
    lcd_string("HAPPY BIRTHDAY",14);
    lcd_cmd(0xC1);
    lcd_string("T H A L A I V A",15);
    delay(10000000);

    while(1)
    {

    }
}

void lcd_data(unsigned char data)
{
    Printdata(data);                 // Pass the 8Bit data to the datalines of lcd
    GPIO_PORTD_DATA_R &= (~(1<<1));  // Turn off the R/W for write operation in lcd
    GPIO_PORTD_DATA_R |= (1<<0);     // Turn on the RS for writing to the data register of lcd
    GPIO_PORTD_DATA_R |= (1<<2);     // Turn on the EN of lcd for enabling the clock of lcd
    delay(10000);                    // Wait for sometime
    GPIO_PORTD_DATA_R &= (~(1<<2));  // Turn off the EN of lcd
}

void lcd_cmd(unsigned char cmd)
{
    Printdata(cmd);                     // Pass the 8Bit data to the datalines of lcd
    GPIO_PORTD_DATA_R &= (~(1<<1));     // Turn off the R/W for write operation in lcd
    GPIO_PORTD_DATA_R &= (~(1<<0));     // Turn off the RS for writing to the data register of lcd
    GPIO_PORTD_DATA_R |= (1<<2);        // Turn on the EN of lcd for enabling the clock of lcd
    delay(10000);                       // Wait for sometime
    GPIO_PORTD_DATA_R &= (~(1<<2));     // Turn off the EN of lcd
}

void lcd_string(char *str,unsigned char len)
{
    char i;
    for(i=0;i<len;i++)
    {
        lcd_data(str[i]);
    }
}

void lcd_init(void)
{
    lcd_cmd(0x38); // 8Bit Mode utilising 16 Columns and 2 Rows
    lcd_cmd(0x06); // Auto incrementing the cursor when prints the data in current
    lcd_cmd(0x0C); // Cursor off and display on
    lcd_cmd(0x01); // Clearscreen
}

void Printdata(unsigned char data)  // data = 8 bit hexadecimal data
{
    // Bit 0 => D0 // D0 = PA7
    if((data&0x01) == 0x01) { GPIO_PORTA_DATA_R |= (1<<7);    }
    else                    { GPIO_PORTA_DATA_R &= (~(1<<7)); }
    // Bit 1 => D1 // D1 = PA6
    if((data&0x02) == 0x02) { GPIO_PORTA_DATA_R |= (1<<6);    }
    else                    { GPIO_PORTA_DATA_R &= (~(1<<6)); }
    // Bit 2 => D2 // D2 = PA5
    if((data&0x04) == 0x04) { GPIO_PORTA_DATA_R |= (1<<5);    }
    else                    { GPIO_PORTA_DATA_R &= (~(1<<5)); }
    // Bit 3 => D3 // D3 = PB4
    if((data&0x08) == 0x08) { GPIO_PORTB_DATA_R |= (1<<4);    }
    else                    { GPIO_PORTB_DATA_R &= (~(1<<4)); }
    // Bit 4 => D4 // D4 = PE5
    if((data&0x10) == 0x10) { GPIO_PORTE_DATA_R |= (1<<5);    }
    else                    { GPIO_PORTE_DATA_R &= (~(1<<5)); }
    // Bit 5 => D5 // D5 = PE4
    if((data&0x20) == 0x20) { GPIO_PORTE_DATA_R |= (1<<4);    }
    else                    { GPIO_PORTE_DATA_R &= (~(1<<4)); }
    // Bit 6 => D6 // D6 = PB1
    if((data&0x40) == 0x40) { GPIO_PORTB_DATA_R |= (1<<1);    }
    else                    { GPIO_PORTB_DATA_R &= (~(1<<1)); }
    // Bit 7 => D7 // D7 = PB0
    if((data&0x80) == 0x80) { GPIO_PORTB_DATA_R |= (1<<0);    }
    else                    { GPIO_PORTB_DATA_R &= (~(1<<0)); }
}
