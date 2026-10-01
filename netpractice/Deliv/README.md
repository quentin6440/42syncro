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

### IP Addressing and Subnet Mask

IPv4 addresses identify devices on a network and consist of four bytes (octets), for example:

```text
192.168.10.37
```

A subnet mask determines which part of an IP address represents the network and which part represents the hosts.

For example:

```text
192.168.10.37/24
255.255.255.0
```

CIDR (Classless Inter-Domain Routing) notation (`/24`, `/25`, `/26`, etc.) determines the size of the subnetwork.

For example '255.255.255.0' which translates to `/24` means the first 24 bits are part of the network prefix and the 8 remaining bits form the host portion, which determines the network address (192.168.10.0), broadcast address (192.168.10.255) and host addresses (254 available here).

#### IPv4 Address Ranges & Special Addresses

Some IPv4 address ranges are reserved for specific purposes. They can be identified using CIDR notation, which also makes their size and boundaries explicit.

> **Note:** IPv4 classful addressing (Class A, B, C, etc.) is historical.
> Modern networks use **CIDR and subnet masks** instead, which provide much
> more flexible network sizes. For NetPractice, understanding CIDR, subnet
> masks, network addresses, broadcast addresses and these special ranges is
> more useful than memorizing the old address classes.

For example:

- `192.168.0.0/24` → `255.255.255.0` → `192.168.0.0` to `192.168.0.255`
- `10.0.0.0/8` → `255.0.0.0` → `10.0.0.0` to `10.255.255.255`

The `/prefix` therefore makes it possible to identify the whole range without
having to explicitly write its first and last address.

<details>
  <summary><b> Private IPv4 Addresses </b></summary>

Private addresses are used inside local networks and are **not directly
routable on the public Internet**.

There are three private IPv4 ranges:

| CIDR | Range | Typical use |
|---|---|---|
| `10.0.0.0/8` | `10.0.0.0` – `10.255.255.255` | Large private networks |
| `172.16.0.0/12` | `172.16.0.0` – `172.31.255.255` | Private networks |
| `192.168.0.0/16` | `192.168.0.0` – `192.168.255.255` | Home/small networks |

These ranges can be reused by different private networks because they are
not globally routable. A router typically uses **NAT** (Network Address
Translation) to allow devices with private addresses to communicate with the public Internet.

</details>
<details>
  <summary><b> Special and Reserved IPv4 Addresses </b></summary>

Some IPv4 ranges have specific purposes and should not be treated as normal
host addresses:

| CIDR | Range | Purpose |
|---|---|---|
| `127.0.0.0/8` | `127.0.0.0` – `127.255.255.255` | Loopback / local host |
| `169.254.0.0/16` | `169.254.0.0` – `169.254.255.255` | Link-local / APIPA |
| `100.64.0.0/10` | `100.64.0.0` – `100.127.255.255` | Carrier-Grade NAT (CGNAT) |
| `224.0.0.0/4` | `224.0.0.0` – `239.255.255.255` | Multicast |

- **Loopback (`127.0.0.0/8`)**: addresses used by a machine to communicate
  with itself. `127.0.0.1` is the most commonly used loopback address and is
  also known as `localhost`.

- **Link-local (`169.254.0.0/16`)**: automatically assigned when a device
  cannot obtain an IPv4 address from a DHCP server. This is commonly called
  **APIPA** (Automatic Private IP Addressing). It allows devices on the same
  local link to communicate without a DHCP server, but it is not intended for
  normal routed communication.

- **CGNAT (`100.64.0.0/10`)**: a range reserved for **Carrier-Grade NAT**.
  Internet Service Providers can use these addresses between their customers
  and their own NAT infrastructure when many customers share a limited
  number of public IPv4 addresses. They are therefore not ordinary private
  addresses like `10.0.0.0/8` or `192.168.0.0/16`.

- **Multicast (`224.0.0.0/4`)**: addresses used to send traffic to multiple
  hosts simultaneously rather than to a single destination.

</details>

### Gateways

A gateway is a device, usually a router, that allows a host to communicate with devices outside its local network.

A host uses its default gateway when the destination IP address is not part of its local subnet.


### Routing

Routing is the process of determining where network packets should be sent to reach their destination.

Routers use routing information to forward packets between different networks. A default route can be used when no more specific route matches the destination.

### OSI and TCP/IP models

The project introduces basic networking concepts related to the OSI and TCP/IP models, especially:

* Layer 2: Ethernet, MAC addresses and switches
* Layer 3: IP addresses, subnetting and routers
* Layer 4: TCP and UDP

## Resources

* 42 NetPractice subject
* RFC 791 — Internet Protocol
* Cisco Networking Basics
* Cloudflare Learning Center — Networking

## Useful links

- [Guide to NetPractice (GitHub)](https://github.com/lpaube/NetPractice) — *Methodical workflow description*
- [Subnet Masks Reference Table](https://www.cloudaccess.net/cloud-control-panel-ccp/157-dns-management/322-subnet-masks-reference-table.html) — *CIDR prefix table referencing subnet masks, block size and number of usable hosts.*

## AI usage

AI was used for answering contextual questions by connecting and formatting different information from different resources.
 
<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>
