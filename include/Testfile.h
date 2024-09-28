// start reading from the first byte (address 0) of the EEPROM
int address = 0;

void TESTsetup()
{
  //Serial1.begin(115200);
  //while (!Serial1);

  delay(200);

  Serial1.print(F("\nStart EEPROM_write on ")); Serial1.println(BOARD_NAME);
  Serial1.println(FLASH_STORAGE_STM32_VERSION);

  Serial1.print("EEPROM length: ");
  Serial1.println(EEPROM.length());
}

void TESTloop()
{
  unsigned long startMillis = millis();
  
  for (int i = 0 ; i < EEPROM.length() ; i++) 
  {
    /***
      The function EEPROM.update(address, val) is equivalent to the following:
  
      if( EEPROM.read(address) != val )
      {
        EEPROM.write(address, val);
      }
    ***/
    EEPROM.write(i, (uint8_t) analogRead(0));
  }
  
  EEPROM.commit();

  Serial1.print("Done writing emulated EEPROM. Time spent (ms) = "); Serial1.println(millis() - startMillis);

  delay(60000);
}