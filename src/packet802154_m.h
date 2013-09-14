//
// Generated file, do not edit! Created by opp_msgc 4.3 from packet802154.msg.
//

#ifndef _PACKET802154_M_H_
#define _PACKET802154_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>packet802154.msg</tt> by opp_msgc.
 * <pre>
 * enum TxType {
 *     TX_PPP = 0; 
 *     TX_BROADCAST = -1;
 * };
 * </pre>
 */
enum TxType {
    TX_PPP = 0,
    TX_BROADCAST = -1
};

/**
 * Class generated from <tt>packet802154.msg</tt> by opp_msgc.
 * <pre>
 * packet Packet802154 {
 *     
 *     int txType @enum(TxType);
 *     
 *     int srcMacAddr;
 *     
 *     int desMacAddr;
 * }
 * </pre>
 */
class Packet802154 : public ::cPacket
{
  protected:
    int txType_var;
    int srcMacAddr_var;
    int desMacAddr_var;

  private:
    void copy(const Packet802154& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Packet802154&);

  public:
    Packet802154(const char *name=NULL, int kind=0);
    Packet802154(const Packet802154& other);
    virtual ~Packet802154();
    Packet802154& operator=(const Packet802154& other);
    virtual Packet802154 *dup() const {return new Packet802154(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getTxType() const;
    virtual void setTxType(int txType);
    virtual int getSrcMacAddr() const;
    virtual void setSrcMacAddr(int srcMacAddr);
    virtual int getDesMacAddr() const;
    virtual void setDesMacAddr(int desMacAddr);
};

inline void doPacking(cCommBuffer *b, Packet802154& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Packet802154& obj) {obj.parsimUnpack(b);}


#endif // _PACKET802154_M_H_