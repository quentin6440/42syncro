*This project has been created as part of the 42 curriculum by qcyril-a.*

# NetPractice

## Description

NetPractice is a networking configuration project from the 42 Common Core.

The goal is to learn and practice the basics of computer networking by configuring network diagrams until they function correctly.

The project contains **10 levels**, covering IP addressing, subnetting, routing, gateways, routers and switches.

## Instructions

Start the training interface with:

```bash
./run.sh
```

Each level provides a network diagram and one or more objectives. Modify the available fields and use **Check again** to verify the configuration.

The **Get my config** button allows you to export the configuration of a completed level.

For submission, **10 exported configuration files** (one for each level) must be placed at the root of the repository.

## Networking Concepts

<details>
  <summary><b> IP Addressing </b></summary>

IPv4 addresses identify devices on a network and consist of four bytes (octets), for example:

```text
192.168.10.37
```

</details>

<details>
  <summary><b> Subnet Masks </b></summary>

A subnet mask determines which part of an IP address represents the network and which part represents the hosts.

For example:

```text
192.168.10.37/24
255.255.255.0
```

CIDR notation (`/24`, `/25`, `/26`, etc.) determines the size of the subnetwork.

For example '255.255.255.0' which translates to `/24` means the first 24 bits are part of the network prefix and the 8 remaining bits form the host portion, which determines the network address (192.168.10.0), broadcast address (192.168.10.255) and host addresses (254 available here).

</details>

<details>
  <summary><b> Gateways </b></summary>
A gateway is a device, usually a router, that allows a host to communicate with devices outside its local network.

A host uses its default gateway when the destination IP address is not part of its local subnet.
</details>

<details>
  <summary><b> Routing </b></summary>

Routing is the process of determining where network packets should be sent to reach their destination.

Routers use routing information to forward packets between different networks. A default route can be used when no more specific route matches the destination.
</details>

<details>
  <summary><b> OSI model, TCP/IP </b></summary>

The project introduces basic networking concepts related to the OSI and TCP/IP models, especially:

* Layer 2: Ethernet, MAC addresses and switches
* Layer 3: IP addresses, subnetting and routers
* Layer 4: TCP and UDP

</details>

## Resources

* 42 NetPractice subject
* RFC 791 — Internet Protocol
* Cisco Networking Basics
* Cloudflare Learning Center — Networking

## Useful links

- [Guide to NetPractice (GitHub)](https://github.com/lpaube/NetPractice) — *Methodical workflow description*
- [Subnet Masks Reference Table](https://www.cloudaccess.net/cloud-control-panel-ccp/157-dns-management/322-subnet-masks-reference-table.html) — *CIDR prefix table referencing subnet masks, block size and number of usable hosts.*

## AI usage

AI was used as a general learning pal to find new or explain internet resources on networking concepts, subnetting, IP calculations, routing and network diagrams. It was also used to answer contextual questions and connect information from different resources, thus helping to apply the theoretical knowledge during the exercises.
 
<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>