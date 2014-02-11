//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/arpees/packetarpees.msg.
//

#ifndef _PACKETARPEES_M_H_
#define _PACKETARPEES_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "packetcr_m.h"
// }}



/**
 * Class generated from <tt>networklayer/arpees/packetarpees.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketARPEES extends PacketCR {
 * }
 * </pre>
 */
class PacketARPEES : public ::PacketCR
{
  protected:

  private:
    void copy(const PacketARPEES& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketARPEES&);

  public:
    PacketARPEES(const char *name=NULL, int kind=0);
    PacketARPEES(const PacketARPEES& other);
    virtual ~PacketARPEES();
    PacketARPEES& operator=(const PacketARPEES& other);
    virtual PacketARPEES *dup() const {return new PacketARPEES(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, PacketARPEES& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketARPEES& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/arpees/packetarpees.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketARPEES_RelayReq extends PacketARPEES {
 *     txType = TX_BROADCAST;
 *     pkType = PK_REQ_RELAY;
 * }
 * </pre>
 */
class PacketARPEES_RelayReq : public ::PacketARPEES
{
  protected:

  private:
    void copy(const PacketARPEES_RelayReq& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketARPEES_RelayReq&);

  public:
    PacketARPEES_RelayReq(const char *name=NULL, int kind=0);
    PacketARPEES_RelayReq(const PacketARPEES_RelayReq& other);
    virtual ~PacketARPEES_RelayReq();
    PacketARPEES_RelayReq& operator=(const PacketARPEES_RelayReq& other);
    virtual PacketARPEES_RelayReq *dup() const {return new PacketARPEES_RelayReq(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, PacketARPEES_RelayReq& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketARPEES_RelayReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/arpees/packetarpees.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketARPEES_RelayInfo extends PacketARPEES {
 *     pkType = PK_RELAY_INFO;
 *     pkSize = 37; 
 *     
 *     bool bsFlag; 
 *     double energy; 
 *     double posX; 
 *     double posY; 
 *     double dBS; 
 * }
 * </pre>
 */
class PacketARPEES_RelayInfo : public ::PacketARPEES
{
  protected:
    bool bsFlag_var;
    double energy_var;
    double posX_var;
    double posY_var;
    double dBS_var;

  private:
    void copy(const PacketARPEES_RelayInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketARPEES_RelayInfo&);

  public:
    PacketARPEES_RelayInfo(const char *name=NULL, int kind=0);
    PacketARPEES_RelayInfo(const PacketARPEES_RelayInfo& other);
    virtual ~PacketARPEES_RelayInfo();
    PacketARPEES_RelayInfo& operator=(const PacketARPEES_RelayInfo& other);
    virtual PacketARPEES_RelayInfo *dup() const {return new PacketARPEES_RelayInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getBsFlag() const;
    virtual void setBsFlag(bool bsFlag);
    virtual double getEnergy() const;
    virtual void setEnergy(double energy);
    virtual double getPosX() const;
    virtual void setPosX(double posX);
    virtual double getPosY() const;
    virtual void setPosY(double posY);
    virtual double getDBS() const;
    virtual void setDBS(double dBS);
};

inline void doPacking(cCommBuffer *b, PacketARPEES_RelayInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketARPEES_RelayInfo& obj) {obj.parsimUnpack(b);}


#endif // _PACKETARPEES_M_H_
