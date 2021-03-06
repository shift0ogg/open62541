/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017-2018 Fraunhofer IOSB (Author: Andreas Ebner)
 */

#ifndef UA_PUBSUB_MANAGER_H_
#define UA_PUBSUB_MANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ua_pubsub.h"
#include "ua_server_pubsub.h"

typedef struct UA_PubSubManager{
    //Connections and PublishedDataSets can exist alone (own lifecycle) -> top level components
    size_t connectionsSize;
    UA_PubSubConnection *connections;
} UA_PubSubManager;

void UA_PubSubManager_delete(UA_Server *server, UA_PubSubManager *pubSubManager);

void UA_PubSubManager_generateUniqueNodeId(UA_Server *server, UA_NodeId *nodeId);

UA_PubSubConnection *
UA_PubSubManager_findConnectionbyId(UA_Server *server, UA_NodeId connectionIdentifier);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* UA_PUBSUB_MANAGER_H_ */
