task main()
{
	TFileHandle Handle;              // will keep track of our file
	TFileIOResult Result;                // will store our IO results
	string Name = "test.txt";   // the name of our file
	int Size = 224;          // will store our file size
	int page = 1;
	int button = 0;

	//struct screen
	//{
	string p1Lines[16];
	string p2Lines[
	int linenum = 0;
	//	int

	const char CR = 0x0D;   // define CR (carriage return)
	const char LF = 0x0A;   // define LF (line feed)

	byte incommingChar;                          // this will store each char as we read back in from the file
	byte incommingString[Size];
	//string shownString;

	OpenRead(Handle, Result, Name, Size);     // open our file 'sFileName' for reading

	//nxtDisplayCenteredBigTextLine(3, "%s", "LOADING");
	for(int i = 0; i <= 14; i++)                          // iterate through the file until we've hit the end:
	{
		for(int j; j <= 16)
		{
		ReadByte(Handle, Result, incommingChar);            // read in a single byte
		incommingString[j] = incommingChar;
		}
			memcpy(p1Lines[linenum], incommingString, 16);
			memset(incommingString, 0, 16);
	}

	Close(Handle, Result);                              // close our file (DON'T FORGET THIS STEP!)

	writeDebugStream(p1Lines);
	while(true);


	/*
	while(true)
	{
	button = nNxtButtonPressed;
	switch (button)
	{
	case -1:
	break;
	case 1:
	page += 1;
	break;
	case 2:
	if (page >= 1)
	{
	page -=1;
	}
	break;
	}
	eraseDisplay();

	for(int i = 1; i >= 8; i++)
	{
	//linenum = (page - 1) * 7;
	nxtDisplayTextLine(i, "%s", p1Lines[i]);
	}


	//nxtDisplayTextLine(1, "%X", incommingString[page]);
	//memcpy(shownString, incommingString, sizeof(incommingString));
	//StringDelete(shownString, 0, place);
	//StringDelete(shownString, place + 16, sizeof(shownString) - 16);
	//nxtDisplayTextLine(2, "%s", shownString);
	//nxtDisplayTextLine(3, "%d", page);
	wait1Msec(250);
	}
	*/
}
