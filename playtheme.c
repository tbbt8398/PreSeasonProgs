
task main()
{
	nxtDisplayRICFile(0, 0, "bot.ric");
	nVolume = 2;
	PlaySoundFile("bang1.rso");
	while(bSoundActive);
	PlaySoundFile("bang2.rso");
	while(bSoundActive);
	PlaySoundFile("bang3.rso");
	while(bSoundActive);

}
