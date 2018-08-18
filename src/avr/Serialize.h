void serialize_lcd1(const char *l) {

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  //char          originalSysEx[128];
  //byte          encodedSysEx[128];
  //unsigned int  encodedSize;

  root["lcd1"] = l;

  Serial3.write(0xF0);
  root.printTo(Serial3);
  Serial3.write(0xF7);
  Serial3.flush();
  /*
    root.printTo(originalSysEx, sizeof(originalSysEx));
    for (unsigned int i = 0; i < strlen(originalSysEx); i++)
    originalSysEx[i] &= 0x7F;
    RTP_MIDI.sendSysEx(originalSysEx, strlen(originalSysEx));
  */
  /*
    DPRINTLN(originalSysEx);
    encodedSize = midi::encodeSysEx((const byte *)originalSysEx, encodedSysEx, strlen(originalSysEx));
    DPRINTLN(encodedSize);
    DPRINTLN((char *)encodedSysEx);
    RTP_MIDI.sendSysEx(encodedSize, encodedSysEx);
  */
}


void serialize_lcd2(const char *l) {

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["lcd2"] = l;

  Serial3.write(0xF0);
  root.printTo(Serial3);
  Serial3.write(0xF7);
  Serial3.flush();
}

void serialize_lcd_clear() {

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["lcd.clear"] = true;

  Serial3.write(0xF0);
  root.printTo(Serial3);
  Serial3.write(0xF7);
  Serial3.flush();
}