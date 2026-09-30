*This project has been created as part of the 42 curriculum by qcyril-a.*

# NetPractice

## Description

NetPractice is a networking project from the 42 curriculum.
The goal is to learn and practice the basics of computer networking by configuring network diagrams until they function correctly.

The project contains **10 levels**, covering IP addressing, subnetting, routing, gateways, routers and switches.

## Instructions

Start the training interface with:

```bash
./run.sh
```

Each level provides a network diagram and one or more objectives. Modify the available fields and use **Check again** to verify the configuration.

The **Get my config** button allows you to export the configuration of a completed level.

For submission, **10 exported configuration files**, one for each level, must be placed at the root of the repository.

## Networking Concepts

### IP Addressing

IPv4 addresses identify devices on a network and consist of four octets, for example:

```text
192.168.10.37
```

### Subnet Masks

A subnet mask determines which part of an IP address represents the network and which part represents the hosts.

For example:

```text
192.168.10.37/24
255.255.255.0
```

CIDR notation (`/24`, `/25`, `/26`, etc.) determines the size of the network.

### OSI / TCP-IP

The project introduces basic networking concepts related to the OSI and TCP/IP models, especially:

* Layer 2: Ethernet, MAC addresses and switches
* Layer 3: IP addresses, subnetting and routers
* Layer 4: TCP and UDP

## Resources

* RFC 791 — Internet Protocol
* Cisco Networking Basics
* Cloudflare Learning Center — Networking
* 42 NetPractice subject

AI was used as a learning aid to explain networking concepts, subnetting, IP calculations, routing and network diagrams, and to help understand errors encountered during the exercises.
 
