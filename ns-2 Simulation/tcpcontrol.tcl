#connection oriented service and congestion control by implementing queue
#Create a simulator object
set ns [new Simulator]
set winfile [open Winfile5 w]
$ns color 1 Blue
$ns color 2 Red
set namfile [open out5.nam w]
$ns namtrace-all $namfile
#Define a 'finish' procedure
proc finish {} {
        global ns namfile
        $ns flush-trace
        close $namfile
        exec nam out5.nam &
        exit 0
}
#Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
#Create links between the nodes
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n3 $n2 1Mb 10ms DropTail
$ns queue-limit $n2 $n3 10
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op  $n2 $n3 orient right
#Implement queue for congestion control
$ns duplex-link-op $n2 $n3 queuePos 0.5


#Create a TCP agent for connection oriented service and attach it to node n0
set sendtcp [new Agent/TCP]
$ns attach-agent $n0 $sendtcp
set rectcp [new Agent/TCPSink]
$ns attach-agent $n3 $rectcp
$sendtcp set packetSize_ 1000
set ftp [new Application/FTP]
$ftp attach-agent $sendtcp
$sendtcp set class_ 1

#Create a UDP agent and attach it to node n1
set udp1 [new Agent/UDP]
$udp1 set class_ 2
$ns attach-agent $n1 $udp1
# Create a CBR traffic source and attach it to udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1
#Create a Null agent (a traffic sink) and attach it to node n3
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
#Connect the traffic sources with the traffic sink
$ns connect $sendtcp $rectcp  
$ns connect $udp1 $null0
proc plotWindow {tcpSource file} {
global ns
set time .1
set now [$ns now]
set cwnd [$tcpSource set cwnd_]
puts $file "$now $cwnd"
$ns at [expr $now + $time] "plotWindow $tcpSource $file"
}
$ns at 0.1 "plotWindow $sendtcp $winfile"

#Schedule events for the CBR agents
$ns at 0.5 "$ftp start"
$ns at 1.0 "$cbr1 start"
$ns at 4.0 "$cbr1 stop" 
$ns at 4.5 "$ftp stop"
$ns at 5.0 "finish"
$ns run
