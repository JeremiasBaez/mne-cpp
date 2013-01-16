/**
 * @author  Christof Pieloth
 */

#ifndef RTCMDCONLIST_H_
#define RTCMDCONLIST_H_

#include <QSharedPointer>

#include "RTCommandRequest.h"

namespace RTSTREAMING
{
    /**
     * Requests a connector list.
     */
    class RTCmdConList: public RTSTREAMING::RTCommandRequest
    {
    public:
        typedef QSharedPointer< RTCmdConList > SPtr;
        typedef QSharedPointer< const RTCmdConList > ConstSPtr;

        RTCmdConList();
        virtual ~RTCmdConList();

        virtual QString getHelpText() const;
    };

} /* namespace RTSTREAMING */
#endif /* RTCMDCONLIST_H_ */
