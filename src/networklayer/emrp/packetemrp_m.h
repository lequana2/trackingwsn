//
// Generated file, do not edit! Created by opp_msgc 4.3 from networklayer/emrp/packetemrp.msg.
//

#ifndef _PACKETEMRP_M_H_
#define _PACKETEMRP_M_H_

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
 * Class generated from <tt>networklayer/emrp/packetemrp.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketEMRP extends PacketCR {
 * }
 * </pre>
 */
class PacketEMRP : public ::PacketCR
{
  protected:

  private:
    void copy(const PacketEMRP& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketEMRP&);

  public:
    PacketEMRP(const char *name=NULL, int kind=0);
    PacketEMRP(const PacketEMRP& other);
    virtual ~PacketEMRP();
    PacketEMRP& operator=(const PacketEMRP& other);
    virtual PacketEMRP *dup() const {return new PacketEMRP(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, PacketEMRP& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketEMRP& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/emrp/packetemrp.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketEMRP_RelayInfo extends PacketEMRP {
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
class PacketEMRP_RelayInfo : public ::PacketEMRP
{
  protected:
    bool bsFlag_var;
    double energy_var;
    double posX_var;
    double posY_var;
    double dBS_var;

  private:
    void copy(const PacketEMRP_RelayInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketEMRP_RelayInfo&);

  public:
    PacketEMRP_RelayInfo(const char *name=NULL, int kind=0);
    PacketEMRP_RelayInfo(const PacketEMRP_RelayInfo& other);
    virtual ~PacketEMRP_RelayInfo();
    PacketEMRP_RelayInfo& operator=(const PacketEMRP_RelayInfo& other);
    virtual PacketEMRP_RelayInfo *dup() const {return new PacketEMRP_RelayInfo(*this);}
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

inline void doPacking(cCommBuffer *b, PacketEMRP_RelayInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketEMRP_RelayInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/emrp/packetemrp.msg</tt> by opp_msgc.
 * <pre>
 * packet PacketEMRP_EnergyInfo extends PacketEMRP {
 *     pkType = PK_ENERGY_INFO;
 *     
 *     
 *     
 *     double remainEnergy;
 *     
 *     pkSize = 24; 
 * }
 * </pre>
 */
class PacketEMRP_EnergyInfo : public ::PacketEMRP
{
  protected:
    double remainEnergy_var;

  private:
    void copy(const PacketEMRP_EnergyInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PacketEMRP_EnergyInfo&);

  public:
    PacketEMRP_EnergyInfo(const char *name=NULL, int kind=0);
    PacketEMRP_EnergyInfo(const PacketEMRP_EnergyInfo& other);
    virtual ~PacketEMRP_EnergyInfo();
    PacketEMRP_EnergyInfo& operator=(const PacketEMRP_EnergyInfo& other);
    virtual PacketEMRP_EnergyInfo *dup() const {return new PacketEMRP_EnergyInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual double getRemainEnergy() const;
    virtual void setRemainEnergy(double remainEnergy);
};

inline void doPacking(cCommBuffer *b, PacketEMRP_EnergyInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PacketEMRP_EnergyInfo& obj) {obj.parsimUnpack(b);}


#endif // _PACKETEMRP_M_H_
