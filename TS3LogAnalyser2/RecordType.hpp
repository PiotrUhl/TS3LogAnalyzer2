#pragma once
enum class RecordType : char {
	UNIDENTIFIED = 0,
	SERVER_STARTED,					// 2014-10-18 09:44:09.925743|INFO    |VirtualServer |  1| listening on 0.0.0.0:9987
	SERVER_MODIFIED,				// 2014-12-10 11:05:01.267303|INFO    |VirtualServerBase|  1| server was edited by 'PiotrU'(id:2)
	SERVER_STOPPED,					// 2014-10-18 10:05:46.614395|INFO    |VirtualServerBase|  1| stopped
	PERMISSION_CHANGED,				// 2014-10-19 11:41:32.945257|INFO    |VirtualServer |  1| permission 'i_ft_needed_file_upload_power'(id:234) with values (value:75) was added by 'PiotrU'(id:2) to channelgroup 'Channel Admin'(id:5)
	QUERY_CONNECTED,				// 2015-01-03 17:16:54.621846|INFO    |VirtualServer |  1| query client connected 'Unknown from 174.36.245.59:50334'(id:47)
	QUERY_DISCONNECTED,				// 2015-01-03 17:16:54.966173|INFO    |VirtualServerBase|  1| query client disconnected 'Unknown from 174.36.245.59:50334'(id:47) reason
	CLIENT_CONNECTED,				// 2014-12-17 19:53:16.868424|INFO    |VirtualServerBase|  1| client connected 'Kudlaty97'(id:8) from 178.37.156.206:1092
	CLIENT_DISCONNECTED,			// 2014-12-17 19:16:48.564515|INFO    |VirtualServerBase|  1| client disconnected 'Niko'(id:4) reason 'reasonmsg=leaving'
	CLIENT_SERVERGRUOP_MODIFIED,	// 2014-10-19 11:42:30.661540|INFO    |VirtualServer |  1| client (id:4) was added to servergroup 'Normal'(id:7) by client 'PiotrU'(id:2)
	CLIENT_CHANNELGROUP_MODIFIED,	// 2014-10-19 11:42:18.902961|INFO    |VirtualServer |  1| client 'PiotrU'(id:2) was added to channelgroup 'Channel Admin'(id:5) by client 'PiotrU'(id:2) in channel 'Kana&#322; podstawowy'(id:1)
	BAN_ADDED,						// 2015-01-08 08:27:28.204767|INFO    |VirtualServer |  1| ban added reason='heheszki' cluid='CNwS8Ol/rpoi1lTZB004mbaBFP0=' bantime=3600 by client 'Marchew'(id:22)
	BAN_DELETED,					// 2015-01-14 17:02:02.313508|INFO    |VirtualServer |  1| ban deleted reason='' cluid='gsJgu8TZmqe4tq/YKaFdvJNl1Uk=' bantime=0 by client 'PameleonNS'(id:6)
	BAN_EXPIRED,					// 2015-01-13 17:30:06.884395|INFO    |BanManager    |  1| ban deleted (expired) reason='tst' cluid='CNwS8Ol/rpoi1lTZB004mbaBFP0=' bantime=60 by client 'server'(id:0)
	COMPLAINT_ADDED,				// 2015-01-14 16:50:00.791808|INFO    |VirtualServer |  1| complaint added for client 'PameleonNS'(id:6) reason 'jebie g&#243;wnem' by client 'Rysiu'(id:5)
	COMPLAINT_DELETED,				// 2015-03-16 10:52:22.129620|INFO    |VirtualServer |  1| complaint got deleted by client 'Marchew'(id:22) for client 'PiotrU'(id:2) complained by 'Marchew'(id:22)
	COMPLAINT_ALL_DELETED,			// 2015-03-16 18:11:44.265863|INFO    |VirtualServer |  1| all complaints got deleted by client 'PiotrU'(id:2) for client 'Marchew'(id:22)
	CHANNEL_CREATED,				// 2014-12-19 09:25:22.665349|INFO    |VirtualServerBase|  1| channel 'a'(id:82) created by 'Rysiu'(id:5)
	CHANNEL_EDITED,					// 2014-12-23 15:07:41.985745|INFO    |VirtualServerBase|  1| channel 'mi sie ta nazwa podoba'(id:90) edited by 'galSOON'(id:10)
	CHANNEL_DELETED,				// 2014-12-19 09:25:30.852913|INFO    |VirtualServerBase|  1| channel 'a'(id:82) deleted by 'server'(id:0)
	CHANNEL_SUB_CREATED,			// 2015-01-14 16:41:05.315766|INFO    |VirtualServerBase|  1| channel 'Tymczasowy kana&#322; wymiany danych'(id:100) created as sub channel of 'Kana&#322; podstawowy'(id:1) by 'PiotrU'(id:2)
	FILE_UPLOADED,					//2014-12-18 21:18:07.750580|INFO    |VirtualServer |  1| file upload to (id:1), '/KolekcjaGierek.png' by client 'Marchew'(id:22)
	FILE_DOWNLOADED,				//2014-12-18 09:22:17.077266|INFO    |VirtualServer |  1| file download from (id:1), '/Archiwum/Zdjecia Matela/2014-11-23_17.21.56.jpg' by client 'Marchew'(id:22)
	FILE_DELETED,					//2014-12-18 21:23:09.538498|INFO    |VirtualServer |  1| file deleted from (id:1), 'files/virtualserver_1/channel_1//KolekcjaGierek.png' by client 'PiotrU'(id:2)
	FILE_MOVED,						//2014-12-18 09:21:45.993603|INFO    |VirtualServer |  1| file renamed/moved from (id:1), 'files/virtualserver_1/channel_1//CISCO CCNA/CCNA Discovery Sieci dla domu i malych przedsiebiorstw (Wersja 4.0) - DHomesb Chapter 4.txt' to (id:1), 'files/virtualserver_1/channel_1//CISCO CCNA/CCNA Chapter 4.txt' by client 'Marchew'(id:22) 
	FILE_DIRECTORY					//2015-01-08 17:34:58.601975|INFO    |VirtualServer |  1| file directory 'files/virtualserver_1/channel_1//Obudowa Marchewy' created by client 'Marchew'(id:22) in (id:1)
};