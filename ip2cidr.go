package main

import (
	log "github.com/sirupsen/logrus"
	"net"
)

func parseCIDRs(txtList []string) []*net.IPNet  {
	var networkList = make([]*net.IPNet,0, 50)
	for _, cidrTxt := range txtList {
		_,network, err := net.ParseCIDR(cidrTxt)
		if err != nil || network == nil {
			log.Printf("%s fail to parse to CIDR\n", cidrTxt)
			continue
		}
		networkList = append(networkList, network)
	}

	return networkList
}