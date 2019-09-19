# BERIST: BBR-powered Efficient and Robust Internet Speed Test for End Users
### Introduction
Web-based speed test systems (STSes) such as SpeedTest:net are extremely popular. In this paper, we conduct a comprehensive measurement study of commercial STSes, finding that their reported speed is oftentimes inaccurate/ inconsistent, that their test duration is typically 10+ seconds, and that their consumed network traffic can reach hundreds of MBs over a high-speed access link. We also carefully reverse-engineer their speed test logic, whose many design decisions are found to be ad-hoc and non-adaptive. Motivated by the above findings, we design and implement BERIST, a novel STS solution that innovates web-based STSes by strategically leveraging the emerging BBR congestion control to provide accurate, robust, and bandwidth-efficient speed test. BERIST is further boosted by several important optimizations such as intelligent sampling, data-driven test server selection, and adaptive multi-homing. Real-world tests including those conducted on commercial 5G networks show that BERIST significantly outperforms existing STSes in accuracy, duration, and data usage under the same server pool size. In addition, using only 30 test servers, BERIST achieves similar accuracy compared to SpeedTest:net that employs 8,800 test servers, while incurring 4.3 shorter duration and 10.7 less data usage.
<br/>


### Client Sides of Other Systems We Implemented

|STS|Website|Our Implementation|
|:----:|------|------|
|SpeedOf|[https://speedof.me](https://speedof.me/)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-Speedof.me/](https://github.com/BERIST/BERIST.github.io/tree/master/client-Speedof.me/)|
|BWP|[https://www.bandwidthplace.com](https://www.bandwidthplace.com/)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-BandwidthPlace](https://github.com/BERIST/BERIST.github.io/tree/master/client-BandwidthPlace/)|
|SFtest|[https://sourceforge.net/speedtest](https://sourceforge.net/speedtest/)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-SourceForge/](https://github.com/BERIST/BERIST.github.io/tree/master/client-SourceForge/)|
|ATTtest|[http://speedtest.att.com/speedtest](http://speedtest.att.com/speedtest/)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-ATTSpeedTest/](https://github.com/BERIST/BERIST.github.io/tree/master/client-ATTSpeedTest/)|
|Xfinity|[http://speedtest.xfinity.com/](http://speedtest.xfinity.com)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-XFinity/](https://github.com/BERIST/BERIST.github.io/tree/master/client-XFinity/)|
|FAST|[https://fast.com](https://fast.com)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-Fast.com/](https://github.com/BERIST/BERIST.github.io/tree/master/client-Fast.com/)|
|SpeedTest|[https://speedtest.net](https://speedtest.net)|[https://github.com/BERIST/BERIST.github.io<br/>/tree/master/client-SpeedTest.net/](https://github.com/BERIST/BERIST.github.io/tree/master/client-SpeedTest.net/)|

