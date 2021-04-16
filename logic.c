logic()
{
	int i = 0;
	j = 1;
	
	myMoney = 7000;
	
	Enter();
	
	vuser_init();
	while (i == 0) {
		i = CreateTicket();
	}
	
	for(i = 1; i<j; i++) {
		lr_output_message("Билет №%d цена %d$.",i,prices[i]);
	}
	
	vuser_end();
	
	return 0;
}
