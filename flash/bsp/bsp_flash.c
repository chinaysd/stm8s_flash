#include "bsp_flash.h"

#if 0
typedef enum
{ 
    FAILED = 0, 
    PASSED = !FAILED
} 
TestStatus;

__IO TestStatus OperationStatus;
#endif

void Test_Flash_Init(void)
{
    #if 0
    uint8_t val = 0x00, val_comp = 0x00;
    uint32_t add = 0x00;
 
     /* Define FLASH programming time */
         //Standard programming time fixed at 1/2 tprog
     FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
 
     /* Unlock Data memory */
         //compare to two hardware key value: 0x56 and 0xAE
     FLASH_Unlock(FLASH_MEMTYPE_DATA); 
 
     /* Read a byte at a specified address */
     add = 0x40A5;
         //read one byte from the address
     val = FLASH_ReadByte(add); 
 
     /* Program complement value (of previous read byte) at previous address + 1 */
     val_comp = (uint8_t)(~val);
         //modify one byte at the address
     FLASH_ProgramByte((add + 1), val_comp); 
 
     /* Check program action */
     val = FLASH_ReadByte((add + 1));
     if (val != val_comp)
     {
         /* Error */
         OperationStatus = FAILED;
         /* OperationStatus = PASSED, if the data written/read to/from DATA EEPROM memory is correct */
         /* OperationStatus = FAILED, if the data written/read to/from DATA EEPROM memory is corrupted */
         while (1)
         {
         }
     }
 
     /* Erase byte at a specified address & address + 1 */
         //erase one byte at the address
     FLASH_EraseByte(add);
     FLASH_EraseByte((add + 1));
          /* Erase action */
     val = FLASH_ReadByte(add);
     val_comp = FLASH_ReadByte((add + 1));
     if ((val != 0x00) & (val_comp != 0x00))
     {
         /* Error */
         OperationStatus = FAILED;
         /* OperationStatus = PASSED, if the data written/read to/from DATA EEPROM memory is correct */
         /* OperationStatus = FAILED, if the data written/read to/from DATA EEPROM memory is corrupted */
         while (1)
         {
         }
     }
 
     /* Pass */
     OperationStatus = PASSED;
     /* OperationStatus = PASSED, if the data written/read to/from DATA EEPROM memory is correct */
     /* OperationStatus = FAILED, if the data written/read to/from DATA EEPROM memory is corrupted */
     #endif
}







