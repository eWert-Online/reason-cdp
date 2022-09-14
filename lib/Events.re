module Accessibility = {
  /* The loadComplete event mirrors the load complete event sent by the browser to assistive
     technology when the web page has finished loading. */
  module LoadComplete = {
    let name = "Accessibility.loadComplete";

    [@deriving yojson]
    type result = {
      [@key "root"]
      root: Types.Accessibility.AXNode.t /* New document root node. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* The nodesUpdated event is sent every time a previously requested node has changed the in tree. */
  module NodesUpdated = {
    let name = "Accessibility.nodesUpdated";

    [@deriving yojson]
    type result = {
      [@key "nodes"]
      nodes: list(Types.Accessibility.AXNode.t) /* Updated node data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Animation = {
  /* Event for when an animation has been cancelled. */
  module AnimationCanceled = {
    let name = "Animation.animationCanceled";

    [@deriving yojson]
    type result = {
      [@key "id"]
      id: string /* Id of the animation that was cancelled. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Event for each animation that has been created. */
  module AnimationCreated = {
    let name = "Animation.animationCreated";

    [@deriving yojson]
    type result = {
      [@key "id"]
      id: string /* Id of the animation that was created. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Event for animation that has been started. */
  module AnimationStarted = {
    let name = "Animation.animationStarted";

    [@deriving yojson]
    type result = {
      [@key "animation"]
      animation: Types.Animation.Animation.t /* Animation that was started. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Audits = {
  /* No description provided */
  module IssueAdded = {
    let name = "Audits.issueAdded";

    [@deriving yojson]
    type result = {
      [@key "issue"]
      issue: Types.Audits.InspectorIssue.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module BackgroundService = {
  /* Called when the recording state for the service has been updated. */
  module RecordingStateChanged = {
    let name = "BackgroundService.recordingStateChanged";

    [@deriving yojson]
    type result = {
      [@key "isRecording"]
      isRecording: bool, /* No description provided */
      [@key "service"]
      service: Types.BackgroundService.ServiceName.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called with all existing backgroundServiceEvents when enabled, and all new
     events afterwards if enabled and recording. */
  module BackgroundServiceEventReceived = {
    let name = "BackgroundService.backgroundServiceEventReceived";

    [@deriving yojson]
    type result = {
      [@key "backgroundServiceEvent"]
      backgroundServiceEvent: Types.BackgroundService.BackgroundServiceEvent.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Browser = {
  /* Fired when page is about to start a download. */
  module DownloadWillBegin = {
    let name = "Browser.downloadWillBegin";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that caused the download to begin. */
      [@key "guid"]
      guid: string, /* Global unique identifier of the download. */
      [@key "url"]
      url: string, /* URL of the resource being downloaded. */
      [@key "suggestedFilename"]
      suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when download makes progress. Last call has |done| == true. */
  module DownloadProgress = {
    let name = "Browser.downloadProgress";

    type downloadprogress_state = [ | `inProgress | `completed | `canceled];
    let downloadprogress_state_of_yojson =
      fun
      | `String("inProgress") => `inProgress
      | `String("completed") => `completed
      | `String("canceled") => `canceled
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_downloadprogress_state =
      fun
      | `inProgress => `String("inProgress")
      | `completed => `String("completed")
      | `canceled => `String("canceled");

    [@deriving yojson]
    type result = {
      [@key "guid"]
      guid: string, /* Global unique identifier of the download. */
      [@key "totalBytes"]
      totalBytes: Types.number, /* Total expected bytes to download. */
      [@key "receivedBytes"]
      receivedBytes: Types.number, /* Total bytes received. */
      [@key "state"]
      state: downloadprogress_state /* Download status. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module CSS = {
  /* Fires whenever a web font is updated.  A non-empty font parameter indicates a successfully loaded
     web font */
  module FontsUpdated = {
    let name = "CSS.fontsUpdated";

    [@deriving yojson]
    type result = {
      [@yojson.option] [@key "font"]
      font: option(Types.CSS.FontFace.t) /* The web font that has loaded. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fires whenever a MediaQuery result changes (for example, after a browser window has been
     resized.) The current implementation considers only viewport-dependent media features. */
  module MediaQueryResultChanged = {
    let name = "CSS.mediaQueryResultChanged";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired whenever an active document stylesheet is added. */
  module StyleSheetAdded = {
    let name = "CSS.styleSheetAdded";

    [@deriving yojson]
    type result = {
      [@key "header"]
      header: Types.CSS.CSSStyleSheetHeader.t /* Added stylesheet metainfo. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired whenever a stylesheet is changed as a result of the client operation. */
  module StyleSheetChanged = {
    let name = "CSS.styleSheetChanged";

    [@deriving yojson]
    type result = {
      [@key "styleSheetId"]
      styleSheetId: Types.CSS.StyleSheetId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired whenever an active document stylesheet is removed. */
  module StyleSheetRemoved = {
    let name = "CSS.styleSheetRemoved";

    [@deriving yojson]
    type result = {
      [@key "styleSheetId"]
      styleSheetId: Types.CSS.StyleSheetId.t /* Identifier of the removed stylesheet. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Cast = {
  /* This is fired whenever the list of available sinks changes. A sink is a
     device or a software surface that you can cast to. */
  module SinksUpdated = {
    let name = "Cast.sinksUpdated";

    [@deriving yojson]
    type result = {
      [@key "sinks"]
      sinks: list(Types.Cast.Sink.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* This is fired whenever the outstanding issue/error message changes.
     |issueMessage| is empty if there is no issue. */
  module IssueUpdated = {
    let name = "Cast.issueUpdated";

    [@deriving yojson]
    type result = {
      [@key "issueMessage"]
      issueMessage: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module DOM = {
  /* Fired when `Element`'s attribute is modified. */
  module AttributeModified = {
    let name = "DOM.attributeModified";

    [@deriving yojson]
    type result = {
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t, /* Id of the node that has changed. */
      [@key "name"]
      name: string, /* Attribute name. */
      [@key "value"]
      value: string /* Attribute value. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when `Element`'s attribute is removed. */
  module AttributeRemoved = {
    let name = "DOM.attributeRemoved";

    [@deriving yojson]
    type result = {
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t, /* Id of the node that has changed. */
      [@key "name"]
      name: string /* A ttribute name. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Mirrors `DOMCharacterDataModified` event. */
  module CharacterDataModified = {
    let name = "DOM.characterDataModified";

    [@deriving yojson]
    type result = {
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t, /* Id of the node that has changed. */
      [@key "characterData"]
      characterData: string /* New text value. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when `Container`'s child node count has changed. */
  module ChildNodeCountUpdated = {
    let name = "DOM.childNodeCountUpdated";

    [@deriving yojson]
    type result = {
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t, /* Id of the node that has changed. */
      [@key "childNodeCount"]
      childNodeCount: Types.number /* New node count. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Mirrors `DOMNodeInserted` event. */
  module ChildNodeInserted = {
    let name = "DOM.childNodeInserted";

    [@deriving yojson]
    type result = {
      [@key "parentNodeId"]
      parentNodeId: Types.DOM.NodeId.t, /* Id of the node that has changed. */
      [@key "previousNodeId"]
      previousNodeId: Types.DOM.NodeId.t, /* Id of the previous sibling. */
      [@key "node"]
      node: Types.DOM.Node.t /* Inserted node data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Mirrors `DOMNodeRemoved` event. */
  module ChildNodeRemoved = {
    let name = "DOM.childNodeRemoved";

    [@deriving yojson]
    type result = {
      [@key "parentNodeId"]
      parentNodeId: Types.DOM.NodeId.t, /* Parent id. */
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t /* Id of the node that has been removed. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when distribution is changed. */
  module DistributedNodesUpdated = {
    let name = "DOM.distributedNodesUpdated";

    [@deriving yojson]
    type result = {
      [@key "insertionPointId"]
      insertionPointId: Types.DOM.NodeId.t, /* Insertion point where distributed nodes were updated. */
      [@key "distributedNodes"]
      distributedNodes: list(Types.DOM.BackendNode.t) /* Distributed nodes for given insertion point. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when `Document` has been totally updated. Node ids are no longer valid. */
  module DocumentUpdated = {
    let name = "DOM.documentUpdated";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when `Element`'s inline style is modified via a CSS property modification. */
  module InlineStyleInvalidated = {
    let name = "DOM.inlineStyleInvalidated";

    [@deriving yojson]
    type result = {
      [@key "nodeIds"]
      nodeIds: list(Types.DOM.NodeId.t) /* Ids of the nodes for which the inline styles have been invalidated. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when a pseudo element is added to an element. */
  module PseudoElementAdded = {
    let name = "DOM.pseudoElementAdded";

    [@deriving yojson]
    type result = {
      [@key "parentId"]
      parentId: Types.DOM.NodeId.t, /* Pseudo element's parent element id. */
      [@key "pseudoElement"]
      pseudoElement: Types.DOM.Node.t /* The added pseudo element. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when top layer elements are changed. */
  module TopLayerElementsUpdated = {
    let name = "DOM.topLayerElementsUpdated";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when a pseudo element is removed from an element. */
  module PseudoElementRemoved = {
    let name = "DOM.pseudoElementRemoved";

    [@deriving yojson]
    type result = {
      [@key "parentId"]
      parentId: Types.DOM.NodeId.t, /* Pseudo element's parent element id. */
      [@key "pseudoElementId"]
      pseudoElementId: Types.DOM.NodeId.t /* The removed pseudo element id. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when backend wants to provide client with the missing DOM structure. This happens upon
     most of the calls requesting node ids. */
  module SetChildNodes = {
    let name = "DOM.setChildNodes";

    [@deriving yojson]
    type result = {
      [@key "parentId"]
      parentId: Types.DOM.NodeId.t, /* Parent node id to populate with children. */
      [@key "nodes"]
      nodes: list(Types.DOM.Node.t) /* Child nodes array. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when shadow root is popped from the element. */
  module ShadowRootPopped = {
    let name = "DOM.shadowRootPopped";

    [@deriving yojson]
    type result = {
      [@key "hostId"]
      hostId: Types.DOM.NodeId.t, /* Host element id. */
      [@key "rootId"]
      rootId: Types.DOM.NodeId.t /* Shadow root id. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called when shadow root is pushed into the element. */
  module ShadowRootPushed = {
    let name = "DOM.shadowRootPushed";

    [@deriving yojson]
    type result = {
      [@key "hostId"]
      hostId: Types.DOM.NodeId.t, /* Host element id. */
      [@key "root"]
      root: Types.DOM.Node.t /* Shadow root. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module DOMStorage = {
  /* No description provided */
  module DomStorageItemAdded = {
    let name = "DOMStorage.domStorageItemAdded";

    [@deriving yojson]
    type result = {
      [@key "storageId"]
      storageId: Types.DOMStorage.StorageId.t, /* No description provided */
      [@key "key"]
      key: string, /* No description provided */
      [@key "newValue"]
      newValue: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module DomStorageItemRemoved = {
    let name = "DOMStorage.domStorageItemRemoved";

    [@deriving yojson]
    type result = {
      [@key "storageId"]
      storageId: Types.DOMStorage.StorageId.t, /* No description provided */
      [@key "key"]
      key: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module DomStorageItemUpdated = {
    let name = "DOMStorage.domStorageItemUpdated";

    [@deriving yojson]
    type result = {
      [@key "storageId"]
      storageId: Types.DOMStorage.StorageId.t, /* No description provided */
      [@key "key"]
      key: string, /* No description provided */
      [@key "oldValue"]
      oldValue: string, /* No description provided */
      [@key "newValue"]
      newValue: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module DomStorageItemsCleared = {
    let name = "DOMStorage.domStorageItemsCleared";

    [@deriving yojson]
    type result = {
      [@key "storageId"]
      storageId: Types.DOMStorage.StorageId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Database = {
  /* No description provided */
  module AddDatabase = {
    let name = "Database.addDatabase";

    [@deriving yojson]
    type result = {
      [@key "database"]
      database: Types.Database.Database.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Emulation = {
  /* Notification sent after the virtual time budget for the current VirtualTimePolicy has run out. */
  module VirtualTimeBudgetExpired = {
    let name = "Emulation.virtualTimeBudgetExpired";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module HeadlessExperimental = {
  /* Issued when the target starts or stops needing BeginFrames.
     Deprecated. Issue beginFrame unconditionally instead and use result from
     beginFrame to detect whether the frames were suppressed. */
  module NeedsBeginFramesChanged = {
    let name = "HeadlessExperimental.needsBeginFramesChanged";

    [@deriving yojson]
    type result = {
      [@key "needsBeginFrames"]
      needsBeginFrames: bool /* True if BeginFrames are needed, false otherwise. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Input = {
  /* Emitted only when `Input.setInterceptDrags` is enabled. Use this data with `Input.dispatchDragEvent` to
     restore normal drag and drop behavior. */
  module DragIntercepted = {
    let name = "Input.dragIntercepted";

    [@deriving yojson]
    type result = {
      [@key "data"]
      data: Types.Input.DragData.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Inspector = {
  /* Fired when remote debugging connection is about to be terminated. Contains detach reason. */
  module Detached = {
    let name = "Inspector.detached";

    [@deriving yojson]
    type result = {
      [@key "reason"]
      reason: string /* The reason why connection has been terminated. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when debugging target has crashed */
  module TargetCrashed = {
    let name = "Inspector.targetCrashed";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when debugging target has reloaded after crash */
  module TargetReloadedAfterCrash = {
    let name = "Inspector.targetReloadedAfterCrash";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module LayerTree = {
  /* No description provided */
  module LayerPainted = {
    let name = "LayerTree.layerPainted";

    [@deriving yojson]
    type result = {
      [@key "layerId"]
      layerId: Types.LayerTree.LayerId.t, /* The id of the painted layer. */
      [@key "clip"]
      clip: Types.DOM.Rect.t /* Clip rectangle. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module LayerTreeDidChange = {
    let name = "LayerTree.layerTreeDidChange";

    [@deriving yojson]
    type result = {
      [@yojson.option] [@key "layers"]
      layers: option(list(Types.LayerTree.Layer.t)) /* Layer tree, absent if not in the comspositing mode. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Log = {
  /* Issued when new message was logged. */
  module EntryAdded = {
    let name = "Log.entryAdded";

    [@deriving yojson]
    type result = {
      [@key "entry"]
      entry: Types.Log.LogEntry.t /* The entry. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Network = {
  /* Fired when data chunk was received over the network. */
  module DataReceived = {
    let name = "Network.dataReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "dataLength"]
      dataLength: Types.number, /* Data chunk length. */
      [@key "encodedDataLength"]
      encodedDataLength: Types.number /* Actual bytes received (might be less than dataLength for compressed encodings). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when EventSource message is received. */
  module EventSourceMessageReceived = {
    let name = "Network.eventSourceMessageReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "eventName"]
      eventName: string, /* Message type. */
      [@key "eventId"]
      eventId: string, /* Message identifier. */
      [@key "data"]
      data: string /* Message content. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when HTTP request has failed to load. */
  module LoadingFailed = {
    let name = "Network.loadingFailed";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "type"]
      type_: Types.Network.ResourceType.t, /* Resource type. */
      [@key "errorText"]
      errorText: string, /* User friendly error message. */
      [@yojson.option] [@key "canceled"]
      canceled: option(bool), /* True if loading was canceled. */
      [@yojson.option] [@key "blockedReason"]
      blockedReason: option(Types.Network.BlockedReason.t), /* The reason why loading was blocked, if any. */
      [@yojson.option] [@key "corsErrorStatus"]
      corsErrorStatus: option(Types.Network.CorsErrorStatus.t) /* The reason why loading was blocked by CORS, if any. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when HTTP request has finished loading. */
  module LoadingFinished = {
    let name = "Network.loadingFinished";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "encodedDataLength"]
      encodedDataLength: Types.number, /* Total number of bytes received for this request. */
      [@yojson.option] [@key "shouldReportCorbBlocking"]
      shouldReportCorbBlocking: option(bool) /* Set when 1) response was blocked by Cross-Origin Read Blocking and also
2) this needs to be reported to the DevTools console. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
     mocked.
     Deprecated, use Fetch.requestPaused instead. */
  module RequestIntercepted = {
    let name = "Network.requestIntercepted";

    [@deriving yojson]
    type result = {
      [@key "interceptionId"]
      interceptionId: Types.Network.InterceptionId.t, /* Each request the page makes will have a unique id, however if any redirects are encountered
while processing that fetch, they will be reported with the same id as the original fetch.
Likewise if HTTP authentication is needed then the same fetch id will be used. */
      [@key "request"]
      request: Types.Network.Request.t, /* No description provided */
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* The id of the frame that initiated the request. */
      [@key "resourceType"]
      resourceType: Types.Network.ResourceType.t, /* How the requested resource will be used. */
      [@key "isNavigationRequest"]
      isNavigationRequest: bool, /* Whether this is a navigation request, which can abort the navigation completely. */
      [@yojson.option] [@key "isDownload"]
      isDownload: option(bool), /* Set if the request is a navigation that will result in a download.
Only present after response is received from the server (i.e. HeadersReceived stage). */
      [@yojson.option] [@key "redirectUrl"]
      redirectUrl: option(string), /* Redirect location, only sent if a redirect was intercepted. */
      [@yojson.option] [@key "authChallenge"]
      authChallenge: option(Types.Network.AuthChallenge.t), /* Details of the Authorization Challenge encountered. If this is set then
continueInterceptedRequest must contain an authChallengeResponse. */
      [@yojson.option] [@key "responseErrorReason"]
      responseErrorReason: option(Types.Network.ErrorReason.t), /* Response error if intercepted at response stage or if redirect occurred while intercepting
request. */
      [@yojson.option] [@key "responseStatusCode"]
      responseStatusCode: option(Types.number), /* Response code if intercepted at response stage or if redirect occurred while intercepting
request or auth retry occurred. */
      [@yojson.option] [@key "responseHeaders"]
      responseHeaders: option(Types.Network.Headers.t), /* Response headers if intercepted at the response stage or if redirect occurred while
intercepting request or auth retry occurred. */
      [@yojson.option] [@key "requestId"]
      requestId: option(Types.Network.RequestId.t) /* If the intercepted request had a corresponding requestWillBeSent event fired for it, then
this requestId will be the same as the requestId present in the requestWillBeSent event. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired if request ended up loading from cache. */
  module RequestServedFromCache = {
    let name = "Network.requestServedFromCache";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t /* Request identifier. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when page is about to send HTTP request. */
  module RequestWillBeSent = {
    let name = "Network.requestWillBeSent";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "loaderId"]
      loaderId: Types.Network.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
      [@key "documentURL"]
      documentURL: string, /* URL of the document this request is loaded for. */
      [@key "request"]
      request: Types.Network.Request.t, /* Request data. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "wallTime"]
      wallTime: Types.Network.TimeSinceEpoch.t, /* Timestamp. */
      [@key "initiator"]
      initiator: Types.Network.Initiator.t, /* Request initiator. */
      [@key "redirectHasExtraInfo"]
      redirectHasExtraInfo: bool, /* In the case that redirectResponse is populated, this flag indicates whether
requestWillBeSentExtraInfo and responseReceivedExtraInfo events will be or were emitted
for the request which was just redirected. */
      [@yojson.option] [@key "redirectResponse"]
      redirectResponse: option(Types.Network.Response.t), /* Redirect response data. */
      [@yojson.option] [@key "type"]
      type_: option(Types.Network.ResourceType.t), /* Type of this resource. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Types.Page.FrameId.t), /* Frame identifier. */
      [@yojson.option] [@key "hasUserGesture"]
      hasUserGesture: option(bool) /* Whether the request is initiated by a user gesture. Defaults to false. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when resource loading priority is changed */
  module ResourceChangedPriority = {
    let name = "Network.resourceChangedPriority";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "newPriority"]
      newPriority: Types.Network.ResourcePriority.t, /* New priority */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* Timestamp. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a signed exchange was received over the network */
  module SignedExchangeReceived = {
    let name = "Network.signedExchangeReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "info"]
      info: Types.Network.SignedExchangeInfo.t /* Information about the signed exchange response. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when HTTP response is available. */
  module ResponseReceived = {
    let name = "Network.responseReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "loaderId"]
      loaderId: Types.Network.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "type"]
      type_: Types.Network.ResourceType.t, /* Resource type. */
      [@key "response"]
      response: Types.Network.Response.t, /* Response data. */
      [@key "hasExtraInfo"]
      hasExtraInfo: bool, /* Indicates whether requestWillBeSentExtraInfo and responseReceivedExtraInfo events will be
or were emitted for this request. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Types.Page.FrameId.t) /* Frame identifier. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket is closed. */
  module WebSocketClosed = {
    let name = "Network.webSocketClosed";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* Timestamp. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired upon WebSocket creation. */
  module WebSocketCreated = {
    let name = "Network.webSocketCreated";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "url"]
      url: string, /* WebSocket request URL. */
      [@yojson.option] [@key "initiator"]
      initiator: option(Types.Network.Initiator.t) /* Request initiator. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket message error occurs. */
  module WebSocketFrameError = {
    let name = "Network.webSocketFrameError";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "errorMessage"]
      errorMessage: string /* WebSocket error message. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket message is received. */
  module WebSocketFrameReceived = {
    let name = "Network.webSocketFrameReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "response"]
      response: Types.Network.WebSocketFrame.t /* WebSocket response data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket message is sent. */
  module WebSocketFrameSent = {
    let name = "Network.webSocketFrameSent";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "response"]
      response: Types.Network.WebSocketFrame.t /* WebSocket response data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket handshake response becomes available. */
  module WebSocketHandshakeResponseReceived = {
    let name = "Network.webSocketHandshakeResponseReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "response"]
      response: Types.Network.WebSocketResponse.t /* WebSocket response data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebSocket is about to initiate handshake. */
  module WebSocketWillSendHandshakeRequest = {
    let name = "Network.webSocketWillSendHandshakeRequest";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@key "wallTime"]
      wallTime: Types.Network.TimeSinceEpoch.t, /* UTC Timestamp. */
      [@key "request"]
      request: Types.Network.WebSocketRequest.t /* WebSocket request data. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired upon WebTransport creation. */
  module WebTransportCreated = {
    let name = "Network.webTransportCreated";

    [@deriving yojson]
    type result = {
      [@key "transportId"]
      transportId: Types.Network.RequestId.t, /* WebTransport identifier. */
      [@key "url"]
      url: string, /* WebTransport request URL. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t, /* Timestamp. */
      [@yojson.option] [@key "initiator"]
      initiator: option(Types.Network.Initiator.t) /* Request initiator. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebTransport handshake is finished. */
  module WebTransportConnectionEstablished = {
    let name = "Network.webTransportConnectionEstablished";

    [@deriving yojson]
    type result = {
      [@key "transportId"]
      transportId: Types.Network.RequestId.t, /* WebTransport identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* Timestamp. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when WebTransport is disposed. */
  module WebTransportClosed = {
    let name = "Network.webTransportClosed";

    [@deriving yojson]
    type result = {
      [@key "transportId"]
      transportId: Types.Network.RequestId.t, /* WebTransport identifier. */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* Timestamp. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when additional information about a requestWillBeSent event is available from the
     network stack. Not every requestWillBeSent event will have an additional
     requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
     or requestWillBeSentExtraInfo will be fired first for the same request. */
  module RequestWillBeSentExtraInfo = {
    let name = "Network.requestWillBeSentExtraInfo";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. Used to match this information to an existing requestWillBeSent event. */
      [@key "associatedCookies"]
      associatedCookies: list(Types.Network.BlockedCookieWithReason.t), /* A list of cookies potentially associated to the requested URL. This includes both cookies sent with
the request and the ones not sent; the latter are distinguished by having blockedReason field set. */
      [@key "headers"]
      headers: Types.Network.Headers.t, /* Raw request headers as they will be sent over the wire. */
      [@key "connectTiming"]
      connectTiming: Types.Network.ConnectTiming.t, /* Connection timing information for the request. */
      [@yojson.option] [@key "clientSecurityState"]
      clientSecurityState: option(Types.Network.ClientSecurityState.t) /* The client security state set for the request. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when additional information about a responseReceived event is available from the network
     stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
     it, and responseReceivedExtraInfo may be fired before or after responseReceived. */
  module ResponseReceivedExtraInfo = {
    let name = "Network.responseReceivedExtraInfo";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. Used to match this information to another responseReceived event. */
      [@key "blockedCookies"]
      blockedCookies: list(Types.Network.BlockedSetCookieWithReason.t), /* A list of cookies which were not stored from the response along with the corresponding
reasons for blocking. The cookies here may not be valid due to syntax errors, which
are represented by the invalid cookie line string instead of a proper cookie. */
      [@key "headers"]
      headers: Types.Network.Headers.t, /* Raw response headers as they were received over the wire. */
      [@key "resourceIPAddressSpace"]
      resourceIPAddressSpace: Types.Network.IPAddressSpace.t, /* The IP address space of the resource. The address space can only be determined once the transport
established the connection, so we can't send it in `requestWillBeSentExtraInfo`. */
      [@key "statusCode"]
      statusCode: Types.number, /* The status code of the response. This is useful in cases the request failed and no responseReceived
event is triggered, which is the case for, e.g., CORS errors. This is also the correct status code
for cached requests, where the status in responseReceived is a 200 and this will be 304. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string) /* Raw response header text as it was received over the wire. The raw text may not always be
available, such as in the case of HTTP/2 or QUIC. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired exactly once for each Trust Token operation. Depending on
     the type of the operation and whether the operation succeeded or
     failed, the event is fired before the corresponding request was sent
     or after the response was received. */
  module TrustTokenOperationDone = {
    let name = "Network.trustTokenOperationDone";

    type trusttokenoperationdone_status = [
      | `Ok
      | `InvalidArgument
      | `FailedPrecondition
      | `ResourceExhausted
      | `AlreadyExists
      | `Unavailable
      | `BadResponse
      | `InternalError
      | `UnknownError
      | `FulfilledLocally
    ];
    let trusttokenoperationdone_status_of_yojson =
      fun
      | `String("Ok") => `Ok
      | `String("InvalidArgument") => `InvalidArgument
      | `String("FailedPrecondition") => `FailedPrecondition
      | `String("ResourceExhausted") => `ResourceExhausted
      | `String("AlreadyExists") => `AlreadyExists
      | `String("Unavailable") => `Unavailable
      | `String("BadResponse") => `BadResponse
      | `String("InternalError") => `InternalError
      | `String("UnknownError") => `UnknownError
      | `String("FulfilledLocally") => `FulfilledLocally
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_trusttokenoperationdone_status =
      fun
      | `Ok => `String("Ok")
      | `InvalidArgument => `String("InvalidArgument")
      | `FailedPrecondition => `String("FailedPrecondition")
      | `ResourceExhausted => `String("ResourceExhausted")
      | `AlreadyExists => `String("AlreadyExists")
      | `Unavailable => `String("Unavailable")
      | `BadResponse => `String("BadResponse")
      | `InternalError => `String("InternalError")
      | `UnknownError => `String("UnknownError")
      | `FulfilledLocally => `String("FulfilledLocally");

    [@deriving yojson]
    type result = {
      [@key "status"]
      status: trusttokenoperationdone_status, /* Detailed success or error status of the operation.
'AlreadyExists' also signifies a successful operation, as the result
of the operation already exists und thus, the operation was abort
preemptively (e.g. a cache hit). */
      [@key "type"]
      type_: Types.Network.TrustTokenOperationType.t, /* No description provided */
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* No description provided */
      [@yojson.option] [@key "topLevelOrigin"]
      topLevelOrigin: option(string), /* Top level origin. The context in which the operation was attempted. */
      [@yojson.option] [@key "issuerOrigin"]
      issuerOrigin: option(string), /* Origin of the issuer in case of a "Issuance" or "Redemption" operation. */
      [@yojson.option] [@key "issuedTokenCount"]
      issuedTokenCount: option(Types.number) /* The number of obtained Trust Tokens on a successful "Issuance" operation. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired once when parsing the .wbn file has succeeded.
     The event contains the information about the web bundle contents. */
  module SubresourceWebBundleMetadataReceived = {
    let name = "Network.subresourceWebBundleMetadataReceived";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. Used to match this information to another event. */
      [@key "urls"]
      urls: list(string) /* A list of URLs of resources in the subresource Web Bundle. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired once when parsing the .wbn file has failed. */
  module SubresourceWebBundleMetadataError = {
    let name = "Network.subresourceWebBundleMetadataError";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Network.RequestId.t, /* Request identifier. Used to match this information to another event. */
      [@key "errorMessage"]
      errorMessage: string /* Error message */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when handling requests for resources within a .wbn file.
     Note: this will only be fired for resources that are requested by the webpage. */
  module SubresourceWebBundleInnerResponseParsed = {
    let name = "Network.subresourceWebBundleInnerResponseParsed";

    [@deriving yojson]
    type result = {
      [@key "innerRequestId"]
      innerRequestId: Types.Network.RequestId.t, /* Request identifier of the subresource request */
      [@key "innerRequestURL"]
      innerRequestURL: string, /* URL of the subresource resource. */
      [@yojson.option] [@key "bundleRequestId"]
      bundleRequestId: option(Types.Network.RequestId.t) /* Bundle request identifier. Used to match this information to another event.
This made be absent in case when the instrumentation was enabled only
after webbundle was parsed. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when request for resources within a .wbn file failed. */
  module SubresourceWebBundleInnerResponseError = {
    let name = "Network.subresourceWebBundleInnerResponseError";

    [@deriving yojson]
    type result = {
      [@key "innerRequestId"]
      innerRequestId: Types.Network.RequestId.t, /* Request identifier of the subresource request */
      [@key "innerRequestURL"]
      innerRequestURL: string, /* URL of the subresource resource. */
      [@key "errorMessage"]
      errorMessage: string, /* Error message */
      [@yojson.option] [@key "bundleRequestId"]
      bundleRequestId: option(Types.Network.RequestId.t) /* Bundle request identifier. Used to match this information to another event.
This made be absent in case when the instrumentation was enabled only
after webbundle was parsed. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Is sent whenever a new report is added.
     And after 'enableReportingApi' for all existing reports. */
  module ReportingApiReportAdded = {
    let name = "Network.reportingApiReportAdded";

    [@deriving yojson]
    type result = {
      [@key "report"]
      report: Types.Network.ReportingApiReport.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module ReportingApiReportUpdated = {
    let name = "Network.reportingApiReportUpdated";

    [@deriving yojson]
    type result = {
      [@key "report"]
      report: Types.Network.ReportingApiReport.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module ReportingApiEndpointsChangedForOrigin = {
    let name = "Network.reportingApiEndpointsChangedForOrigin";

    [@deriving yojson]
    type result = {
      [@key "origin"]
      origin: string, /* Origin of the document(s) which configured the endpoints. */
      [@key "endpoints"]
      endpoints: list(Types.Network.ReportingApiEndpoint.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Overlay = {
  /* Fired when the node should be inspected. This happens after call to `setInspectMode` or when
     user manually inspects an element. */
  module InspectNodeRequested = {
    let name = "Overlay.inspectNodeRequested";

    [@deriving yojson]
    type result = {
      [@key "backendNodeId"]
      backendNodeId: Types.DOM.BackendNodeId.t /* Id of the node to inspect. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when the node should be highlighted. This happens after call to `setInspectMode`. */
  module NodeHighlightRequested = {
    let name = "Overlay.nodeHighlightRequested";

    [@deriving yojson]
    type result = {
      [@key "nodeId"]
      nodeId: Types.DOM.NodeId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when user asks to capture screenshot of some area on the page. */
  module ScreenshotRequested = {
    let name = "Overlay.screenshotRequested";

    [@deriving yojson]
    type result = {
      [@key "viewport"]
      viewport: Types.Page.Viewport.t /* Viewport to capture, in device independent pixels (dip). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when user cancels the inspect mode. */
  module InspectModeCanceled = {
    let name = "Overlay.inspectModeCanceled";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Page = {
  /* No description provided */
  module DomContentEventFired = {
    let name = "Page.domContentEventFired";

    [@deriving yojson]
    type result = {
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Emitted only when `page.interceptFileChooser` is enabled. */
  module FileChooserOpened = {
    let name = "Page.fileChooserOpened";

    type filechooseropened_mode = [ | `selectSingle | `selectMultiple];
    let filechooseropened_mode_of_yojson =
      fun
      | `String("selectSingle") => `selectSingle
      | `String("selectMultiple") => `selectMultiple
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_filechooseropened_mode =
      fun
      | `selectSingle => `String("selectSingle")
      | `selectMultiple => `String("selectMultiple");

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame containing input node. */
      [@key "mode"]
      mode: filechooseropened_mode, /* Input mode. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(Types.DOM.BackendNodeId.t) /* Input node id. Only present for file choosers opened via an <input type="file"> element. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame has been attached to its parent. */
  module FrameAttached = {
    let name = "Page.frameAttached";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that has been attached. */
      [@key "parentFrameId"]
      parentFrameId: Types.Page.FrameId.t, /* Parent frame identifier. */
      [@yojson.option] [@key "stack"]
      stack: option(Types.Runtime.StackTrace.t), /* JavaScript stack trace of when frame was attached, only set if frame initiated from script. */
      [@yojson.option] [@key "adScriptId"]
      adScriptId: option(Types.Page.AdScriptId.t) /* Identifies the bottom-most script which caused the frame to be labelled
as an ad. Only sent if frame is labelled as an ad and id is available. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame no longer has a scheduled navigation. */
  module FrameClearedScheduledNavigation = {
    let name = "Page.frameClearedScheduledNavigation";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t /* Id of the frame that has cleared its scheduled navigation. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame has been detached from its parent. */
  module FrameDetached = {
    let name = "Page.frameDetached";

    type framedetached_reason = [ | `remove | `swap];
    let framedetached_reason_of_yojson =
      fun
      | `String("remove") => `remove
      | `String("swap") => `swap
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_framedetached_reason =
      fun
      | `remove => `String("remove")
      | `swap => `String("swap");

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that has been detached. */
      [@key "reason"]
      reason: framedetached_reason /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired once navigation of the frame has completed. Frame is now associated with the new loader. */
  module FrameNavigated = {
    let name = "Page.frameNavigated";

    [@deriving yojson]
    type result = {
      [@key "frame"]
      frame: Types.Page.Frame.t, /* Frame object. */
      [@key "type"]
      type_: Types.Page.NavigationType.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when opening document to write to. */
  module DocumentOpened = {
    let name = "Page.documentOpened";

    [@deriving yojson]
    type result = {
      [@key "frame"]
      frame: Types.Page.Frame.t /* Frame object. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module FrameResized = {
    let name = "Page.frameResized";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a renderer-initiated navigation is requested.
     Navigation may still be cancelled after the event is issued. */
  module FrameRequestedNavigation = {
    let name = "Page.frameRequestedNavigation";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that is being navigated. */
      [@key "reason"]
      reason: Types.Page.ClientNavigationReason.t, /* The reason for the navigation. */
      [@key "url"]
      url: string, /* The destination URL for the requested navigation. */
      [@key "disposition"]
      disposition: Types.Page.ClientNavigationDisposition.t /* The disposition for the navigation. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame schedules a potential navigation. */
  module FrameScheduledNavigation = {
    let name = "Page.frameScheduledNavigation";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that has scheduled a navigation. */
      [@key "delay"]
      delay: Types.number, /* Delay (in seconds) until the navigation is scheduled to begin. The navigation is not
guaranteed to start. */
      [@key "reason"]
      reason: Types.Page.ClientNavigationReason.t, /* The reason for the navigation. */
      [@key "url"]
      url: string /* The destination URL for the scheduled navigation. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame has started loading. */
  module FrameStartedLoading = {
    let name = "Page.frameStartedLoading";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t /* Id of the frame that has started loading. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when frame has stopped loading. */
  module FrameStoppedLoading = {
    let name = "Page.frameStoppedLoading";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t /* Id of the frame that has stopped loading. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when page is about to start a download.
     Deprecated. Use Browser.downloadWillBegin instead. */
  module DownloadWillBegin = {
    let name = "Page.downloadWillBegin";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame that caused download to begin. */
      [@key "guid"]
      guid: string, /* Global unique identifier of the download. */
      [@key "url"]
      url: string, /* URL of the resource being downloaded. */
      [@key "suggestedFilename"]
      suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when download makes progress. Last call has |done| == true.
     Deprecated. Use Browser.downloadProgress instead. */
  module DownloadProgress = {
    let name = "Page.downloadProgress";

    type downloadprogress_state = [ | `inProgress | `completed | `canceled];
    let downloadprogress_state_of_yojson =
      fun
      | `String("inProgress") => `inProgress
      | `String("completed") => `completed
      | `String("canceled") => `canceled
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_downloadprogress_state =
      fun
      | `inProgress => `String("inProgress")
      | `completed => `String("completed")
      | `canceled => `String("canceled");

    [@deriving yojson]
    type result = {
      [@key "guid"]
      guid: string, /* Global unique identifier of the download. */
      [@key "totalBytes"]
      totalBytes: Types.number, /* Total expected bytes to download. */
      [@key "receivedBytes"]
      receivedBytes: Types.number, /* Total bytes received. */
      [@key "state"]
      state: downloadprogress_state /* Download status. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when interstitial page was hidden */
  module InterstitialHidden = {
    let name = "Page.interstitialHidden";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when interstitial page was shown */
  module InterstitialShown = {
    let name = "Page.interstitialShown";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) has been
     closed. */
  module JavascriptDialogClosed = {
    let name = "Page.javascriptDialogClosed";

    [@deriving yojson]
    type result = {
      [@key "result"]
      result: bool, /* Whether dialog was confirmed. */
      [@key "userInput"]
      userInput: string /* User input in case of prompt. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) is about to
     open. */
  module JavascriptDialogOpening = {
    let name = "Page.javascriptDialogOpening";

    [@deriving yojson]
    type result = {
      [@key "url"]
      url: string, /* Frame url. */
      [@key "message"]
      message: string, /* Message that will be displayed by the dialog. */
      [@key "type"]
      type_: Types.Page.DialogType.t, /* Dialog type. */
      [@key "hasBrowserHandler"]
      hasBrowserHandler: bool, /* True iff browser is capable showing or acting on the given dialog. When browser has no
dialog handler for given target, calling alert while Page domain is engaged will stall
the page execution. Execution can be resumed via calling Page.handleJavaScriptDialog. */
      [@yojson.option] [@key "defaultPrompt"]
      defaultPrompt: option(string) /* Default dialog prompt. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired for top level page lifecycle events such as navigation, load, paint, etc. */
  module LifecycleEvent = {
    let name = "Page.lifecycleEvent";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame. */
      [@key "loaderId"]
      loaderId: Types.Network.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
      [@key "name"]
      name: string, /* No description provided */
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired for failed bfcache history navigations if BackForwardCache feature is enabled. Do
     not assume any ordering with the Page.frameNavigated event. This event is fired only for
     main-frame history navigation where the document changes (non-same-document navigations),
     when bfcache navigation fails. */
  module BackForwardCacheNotUsed = {
    let name = "Page.backForwardCacheNotUsed";

    [@deriving yojson]
    type result = {
      [@key "loaderId"]
      loaderId: Types.Network.LoaderId.t, /* The loader id for the associated navgation. */
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* The frame id of the associated frame. */
      [@key "notRestoredExplanations"]
      notRestoredExplanations:
        list(Types.Page.BackForwardCacheNotRestoredExplanation.t), /* Array of reasons why the page could not be cached. This must not be empty. */
      [@yojson.option] [@key "notRestoredExplanationsTree"]
      notRestoredExplanationsTree:
        option(Types.Page.BackForwardCacheNotRestoredExplanationTree.t) /* Tree structure of reasons why the page could not be cached for each frame. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a prerender attempt is completed. */
  module PrerenderAttemptCompleted = {
    let name = "Page.prerenderAttemptCompleted";

    [@deriving yojson]
    type result = {
      [@key "initiatingFrameId"]
      initiatingFrameId: Types.Page.FrameId.t, /* The frame id of the frame initiating prerendering. */
      [@key "prerenderingUrl"]
      prerenderingUrl: string, /* No description provided */
      [@key "finalStatus"]
      finalStatus: Types.Page.PrerenderFinalStatus.t, /* No description provided */
      [@yojson.option] [@key "disallowedApiMethod"]
      disallowedApiMethod: option(string) /* This is used to give users more information about the name of the API call
that is incompatible with prerender and has caused the cancellation of the attempt */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module LoadEventFired = {
    let name = "Page.loadEventFired";

    [@deriving yojson]
    type result = {
      [@key "timestamp"]
      timestamp: Types.Network.MonotonicTime.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when same-document navigation happens, e.g. due to history API usage or anchor navigation. */
  module NavigatedWithinDocument = {
    let name = "Page.navigatedWithinDocument";

    [@deriving yojson]
    type result = {
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* Id of the frame. */
      [@key "url"]
      url: string /* Frame's new url. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Compressed image data requested by the `startScreencast`. */
  module ScreencastFrame = {
    let name = "Page.screencastFrame";

    [@deriving yojson]
    type result = {
      [@key "data"]
      data: string, /* Base64-encoded compressed image. (Encoded as a base64 string when passed over JSON) */
      [@key "metadata"]
      metadata: Types.Page.ScreencastFrameMetadata.t, /* Screencast frame metadata. */
      [@key "sessionId"]
      sessionId: Types.number /* Frame number. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when the page with currently enabled screencast was shown or hidden `. */
  module ScreencastVisibilityChanged = {
    let name = "Page.screencastVisibilityChanged";

    [@deriving yojson]
    type result = {
      [@key "visible"]
      visible: bool /* True if the page is visible. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when a new window is going to be opened, via window.open(), link click, form submission,
     etc. */
  module WindowOpen = {
    let name = "Page.windowOpen";

    [@deriving yojson]
    type result = {
      [@key "url"]
      url: string, /* The URL for the new window. */
      [@key "windowName"]
      windowName: string, /* Window name. */
      [@key "windowFeatures"]
      windowFeatures: list(string), /* An array of enabled window features. */
      [@key "userGesture"]
      userGesture: bool /* Whether or not it was triggered by user gesture. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued for every compilation cache generated. Is only available
     if Page.setGenerateCompilationCache is enabled. */
  module CompilationCacheProduced = {
    let name = "Page.compilationCacheProduced";

    [@deriving yojson]
    type result = {
      [@key "url"]
      url: string, /* No description provided */
      [@key "data"]
      data: string /* Base64-encoded data (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Performance = {
  /* Current values of the metrics. */
  module Metrics = {
    let name = "Performance.metrics";

    [@deriving yojson]
    type result = {
      [@key "metrics"]
      metrics: list(Types.Performance.Metric.t), /* Current values of the metrics. */
      [@key "title"]
      title: string /* Timestamp title. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module PerformanceTimeline = {
  /* Sent when a performance timeline event is added. See reportPerformanceTimeline method. */
  module TimelineEventAdded = {
    let name = "PerformanceTimeline.timelineEventAdded";

    [@deriving yojson]
    type result = {
      [@key "event"]
      event: Types.PerformanceTimeline.TimelineEvent.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Security = {
  /* There is a certificate error. If overriding certificate errors is enabled, then it should be
     handled with the `handleCertificateError` command. Note: this event does not fire if the
     certificate error has been allowed internally. Only one client per target should override
     certificate errors at the same time. */
  module CertificateError = {
    let name = "Security.certificateError";

    [@deriving yojson]
    type result = {
      [@key "eventId"]
      eventId: Types.number, /* The ID of the event. */
      [@key "errorType"]
      errorType: string, /* The type of the error. */
      [@key "requestURL"]
      requestURL: string /* The url that was requested. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* The security state of the page changed. */
  module VisibleSecurityStateChanged = {
    let name = "Security.visibleSecurityStateChanged";

    [@deriving yojson]
    type result = {
      [@key "visibleSecurityState"]
      visibleSecurityState: Types.Security.VisibleSecurityState.t /* Security state information about the page. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* The security state of the page changed. No longer being sent. */
  module SecurityStateChanged = {
    let name = "Security.securityStateChanged";

    [@deriving yojson]
    type result = {
      [@key "securityState"]
      securityState: Types.Security.SecurityState.t, /* Security state. */
      [@key "schemeIsCryptographic"]
      schemeIsCryptographic: bool, /* True if the page was loaded over cryptographic transport such as HTTPS. */
      [@key "explanations"]
      explanations: list(Types.Security.SecurityStateExplanation.t), /* Previously a list of explanations for the security state. Now always
empty. */
      [@key "insecureContentStatus"]
      insecureContentStatus: Types.Security.InsecureContentStatus.t, /* Information about insecure content on the page. */
      [@yojson.option] [@key "summary"]
      summary: option(string) /* Overrides user-visible description of the state. Always omitted. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module ServiceWorker = {
  /* No description provided */
  module WorkerErrorReported = {
    let name = "ServiceWorker.workerErrorReported";

    [@deriving yojson]
    type result = {
      [@key "errorMessage"]
      errorMessage: Types.ServiceWorker.ServiceWorkerErrorMessage.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module WorkerRegistrationUpdated = {
    let name = "ServiceWorker.workerRegistrationUpdated";

    [@deriving yojson]
    type result = {
      [@key "registrations"]
      registrations: list(Types.ServiceWorker.ServiceWorkerRegistration.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module WorkerVersionUpdated = {
    let name = "ServiceWorker.workerVersionUpdated";

    [@deriving yojson]
    type result = {
      [@key "versions"]
      versions: list(Types.ServiceWorker.ServiceWorkerVersion.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Storage = {
  /* A cache's contents have been modified. */
  module CacheStorageContentUpdated = {
    let name = "Storage.cacheStorageContentUpdated";

    [@deriving yojson]
    type result = {
      [@key "origin"]
      origin: string, /* Origin to update. */
      [@key "cacheName"]
      cacheName: string /* Name of cache in origin. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* A cache has been added/deleted. */
  module CacheStorageListUpdated = {
    let name = "Storage.cacheStorageListUpdated";

    [@deriving yojson]
    type result = {
      [@key "origin"]
      origin: string /* Origin to update. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* The origin's IndexedDB object store has been modified. */
  module IndexedDBContentUpdated = {
    let name = "Storage.indexedDBContentUpdated";

    [@deriving yojson]
    type result = {
      [@key "origin"]
      origin: string, /* Origin to update. */
      [@key "storageKey"]
      storageKey: string, /* Storage key to update. */
      [@key "databaseName"]
      databaseName: string, /* Database to update. */
      [@key "objectStoreName"]
      objectStoreName: string /* ObjectStore to update. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* The origin's IndexedDB database list has been modified. */
  module IndexedDBListUpdated = {
    let name = "Storage.indexedDBListUpdated";

    [@deriving yojson]
    type result = {
      [@key "origin"]
      origin: string, /* Origin to update. */
      [@key "storageKey"]
      storageKey: string /* Storage key to update. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* One of the interest groups was accessed by the associated page. */
  module InterestGroupAccessed = {
    let name = "Storage.interestGroupAccessed";

    [@deriving yojson]
    type result = {
      [@key "accessTime"]
      accessTime: Types.Network.TimeSinceEpoch.t, /* No description provided */
      [@key "type"]
      type_: Types.Storage.InterestGroupAccessType.t, /* No description provided */
      [@key "ownerOrigin"]
      ownerOrigin: string, /* No description provided */
      [@key "name"]
      name: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Target = {
  /* Issued when attached to target because of auto-attach or `attachToTarget` command. */
  module AttachedToTarget = {
    let name = "Target.attachedToTarget";

    [@deriving yojson]
    type result = {
      [@key "sessionId"]
      sessionId: Types.Target.SessionID.t, /* Identifier assigned to the session used to send/receive messages. */
      [@key "targetInfo"]
      targetInfo: Types.Target.TargetInfo.t, /* No description provided */
      [@key "waitingForDebugger"]
      waitingForDebugger: bool /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when detached from target for any reason (including `detachFromTarget` command). Can be
     issued multiple times per target if multiple sessions have been attached to it. */
  module DetachedFromTarget = {
    let name = "Target.detachedFromTarget";

    [@deriving yojson]
    type result = {
      [@key "sessionId"]
      sessionId: Types.Target.SessionID.t, /* Detached session identifier. */
      [@yojson.option] [@key "targetId"]
      targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies about a new protocol message received from the session (as reported in
     `attachedToTarget` event). */
  module ReceivedMessageFromTarget = {
    let name = "Target.receivedMessageFromTarget";

    [@deriving yojson]
    type result = {
      [@key "sessionId"]
      sessionId: Types.Target.SessionID.t, /* Identifier of a session which sends a message. */
      [@key "message"]
      message: string, /* No description provided */
      [@yojson.option] [@key "targetId"]
      targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when a possible inspection target is created. */
  module TargetCreated = {
    let name = "Target.targetCreated";

    [@deriving yojson]
    type result = {
      [@key "targetInfo"]
      targetInfo: Types.Target.TargetInfo.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when a target is destroyed. */
  module TargetDestroyed = {
    let name = "Target.targetDestroyed";

    [@deriving yojson]
    type result = {
      [@key "targetId"]
      targetId: Types.Target.TargetID.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when a target has crashed. */
  module TargetCrashed = {
    let name = "Target.targetCrashed";

    [@deriving yojson]
    type result = {
      [@key "targetId"]
      targetId: Types.Target.TargetID.t, /* No description provided */
      [@key "status"]
      status: string, /* Termination status type. */
      [@key "errorCode"]
      errorCode: Types.number /* Termination error code. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when some information about a target has changed. This only happens between
     `targetCreated` and `targetDestroyed`. */
  module TargetInfoChanged = {
    let name = "Target.targetInfoChanged";

    [@deriving yojson]
    type result = {
      [@key "targetInfo"]
      targetInfo: Types.Target.TargetInfo.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Tethering = {
  /* Informs that port was successfully bound and got a specified connection id. */
  module Accepted = {
    let name = "Tethering.accepted";

    [@deriving yojson]
    type result = {
      [@key "port"]
      port: Types.number, /* Port number that was successfully bound. */
      [@key "connectionId"]
      connectionId: string /* Connection id to be used. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Tracing = {
  /* No description provided */
  module BufferUsage = {
    let name = "Tracing.bufferUsage";

    [@deriving yojson]
    type result = {
      [@yojson.option] [@key "percentFull"]
      percentFull: option(Types.number), /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */
      [@yojson.option] [@key "eventCount"]
      eventCount: option(Types.number), /* An approximate number of events in the trace log. */
      [@yojson.option] [@key "value"]
      value: option(Types.number) /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Contains an bucket of collected trace events. When tracing is stopped collected events will be
     send as a sequence of dataCollected events followed by tracingComplete event. */
  module DataCollected = {
    let name = "Tracing.dataCollected";

    [@deriving yojson]
    type result = {
      [@key "value"]
      value: list(Types.assoc) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Signals that tracing is stopped and there is no trace buffers pending flush, all data were
     delivered via dataCollected events. */
  module TracingComplete = {
    let name = "Tracing.tracingComplete";

    [@deriving yojson]
    type result = {
      [@key "dataLossOccurred"]
      dataLossOccurred: bool, /* Indicates whether some trace data is known to have been lost, e.g. because the trace ring
buffer wrapped around. */
      [@yojson.option] [@key "stream"]
      stream: option(Types.IO.StreamHandle.t), /* A handle of the stream that holds resulting trace data. */
      [@yojson.option] [@key "traceFormat"]
      traceFormat: option(Types.Tracing.StreamFormat.t), /* Trace data format of returned stream. */
      [@yojson.option] [@key "streamCompression"]
      streamCompression: option(Types.Tracing.StreamCompression.t) /* Compression format of returned stream. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Fetch = {
  /* Issued when the domain is enabled and the request URL matches the
     specified filter. The request is paused until the client responds
     with one of continueRequest, failRequest or fulfillRequest.
     The stage of the request can be determined by presence of responseErrorReason
     and responseStatusCode -- the request is at the response stage if either
     of these fields is present and in the request stage otherwise. */
  module RequestPaused = {
    let name = "Fetch.requestPaused";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Fetch.RequestId.t, /* Each request the page makes will have a unique id. */
      [@key "request"]
      request: Types.Network.Request.t, /* The details of the request. */
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* The id of the frame that initiated the request. */
      [@key "resourceType"]
      resourceType: Types.Network.ResourceType.t, /* How the requested resource will be used. */
      [@yojson.option] [@key "responseErrorReason"]
      responseErrorReason: option(Types.Network.ErrorReason.t), /* Response error if intercepted at response stage. */
      [@yojson.option] [@key "responseStatusCode"]
      responseStatusCode: option(Types.number), /* Response code if intercepted at response stage. */
      [@yojson.option] [@key "responseStatusText"]
      responseStatusText: option(string), /* Response status text if intercepted at response stage. */
      [@yojson.option] [@key "responseHeaders"]
      responseHeaders: option(list(Types.Fetch.HeaderEntry.t)), /* Response headers if intercepted at the response stage. */
      [@yojson.option] [@key "networkId"]
      networkId: option(Types.Fetch.RequestId.t) /* If the intercepted request had a corresponding Network.requestWillBeSent event fired for it,
then this networkId will be the same as the requestId present in the requestWillBeSent event. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when the domain is enabled with handleAuthRequests set to true.
     The request is paused until client responds with continueWithAuth. */
  module AuthRequired = {
    let name = "Fetch.authRequired";

    [@deriving yojson]
    type result = {
      [@key "requestId"]
      requestId: Types.Fetch.RequestId.t, /* Each request the page makes will have a unique id. */
      [@key "request"]
      request: Types.Network.Request.t, /* The details of the request. */
      [@key "frameId"]
      frameId: Types.Page.FrameId.t, /* The id of the frame that initiated the request. */
      [@key "resourceType"]
      resourceType: Types.Network.ResourceType.t, /* How the requested resource will be used. */
      [@key "authChallenge"]
      authChallenge: Types.Fetch.AuthChallenge.t /* Details of the Authorization Challenge encountered.
If this is set, client should respond with continueRequest that
contains AuthChallengeResponse. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module WebAudio = {
  /* Notifies that a new BaseAudioContext has been created. */
  module ContextCreated = {
    let name = "WebAudio.contextCreated";

    [@deriving yojson]
    type result = {
      [@key "context"]
      context: Types.WebAudio.BaseAudioContext.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that an existing BaseAudioContext will be destroyed. */
  module ContextWillBeDestroyed = {
    let name = "WebAudio.contextWillBeDestroyed";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that existing BaseAudioContext has changed some properties (id stays the same).. */
  module ContextChanged = {
    let name = "WebAudio.contextChanged";

    [@deriving yojson]
    type result = {
      [@key "context"]
      context: Types.WebAudio.BaseAudioContext.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that the construction of an AudioListener has finished. */
  module AudioListenerCreated = {
    let name = "WebAudio.audioListenerCreated";

    [@deriving yojson]
    type result = {
      [@key "listener"]
      listener: Types.WebAudio.AudioListener.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that a new AudioListener has been created. */
  module AudioListenerWillBeDestroyed = {
    let name = "WebAudio.audioListenerWillBeDestroyed";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "listenerId"]
      listenerId: Types.WebAudio.GraphObjectId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that a new AudioNode has been created. */
  module AudioNodeCreated = {
    let name = "WebAudio.audioNodeCreated";

    [@deriving yojson]
    type result = {
      [@key "node"]
      node: Types.WebAudio.AudioNode.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that an existing AudioNode has been destroyed. */
  module AudioNodeWillBeDestroyed = {
    let name = "WebAudio.audioNodeWillBeDestroyed";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "nodeId"]
      nodeId: Types.WebAudio.GraphObjectId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that a new AudioParam has been created. */
  module AudioParamCreated = {
    let name = "WebAudio.audioParamCreated";

    [@deriving yojson]
    type result = {
      [@key "param"]
      param: Types.WebAudio.AudioParam.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that an existing AudioParam has been destroyed. */
  module AudioParamWillBeDestroyed = {
    let name = "WebAudio.audioParamWillBeDestroyed";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "nodeId"]
      nodeId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "paramId"]
      paramId: Types.WebAudio.GraphObjectId.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that two AudioNodes are connected. */
  module NodesConnected = {
    let name = "WebAudio.nodesConnected";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "sourceId"]
      sourceId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "destinationId"]
      destinationId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@yojson.option] [@key "sourceOutputIndex"]
      sourceOutputIndex: option(Types.number), /* No description provided */
      [@yojson.option] [@key "destinationInputIndex"]
      destinationInputIndex: option(Types.number) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected. */
  module NodesDisconnected = {
    let name = "WebAudio.nodesDisconnected";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "sourceId"]
      sourceId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "destinationId"]
      destinationId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@yojson.option] [@key "sourceOutputIndex"]
      sourceOutputIndex: option(Types.number), /* No description provided */
      [@yojson.option] [@key "destinationInputIndex"]
      destinationInputIndex: option(Types.number) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that an AudioNode is connected to an AudioParam. */
  module NodeParamConnected = {
    let name = "WebAudio.nodeParamConnected";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "sourceId"]
      sourceId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "destinationId"]
      destinationId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@yojson.option] [@key "sourceOutputIndex"]
      sourceOutputIndex: option(Types.number) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Notifies that an AudioNode is disconnected to an AudioParam. */
  module NodeParamDisconnected = {
    let name = "WebAudio.nodeParamDisconnected";

    [@deriving yojson]
    type result = {
      [@key "contextId"]
      contextId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "sourceId"]
      sourceId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@key "destinationId"]
      destinationId: Types.WebAudio.GraphObjectId.t, /* No description provided */
      [@yojson.option] [@key "sourceOutputIndex"]
      sourceOutputIndex: option(Types.number) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Media = {
  /* This can be called multiple times, and can be used to set / override /
     remove player properties. A null propValue indicates removal. */
  module PlayerPropertiesChanged = {
    let name = "Media.playerPropertiesChanged";

    [@deriving yojson]
    type result = {
      [@key "playerId"]
      playerId: Types.Media.PlayerId.t, /* No description provided */
      [@key "properties"]
      properties: list(Types.Media.PlayerProperty.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Send events as a list, allowing them to be batched on the browser for less
     congestion. If batched, events must ALWAYS be in chronological order. */
  module PlayerEventsAdded = {
    let name = "Media.playerEventsAdded";

    [@deriving yojson]
    type result = {
      [@key "playerId"]
      playerId: Types.Media.PlayerId.t, /* No description provided */
      [@key "events"]
      events: list(Types.Media.PlayerEvent.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Send a list of any messages that need to be delivered. */
  module PlayerMessagesLogged = {
    let name = "Media.playerMessagesLogged";

    [@deriving yojson]
    type result = {
      [@key "playerId"]
      playerId: Types.Media.PlayerId.t, /* No description provided */
      [@key "messages"]
      messages: list(Types.Media.PlayerMessage.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Send a list of any errors that need to be delivered. */
  module PlayerErrorsRaised = {
    let name = "Media.playerErrorsRaised";

    [@deriving yojson]
    type result = {
      [@key "playerId"]
      playerId: Types.Media.PlayerId.t, /* No description provided */
      [@key "errors"]
      errors: list(Types.Media.PlayerError.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Called whenever a player is created, or when a new agent joins and receives
     a list of active players. If an agent is restored, it will receive the full
     list of player ids and all events again. */
  module PlayersCreated = {
    let name = "Media.playersCreated";

    [@deriving yojson]
    type result = {
      [@key "players"]
      players: list(Types.Media.PlayerId.t) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Console = {
  /* Issued when new console message is added. */
  module MessageAdded = {
    let name = "Console.messageAdded";

    [@deriving yojson]
    type result = {
      [@key "message"]
      message: Types.Console.ConsoleMessage.t /* Console message that has been added. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Debugger = {
  /* Fired when breakpoint is resolved to an actual script and location. */
  module BreakpointResolved = {
    let name = "Debugger.breakpointResolved";

    [@deriving yojson]
    type result = {
      [@key "breakpointId"]
      breakpointId: Types.Debugger.BreakpointId.t, /* Breakpoint unique identifier. */
      [@key "location"]
      location: Types.Debugger.Location.t /* Actual breakpoint location. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria. */
  module Paused = {
    let name = "Debugger.paused";

    type paused_reason = [
      | `ambiguous
      | `assert_
      | `CSPViolation
      | `debugCommand
      | `DOM
      | `EventListener
      | `exception_
      | `instrumentation
      | `OOM
      | `other
      | `promiseRejection
      | `XHR
    ];
    let paused_reason_of_yojson =
      fun
      | `String("ambiguous") => `ambiguous
      | `String("assert") => `assert_
      | `String("CSPViolation") => `CSPViolation
      | `String("debugCommand") => `debugCommand
      | `String("DOM") => `DOM
      | `String("EventListener") => `EventListener
      | `String("exception") => `exception_
      | `String("instrumentation") => `instrumentation
      | `String("OOM") => `OOM
      | `String("other") => `other
      | `String("promiseRejection") => `promiseRejection
      | `String("XHR") => `XHR
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_paused_reason =
      fun
      | `ambiguous => `String("ambiguous")
      | `assert_ => `String("assert")
      | `CSPViolation => `String("CSPViolation")
      | `debugCommand => `String("debugCommand")
      | `DOM => `String("DOM")
      | `EventListener => `String("EventListener")
      | `exception_ => `String("exception")
      | `instrumentation => `String("instrumentation")
      | `OOM => `String("OOM")
      | `other => `String("other")
      | `promiseRejection => `String("promiseRejection")
      | `XHR => `String("XHR");

    [@deriving yojson]
    type result = {
      [@key "callFrames"]
      callFrames: list(Types.Debugger.CallFrame.t), /* Call stack the virtual machine stopped on. */
      [@key "reason"]
      reason: paused_reason, /* Pause reason. */
      [@yojson.option] [@key "data"]
      data: option(Types.assoc), /* Object containing break-specific auxiliary properties. */
      [@yojson.option] [@key "hitBreakpoints"]
      hitBreakpoints: option(list(string)), /* Hit breakpoints IDs */
      [@yojson.option] [@key "asyncStackTrace"]
      asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
      [@yojson.option] [@key "asyncStackTraceId"]
      asyncStackTraceId: option(Types.Runtime.StackTraceId.t), /* Async stack trace, if any. */
      [@yojson.option] [@key "asyncCallStackTraceId"]
      asyncCallStackTraceId: option(Types.Runtime.StackTraceId.t) /* Never present, will be removed. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when the virtual machine resumed execution. */
  module Resumed = {
    let name = "Debugger.resumed";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when virtual machine fails to parse the script. */
  module ScriptFailedToParse = {
    let name = "Debugger.scriptFailedToParse";

    [@deriving yojson]
    type result = {
      [@key "scriptId"]
      scriptId: Types.Runtime.ScriptId.t, /* Identifier of the script parsed. */
      [@key "url"]
      url: string, /* URL or name of the script parsed (if any). */
      [@key "startLine"]
      startLine: Types.number, /* Line offset of the script within the resource with given URL (for script tags). */
      [@key "startColumn"]
      startColumn: Types.number, /* Column offset of the script within the resource with given URL. */
      [@key "endLine"]
      endLine: Types.number, /* Last line of the script. */
      [@key "endColumn"]
      endColumn: Types.number, /* Length of the last line of the script. */
      [@key "executionContextId"]
      executionContextId: Types.Runtime.ExecutionContextId.t, /* Specifies script creation context. */
      [@key "hash"]
      hash: string, /* Content hash of the script, SHA-256. */
      [@yojson.option] [@key "executionContextAuxData"]
      executionContextAuxData: option(Types.assoc), /* Embedder-specific auxiliary data. */
      [@yojson.option] [@key "sourceMapURL"]
      sourceMapURL: option(string), /* URL of source map associated with script (if any). */
      [@yojson.option] [@key "hasSourceURL"]
      hasSourceURL: option(bool), /* True, if this script has sourceURL. */
      [@yojson.option] [@key "isModule"]
      isModule: option(bool), /* True, if this script is ES6 module. */
      [@yojson.option] [@key "length"]
      length: option(Types.number), /* This script length. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Types.Runtime.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
      [@yojson.option] [@key "codeOffset"]
      codeOffset: option(Types.number), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
      [@yojson.option] [@key "scriptLanguage"]
      scriptLanguage: option(Types.Debugger.ScriptLanguage.t), /* The language of the script. */
      [@yojson.option] [@key "embedderName"]
      embedderName: option(string) /* The name the embedder supplied for this script. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Fired when virtual machine parses script. This event is also fired for all known and uncollected
     scripts upon enabling debugger. */
  module ScriptParsed = {
    let name = "Debugger.scriptParsed";

    [@deriving yojson]
    type result = {
      [@key "scriptId"]
      scriptId: Types.Runtime.ScriptId.t, /* Identifier of the script parsed. */
      [@key "url"]
      url: string, /* URL or name of the script parsed (if any). */
      [@key "startLine"]
      startLine: Types.number, /* Line offset of the script within the resource with given URL (for script tags). */
      [@key "startColumn"]
      startColumn: Types.number, /* Column offset of the script within the resource with given URL. */
      [@key "endLine"]
      endLine: Types.number, /* Last line of the script. */
      [@key "endColumn"]
      endColumn: Types.number, /* Length of the last line of the script. */
      [@key "executionContextId"]
      executionContextId: Types.Runtime.ExecutionContextId.t, /* Specifies script creation context. */
      [@key "hash"]
      hash: string, /* Content hash of the script, SHA-256. */
      [@yojson.option] [@key "executionContextAuxData"]
      executionContextAuxData: option(Types.assoc), /* Embedder-specific auxiliary data. */
      [@yojson.option] [@key "isLiveEdit"]
      isLiveEdit: option(bool), /* True, if this script is generated as a result of the live edit operation. */
      [@yojson.option] [@key "sourceMapURL"]
      sourceMapURL: option(string), /* URL of source map associated with script (if any). */
      [@yojson.option] [@key "hasSourceURL"]
      hasSourceURL: option(bool), /* True, if this script has sourceURL. */
      [@yojson.option] [@key "isModule"]
      isModule: option(bool), /* True, if this script is ES6 module. */
      [@yojson.option] [@key "length"]
      length: option(Types.number), /* This script length. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Types.Runtime.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
      [@yojson.option] [@key "codeOffset"]
      codeOffset: option(Types.number), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
      [@yojson.option] [@key "scriptLanguage"]
      scriptLanguage: option(Types.Debugger.ScriptLanguage.t), /* The language of the script. */
      [@yojson.option] [@key "debugSymbols"]
      debugSymbols: option(Types.Debugger.DebugSymbols.t), /* If the scriptLanguage is WebASsembly, the source of debug symbols for the module. */
      [@yojson.option] [@key "embedderName"]
      embedderName: option(string) /* The name the embedder supplied for this script. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module HeapProfiler = {
  /* No description provided */
  module AddHeapSnapshotChunk = {
    let name = "HeapProfiler.addHeapSnapshotChunk";

    [@deriving yojson]
    type result = {
      [@key "chunk"]
      chunk: string /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* If heap objects tracking has been started then backend may send update for one or more fragments */
  module HeapStatsUpdate = {
    let name = "HeapProfiler.heapStatsUpdate";

    [@deriving yojson]
    type result = {
      [@key "statsUpdate"]
      statsUpdate: list(Types.number) /* An array of triplets. Each triplet describes a fragment. The first integer is the fragment
index, the second integer is a total count of objects for the fragment, the third integer is
a total size of the objects for the fragment. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* If heap objects tracking has been started then backend regularly sends a current value for last
     seen object id and corresponding timestamp. If the were changes in the heap since last event
     then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event. */
  module LastSeenObjectId = {
    let name = "HeapProfiler.lastSeenObjectId";

    [@deriving yojson]
    type result = {
      [@key "lastSeenObjectId"]
      lastSeenObjectId: Types.number, /* No description provided */
      [@key "timestamp"]
      timestamp: Types.number /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module ReportHeapSnapshotProgress = {
    let name = "HeapProfiler.reportHeapSnapshotProgress";

    [@deriving yojson]
    type result = {
      [@key "done"]
      done_: Types.number, /* No description provided */
      [@key "total"]
      total: Types.number, /* No description provided */
      [@yojson.option] [@key "finished"]
      finished: option(bool) /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* No description provided */
  module ResetProfiles = {
    let name = "HeapProfiler.resetProfiles";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Profiler = {
  /* No description provided */
  module ConsoleProfileFinished = {
    let name = "Profiler.consoleProfileFinished";

    [@deriving yojson]
    type result = {
      [@key "id"]
      id: string, /* No description provided */
      [@key "location"]
      location: Types.Debugger.Location.t, /* Location of console.profileEnd(). */
      [@key "profile"]
      profile: Types.Profiler.Profile.t, /* No description provided */
      [@yojson.option] [@key "title"]
      title: option(string) /* Profile title passed as an argument to console.profile(). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Sent when new profile recording is started using console.profile() call. */
  module ConsoleProfileStarted = {
    let name = "Profiler.consoleProfileStarted";

    [@deriving yojson]
    type result = {
      [@key "id"]
      id: string, /* No description provided */
      [@key "location"]
      location: Types.Debugger.Location.t, /* Location of console.profile(). */
      [@yojson.option] [@key "title"]
      title: option(string) /* Profile title passed as an argument to console.profile(). */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Reports coverage delta since the last poll (either from an event like this, or from
     `takePreciseCoverage` for the current isolate. May only be sent if precise code
     coverage has been started. This event can be trigged by the embedder to, for example,
     trigger collection of coverage data immediately at a certain point in time. */
  module PreciseCoverageDeltaUpdate = {
    let name = "Profiler.preciseCoverageDeltaUpdate";

    [@deriving yojson]
    type result = {
      [@key "timestamp"]
      timestamp: Types.number, /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */
      [@key "occasion"]
      occasion: string, /* Identifier for distinguishing coverage events. */
      [@key "result"]
      result: list(Types.Profiler.ScriptCoverage.t) /* Coverage data for the current isolate. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
module Runtime = {
  /* Notification is issued every time when binding is called. */
  module BindingCalled = {
    let name = "Runtime.bindingCalled";

    [@deriving yojson]
    type result = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "payload"]
      payload: string, /* No description provided */
      [@key "executionContextId"]
      executionContextId: Types.Runtime.ExecutionContextId.t /* Identifier of the context where the call was made. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when console API was called. */
  module ConsoleAPICalled = {
    let name = "Runtime.consoleAPICalled";

    type consoleapicalled_type = [
      | `log
      | `debug
      | `info
      | `error
      | `warning
      | `dir
      | `dirxml
      | `table
      | `trace
      | `clear
      | `startGroup
      | `startGroupCollapsed
      | `endGroup
      | `assert_
      | `profile
      | `profileEnd
      | `count
      | `timeEnd
    ];
    let consoleapicalled_type_of_yojson =
      fun
      | `String("log") => `log
      | `String("debug") => `debug
      | `String("info") => `info
      | `String("error") => `error
      | `String("warning") => `warning
      | `String("dir") => `dir
      | `String("dirxml") => `dirxml
      | `String("table") => `table
      | `String("trace") => `trace
      | `String("clear") => `clear
      | `String("startGroup") => `startGroup
      | `String("startGroupCollapsed") => `startGroupCollapsed
      | `String("endGroup") => `endGroup
      | `String("assert") => `assert_
      | `String("profile") => `profile
      | `String("profileEnd") => `profileEnd
      | `String("count") => `count
      | `String("timeEnd") => `timeEnd
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of_consoleapicalled_type =
      fun
      | `log => `String("log")
      | `debug => `String("debug")
      | `info => `String("info")
      | `error => `String("error")
      | `warning => `String("warning")
      | `dir => `String("dir")
      | `dirxml => `String("dirxml")
      | `table => `String("table")
      | `trace => `String("trace")
      | `clear => `String("clear")
      | `startGroup => `String("startGroup")
      | `startGroupCollapsed => `String("startGroupCollapsed")
      | `endGroup => `String("endGroup")
      | `assert_ => `String("assert")
      | `profile => `String("profile")
      | `profileEnd => `String("profileEnd")
      | `count => `String("count")
      | `timeEnd => `String("timeEnd");

    [@deriving yojson]
    type result = {
      [@key "type"]
      type_: consoleapicalled_type, /* Type of the call. */
      [@key "args"]
      args: list(Types.Runtime.RemoteObject.t), /* Call arguments. */
      [@key "executionContextId"]
      executionContextId: Types.Runtime.ExecutionContextId.t, /* Identifier of the context where the call was made. */
      [@key "timestamp"]
      timestamp: Types.Runtime.Timestamp.t, /* Call timestamp. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Types.Runtime.StackTrace.t), /* Stack trace captured when the call was made. The async stack chain is automatically reported for
the following call types: `assert`, `error`, `trace`, `warning`. For other types the async call
chain can be retrieved using `Debugger.getStackTrace` and `stackTrace.parentId` field. */
      [@yojson.option] [@key "context"]
      context: option(string) /* Console context descriptor for calls on non-default console context (not console.*):
'anonymous#unique-logger-id' for call on unnamed context, 'name#unique-logger-id' for call
on named context. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when unhandled exception was revoked. */
  module ExceptionRevoked = {
    let name = "Runtime.exceptionRevoked";

    [@deriving yojson]
    type result = {
      [@key "reason"]
      reason: string, /* Reason describing why exception was revoked. */
      [@key "exceptionId"]
      exceptionId: Types.number /* The id of revoked exception, as reported in `exceptionThrown`. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when exception was thrown and unhandled. */
  module ExceptionThrown = {
    let name = "Runtime.exceptionThrown";

    [@deriving yojson]
    type result = {
      [@key "timestamp"]
      timestamp: Types.Runtime.Timestamp.t, /* Timestamp of the exception. */
      [@key "exceptionDetails"]
      exceptionDetails: Types.Runtime.ExceptionDetails.t /* No description provided */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when new execution context is created. */
  module ExecutionContextCreated = {
    let name = "Runtime.executionContextCreated";

    [@deriving yojson]
    type result = {
      [@key "context"]
      context: Types.Runtime.ExecutionContextDescription.t /* A newly created execution context. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when execution context is destroyed. */
  module ExecutionContextDestroyed = {
    let name = "Runtime.executionContextDestroyed";

    [@deriving yojson]
    type result = {
      [@key "executionContextId"]
      executionContextId: Types.Runtime.ExecutionContextId.t /* Id of the destroyed context */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when all executionContexts were cleared in browser */
  module ExecutionContextsCleared = {
    let name = "Runtime.executionContextsCleared";

    [@deriving yojson]
    type result = Types.empty;

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
  /* Issued when object should be inspected (for example, as a result of inspect() command line API
     call). */
  module InspectRequested = {
    let name = "Runtime.inspectRequested";

    [@deriving yojson]
    type result = {
      [@key "object"]
      object_: Types.Runtime.RemoteObject.t, /* No description provided */
      [@key "hints"]
      hints: Types.assoc, /* No description provided */
      [@yojson.option] [@key "executionContextId"]
      executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Identifier of the context where the call was made. */,
    };

    [@deriving yojson]
    type t = {
      method: string,
      params: result,
      sessionId: Types.Target.SessionID.t,
    };

    let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
  };
};
