int CreateTicket()
{
	int i, coast;
    char separators[] = ";";
    char *token;
	
	lr_output_message("Денег: %d", myMoney);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_ex(
	    "ParamName=outFlight", 
	    "LB/IC=name=\"outboundFlight\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=all");
	
	web_reg_save_param_ex(
	    "ParamName=returnFlight", 
	    "LB/IC=name=\"returnFlight\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=all");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=depart", "Value={city1}", ENDITEM, 
		"Name=departDate", "Value={date1}", ENDITEM, 
		"Name=arrive", "Value={city2}", ENDITEM, 
		"Name=returnDate", "Value={date2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={sPref}", ENDITEM, 
		"Name=seatType", "Value={sType}", ENDITEM, 
		"Name=findFlights.x", "Value=64", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);
	
	lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket1");
	lr_save_string(lr_eval_string(lr_paramarr_random("returnFlight")),"randomTicket2");

    token = (char *)strtok(lr_eval_string("{randomTicket1}"),separators);
	token = (char *)strtok(NULL, separators);
	coast = atoi(token);
	
    token = (char *)strtok(lr_eval_string("{randomTicket2}"),separators);
	token = (char *)strtok(NULL, separators);
	coast = coast + atoi(token);
	
	if (myMoney - coast < 0) {
		lr_output_message("Денег не хватило. Стоимость билета: %d. Остатовк денег: %d", coast, myMoney);
		return 1;
	}
	
	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={randomTicket1}", ENDITEM, 
		"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={sType}", ENDITEM, 
		"Name=seatPref", "Value={sPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=53", ENDITEM, 
		"Name=reserveFlights.y", "Value=14", ENDITEM, 
		LAST);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={name}", ENDITEM, 
		"Name=lastName", "Value={surname}", ENDITEM, 
		"Name=address1", "Value={adr1}", ENDITEM, 
		"Name=address2", "Value={adr2}", ENDITEM, 
		"Name=pass1", "Value={name} {surname}", ENDITEM, 
		"Name=creditCard", "Value={cCard}", ENDITEM, 
		"Name=expDate", "Value={cDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={sType}", ENDITEM, 
		"Name=seatPref", "Value={sPref}", ENDITEM, 
		"Name=outboundFlight", "Value={randomTicket1}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=61", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	lr_output_message("Куплен билет из %s до %s. Цена: %d. ID рейса туда: %s. ID рейса обратно: %s.", 
	                  lr_eval_string("{city1}"), 
	                  lr_eval_string("{city2}"),
	                  coast,
	                  lr_eval_string("{randomTicket1}"),
	                  lr_eval_string("{randomTicket2}"));
	
	myMoney = myMoney - coast;
//	lr_output_message("Остатовк денег: %d", myMoney);
	prices[j] = coast;
	++j;

	return 0;
}
