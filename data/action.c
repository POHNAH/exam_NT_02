Action()
{

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	/* enter */

	lr_think_time(19);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=alex", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=passwordConfirm", "Value=1234", ENDITEM, 
		"Name=firstName", "Value=Alexander", ENDITEM, 
		"Name=lastName", "Value=Volkov", ENDITEM, 
		"Name=address1", "Value=Lenina", ENDITEM, 
		"Name=address2", "Value=12", ENDITEM, 
		"Name=register.x", "Value=52", ENDITEM, 
		"Name=register.y", "Value=14", ENDITEM, 
		LAST);

	/* user */

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	/* logoff1 */

	lr_think_time(21);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(23);

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=131106.084649656zHtDHzQpccQVzzzHtAtzcpzVfDHf", ENDITEM, 
		"Name=username", "Value=Alex", ENDITEM, 
		"Name=password", "Value=1234", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=73", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		LAST);

	lr_think_time(18);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	/* login */

	/* flightCity */

	lr_think_time(17);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=04/16/2021", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=04/17/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=56", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=051;245;04/16/2021", ENDITEM, 
		"Name=returnFlight", "Value=502;260;04/17/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=53", ENDITEM, 
		"Name=reserveFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_think_time(17);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Alexander", ENDITEM, 
		"Name=lastName", "Value=Volkov", ENDITEM, 
		"Name=address1", "Value=Lenina", ENDITEM, 
		"Name=address2", "Value=12", ENDITEM, 
		"Name=pass1", "Value=Alexander Volkov", ENDITEM, 
		"Name=creditCard", "Value=1234", ENDITEM, 
		"Name=expDate", "Value=01/24", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value=051;245;04/16/2021", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=502;260;04/17/2021", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=61", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);

	/* logoff2 */

	lr_think_time(24);

	web_url("SignOff Button_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}