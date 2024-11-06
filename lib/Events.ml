open Ppx_yojson_conv_lib.Yojson_conv.Primitives

module Accessibility = struct
  (* The loadComplete event mirrors the load complete event sent by the browser to assistive
     technology when the web page has finished loading. *)
  module LoadComplete = struct
    let name = "Accessibility.loadComplete"

    type result = {
      root : Types.Accessibility.AXNode.t;
          [@key "root"] [@ocaml.doc "New document root node."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* The nodesUpdated event is sent every time a previously requested node has changed the in tree. *)
  module NodesUpdated = struct
    let name = "Accessibility.nodesUpdated"

    type result = {
      nodes : Types.Accessibility.AXNode.t list;
          [@key "nodes"] [@ocaml.doc "Updated node data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Animation = struct
  (* Event for when an animation has been cancelled. *)
  module AnimationCanceled = struct
    let name = "Animation.animationCanceled"

    type result = {
      id : string;
          [@key "id"] [@ocaml.doc "Id of the animation that was cancelled."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Event for each animation that has been created. *)
  module AnimationCreated = struct
    let name = "Animation.animationCreated"

    type result = {
      id : string;
          [@key "id"] [@ocaml.doc "Id of the animation that was created."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Event for animation that has been started. *)
  module AnimationStarted = struct
    let name = "Animation.animationStarted"

    type result = {
      animation : Types.Animation.Animation.t;
          [@key "animation"] [@ocaml.doc "Animation that was started."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Event for animation that has been updated. *)
  module AnimationUpdated = struct
    let name = "Animation.animationUpdated"

    type result = {
      animation : Types.Animation.Animation.t;
          [@key "animation"] [@ocaml.doc "Animation that was updated."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Audits = struct
  (* No description provided *)
  module IssueAdded = struct
    let name = "Audits.issueAdded"

    type result = {
      issue : Types.Audits.InspectorIssue.t;
          [@key "issue"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Autofill = struct
  (* Emitted when an address form is filled. *)
  module AddressFormFilled = struct
    let name = "Autofill.addressFormFilled"

    type result = {
      filledFields : Types.Autofill.FilledField.t list;
          [@key "filledFields"]
          [@ocaml.doc "Information about the fields that were filled"]
      addressUi : Types.Autofill.AddressUI.t;
          [@key "addressUi"]
          [@ocaml.doc
            "An UI representation of the address used to fill the form.\n\
             Consists of a 2D array where each child represents an \
             address/profile line."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module BackgroundService = struct
  (* Called when the recording state for the service has been updated. *)
  module RecordingStateChanged = struct
    let name = "BackgroundService.recordingStateChanged"

    type result = {
      isRecording : bool;
          [@key "isRecording"] [@ocaml.doc "No description provided"]
      service : Types.BackgroundService.ServiceName.t;
          [@key "service"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called with all existing backgroundServiceEvents when enabled, and all new
     events afterwards if enabled and recording. *)
  module BackgroundServiceEventReceived = struct
    let name = "BackgroundService.backgroundServiceEventReceived"

    type result = {
      backgroundServiceEvent : Types.BackgroundService.BackgroundServiceEvent.t;
          [@key "backgroundServiceEvent"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Browser = struct
  (* Fired when page is about to start a download. *)
  module DownloadWillBegin = struct
    let name = "Browser.downloadWillBegin"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that caused the download to begin."]
      guid : string;
          [@key "guid"] [@ocaml.doc "Global unique identifier of the download."]
      url : string;
          [@key "url"] [@ocaml.doc "URL of the resource being downloaded."]
      suggestedFilename : string;
          [@key "suggestedFilename"]
          [@ocaml.doc
            "Suggested file name of the resource (the actual name of the file \
             saved on disk may differ)."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when download makes progress. Last call has |done| == true. *)
  module DownloadProgress = struct
    let name = "Browser.downloadProgress"

    type downloadprogress_state = [ `inProgress | `completed | `canceled ]

    let downloadprogress_state_of_yojson = function
      | `String "inProgress" -> `inProgress
      | `String "completed" -> `completed
      | `String "canceled" -> `canceled
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_downloadprogress_state = function
      | `inProgress -> `String "inProgress"
      | `completed -> `String "completed"
      | `canceled -> `String "canceled"

    type result = {
      guid : string;
          [@key "guid"] [@ocaml.doc "Global unique identifier of the download."]
      totalBytes : Types.number;
          [@key "totalBytes"] [@ocaml.doc "Total expected bytes to download."]
      receivedBytes : Types.number;
          [@key "receivedBytes"] [@ocaml.doc "Total bytes received."]
      state : downloadprogress_state;
          [@key "state"] [@ocaml.doc "Download status."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module CSS = struct
  (* Fires whenever a web font is updated.  A non-empty font parameter indicates a successfully loaded
     web font. *)
  module FontsUpdated = struct
    let name = "CSS.fontsUpdated"

    type result = {
      font : Types.CSS.FontFace.t option;
          [@key "font"]
          [@yojson.option]
          [@ocaml.doc "The web font that has loaded."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fires whenever a MediaQuery result changes (for example, after a browser window has been
     resized.) The current implementation considers only viewport-dependent media features. *)
  module MediaQueryResultChanged = struct
    let name = "CSS.mediaQueryResultChanged"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired whenever an active document stylesheet is added. *)
  module StyleSheetAdded = struct
    let name = "CSS.styleSheetAdded"

    type result = {
      header : Types.CSS.CSSStyleSheetHeader.t;
          [@key "header"] [@ocaml.doc "Added stylesheet metainfo."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired whenever a stylesheet is changed as a result of the client operation. *)
  module StyleSheetChanged = struct
    let name = "CSS.styleSheetChanged"

    type result = {
      styleSheetId : Types.CSS.StyleSheetId.t;
          [@key "styleSheetId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired whenever an active document stylesheet is removed. *)
  module StyleSheetRemoved = struct
    let name = "CSS.styleSheetRemoved"

    type result = {
      styleSheetId : Types.CSS.StyleSheetId.t;
          [@key "styleSheetId"]
          [@ocaml.doc "Identifier of the removed stylesheet."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module ComputedStyleUpdated = struct
    let name = "CSS.computedStyleUpdated"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"]
          [@ocaml.doc "The node id that has updated computed styles."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Cast = struct
  (* This is fired whenever the list of available sinks changes. A sink is a
     device or a software surface that you can cast to. *)
  module SinksUpdated = struct
    let name = "Cast.sinksUpdated"

    type result = {
      sinks : Types.Cast.Sink.t list;
          [@key "sinks"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* This is fired whenever the outstanding issue/error message changes.
     |issueMessage| is empty if there is no issue. *)
  module IssueUpdated = struct
    let name = "Cast.issueUpdated"

    type result = {
      issueMessage : string;
          [@key "issueMessage"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module DOM = struct
  (* Fired when `Element`'s attribute is modified. *)
  module AttributeModified = struct
    let name = "DOM.attributeModified"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "Id of the node that has changed."]
      name : string; [@key "name"] [@ocaml.doc "Attribute name."]
      value : string; [@key "value"] [@ocaml.doc "Attribute value."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when `Element`'s attribute is removed. *)
  module AttributeRemoved = struct
    let name = "DOM.attributeRemoved"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "Id of the node that has changed."]
      name : string; [@key "name"] [@ocaml.doc "A ttribute name."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Mirrors `DOMCharacterDataModified` event. *)
  module CharacterDataModified = struct
    let name = "DOM.characterDataModified"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "Id of the node that has changed."]
      characterData : string;
          [@key "characterData"] [@ocaml.doc "New text value."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when `Container`'s child node count has changed. *)
  module ChildNodeCountUpdated = struct
    let name = "DOM.childNodeCountUpdated"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "Id of the node that has changed."]
      childNodeCount : Types.number;
          [@key "childNodeCount"] [@ocaml.doc "New node count."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Mirrors `DOMNodeInserted` event. *)
  module ChildNodeInserted = struct
    let name = "DOM.childNodeInserted"

    type result = {
      parentNodeId : Types.DOM.NodeId.t;
          [@key "parentNodeId"] [@ocaml.doc "Id of the node that has changed."]
      previousNodeId : Types.DOM.NodeId.t;
          [@key "previousNodeId"] [@ocaml.doc "Id of the previous sibling."]
      node : Types.DOM.Node.t; [@key "node"] [@ocaml.doc "Inserted node data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Mirrors `DOMNodeRemoved` event. *)
  module ChildNodeRemoved = struct
    let name = "DOM.childNodeRemoved"

    type result = {
      parentNodeId : Types.DOM.NodeId.t;
          [@key "parentNodeId"] [@ocaml.doc "Parent id."]
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "Id of the node that has been removed."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when distribution is changed. *)
  module DistributedNodesUpdated = struct
    let name = "DOM.distributedNodesUpdated"

    type result = {
      insertionPointId : Types.DOM.NodeId.t;
          [@key "insertionPointId"]
          [@ocaml.doc "Insertion point where distributed nodes were updated."]
      distributedNodes : Types.DOM.BackendNode.t list;
          [@key "distributedNodes"]
          [@ocaml.doc "Distributed nodes for given insertion point."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when `Document` has been totally updated. Node ids are no longer valid. *)
  module DocumentUpdated = struct
    let name = "DOM.documentUpdated"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when `Element`'s inline style is modified via a CSS property modification. *)
  module InlineStyleInvalidated = struct
    let name = "DOM.inlineStyleInvalidated"

    type result = {
      nodeIds : Types.DOM.NodeId.t list;
          [@key "nodeIds"]
          [@ocaml.doc
            "Ids of the nodes for which the inline styles have been \
             invalidated."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when a pseudo element is added to an element. *)
  module PseudoElementAdded = struct
    let name = "DOM.pseudoElementAdded"

    type result = {
      parentId : Types.DOM.NodeId.t;
          [@key "parentId"] [@ocaml.doc "Pseudo element's parent element id."]
      pseudoElement : Types.DOM.Node.t;
          [@key "pseudoElement"] [@ocaml.doc "The added pseudo element."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when top layer elements are changed. *)
  module TopLayerElementsUpdated = struct
    let name = "DOM.topLayerElementsUpdated"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a node's scrollability state changes. *)
  module ScrollableFlagUpdated = struct
    let name = "DOM.scrollableFlagUpdated"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "The id of the node."]
      isScrollable : bool;
          [@key "isScrollable"] [@ocaml.doc "If the node is scrollable."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when a pseudo element is removed from an element. *)
  module PseudoElementRemoved = struct
    let name = "DOM.pseudoElementRemoved"

    type result = {
      parentId : Types.DOM.NodeId.t;
          [@key "parentId"] [@ocaml.doc "Pseudo element's parent element id."]
      pseudoElementId : Types.DOM.NodeId.t;
          [@key "pseudoElementId"] [@ocaml.doc "The removed pseudo element id."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when backend wants to provide client with the missing DOM structure. This happens upon
     most of the calls requesting node ids. *)
  module SetChildNodes = struct
    let name = "DOM.setChildNodes"

    type result = {
      parentId : Types.DOM.NodeId.t;
          [@key "parentId"]
          [@ocaml.doc "Parent node id to populate with children."]
      nodes : Types.DOM.Node.t list;
          [@key "nodes"] [@ocaml.doc "Child nodes array."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when shadow root is popped from the element. *)
  module ShadowRootPopped = struct
    let name = "DOM.shadowRootPopped"

    type result = {
      hostId : Types.DOM.NodeId.t;
          [@key "hostId"] [@ocaml.doc "Host element id."]
      rootId : Types.DOM.NodeId.t; [@key "rootId"] [@ocaml.doc "Shadow root id."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called when shadow root is pushed into the element. *)
  module ShadowRootPushed = struct
    let name = "DOM.shadowRootPushed"

    type result = {
      hostId : Types.DOM.NodeId.t;
          [@key "hostId"] [@ocaml.doc "Host element id."]
      root : Types.DOM.Node.t; [@key "root"] [@ocaml.doc "Shadow root."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module DOMStorage = struct
  (* No description provided *)
  module DomStorageItemAdded = struct
    let name = "DOMStorage.domStorageItemAdded"

    type result = {
      storageId : Types.DOMStorage.StorageId.t;
          [@key "storageId"] [@ocaml.doc "No description provided"]
      key : string; [@key "key"] [@ocaml.doc "No description provided"]
      newValue : string; [@key "newValue"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module DomStorageItemRemoved = struct
    let name = "DOMStorage.domStorageItemRemoved"

    type result = {
      storageId : Types.DOMStorage.StorageId.t;
          [@key "storageId"] [@ocaml.doc "No description provided"]
      key : string; [@key "key"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module DomStorageItemUpdated = struct
    let name = "DOMStorage.domStorageItemUpdated"

    type result = {
      storageId : Types.DOMStorage.StorageId.t;
          [@key "storageId"] [@ocaml.doc "No description provided"]
      key : string; [@key "key"] [@ocaml.doc "No description provided"]
      oldValue : string;
          [@key "oldValue"] [@ocaml.doc "No description provided"]
      newValue : string; [@key "newValue"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module DomStorageItemsCleared = struct
    let name = "DOMStorage.domStorageItemsCleared"

    type result = {
      storageId : Types.DOMStorage.StorageId.t;
          [@key "storageId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Database = struct
  (* No description provided *)
  module AddDatabase = struct
    let name = "Database.addDatabase"

    type result = {
      database : Types.Database.Database.t;
          [@key "database"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Emulation = struct
  (* Notification sent after the virtual time budget for the current VirtualTimePolicy has run out. *)
  module VirtualTimeBudgetExpired = struct
    let name = "Emulation.virtualTimeBudgetExpired"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Input = struct
  (* Emitted only when `Input.setInterceptDrags` is enabled. Use this data with `Input.dispatchDragEvent` to
     restore normal drag and drop behavior. *)
  module DragIntercepted = struct
    let name = "Input.dragIntercepted"

    type result = {
      data : Types.Input.DragData.t;
          [@key "data"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Inspector = struct
  (* Fired when remote debugging connection is about to be terminated. Contains detach reason. *)
  module Detached = struct
    let name = "Inspector.detached"

    type result = {
      reason : string;
          [@key "reason"]
          [@ocaml.doc "The reason why connection has been terminated."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when debugging target has crashed *)
  module TargetCrashed = struct
    let name = "Inspector.targetCrashed"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when debugging target has reloaded after crash *)
  module TargetReloadedAfterCrash = struct
    let name = "Inspector.targetReloadedAfterCrash"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module LayerTree = struct
  (* No description provided *)
  module LayerPainted = struct
    let name = "LayerTree.layerPainted"

    type result = {
      layerId : Types.LayerTree.LayerId.t;
          [@key "layerId"] [@ocaml.doc "The id of the painted layer."]
      clip : Types.DOM.Rect.t; [@key "clip"] [@ocaml.doc "Clip rectangle."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module LayerTreeDidChange = struct
    let name = "LayerTree.layerTreeDidChange"

    type result = {
      layers : Types.LayerTree.Layer.t list option;
          [@key "layers"]
          [@yojson.option]
          [@ocaml.doc "Layer tree, absent if not in the compositing mode."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Log = struct
  (* Issued when new message was logged. *)
  module EntryAdded = struct
    let name = "Log.entryAdded"

    type result = {
      entry : Types.Log.LogEntry.t; [@key "entry"] [@ocaml.doc "The entry."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Network = struct
  (* Fired when data chunk was received over the network. *)
  module DataReceived = struct
    let name = "Network.dataReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      dataLength : Types.number;
          [@key "dataLength"] [@ocaml.doc "Data chunk length."]
      encodedDataLength : Types.number;
          [@key "encodedDataLength"]
          [@ocaml.doc
            "Actual bytes received (might be less than dataLength for \
             compressed encodings)."]
      data : string option;
          [@key "data"]
          [@yojson.option]
          [@ocaml.doc
            "Data that was received. (Encoded as a base64 string when passed \
             over JSON)"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when EventSource message is received. *)
  module EventSourceMessageReceived = struct
    let name = "Network.eventSourceMessageReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      eventName : string; [@key "eventName"] [@ocaml.doc "Message type."]
      eventId : string; [@key "eventId"] [@ocaml.doc "Message identifier."]
      data : string; [@key "data"] [@ocaml.doc "Message content."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when HTTP request has failed to load. *)
  module LoadingFailed = struct
    let name = "Network.loadingFailed"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      type_ : Types.Network.ResourceType.t;
          [@key "type"] [@ocaml.doc "Resource type."]
      errorText : string;
          [@key "errorText"]
          [@ocaml.doc
            "Error message. List of network errors: \
             https://cs.chromium.org/chromium/src/net/base/net_error_list.h"]
      canceled : bool option;
          [@key "canceled"]
          [@yojson.option]
          [@ocaml.doc "True if loading was canceled."]
      blockedReason : Types.Network.BlockedReason.t option;
          [@key "blockedReason"]
          [@yojson.option]
          [@ocaml.doc "The reason why loading was blocked, if any."]
      corsErrorStatus : Types.Network.CorsErrorStatus.t option;
          [@key "corsErrorStatus"]
          [@yojson.option]
          [@ocaml.doc "The reason why loading was blocked by CORS, if any."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when HTTP request has finished loading. *)
  module LoadingFinished = struct
    let name = "Network.loadingFinished"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      encodedDataLength : Types.number;
          [@key "encodedDataLength"]
          [@ocaml.doc "Total number of bytes received for this request."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
     mocked.
     Deprecated, use Fetch.requestPaused instead. *)
  module RequestIntercepted = struct
    let name = "Network.requestIntercepted"

    type result = {
      interceptionId : Types.Network.InterceptionId.t;
          [@key "interceptionId"]
          [@ocaml.doc
            "Each request the page makes will have a unique id, however if any \
             redirects are encountered\n\
             while processing that fetch, they will be reported with the same \
             id as the original fetch.\n\
             Likewise if HTTP authentication is needed then the same fetch id \
             will be used."]
      request : Types.Network.Request.t;
          [@key "request"] [@ocaml.doc "No description provided"]
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "The id of the frame that initiated the request."]
      resourceType : Types.Network.ResourceType.t;
          [@key "resourceType"]
          [@ocaml.doc "How the requested resource will be used."]
      isNavigationRequest : bool;
          [@key "isNavigationRequest"]
          [@ocaml.doc
            "Whether this is a navigation request, which can abort the \
             navigation completely."]
      isDownload : bool option;
          [@key "isDownload"]
          [@yojson.option]
          [@ocaml.doc
            "Set if the request is a navigation that will result in a download.\n\
             Only present after response is received from the server (i.e. \
             HeadersReceived stage)."]
      redirectUrl : string option;
          [@key "redirectUrl"]
          [@yojson.option]
          [@ocaml.doc
            "Redirect location, only sent if a redirect was intercepted."]
      authChallenge : Types.Network.AuthChallenge.t option;
          [@key "authChallenge"]
          [@yojson.option]
          [@ocaml.doc
            "Details of the Authorization Challenge encountered. If this is \
             set then\n\
             continueInterceptedRequest must contain an authChallengeResponse."]
      responseErrorReason : Types.Network.ErrorReason.t option;
          [@key "responseErrorReason"]
          [@yojson.option]
          [@ocaml.doc
            "Response error if intercepted at response stage or if redirect \
             occurred while intercepting\n\
             request."]
      responseStatusCode : Types.number option;
          [@key "responseStatusCode"]
          [@yojson.option]
          [@ocaml.doc
            "Response code if intercepted at response stage or if redirect \
             occurred while intercepting\n\
             request or auth retry occurred."]
      responseHeaders : Types.Network.Headers.t option;
          [@key "responseHeaders"]
          [@yojson.option]
          [@ocaml.doc
            "Response headers if intercepted at the response stage or if \
             redirect occurred while\n\
             intercepting request or auth retry occurred."]
      requestId : Types.Network.RequestId.t option;
          [@key "requestId"]
          [@yojson.option]
          [@ocaml.doc
            "If the intercepted request had a corresponding requestWillBeSent \
             event fired for it, then\n\
             this requestId will be the same as the requestId present in the \
             requestWillBeSent event."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired if request ended up loading from cache. *)
  module RequestServedFromCache = struct
    let name = "Network.requestServedFromCache"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when page is about to send HTTP request. *)
  module RequestWillBeSent = struct
    let name = "Network.requestWillBeSent"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      loaderId : Types.Network.LoaderId.t;
          [@key "loaderId"]
          [@ocaml.doc
            "Loader identifier. Empty string if the request is fetched from \
             worker."]
      documentURL : string;
          [@key "documentURL"]
          [@ocaml.doc "URL of the document this request is loaded for."]
      request : Types.Network.Request.t;
          [@key "request"] [@ocaml.doc "Request data."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      wallTime : Types.Network.TimeSinceEpoch.t;
          [@key "wallTime"] [@ocaml.doc "Timestamp."]
      initiator : Types.Network.Initiator.t;
          [@key "initiator"] [@ocaml.doc "Request initiator."]
      redirectHasExtraInfo : bool;
          [@key "redirectHasExtraInfo"]
          [@ocaml.doc
            "In the case that redirectResponse is populated, this flag \
             indicates whether\n\
             requestWillBeSentExtraInfo and responseReceivedExtraInfo events \
             will be or were emitted\n\
             for the request which was just redirected."]
      redirectResponse : Types.Network.Response.t option;
          [@key "redirectResponse"]
          [@yojson.option]
          [@ocaml.doc "Redirect response data."]
      type_ : Types.Network.ResourceType.t option;
          [@key "type"] [@yojson.option] [@ocaml.doc "Type of this resource."]
      frameId : Types.Page.FrameId.t option;
          [@key "frameId"] [@yojson.option] [@ocaml.doc "Frame identifier."]
      hasUserGesture : bool option;
          [@key "hasUserGesture"]
          [@yojson.option]
          [@ocaml.doc
            "Whether the request is initiated by a user gesture. Defaults to \
             false."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when resource loading priority is changed *)
  module ResourceChangedPriority = struct
    let name = "Network.resourceChangedPriority"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      newPriority : Types.Network.ResourcePriority.t;
          [@key "newPriority"] [@ocaml.doc "New priority"]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a signed exchange was received over the network *)
  module SignedExchangeReceived = struct
    let name = "Network.signedExchangeReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      info : Types.Network.SignedExchangeInfo.t;
          [@key "info"]
          [@ocaml.doc "Information about the signed exchange response."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when HTTP response is available. *)
  module ResponseReceived = struct
    let name = "Network.responseReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      loaderId : Types.Network.LoaderId.t;
          [@key "loaderId"]
          [@ocaml.doc
            "Loader identifier. Empty string if the request is fetched from \
             worker."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      type_ : Types.Network.ResourceType.t;
          [@key "type"] [@ocaml.doc "Resource type."]
      response : Types.Network.Response.t;
          [@key "response"] [@ocaml.doc "Response data."]
      hasExtraInfo : bool;
          [@key "hasExtraInfo"]
          [@ocaml.doc
            "Indicates whether requestWillBeSentExtraInfo and \
             responseReceivedExtraInfo events will be\n\
             or were emitted for this request."]
      frameId : Types.Page.FrameId.t option;
          [@key "frameId"] [@yojson.option] [@ocaml.doc "Frame identifier."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket is closed. *)
  module WebSocketClosed = struct
    let name = "Network.webSocketClosed"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired upon WebSocket creation. *)
  module WebSocketCreated = struct
    let name = "Network.webSocketCreated"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      url : string; [@key "url"] [@ocaml.doc "WebSocket request URL."]
      initiator : Types.Network.Initiator.t option;
          [@key "initiator"] [@yojson.option] [@ocaml.doc "Request initiator."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket message error occurs. *)
  module WebSocketFrameError = struct
    let name = "Network.webSocketFrameError"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      errorMessage : string;
          [@key "errorMessage"] [@ocaml.doc "WebSocket error message."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket message is received. *)
  module WebSocketFrameReceived = struct
    let name = "Network.webSocketFrameReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      response : Types.Network.WebSocketFrame.t;
          [@key "response"] [@ocaml.doc "WebSocket response data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket message is sent. *)
  module WebSocketFrameSent = struct
    let name = "Network.webSocketFrameSent"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      response : Types.Network.WebSocketFrame.t;
          [@key "response"] [@ocaml.doc "WebSocket response data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket handshake response becomes available. *)
  module WebSocketHandshakeResponseReceived = struct
    let name = "Network.webSocketHandshakeResponseReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      response : Types.Network.WebSocketResponse.t;
          [@key "response"] [@ocaml.doc "WebSocket response data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebSocket is about to initiate handshake. *)
  module WebSocketWillSendHandshakeRequest = struct
    let name = "Network.webSocketWillSendHandshakeRequest"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "Request identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      wallTime : Types.Network.TimeSinceEpoch.t;
          [@key "wallTime"] [@ocaml.doc "UTC Timestamp."]
      request : Types.Network.WebSocketRequest.t;
          [@key "request"] [@ocaml.doc "WebSocket request data."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired upon WebTransport creation. *)
  module WebTransportCreated = struct
    let name = "Network.webTransportCreated"

    type result = {
      transportId : Types.Network.RequestId.t;
          [@key "transportId"] [@ocaml.doc "WebTransport identifier."]
      url : string; [@key "url"] [@ocaml.doc "WebTransport request URL."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
      initiator : Types.Network.Initiator.t option;
          [@key "initiator"] [@yojson.option] [@ocaml.doc "Request initiator."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebTransport handshake is finished. *)
  module WebTransportConnectionEstablished = struct
    let name = "Network.webTransportConnectionEstablished"

    type result = {
      transportId : Types.Network.RequestId.t;
          [@key "transportId"] [@ocaml.doc "WebTransport identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when WebTransport is disposed. *)
  module WebTransportClosed = struct
    let name = "Network.webTransportClosed"

    type result = {
      transportId : Types.Network.RequestId.t;
          [@key "transportId"] [@ocaml.doc "WebTransport identifier."]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when additional information about a requestWillBeSent event is available from the
     network stack. Not every requestWillBeSent event will have an additional
     requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
     or requestWillBeSentExtraInfo will be fired first for the same request. *)
  module RequestWillBeSentExtraInfo = struct
    let name = "Network.requestWillBeSentExtraInfo"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc
            "Request identifier. Used to match this information to an existing \
             requestWillBeSent event."]
      associatedCookies : Types.Network.AssociatedCookie.t list;
          [@key "associatedCookies"]
          [@ocaml.doc
            "A list of cookies potentially associated to the requested URL. \
             This includes both cookies sent with\n\
             the request and the ones not sent; the latter are distinguished \
             by having blockedReasons field set."]
      headers : Types.Network.Headers.t;
          [@key "headers"]
          [@ocaml.doc "Raw request headers as they will be sent over the wire."]
      connectTiming : Types.Network.ConnectTiming.t;
          [@key "connectTiming"]
          [@ocaml.doc "Connection timing information for the request."]
      clientSecurityState : Types.Network.ClientSecurityState.t option;
          [@key "clientSecurityState"]
          [@yojson.option]
          [@ocaml.doc "The client security state set for the request."]
      siteHasCookieInOtherPartition : bool option;
          [@key "siteHasCookieInOtherPartition"]
          [@yojson.option]
          [@ocaml.doc
            "Whether the site has partitioned cookies stored in a partition \
             different than the current one."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when additional information about a responseReceived event is available from the network
     stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
     it, and responseReceivedExtraInfo may be fired before or after responseReceived. *)
  module ResponseReceivedExtraInfo = struct
    let name = "Network.responseReceivedExtraInfo"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc
            "Request identifier. Used to match this information to another \
             responseReceived event."]
      blockedCookies : Types.Network.BlockedSetCookieWithReason.t list;
          [@key "blockedCookies"]
          [@ocaml.doc
            "A list of cookies which were not stored from the response along \
             with the corresponding\n\
             reasons for blocking. The cookies here may not be valid due to \
             syntax errors, which\n\
             are represented by the invalid cookie line string instead of a \
             proper cookie."]
      headers : Types.Network.Headers.t;
          [@key "headers"]
          [@ocaml.doc
            "Raw response headers as they were received over the wire."]
      resourceIPAddressSpace : Types.Network.IPAddressSpace.t;
          [@key "resourceIPAddressSpace"]
          [@ocaml.doc
            "The IP address space of the resource. The address space can only \
             be determined once the transport\n\
             established the connection, so we can't send it in \
             `requestWillBeSentExtraInfo`."]
      statusCode : Types.number;
          [@key "statusCode"]
          [@ocaml.doc
            "The status code of the response. This is useful in cases the \
             request failed and no responseReceived\n\
             event is triggered, which is the case for, e.g., CORS errors. \
             This is also the correct status code\n\
             for cached requests, where the status in responseReceived is a \
             200 and this will be 304."]
      headersText : string option;
          [@key "headersText"]
          [@yojson.option]
          [@ocaml.doc
            "Raw response header text as it was received over the wire. The \
             raw text may not always be\n\
             available, such as in the case of HTTP/2 or QUIC."]
      cookiePartitionKey : Types.Network.CookiePartitionKey.t option;
          [@key "cookiePartitionKey"]
          [@yojson.option]
          [@ocaml.doc
            "The cookie partition key that will be used to store partitioned \
             cookies set in this response.\n\
             Only sent when partitioned cookies are enabled."]
      cookiePartitionKeyOpaque : bool option;
          [@key "cookiePartitionKeyOpaque"]
          [@yojson.option]
          [@ocaml.doc
            "True if partitioned cookies are enabled, but the partition key is \
             not serializable to string."]
      exemptedCookies : Types.Network.ExemptedSetCookieWithReason.t list option;
          [@key "exemptedCookies"]
          [@yojson.option]
          [@ocaml.doc
            "A list of cookies which should have been blocked by 3PCD but are \
             exempted and stored from\n\
             the response with the corresponding reason."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when 103 Early Hints headers is received in addition to the common response.
     Not every responseReceived event will have an responseReceivedEarlyHints fired.
     Only one responseReceivedEarlyHints may be fired for eached responseReceived event. *)
  module ResponseReceivedEarlyHints = struct
    let name = "Network.responseReceivedEarlyHints"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc
            "Request identifier. Used to match this information to another \
             responseReceived event."]
      headers : Types.Network.Headers.t;
          [@key "headers"]
          [@ocaml.doc
            "Raw response headers as they were received over the wire."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired exactly once for each Trust Token operation. Depending on
     the type of the operation and whether the operation succeeded or
     failed, the event is fired before the corresponding request was sent
     or after the response was received. *)
  module TrustTokenOperationDone = struct
    let name = "Network.trustTokenOperationDone"

    type trusttokenoperationdone_status =
      [ `Ok
      | `InvalidArgument
      | `MissingIssuerKeys
      | `FailedPrecondition
      | `ResourceExhausted
      | `AlreadyExists
      | `ResourceLimited
      | `Unauthorized
      | `BadResponse
      | `InternalError
      | `UnknownError
      | `FulfilledLocally ]

    let trusttokenoperationdone_status_of_yojson = function
      | `String "Ok" -> `Ok
      | `String "InvalidArgument" -> `InvalidArgument
      | `String "MissingIssuerKeys" -> `MissingIssuerKeys
      | `String "FailedPrecondition" -> `FailedPrecondition
      | `String "ResourceExhausted" -> `ResourceExhausted
      | `String "AlreadyExists" -> `AlreadyExists
      | `String "ResourceLimited" -> `ResourceLimited
      | `String "Unauthorized" -> `Unauthorized
      | `String "BadResponse" -> `BadResponse
      | `String "InternalError" -> `InternalError
      | `String "UnknownError" -> `UnknownError
      | `String "FulfilledLocally" -> `FulfilledLocally
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_trusttokenoperationdone_status = function
      | `Ok -> `String "Ok"
      | `InvalidArgument -> `String "InvalidArgument"
      | `MissingIssuerKeys -> `String "MissingIssuerKeys"
      | `FailedPrecondition -> `String "FailedPrecondition"
      | `ResourceExhausted -> `String "ResourceExhausted"
      | `AlreadyExists -> `String "AlreadyExists"
      | `ResourceLimited -> `String "ResourceLimited"
      | `Unauthorized -> `String "Unauthorized"
      | `BadResponse -> `String "BadResponse"
      | `InternalError -> `String "InternalError"
      | `UnknownError -> `String "UnknownError"
      | `FulfilledLocally -> `String "FulfilledLocally"

    type result = {
      status : trusttokenoperationdone_status;
          [@key "status"]
          [@ocaml.doc
            "Detailed success or error status of the operation.\n\
             'AlreadyExists' also signifies a successful operation, as the \
             result\n\
             of the operation already exists und thus, the operation was abort\n\
             preemptively (e.g. a cache hit)."]
      type_ : Types.Network.TrustTokenOperationType.t;
          [@key "type"] [@ocaml.doc "No description provided"]
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "No description provided"]
      topLevelOrigin : string option;
          [@key "topLevelOrigin"]
          [@yojson.option]
          [@ocaml.doc
            "Top level origin. The context in which the operation was \
             attempted."]
      issuerOrigin : string option;
          [@key "issuerOrigin"]
          [@yojson.option]
          [@ocaml.doc
            "Origin of the issuer in case of a \"Issuance\" or \"Redemption\" \
             operation."]
      issuedTokenCount : Types.number option;
          [@key "issuedTokenCount"]
          [@yojson.option]
          [@ocaml.doc
            "The number of obtained Trust Tokens on a successful \"Issuance\" \
             operation."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired once security policy has been updated. *)
  module PolicyUpdated = struct
    let name = "Network.policyUpdated"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired once when parsing the .wbn file has succeeded.
     The event contains the information about the web bundle contents. *)
  module SubresourceWebBundleMetadataReceived = struct
    let name = "Network.subresourceWebBundleMetadataReceived"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc
            "Request identifier. Used to match this information to another \
             event."]
      urls : string list;
          [@key "urls"]
          [@ocaml.doc
            "A list of URLs of resources in the subresource Web Bundle."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired once when parsing the .wbn file has failed. *)
  module SubresourceWebBundleMetadataError = struct
    let name = "Network.subresourceWebBundleMetadataError"

    type result = {
      requestId : Types.Network.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc
            "Request identifier. Used to match this information to another \
             event."]
      errorMessage : string; [@key "errorMessage"] [@ocaml.doc "Error message"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when handling requests for resources within a .wbn file.
     Note: this will only be fired for resources that are requested by the webpage. *)
  module SubresourceWebBundleInnerResponseParsed = struct
    let name = "Network.subresourceWebBundleInnerResponseParsed"

    type result = {
      innerRequestId : Types.Network.RequestId.t;
          [@key "innerRequestId"]
          [@ocaml.doc "Request identifier of the subresource request"]
      innerRequestURL : string;
          [@key "innerRequestURL"]
          [@ocaml.doc "URL of the subresource resource."]
      bundleRequestId : Types.Network.RequestId.t option;
          [@key "bundleRequestId"]
          [@yojson.option]
          [@ocaml.doc
            "Bundle request identifier. Used to match this information to \
             another event.\n\
             This made be absent in case when the instrumentation was enabled \
             only\n\
             after webbundle was parsed."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when request for resources within a .wbn file failed. *)
  module SubresourceWebBundleInnerResponseError = struct
    let name = "Network.subresourceWebBundleInnerResponseError"

    type result = {
      innerRequestId : Types.Network.RequestId.t;
          [@key "innerRequestId"]
          [@ocaml.doc "Request identifier of the subresource request"]
      innerRequestURL : string;
          [@key "innerRequestURL"]
          [@ocaml.doc "URL of the subresource resource."]
      errorMessage : string; [@key "errorMessage"] [@ocaml.doc "Error message"]
      bundleRequestId : Types.Network.RequestId.t option;
          [@key "bundleRequestId"]
          [@yojson.option]
          [@ocaml.doc
            "Bundle request identifier. Used to match this information to \
             another event.\n\
             This made be absent in case when the instrumentation was enabled \
             only\n\
             after webbundle was parsed."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Is sent whenever a new report is added.
     And after 'enableReportingApi' for all existing reports. *)
  module ReportingApiReportAdded = struct
    let name = "Network.reportingApiReportAdded"

    type result = {
      report : Types.Network.ReportingApiReport.t;
          [@key "report"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module ReportingApiReportUpdated = struct
    let name = "Network.reportingApiReportUpdated"

    type result = {
      report : Types.Network.ReportingApiReport.t;
          [@key "report"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module ReportingApiEndpointsChangedForOrigin = struct
    let name = "Network.reportingApiEndpointsChangedForOrigin"

    type result = {
      origin : string;
          [@key "origin"]
          [@ocaml.doc
            "Origin of the document(s) which configured the endpoints."]
      endpoints : Types.Network.ReportingApiEndpoint.t list;
          [@key "endpoints"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Overlay = struct
  (* Fired when the node should be inspected. This happens after call to `setInspectMode` or when
     user manually inspects an element. *)
  module InspectNodeRequested = struct
    let name = "Overlay.inspectNodeRequested"

    type result = {
      backendNodeId : Types.DOM.BackendNodeId.t;
          [@key "backendNodeId"] [@ocaml.doc "Id of the node to inspect."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when the node should be highlighted. This happens after call to `setInspectMode`. *)
  module NodeHighlightRequested = struct
    let name = "Overlay.nodeHighlightRequested"

    type result = {
      nodeId : Types.DOM.NodeId.t;
          [@key "nodeId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when user asks to capture screenshot of some area on the page. *)
  module ScreenshotRequested = struct
    let name = "Overlay.screenshotRequested"

    type result = {
      viewport : Types.Page.Viewport.t;
          [@key "viewport"]
          [@ocaml.doc
            "Viewport to capture, in device independent pixels (dip)."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when user cancels the inspect mode. *)
  module InspectModeCanceled = struct
    let name = "Overlay.inspectModeCanceled"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Page = struct
  (* No description provided *)
  module DomContentEventFired = struct
    let name = "Page.domContentEventFired"

    type result = {
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Emitted only when `page.interceptFileChooser` is enabled. *)
  module FileChooserOpened = struct
    let name = "Page.fileChooserOpened"

    type filechooseropened_mode = [ `selectSingle | `selectMultiple ]

    let filechooseropened_mode_of_yojson = function
      | `String "selectSingle" -> `selectSingle
      | `String "selectMultiple" -> `selectMultiple
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_filechooseropened_mode = function
      | `selectSingle -> `String "selectSingle"
      | `selectMultiple -> `String "selectMultiple"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"] [@ocaml.doc "Id of the frame containing input node."]
      mode : filechooseropened_mode; [@key "mode"] [@ocaml.doc "Input mode."]
      backendNodeId : Types.DOM.BackendNodeId.t option;
          [@key "backendNodeId"]
          [@yojson.option]
          [@ocaml.doc
            "Input node id. Only present for file choosers opened via an \
             `<input type=\"file\">` element."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame has been attached to its parent. *)
  module FrameAttached = struct
    let name = "Page.frameAttached"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that has been attached."]
      parentFrameId : Types.Page.FrameId.t;
          [@key "parentFrameId"] [@ocaml.doc "Parent frame identifier."]
      stack : Types.Runtime.StackTrace.t option;
          [@key "stack"]
          [@yojson.option]
          [@ocaml.doc
            "JavaScript stack trace of when frame was attached, only set if \
             frame initiated from script."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame no longer has a scheduled navigation. *)
  module FrameClearedScheduledNavigation = struct
    let name = "Page.frameClearedScheduledNavigation"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc
            "Id of the frame that has cleared its scheduled navigation."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame has been detached from its parent. *)
  module FrameDetached = struct
    let name = "Page.frameDetached"

    type framedetached_reason = [ `remove | `swap ]

    let framedetached_reason_of_yojson = function
      | `String "remove" -> `remove
      | `String "swap" -> `swap
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_framedetached_reason = function
      | `remove -> `String "remove"
      | `swap -> `String "swap"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that has been detached."]
      reason : framedetached_reason;
          [@key "reason"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired before frame subtree is detached. Emitted before any frame of the
     subtree is actually detached. *)
  module FrameSubtreeWillBeDetached = struct
    let name = "Page.frameSubtreeWillBeDetached"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc
            "Id of the frame that is the root of the subtree that will be \
             detached."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired once navigation of the frame has completed. Frame is now associated with the new loader. *)
  module FrameNavigated = struct
    let name = "Page.frameNavigated"

    type result = {
      frame : Types.Page.Frame.t; [@key "frame"] [@ocaml.doc "Frame object."]
      type_ : Types.Page.NavigationType.t;
          [@key "type"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when opening document to write to. *)
  module DocumentOpened = struct
    let name = "Page.documentOpened"

    type result = {
      frame : Types.Page.Frame.t; [@key "frame"] [@ocaml.doc "Frame object."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module FrameResized = struct
    let name = "Page.frameResized"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a renderer-initiated navigation is requested.
     Navigation may still be cancelled after the event is issued. *)
  module FrameRequestedNavigation = struct
    let name = "Page.frameRequestedNavigation"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that is being navigated."]
      reason : Types.Page.ClientNavigationReason.t;
          [@key "reason"] [@ocaml.doc "The reason for the navigation."]
      url : string;
          [@key "url"]
          [@ocaml.doc "The destination URL for the requested navigation."]
      disposition : Types.Page.ClientNavigationDisposition.t;
          [@key "disposition"]
          [@ocaml.doc "The disposition for the navigation."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame schedules a potential navigation. *)
  module FrameScheduledNavigation = struct
    let name = "Page.frameScheduledNavigation"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that has scheduled a navigation."]
      delay : Types.number;
          [@key "delay"]
          [@ocaml.doc
            "Delay (in seconds) until the navigation is scheduled to begin. \
             The navigation is not\n\
             guaranteed to start."]
      reason : Types.Page.ClientNavigationReason.t;
          [@key "reason"] [@ocaml.doc "The reason for the navigation."]
      url : string;
          [@key "url"]
          [@ocaml.doc "The destination URL for the scheduled navigation."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame has started loading. *)
  module FrameStartedLoading = struct
    let name = "Page.frameStartedLoading"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that has started loading."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when frame has stopped loading. *)
  module FrameStoppedLoading = struct
    let name = "Page.frameStoppedLoading"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that has stopped loading."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when page is about to start a download.
     Deprecated. Use Browser.downloadWillBegin instead. *)
  module DownloadWillBegin = struct
    let name = "Page.downloadWillBegin"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "Id of the frame that caused download to begin."]
      guid : string;
          [@key "guid"] [@ocaml.doc "Global unique identifier of the download."]
      url : string;
          [@key "url"] [@ocaml.doc "URL of the resource being downloaded."]
      suggestedFilename : string;
          [@key "suggestedFilename"]
          [@ocaml.doc
            "Suggested file name of the resource (the actual name of the file \
             saved on disk may differ)."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when download makes progress. Last call has |done| == true.
     Deprecated. Use Browser.downloadProgress instead. *)
  module DownloadProgress = struct
    let name = "Page.downloadProgress"

    type downloadprogress_state = [ `inProgress | `completed | `canceled ]

    let downloadprogress_state_of_yojson = function
      | `String "inProgress" -> `inProgress
      | `String "completed" -> `completed
      | `String "canceled" -> `canceled
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_downloadprogress_state = function
      | `inProgress -> `String "inProgress"
      | `completed -> `String "completed"
      | `canceled -> `String "canceled"

    type result = {
      guid : string;
          [@key "guid"] [@ocaml.doc "Global unique identifier of the download."]
      totalBytes : Types.number;
          [@key "totalBytes"] [@ocaml.doc "Total expected bytes to download."]
      receivedBytes : Types.number;
          [@key "receivedBytes"] [@ocaml.doc "Total bytes received."]
      state : downloadprogress_state;
          [@key "state"] [@ocaml.doc "Download status."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when interstitial page was hidden *)
  module InterstitialHidden = struct
    let name = "Page.interstitialHidden"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when interstitial page was shown *)
  module InterstitialShown = struct
    let name = "Page.interstitialShown"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) has been
     closed. *)
  module JavascriptDialogClosed = struct
    let name = "Page.javascriptDialogClosed"

    type result = {
      result : bool;
          [@key "result"] [@ocaml.doc "Whether dialog was confirmed."]
      userInput : string;
          [@key "userInput"] [@ocaml.doc "User input in case of prompt."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) is about to
     open. *)
  module JavascriptDialogOpening = struct
    let name = "Page.javascriptDialogOpening"

    type result = {
      url : string; [@key "url"] [@ocaml.doc "Frame url."]
      message : string;
          [@key "message"]
          [@ocaml.doc "Message that will be displayed by the dialog."]
      type_ : Types.Page.DialogType.t; [@key "type"] [@ocaml.doc "Dialog type."]
      hasBrowserHandler : bool;
          [@key "hasBrowserHandler"]
          [@ocaml.doc
            "True iff browser is capable showing or acting on the given \
             dialog. When browser has no\n\
             dialog handler for given target, calling alert while Page domain \
             is engaged will stall\n\
             the page execution. Execution can be resumed via calling \
             Page.handleJavaScriptDialog."]
      defaultPrompt : string option;
          [@key "defaultPrompt"]
          [@yojson.option]
          [@ocaml.doc "Default dialog prompt."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired for top level page lifecycle events such as navigation, load, paint, etc. *)
  module LifecycleEvent = struct
    let name = "Page.lifecycleEvent"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"] [@ocaml.doc "Id of the frame."]
      loaderId : Types.Network.LoaderId.t;
          [@key "loaderId"]
          [@ocaml.doc
            "Loader identifier. Empty string if the request is fetched from \
             worker."]
      name : string; [@key "name"] [@ocaml.doc "No description provided"]
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired for failed bfcache history navigations if BackForwardCache feature is enabled. Do
     not assume any ordering with the Page.frameNavigated event. This event is fired only for
     main-frame history navigation where the document changes (non-same-document navigations),
     when bfcache navigation fails. *)
  module BackForwardCacheNotUsed = struct
    let name = "Page.backForwardCacheNotUsed"

    type result = {
      loaderId : Types.Network.LoaderId.t;
          [@key "loaderId"]
          [@ocaml.doc "The loader id for the associated navigation."]
      frameId : Types.Page.FrameId.t;
          [@key "frameId"] [@ocaml.doc "The frame id of the associated frame."]
      notRestoredExplanations :
        Types.Page.BackForwardCacheNotRestoredExplanation.t list;
          [@key "notRestoredExplanations"]
          [@ocaml.doc
            "Array of reasons why the page could not be cached. This must not \
             be empty."]
      notRestoredExplanationsTree :
        Types.Page.BackForwardCacheNotRestoredExplanationTree.t option;
          [@key "notRestoredExplanationsTree"]
          [@yojson.option]
          [@ocaml.doc
            "Tree structure of reasons why the page could not be cached for \
             each frame."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module LoadEventFired = struct
    let name = "Page.loadEventFired"

    type result = {
      timestamp : Types.Network.MonotonicTime.t;
          [@key "timestamp"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when same-document navigation happens, e.g. due to history API usage or anchor navigation. *)
  module NavigatedWithinDocument = struct
    let name = "Page.navigatedWithinDocument"

    type navigatedwithindocument_navigationtype =
      [ `fragment | `historyApi | `other ]

    let navigatedwithindocument_navigationtype_of_yojson = function
      | `String "fragment" -> `fragment
      | `String "historyApi" -> `historyApi
      | `String "other" -> `other
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_navigatedwithindocument_navigationtype = function
      | `fragment -> `String "fragment"
      | `historyApi -> `String "historyApi"
      | `other -> `String "other"

    type result = {
      frameId : Types.Page.FrameId.t;
          [@key "frameId"] [@ocaml.doc "Id of the frame."]
      url : string; [@key "url"] [@ocaml.doc "Frame's new url."]
      navigationType : navigatedwithindocument_navigationtype;
          [@key "navigationType"] [@ocaml.doc "Navigation type"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Compressed image data requested by the `startScreencast`. *)
  module ScreencastFrame = struct
    let name = "Page.screencastFrame"

    type result = {
      data : string;
          [@key "data"]
          [@ocaml.doc
            "Base64-encoded compressed image. (Encoded as a base64 string when \
             passed over JSON)"]
      metadata : Types.Page.ScreencastFrameMetadata.t;
          [@key "metadata"] [@ocaml.doc "Screencast frame metadata."]
      sessionId : Types.number; [@key "sessionId"] [@ocaml.doc "Frame number."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when the page with currently enabled screencast was shown or hidden `. *)
  module ScreencastVisibilityChanged = struct
    let name = "Page.screencastVisibilityChanged"

    type result = {
      visible : bool;
          [@key "visible"] [@ocaml.doc "True if the page is visible."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a new window is going to be opened, via window.open(), link click, form submission,
     etc. *)
  module WindowOpen = struct
    let name = "Page.windowOpen"

    type result = {
      url : string; [@key "url"] [@ocaml.doc "The URL for the new window."]
      windowName : string; [@key "windowName"] [@ocaml.doc "Window name."]
      windowFeatures : string list;
          [@key "windowFeatures"]
          [@ocaml.doc "An array of enabled window features."]
      userGesture : bool;
          [@key "userGesture"]
          [@ocaml.doc "Whether or not it was triggered by user gesture."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued for every compilation cache generated. Is only available
     if Page.setGenerateCompilationCache is enabled. *)
  module CompilationCacheProduced = struct
    let name = "Page.compilationCacheProduced"

    type result = {
      url : string; [@key "url"] [@ocaml.doc "No description provided"]
      data : string;
          [@key "data"]
          [@ocaml.doc
            "Base64-encoded data (Encoded as a base64 string when passed over \
             JSON)"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Performance = struct
  (* Current values of the metrics. *)
  module Metrics = struct
    let name = "Performance.metrics"

    type result = {
      metrics : Types.Performance.Metric.t list;
          [@key "metrics"] [@ocaml.doc "Current values of the metrics."]
      title : string; [@key "title"] [@ocaml.doc "Timestamp title."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module PerformanceTimeline = struct
  (* Sent when a performance timeline event is added. See reportPerformanceTimeline method. *)
  module TimelineEventAdded = struct
    let name = "PerformanceTimeline.timelineEventAdded"

    type result = {
      event : Types.PerformanceTimeline.TimelineEvent.t;
          [@key "event"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Security = struct
  (* There is a certificate error. If overriding certificate errors is enabled, then it should be
     handled with the `handleCertificateError` command. Note: this event does not fire if the
     certificate error has been allowed internally. Only one client per target should override
     certificate errors at the same time. *)
  module CertificateError = struct
    let name = "Security.certificateError"

    type result = {
      eventId : Types.number;
          [@key "eventId"] [@ocaml.doc "The ID of the event."]
      errorType : string;
          [@key "errorType"] [@ocaml.doc "The type of the error."]
      requestURL : string;
          [@key "requestURL"] [@ocaml.doc "The url that was requested."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* The security state of the page changed. *)
  module VisibleSecurityStateChanged = struct
    let name = "Security.visibleSecurityStateChanged"

    type result = {
      visibleSecurityState : Types.Security.VisibleSecurityState.t;
          [@key "visibleSecurityState"]
          [@ocaml.doc "Security state information about the page."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* The security state of the page changed. No longer being sent. *)
  module SecurityStateChanged = struct
    let name = "Security.securityStateChanged"

    type result = {
      securityState : Types.Security.SecurityState.t;
          [@key "securityState"] [@ocaml.doc "Security state."]
      schemeIsCryptographic : bool;
          [@key "schemeIsCryptographic"]
          [@ocaml.doc
            "True if the page was loaded over cryptographic transport such as \
             HTTPS."]
      explanations : Types.Security.SecurityStateExplanation.t list;
          [@key "explanations"]
          [@ocaml.doc
            "Previously a list of explanations for the security state. Now \
             always\n\
             empty."]
      insecureContentStatus : Types.Security.InsecureContentStatus.t;
          [@key "insecureContentStatus"]
          [@ocaml.doc "Information about insecure content on the page."]
      summary : string option;
          [@key "summary"]
          [@yojson.option]
          [@ocaml.doc
            "Overrides user-visible description of the state. Always omitted."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module ServiceWorker = struct
  (* No description provided *)
  module WorkerErrorReported = struct
    let name = "ServiceWorker.workerErrorReported"

    type result = {
      errorMessage : Types.ServiceWorker.ServiceWorkerErrorMessage.t;
          [@key "errorMessage"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module WorkerRegistrationUpdated = struct
    let name = "ServiceWorker.workerRegistrationUpdated"

    type result = {
      registrations : Types.ServiceWorker.ServiceWorkerRegistration.t list;
          [@key "registrations"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module WorkerVersionUpdated = struct
    let name = "ServiceWorker.workerVersionUpdated"

    type result = {
      versions : Types.ServiceWorker.ServiceWorkerVersion.t list;
          [@key "versions"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Storage = struct
  (* A cache's contents have been modified. *)
  module CacheStorageContentUpdated = struct
    let name = "Storage.cacheStorageContentUpdated"

    type result = {
      origin : string; [@key "origin"] [@ocaml.doc "Origin to update."]
      storageKey : string;
          [@key "storageKey"] [@ocaml.doc "Storage key to update."]
      bucketId : string;
          [@key "bucketId"] [@ocaml.doc "Storage bucket to update."]
      cacheName : string;
          [@key "cacheName"] [@ocaml.doc "Name of cache in origin."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* A cache has been added/deleted. *)
  module CacheStorageListUpdated = struct
    let name = "Storage.cacheStorageListUpdated"

    type result = {
      origin : string; [@key "origin"] [@ocaml.doc "Origin to update."]
      storageKey : string;
          [@key "storageKey"] [@ocaml.doc "Storage key to update."]
      bucketId : string;
          [@key "bucketId"] [@ocaml.doc "Storage bucket to update."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* The origin's IndexedDB object store has been modified. *)
  module IndexedDBContentUpdated = struct
    let name = "Storage.indexedDBContentUpdated"

    type result = {
      origin : string; [@key "origin"] [@ocaml.doc "Origin to update."]
      storageKey : string;
          [@key "storageKey"] [@ocaml.doc "Storage key to update."]
      bucketId : string;
          [@key "bucketId"] [@ocaml.doc "Storage bucket to update."]
      databaseName : string;
          [@key "databaseName"] [@ocaml.doc "Database to update."]
      objectStoreName : string;
          [@key "objectStoreName"] [@ocaml.doc "ObjectStore to update."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* The origin's IndexedDB database list has been modified. *)
  module IndexedDBListUpdated = struct
    let name = "Storage.indexedDBListUpdated"

    type result = {
      origin : string; [@key "origin"] [@ocaml.doc "Origin to update."]
      storageKey : string;
          [@key "storageKey"] [@ocaml.doc "Storage key to update."]
      bucketId : string;
          [@key "bucketId"] [@ocaml.doc "Storage bucket to update."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* One of the interest groups was accessed. Note that these events are global
     to all targets sharing an interest group store. *)
  module InterestGroupAccessed = struct
    let name = "Storage.interestGroupAccessed"

    type result = {
      accessTime : Types.Network.TimeSinceEpoch.t;
          [@key "accessTime"] [@ocaml.doc "No description provided"]
      type_ : Types.Storage.InterestGroupAccessType.t;
          [@key "type"] [@ocaml.doc "No description provided"]
      ownerOrigin : string;
          [@key "ownerOrigin"] [@ocaml.doc "No description provided"]
      name : string; [@key "name"] [@ocaml.doc "No description provided"]
      componentSellerOrigin : string option;
          [@key "componentSellerOrigin"]
          [@yojson.option]
          [@ocaml.doc
            "For topLevelBid/topLevelAdditionalBid, and when appropriate,\n\
             win and additionalBidWin"]
      bid : Types.number option;
          [@key "bid"]
          [@yojson.option]
          [@ocaml.doc
            "For bid or somethingBid event, if done locally and not on a \
             server."]
      bidCurrency : string option;
          [@key "bidCurrency"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
      uniqueAuctionId : Types.Storage.InterestGroupAuctionId.t option;
          [@key "uniqueAuctionId"]
          [@yojson.option]
          [@ocaml.doc
            "For non-global events --- links to interestGroupAuctionEvent"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* An auction involving interest groups is taking place. These events are
     target-specific. *)
  module InterestGroupAuctionEventOccurred = struct
    let name = "Storage.interestGroupAuctionEventOccurred"

    type result = {
      eventTime : Types.Network.TimeSinceEpoch.t;
          [@key "eventTime"] [@ocaml.doc "No description provided"]
      type_ : Types.Storage.InterestGroupAuctionEventType.t;
          [@key "type"] [@ocaml.doc "No description provided"]
      uniqueAuctionId : Types.Storage.InterestGroupAuctionId.t;
          [@key "uniqueAuctionId"] [@ocaml.doc "No description provided"]
      parentAuctionId : Types.Storage.InterestGroupAuctionId.t option;
          [@key "parentAuctionId"]
          [@yojson.option]
          [@ocaml.doc "Set for child auctions."]
      auctionConfig : Types.assoc option;
          [@key "auctionConfig"]
          [@yojson.option]
          [@ocaml.doc "Set for started and configResolved"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Specifies which auctions a particular network fetch may be related to, and
     in what role. Note that it is not ordered with respect to
     Network.requestWillBeSent (but will happen before loadingFinished
     loadingFailed). *)
  module InterestGroupAuctionNetworkRequestCreated = struct
    let name = "Storage.interestGroupAuctionNetworkRequestCreated"

    type result = {
      type_ : Types.Storage.InterestGroupAuctionFetchType.t;
          [@key "type"] [@ocaml.doc "No description provided"]
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "No description provided"]
      auctions : Types.Storage.InterestGroupAuctionId.t list;
          [@key "auctions"]
          [@ocaml.doc
            "This is the set of the auctions using the worklet that issued this\n\
             request.  In the case of trusted signals, it's possible that only \
             some of\n\
             them actually care about the keys being queried."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Shared storage was accessed by the associated page.
     The following parameters are included in all events. *)
  module SharedStorageAccessed = struct
    let name = "Storage.sharedStorageAccessed"

    type result = {
      accessTime : Types.Network.TimeSinceEpoch.t;
          [@key "accessTime"] [@ocaml.doc "Time of the access."]
      type_ : Types.Storage.SharedStorageAccessType.t;
          [@key "type"]
          [@ocaml.doc
            "Enum value indicating the Shared Storage API method invoked."]
      mainFrameId : Types.Page.FrameId.t;
          [@key "mainFrameId"]
          [@ocaml.doc "DevTools Frame Token for the primary frame tree's root."]
      ownerOrigin : string;
          [@key "ownerOrigin"]
          [@ocaml.doc
            "Serialized origin for the context that invoked the Shared Storage \
             API."]
      params : Types.Storage.SharedStorageAccessParams.t;
          [@key "params"]
          [@ocaml.doc
            "The sub-parameters wrapped by `params` are all optional and their\n\
             presence/absence depends on `type`."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module StorageBucketCreatedOrUpdated = struct
    let name = "Storage.storageBucketCreatedOrUpdated"

    type result = {
      bucketInfo : Types.Storage.StorageBucketInfo.t;
          [@key "bucketInfo"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module StorageBucketDeleted = struct
    let name = "Storage.storageBucketDeleted"

    type result = {
      bucketId : string; [@key "bucketId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module AttributionReportingSourceRegistered = struct
    let name = "Storage.attributionReportingSourceRegistered"

    type result = {
      registration : Types.Storage.AttributionReportingSourceRegistration.t;
          [@key "registration"] [@ocaml.doc "No description provided"]
      result : Types.Storage.AttributionReportingSourceRegistrationResult.t;
          [@key "result"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module AttributionReportingTriggerRegistered = struct
    let name = "Storage.attributionReportingTriggerRegistered"

    type result = {
      registration : Types.Storage.AttributionReportingTriggerRegistration.t;
          [@key "registration"] [@ocaml.doc "No description provided"]
      eventLevel : Types.Storage.AttributionReportingEventLevelResult.t;
          [@key "eventLevel"] [@ocaml.doc "No description provided"]
      aggregatable : Types.Storage.AttributionReportingAggregatableResult.t;
          [@key "aggregatable"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Target = struct
  (* Issued when attached to target because of auto-attach or `attachToTarget` command. *)
  module AttachedToTarget = struct
    let name = "Target.attachedToTarget"

    type result = {
      sessionId : Types.Target.SessionID.t;
          [@key "sessionId"]
          [@ocaml.doc
            "Identifier assigned to the session used to send/receive messages."]
      targetInfo : Types.Target.TargetInfo.t;
          [@key "targetInfo"] [@ocaml.doc "No description provided"]
      waitingForDebugger : bool;
          [@key "waitingForDebugger"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when detached from target for any reason (including `detachFromTarget` command). Can be
     issued multiple times per target if multiple sessions have been attached to it. *)
  module DetachedFromTarget = struct
    let name = "Target.detachedFromTarget"

    type result = {
      sessionId : Types.Target.SessionID.t;
          [@key "sessionId"] [@ocaml.doc "Detached session identifier."]
      targetId : Types.Target.TargetID.t option;
          [@key "targetId"] [@yojson.option] [@ocaml.doc "Deprecated."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies about a new protocol message received from the session (as reported in
     `attachedToTarget` event). *)
  module ReceivedMessageFromTarget = struct
    let name = "Target.receivedMessageFromTarget"

    type result = {
      sessionId : Types.Target.SessionID.t;
          [@key "sessionId"]
          [@ocaml.doc "Identifier of a session which sends a message."]
      message : string; [@key "message"] [@ocaml.doc "No description provided"]
      targetId : Types.Target.TargetID.t option;
          [@key "targetId"] [@yojson.option] [@ocaml.doc "Deprecated."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when a possible inspection target is created. *)
  module TargetCreated = struct
    let name = "Target.targetCreated"

    type result = {
      targetInfo : Types.Target.TargetInfo.t;
          [@key "targetInfo"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when a target is destroyed. *)
  module TargetDestroyed = struct
    let name = "Target.targetDestroyed"

    type result = {
      targetId : Types.Target.TargetID.t;
          [@key "targetId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when a target has crashed. *)
  module TargetCrashed = struct
    let name = "Target.targetCrashed"

    type result = {
      targetId : Types.Target.TargetID.t;
          [@key "targetId"] [@ocaml.doc "No description provided"]
      status : string; [@key "status"] [@ocaml.doc "Termination status type."]
      errorCode : Types.number;
          [@key "errorCode"] [@ocaml.doc "Termination error code."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when some information about a target has changed. This only happens between
     `targetCreated` and `targetDestroyed`. *)
  module TargetInfoChanged = struct
    let name = "Target.targetInfoChanged"

    type result = {
      targetInfo : Types.Target.TargetInfo.t;
          [@key "targetInfo"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Tethering = struct
  (* Informs that port was successfully bound and got a specified connection id. *)
  module Accepted = struct
    let name = "Tethering.accepted"

    type result = {
      port : Types.number;
          [@key "port"] [@ocaml.doc "Port number that was successfully bound."]
      connectionId : string;
          [@key "connectionId"] [@ocaml.doc "Connection id to be used."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Tracing = struct
  (* No description provided *)
  module BufferUsage = struct
    let name = "Tracing.bufferUsage"

    type result = {
      percentFull : Types.number option;
          [@key "percentFull"]
          [@yojson.option]
          [@ocaml.doc
            "A number in range [0..1] that indicates the used size of event \
             buffer as a fraction of its\n\
             total size."]
      eventCount : Types.number option;
          [@key "eventCount"]
          [@yojson.option]
          [@ocaml.doc "An approximate number of events in the trace log."]
      value : Types.number option;
          [@key "value"]
          [@yojson.option]
          [@ocaml.doc
            "A number in range [0..1] that indicates the used size of event \
             buffer as a fraction of its\n\
             total size."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Contains a bucket of collected trace events. When tracing is stopped collected events will be
     sent as a sequence of dataCollected events followed by tracingComplete event. *)
  module DataCollected = struct
    let name = "Tracing.dataCollected"

    type result = {
      value : Types.assoc list;
          [@key "value"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Signals that tracing is stopped and there is no trace buffers pending flush, all data were
     delivered via dataCollected events. *)
  module TracingComplete = struct
    let name = "Tracing.tracingComplete"

    type result = {
      dataLossOccurred : bool;
          [@key "dataLossOccurred"]
          [@ocaml.doc
            "Indicates whether some trace data is known to have been lost, \
             e.g. because the trace ring\n\
             buffer wrapped around."]
      stream : Types.IO.StreamHandle.t option;
          [@key "stream"]
          [@yojson.option]
          [@ocaml.doc "A handle of the stream that holds resulting trace data."]
      traceFormat : Types.Tracing.StreamFormat.t option;
          [@key "traceFormat"]
          [@yojson.option]
          [@ocaml.doc "Trace data format of returned stream."]
      streamCompression : Types.Tracing.StreamCompression.t option;
          [@key "streamCompression"]
          [@yojson.option]
          [@ocaml.doc "Compression format of returned stream."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Fetch = struct
  (* Issued when the domain is enabled and the request URL matches the
     specified filter. The request is paused until the client responds
     with one of continueRequest, failRequest or fulfillRequest.
     The stage of the request can be determined by presence of responseErrorReason
     and responseStatusCode -- the request is at the response stage if either
     of these fields is present and in the request stage otherwise.
     Redirect responses and subsequent requests are reported similarly to regular
     responses and requests. Redirect responses may be distinguished by the value
     of `responseStatusCode` (which is one of 301, 302, 303, 307, 308) along with
     presence of the `location` header. Requests resulting from a redirect will
     have `redirectedRequestId` field set. *)
  module RequestPaused = struct
    let name = "Fetch.requestPaused"

    type result = {
      requestId : Types.Fetch.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc "Each request the page makes will have a unique id."]
      request : Types.Network.Request.t;
          [@key "request"] [@ocaml.doc "The details of the request."]
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "The id of the frame that initiated the request."]
      resourceType : Types.Network.ResourceType.t;
          [@key "resourceType"]
          [@ocaml.doc "How the requested resource will be used."]
      responseErrorReason : Types.Network.ErrorReason.t option;
          [@key "responseErrorReason"]
          [@yojson.option]
          [@ocaml.doc "Response error if intercepted at response stage."]
      responseStatusCode : Types.number option;
          [@key "responseStatusCode"]
          [@yojson.option]
          [@ocaml.doc "Response code if intercepted at response stage."]
      responseStatusText : string option;
          [@key "responseStatusText"]
          [@yojson.option]
          [@ocaml.doc "Response status text if intercepted at response stage."]
      responseHeaders : Types.Fetch.HeaderEntry.t list option;
          [@key "responseHeaders"]
          [@yojson.option]
          [@ocaml.doc "Response headers if intercepted at the response stage."]
      networkId : Types.Network.RequestId.t option;
          [@key "networkId"]
          [@yojson.option]
          [@ocaml.doc
            "If the intercepted request had a corresponding \
             Network.requestWillBeSent event fired for it,\n\
             then this networkId will be the same as the requestId present in \
             the requestWillBeSent event."]
      redirectedRequestId : Types.Fetch.RequestId.t option;
          [@key "redirectedRequestId"]
          [@yojson.option]
          [@ocaml.doc
            "If the request is due to a redirect response from the server, the \
             id of the request that\n\
             has caused the redirect."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when the domain is enabled with handleAuthRequests set to true.
     The request is paused until client responds with continueWithAuth. *)
  module AuthRequired = struct
    let name = "Fetch.authRequired"

    type result = {
      requestId : Types.Fetch.RequestId.t;
          [@key "requestId"]
          [@ocaml.doc "Each request the page makes will have a unique id."]
      request : Types.Network.Request.t;
          [@key "request"] [@ocaml.doc "The details of the request."]
      frameId : Types.Page.FrameId.t;
          [@key "frameId"]
          [@ocaml.doc "The id of the frame that initiated the request."]
      resourceType : Types.Network.ResourceType.t;
          [@key "resourceType"]
          [@ocaml.doc "How the requested resource will be used."]
      authChallenge : Types.Fetch.AuthChallenge.t;
          [@key "authChallenge"]
          [@ocaml.doc
            "Details of the Authorization Challenge encountered.\n\
             If this is set, client should respond with continueRequest that\n\
             contains AuthChallengeResponse."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module WebAudio = struct
  (* Notifies that a new BaseAudioContext has been created. *)
  module ContextCreated = struct
    let name = "WebAudio.contextCreated"

    type result = {
      context : Types.WebAudio.BaseAudioContext.t;
          [@key "context"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that an existing BaseAudioContext will be destroyed. *)
  module ContextWillBeDestroyed = struct
    let name = "WebAudio.contextWillBeDestroyed"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that existing BaseAudioContext has changed some properties (id stays the same).. *)
  module ContextChanged = struct
    let name = "WebAudio.contextChanged"

    type result = {
      context : Types.WebAudio.BaseAudioContext.t;
          [@key "context"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that the construction of an AudioListener has finished. *)
  module AudioListenerCreated = struct
    let name = "WebAudio.audioListenerCreated"

    type result = {
      listener : Types.WebAudio.AudioListener.t;
          [@key "listener"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that a new AudioListener has been created. *)
  module AudioListenerWillBeDestroyed = struct
    let name = "WebAudio.audioListenerWillBeDestroyed"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      listenerId : Types.WebAudio.GraphObjectId.t;
          [@key "listenerId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that a new AudioNode has been created. *)
  module AudioNodeCreated = struct
    let name = "WebAudio.audioNodeCreated"

    type result = {
      node : Types.WebAudio.AudioNode.t;
          [@key "node"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that an existing AudioNode has been destroyed. *)
  module AudioNodeWillBeDestroyed = struct
    let name = "WebAudio.audioNodeWillBeDestroyed"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      nodeId : Types.WebAudio.GraphObjectId.t;
          [@key "nodeId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that a new AudioParam has been created. *)
  module AudioParamCreated = struct
    let name = "WebAudio.audioParamCreated"

    type result = {
      param : Types.WebAudio.AudioParam.t;
          [@key "param"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that an existing AudioParam has been destroyed. *)
  module AudioParamWillBeDestroyed = struct
    let name = "WebAudio.audioParamWillBeDestroyed"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      nodeId : Types.WebAudio.GraphObjectId.t;
          [@key "nodeId"] [@ocaml.doc "No description provided"]
      paramId : Types.WebAudio.GraphObjectId.t;
          [@key "paramId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that two AudioNodes are connected. *)
  module NodesConnected = struct
    let name = "WebAudio.nodesConnected"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      sourceId : Types.WebAudio.GraphObjectId.t;
          [@key "sourceId"] [@ocaml.doc "No description provided"]
      destinationId : Types.WebAudio.GraphObjectId.t;
          [@key "destinationId"] [@ocaml.doc "No description provided"]
      sourceOutputIndex : Types.number option;
          [@key "sourceOutputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
      destinationInputIndex : Types.number option;
          [@key "destinationInputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected. *)
  module NodesDisconnected = struct
    let name = "WebAudio.nodesDisconnected"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      sourceId : Types.WebAudio.GraphObjectId.t;
          [@key "sourceId"] [@ocaml.doc "No description provided"]
      destinationId : Types.WebAudio.GraphObjectId.t;
          [@key "destinationId"] [@ocaml.doc "No description provided"]
      sourceOutputIndex : Types.number option;
          [@key "sourceOutputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
      destinationInputIndex : Types.number option;
          [@key "destinationInputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that an AudioNode is connected to an AudioParam. *)
  module NodeParamConnected = struct
    let name = "WebAudio.nodeParamConnected"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      sourceId : Types.WebAudio.GraphObjectId.t;
          [@key "sourceId"] [@ocaml.doc "No description provided"]
      destinationId : Types.WebAudio.GraphObjectId.t;
          [@key "destinationId"] [@ocaml.doc "No description provided"]
      sourceOutputIndex : Types.number option;
          [@key "sourceOutputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Notifies that an AudioNode is disconnected to an AudioParam. *)
  module NodeParamDisconnected = struct
    let name = "WebAudio.nodeParamDisconnected"

    type result = {
      contextId : Types.WebAudio.GraphObjectId.t;
          [@key "contextId"] [@ocaml.doc "No description provided"]
      sourceId : Types.WebAudio.GraphObjectId.t;
          [@key "sourceId"] [@ocaml.doc "No description provided"]
      destinationId : Types.WebAudio.GraphObjectId.t;
          [@key "destinationId"] [@ocaml.doc "No description provided"]
      sourceOutputIndex : Types.number option;
          [@key "sourceOutputIndex"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module WebAuthn = struct
  (* Triggered when a credential is added to an authenticator. *)
  module CredentialAdded = struct
    let name = "WebAuthn.credentialAdded"

    type result = {
      authenticatorId : Types.WebAuthn.AuthenticatorId.t;
          [@key "authenticatorId"] [@ocaml.doc "No description provided"]
      credential : Types.WebAuthn.Credential.t;
          [@key "credential"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Triggered when a credential is deleted, e.g. through
     PublicKeyCredential.signalUnknownCredential(). *)
  module CredentialDeleted = struct
    let name = "WebAuthn.credentialDeleted"

    type result = {
      authenticatorId : Types.WebAuthn.AuthenticatorId.t;
          [@key "authenticatorId"] [@ocaml.doc "No description provided"]
      credentialId : string;
          [@key "credentialId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Triggered when a credential is updated, e.g. through
     PublicKeyCredential.signalCurrentUserDetails(). *)
  module CredentialUpdated = struct
    let name = "WebAuthn.credentialUpdated"

    type result = {
      authenticatorId : Types.WebAuthn.AuthenticatorId.t;
          [@key "authenticatorId"] [@ocaml.doc "No description provided"]
      credential : Types.WebAuthn.Credential.t;
          [@key "credential"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Triggered when a credential is used in a webauthn assertion. *)
  module CredentialAsserted = struct
    let name = "WebAuthn.credentialAsserted"

    type result = {
      authenticatorId : Types.WebAuthn.AuthenticatorId.t;
          [@key "authenticatorId"] [@ocaml.doc "No description provided"]
      credential : Types.WebAuthn.Credential.t;
          [@key "credential"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Media = struct
  (* This can be called multiple times, and can be used to set / override /
     remove player properties. A null propValue indicates removal. *)
  module PlayerPropertiesChanged = struct
    let name = "Media.playerPropertiesChanged"

    type result = {
      playerId : Types.Media.PlayerId.t;
          [@key "playerId"] [@ocaml.doc "No description provided"]
      properties : Types.Media.PlayerProperty.t list;
          [@key "properties"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Send events as a list, allowing them to be batched on the browser for less
     congestion. If batched, events must ALWAYS be in chronological order. *)
  module PlayerEventsAdded = struct
    let name = "Media.playerEventsAdded"

    type result = {
      playerId : Types.Media.PlayerId.t;
          [@key "playerId"] [@ocaml.doc "No description provided"]
      events : Types.Media.PlayerEvent.t list;
          [@key "events"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Send a list of any messages that need to be delivered. *)
  module PlayerMessagesLogged = struct
    let name = "Media.playerMessagesLogged"

    type result = {
      playerId : Types.Media.PlayerId.t;
          [@key "playerId"] [@ocaml.doc "No description provided"]
      messages : Types.Media.PlayerMessage.t list;
          [@key "messages"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Send a list of any errors that need to be delivered. *)
  module PlayerErrorsRaised = struct
    let name = "Media.playerErrorsRaised"

    type result = {
      playerId : Types.Media.PlayerId.t;
          [@key "playerId"] [@ocaml.doc "No description provided"]
      errors : Types.Media.PlayerError.t list;
          [@key "errors"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Called whenever a player is created, or when a new agent joins and receives
     a list of active players. If an agent is restored, it will receive the full
     list of player ids and all events again. *)
  module PlayersCreated = struct
    let name = "Media.playersCreated"

    type result = {
      players : Types.Media.PlayerId.t list;
          [@key "players"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module DeviceAccess = struct
  (* A device request opened a user prompt to select a device. Respond with the
     selectPrompt or cancelPrompt command. *)
  module DeviceRequestPrompted = struct
    let name = "DeviceAccess.deviceRequestPrompted"

    type result = {
      id : Types.DeviceAccess.RequestId.t;
          [@key "id"] [@ocaml.doc "No description provided"]
      devices : Types.DeviceAccess.PromptDevice.t list;
          [@key "devices"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Preload = struct
  (* Upsert. Currently, it is only emitted when a rule set added. *)
  module RuleSetUpdated = struct
    let name = "Preload.ruleSetUpdated"

    type result = {
      ruleSet : Types.Preload.RuleSet.t;
          [@key "ruleSet"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module RuleSetRemoved = struct
    let name = "Preload.ruleSetRemoved"

    type result = {
      id : Types.Preload.RuleSetId.t;
          [@key "id"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a preload enabled state is updated. *)
  module PreloadEnabledStateUpdated = struct
    let name = "Preload.preloadEnabledStateUpdated"

    type result = {
      disabledByPreference : bool;
          [@key "disabledByPreference"] [@ocaml.doc "No description provided"]
      disabledByDataSaver : bool;
          [@key "disabledByDataSaver"] [@ocaml.doc "No description provided"]
      disabledByBatterySaver : bool;
          [@key "disabledByBatterySaver"] [@ocaml.doc "No description provided"]
      disabledByHoldbackPrefetchSpeculationRules : bool;
          [@key "disabledByHoldbackPrefetchSpeculationRules"]
          [@ocaml.doc "No description provided"]
      disabledByHoldbackPrerenderSpeculationRules : bool;
          [@key "disabledByHoldbackPrerenderSpeculationRules"]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a prefetch attempt is updated. *)
  module PrefetchStatusUpdated = struct
    let name = "Preload.prefetchStatusUpdated"

    type result = {
      key : Types.Preload.PreloadingAttemptKey.t;
          [@key "key"] [@ocaml.doc "No description provided"]
      initiatingFrameId : Types.Page.FrameId.t;
          [@key "initiatingFrameId"]
          [@ocaml.doc "The frame id of the frame initiating prefetch."]
      prefetchUrl : string;
          [@key "prefetchUrl"] [@ocaml.doc "No description provided"]
      status : Types.Preload.PreloadingStatus.t;
          [@key "status"] [@ocaml.doc "No description provided"]
      prefetchStatus : Types.Preload.PrefetchStatus.t;
          [@key "prefetchStatus"] [@ocaml.doc "No description provided"]
      requestId : Types.Network.RequestId.t;
          [@key "requestId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when a prerender attempt is updated. *)
  module PrerenderStatusUpdated = struct
    let name = "Preload.prerenderStatusUpdated"

    type result = {
      key : Types.Preload.PreloadingAttemptKey.t;
          [@key "key"] [@ocaml.doc "No description provided"]
      status : Types.Preload.PreloadingStatus.t;
          [@key "status"] [@ocaml.doc "No description provided"]
      prerenderStatus : Types.Preload.PrerenderFinalStatus.t option;
          [@key "prerenderStatus"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
      disallowedMojoInterface : string option;
          [@key "disallowedMojoInterface"]
          [@yojson.option]
          [@ocaml.doc
            "This is used to give users more information about the name of \
             Mojo interface\n\
             that is incompatible with prerender and has caused the \
             cancellation of the attempt."]
      mismatchedHeaders : Types.Preload.PrerenderMismatchedHeaders.t list option;
          [@key "mismatchedHeaders"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Send a list of sources for all preloading attempts in a document. *)
  module PreloadingAttemptSourcesUpdated = struct
    let name = "Preload.preloadingAttemptSourcesUpdated"

    type result = {
      loaderId : Types.Network.LoaderId.t;
          [@key "loaderId"] [@ocaml.doc "No description provided"]
      preloadingAttemptSources : Types.Preload.PreloadingAttemptSource.t list;
          [@key "preloadingAttemptSources"]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module FedCm = struct
  (* No description provided *)
  module DialogShown = struct
    let name = "FedCm.dialogShown"

    type result = {
      dialogId : string;
          [@key "dialogId"] [@ocaml.doc "No description provided"]
      dialogType : Types.FedCm.DialogType.t;
          [@key "dialogType"] [@ocaml.doc "No description provided"]
      accounts : Types.FedCm.Account.t list;
          [@key "accounts"] [@ocaml.doc "No description provided"]
      title : string;
          [@key "title"]
          [@ocaml.doc
            "These exist primarily so that the caller can verify the\n\
             RP context was used appropriately."]
      subtitle : string option;
          [@key "subtitle"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Triggered when a dialog is closed, either by user action, JS abort,
     or a command below. *)
  module DialogClosed = struct
    let name = "FedCm.dialogClosed"

    type result = {
      dialogId : string; [@key "dialogId"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Console = struct
  (* Issued when new console message is added. *)
  module MessageAdded = struct
    let name = "Console.messageAdded"

    type result = {
      message : Types.Console.ConsoleMessage.t;
          [@key "message"] [@ocaml.doc "Console message that has been added."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Debugger = struct
  (* Fired when breakpoint is resolved to an actual script and location. *)
  module BreakpointResolved = struct
    let name = "Debugger.breakpointResolved"

    type result = {
      breakpointId : Types.Debugger.BreakpointId.t;
          [@key "breakpointId"] [@ocaml.doc "Breakpoint unique identifier."]
      location : Types.Debugger.Location.t;
          [@key "location"] [@ocaml.doc "Actual breakpoint location."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria. *)
  module Paused = struct
    let name = "Debugger.paused"

    type paused_reason =
      [ `ambiguous
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
      | `step ]

    let paused_reason_of_yojson = function
      | `String "ambiguous" -> `ambiguous
      | `String "assert" -> `assert_
      | `String "CSPViolation" -> `CSPViolation
      | `String "debugCommand" -> `debugCommand
      | `String "DOM" -> `DOM
      | `String "EventListener" -> `EventListener
      | `String "exception" -> `exception_
      | `String "instrumentation" -> `instrumentation
      | `String "OOM" -> `OOM
      | `String "other" -> `other
      | `String "promiseRejection" -> `promiseRejection
      | `String "XHR" -> `XHR
      | `String "step" -> `step
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_paused_reason = function
      | `ambiguous -> `String "ambiguous"
      | `assert_ -> `String "assert"
      | `CSPViolation -> `String "CSPViolation"
      | `debugCommand -> `String "debugCommand"
      | `DOM -> `String "DOM"
      | `EventListener -> `String "EventListener"
      | `exception_ -> `String "exception"
      | `instrumentation -> `String "instrumentation"
      | `OOM -> `String "OOM"
      | `other -> `String "other"
      | `promiseRejection -> `String "promiseRejection"
      | `XHR -> `String "XHR"
      | `step -> `String "step"

    type result = {
      callFrames : Types.Debugger.CallFrame.t list;
          [@key "callFrames"]
          [@ocaml.doc "Call stack the virtual machine stopped on."]
      reason : paused_reason; [@key "reason"] [@ocaml.doc "Pause reason."]
      data : Types.assoc option;
          [@key "data"]
          [@yojson.option]
          [@ocaml.doc "Object containing break-specific auxiliary properties."]
      hitBreakpoints : string list option;
          [@key "hitBreakpoints"]
          [@yojson.option]
          [@ocaml.doc "Hit breakpoints IDs"]
      asyncStackTrace : Types.Runtime.StackTrace.t option;
          [@key "asyncStackTrace"]
          [@yojson.option]
          [@ocaml.doc "Async stack trace, if any."]
      asyncStackTraceId : Types.Runtime.StackTraceId.t option;
          [@key "asyncStackTraceId"]
          [@yojson.option]
          [@ocaml.doc "Async stack trace, if any."]
      asyncCallStackTraceId : Types.Runtime.StackTraceId.t option;
          [@key "asyncCallStackTraceId"]
          [@yojson.option]
          [@ocaml.doc "Never present, will be removed."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when the virtual machine resumed execution. *)
  module Resumed = struct
    let name = "Debugger.resumed"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when virtual machine fails to parse the script. *)
  module ScriptFailedToParse = struct
    let name = "Debugger.scriptFailedToParse"

    type result = {
      scriptId : Types.Runtime.ScriptId.t;
          [@key "scriptId"] [@ocaml.doc "Identifier of the script parsed."]
      url : string;
          [@key "url"] [@ocaml.doc "URL or name of the script parsed (if any)."]
      startLine : Types.number;
          [@key "startLine"]
          [@ocaml.doc
            "Line offset of the script within the resource with given URL (for \
             script tags)."]
      startColumn : Types.number;
          [@key "startColumn"]
          [@ocaml.doc
            "Column offset of the script within the resource with given URL."]
      endLine : Types.number;
          [@key "endLine"] [@ocaml.doc "Last line of the script."]
      endColumn : Types.number;
          [@key "endColumn"]
          [@ocaml.doc "Length of the last line of the script."]
      executionContextId : Types.Runtime.ExecutionContextId.t;
          [@key "executionContextId"]
          [@ocaml.doc "Specifies script creation context."]
      hash : string;
          [@key "hash"] [@ocaml.doc "Content hash of the script, SHA-256."]
      executionContextAuxData : Types.assoc option;
          [@key "executionContextAuxData"]
          [@yojson.option]
          [@ocaml.doc
            "Embedder-specific auxiliary data likely matching {isDefault: \
             boolean, type: 'default'|'isolated'|'worker', frameId: string}"]
      sourceMapURL : string option;
          [@key "sourceMapURL"]
          [@yojson.option]
          [@ocaml.doc "URL of source map associated with script (if any)."]
      hasSourceURL : bool option;
          [@key "hasSourceURL"]
          [@yojson.option]
          [@ocaml.doc "True, if this script has sourceURL."]
      isModule : bool option;
          [@key "isModule"]
          [@yojson.option]
          [@ocaml.doc "True, if this script is ES6 module."]
      length : Types.number option;
          [@key "length"] [@yojson.option] [@ocaml.doc "This script length."]
      stackTrace : Types.Runtime.StackTrace.t option;
          [@key "stackTrace"]
          [@yojson.option]
          [@ocaml.doc
            "JavaScript top stack frame of where the script parsed event was \
             triggered if available."]
      codeOffset : Types.number option;
          [@key "codeOffset"]
          [@yojson.option]
          [@ocaml.doc
            "If the scriptLanguage is WebAssembly, the code section offset in \
             the module."]
      scriptLanguage : Types.Debugger.ScriptLanguage.t option;
          [@key "scriptLanguage"]
          [@yojson.option]
          [@ocaml.doc "The language of the script."]
      embedderName : string option;
          [@key "embedderName"]
          [@yojson.option]
          [@ocaml.doc "The name the embedder supplied for this script."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Fired when virtual machine parses script. This event is also fired for all known and uncollected
     scripts upon enabling debugger. *)
  module ScriptParsed = struct
    let name = "Debugger.scriptParsed"

    type result = {
      scriptId : Types.Runtime.ScriptId.t;
          [@key "scriptId"] [@ocaml.doc "Identifier of the script parsed."]
      url : string;
          [@key "url"] [@ocaml.doc "URL or name of the script parsed (if any)."]
      startLine : Types.number;
          [@key "startLine"]
          [@ocaml.doc
            "Line offset of the script within the resource with given URL (for \
             script tags)."]
      startColumn : Types.number;
          [@key "startColumn"]
          [@ocaml.doc
            "Column offset of the script within the resource with given URL."]
      endLine : Types.number;
          [@key "endLine"] [@ocaml.doc "Last line of the script."]
      endColumn : Types.number;
          [@key "endColumn"]
          [@ocaml.doc "Length of the last line of the script."]
      executionContextId : Types.Runtime.ExecutionContextId.t;
          [@key "executionContextId"]
          [@ocaml.doc "Specifies script creation context."]
      hash : string;
          [@key "hash"] [@ocaml.doc "Content hash of the script, SHA-256."]
      executionContextAuxData : Types.assoc option;
          [@key "executionContextAuxData"]
          [@yojson.option]
          [@ocaml.doc
            "Embedder-specific auxiliary data likely matching {isDefault: \
             boolean, type: 'default'|'isolated'|'worker', frameId: string}"]
      isLiveEdit : bool option;
          [@key "isLiveEdit"]
          [@yojson.option]
          [@ocaml.doc
            "True, if this script is generated as a result of the live edit \
             operation."]
      sourceMapURL : string option;
          [@key "sourceMapURL"]
          [@yojson.option]
          [@ocaml.doc "URL of source map associated with script (if any)."]
      hasSourceURL : bool option;
          [@key "hasSourceURL"]
          [@yojson.option]
          [@ocaml.doc "True, if this script has sourceURL."]
      isModule : bool option;
          [@key "isModule"]
          [@yojson.option]
          [@ocaml.doc "True, if this script is ES6 module."]
      length : Types.number option;
          [@key "length"] [@yojson.option] [@ocaml.doc "This script length."]
      stackTrace : Types.Runtime.StackTrace.t option;
          [@key "stackTrace"]
          [@yojson.option]
          [@ocaml.doc
            "JavaScript top stack frame of where the script parsed event was \
             triggered if available."]
      codeOffset : Types.number option;
          [@key "codeOffset"]
          [@yojson.option]
          [@ocaml.doc
            "If the scriptLanguage is WebAssembly, the code section offset in \
             the module."]
      scriptLanguage : Types.Debugger.ScriptLanguage.t option;
          [@key "scriptLanguage"]
          [@yojson.option]
          [@ocaml.doc "The language of the script."]
      debugSymbols : Types.Debugger.DebugSymbols.t list option;
          [@key "debugSymbols"]
          [@yojson.option]
          [@ocaml.doc
            "If the scriptLanguage is WebAssembly, the source of debug symbols \
             for the module."]
      embedderName : string option;
          [@key "embedderName"]
          [@yojson.option]
          [@ocaml.doc "The name the embedder supplied for this script."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module HeapProfiler = struct
  (* No description provided *)
  module AddHeapSnapshotChunk = struct
    let name = "HeapProfiler.addHeapSnapshotChunk"

    type result = {
      chunk : string; [@key "chunk"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* If heap objects tracking has been started then backend may send update for one or more fragments *)
  module HeapStatsUpdate = struct
    let name = "HeapProfiler.heapStatsUpdate"

    type result = {
      statsUpdate : Types.number list;
          [@key "statsUpdate"]
          [@ocaml.doc
            "An array of triplets. Each triplet describes a fragment. The \
             first integer is the fragment\n\
             index, the second integer is a total count of objects for the \
             fragment, the third integer is\n\
             a total size of the objects for the fragment."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* If heap objects tracking has been started then backend regularly sends a current value for last
     seen object id and corresponding timestamp. If the were changes in the heap since last event
     then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event. *)
  module LastSeenObjectId = struct
    let name = "HeapProfiler.lastSeenObjectId"

    type result = {
      lastSeenObjectId : Types.number;
          [@key "lastSeenObjectId"] [@ocaml.doc "No description provided"]
      timestamp : Types.number;
          [@key "timestamp"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module ReportHeapSnapshotProgress = struct
    let name = "HeapProfiler.reportHeapSnapshotProgress"

    type result = {
      done_ : Types.number; [@key "done"] [@ocaml.doc "No description provided"]
      total : Types.number;
          [@key "total"] [@ocaml.doc "No description provided"]
      finished : bool option;
          [@key "finished"]
          [@yojson.option]
          [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* No description provided *)
  module ResetProfiles = struct
    let name = "HeapProfiler.resetProfiles"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Profiler = struct
  (* No description provided *)
  module ConsoleProfileFinished = struct
    let name = "Profiler.consoleProfileFinished"

    type result = {
      id : string; [@key "id"] [@ocaml.doc "No description provided"]
      location : Types.Debugger.Location.t;
          [@key "location"] [@ocaml.doc "Location of console.profileEnd()."]
      profile : Types.Profiler.Profile.t;
          [@key "profile"] [@ocaml.doc "No description provided"]
      title : string option;
          [@key "title"]
          [@yojson.option]
          [@ocaml.doc
            "Profile title passed as an argument to console.profile()."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Sent when new profile recording is started using console.profile() call. *)
  module ConsoleProfileStarted = struct
    let name = "Profiler.consoleProfileStarted"

    type result = {
      id : string; [@key "id"] [@ocaml.doc "No description provided"]
      location : Types.Debugger.Location.t;
          [@key "location"] [@ocaml.doc "Location of console.profile()."]
      title : string option;
          [@key "title"]
          [@yojson.option]
          [@ocaml.doc
            "Profile title passed as an argument to console.profile()."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Reports coverage delta since the last poll (either from an event like this, or from
     `takePreciseCoverage` for the current isolate. May only be sent if precise code
     coverage has been started. This event can be trigged by the embedder to, for example,
     trigger collection of coverage data immediately at a certain point in time. *)
  module PreciseCoverageDeltaUpdate = struct
    let name = "Profiler.preciseCoverageDeltaUpdate"

    type result = {
      timestamp : Types.number;
          [@key "timestamp"]
          [@ocaml.doc
            "Monotonically increasing time (in seconds) when the coverage \
             update was taken in the backend."]
      occasion : string;
          [@key "occasion"]
          [@ocaml.doc "Identifier for distinguishing coverage events."]
      result : Types.Profiler.ScriptCoverage.t list;
          [@key "result"] [@ocaml.doc "Coverage data for the current isolate."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end

module Runtime = struct
  (* Notification is issued every time when binding is called. *)
  module BindingCalled = struct
    let name = "Runtime.bindingCalled"

    type result = {
      name : string; [@key "name"] [@ocaml.doc "No description provided"]
      payload : string; [@key "payload"] [@ocaml.doc "No description provided"]
      executionContextId : Types.Runtime.ExecutionContextId.t;
          [@key "executionContextId"]
          [@ocaml.doc "Identifier of the context where the call was made."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when console API was called. *)
  module ConsoleAPICalled = struct
    let name = "Runtime.consoleAPICalled"

    type consoleapicalled_type =
      [ `log
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
      | `timeEnd ]

    let consoleapicalled_type_of_yojson = function
      | `String "log" -> `log
      | `String "debug" -> `debug
      | `String "info" -> `info
      | `String "error" -> `error
      | `String "warning" -> `warning
      | `String "dir" -> `dir
      | `String "dirxml" -> `dirxml
      | `String "table" -> `table
      | `String "trace" -> `trace
      | `String "clear" -> `clear
      | `String "startGroup" -> `startGroup
      | `String "startGroupCollapsed" -> `startGroupCollapsed
      | `String "endGroup" -> `endGroup
      | `String "assert" -> `assert_
      | `String "profile" -> `profile
      | `String "profileEnd" -> `profileEnd
      | `String "count" -> `count
      | `String "timeEnd" -> `timeEnd
      | `String s -> failwith ("unknown enum: " ^ s)
      | _ -> failwith "unknown enum type"

    let yojson_of_consoleapicalled_type = function
      | `log -> `String "log"
      | `debug -> `String "debug"
      | `info -> `String "info"
      | `error -> `String "error"
      | `warning -> `String "warning"
      | `dir -> `String "dir"
      | `dirxml -> `String "dirxml"
      | `table -> `String "table"
      | `trace -> `String "trace"
      | `clear -> `String "clear"
      | `startGroup -> `String "startGroup"
      | `startGroupCollapsed -> `String "startGroupCollapsed"
      | `endGroup -> `String "endGroup"
      | `assert_ -> `String "assert"
      | `profile -> `String "profile"
      | `profileEnd -> `String "profileEnd"
      | `count -> `String "count"
      | `timeEnd -> `String "timeEnd"

    type result = {
      type_ : consoleapicalled_type;
          [@key "type"] [@ocaml.doc "Type of the call."]
      args : Types.Runtime.RemoteObject.t list;
          [@key "args"] [@ocaml.doc "Call arguments."]
      executionContextId : Types.Runtime.ExecutionContextId.t;
          [@key "executionContextId"]
          [@ocaml.doc "Identifier of the context where the call was made."]
      timestamp : Types.Runtime.Timestamp.t;
          [@key "timestamp"] [@ocaml.doc "Call timestamp."]
      stackTrace : Types.Runtime.StackTrace.t option;
          [@key "stackTrace"]
          [@yojson.option]
          [@ocaml.doc
            "Stack trace captured when the call was made. The async stack \
             chain is automatically reported for\n\
             the following call types: `assert`, `error`, `trace`, `warning`. \
             For other types the async call\n\
             chain can be retrieved using `Debugger.getStackTrace` and \
             `stackTrace.parentId` field."]
      context : string option;
          [@key "context"]
          [@yojson.option]
          [@ocaml.doc
            "Console context descriptor for calls on non-default console \
             context (not console.*):\n\
             'anonymous#unique-logger-id' for call on unnamed context, \
             'name#unique-logger-id' for call\n\
             on named context."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when unhandled exception was revoked. *)
  module ExceptionRevoked = struct
    let name = "Runtime.exceptionRevoked"

    type result = {
      reason : string;
          [@key "reason"]
          [@ocaml.doc "Reason describing why exception was revoked."]
      exceptionId : Types.number;
          [@key "exceptionId"]
          [@ocaml.doc
            "The id of revoked exception, as reported in `exceptionThrown`."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when exception was thrown and unhandled. *)
  module ExceptionThrown = struct
    let name = "Runtime.exceptionThrown"

    type result = {
      timestamp : Types.Runtime.Timestamp.t;
          [@key "timestamp"] [@ocaml.doc "Timestamp of the exception."]
      exceptionDetails : Types.Runtime.ExceptionDetails.t;
          [@key "exceptionDetails"] [@ocaml.doc "No description provided"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when new execution context is created. *)
  module ExecutionContextCreated = struct
    let name = "Runtime.executionContextCreated"

    type result = {
      context : Types.Runtime.ExecutionContextDescription.t;
          [@key "context"] [@ocaml.doc "A newly created execution context."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when execution context is destroyed. *)
  module ExecutionContextDestroyed = struct
    let name = "Runtime.executionContextDestroyed"

    type result = {
      executionContextId : Types.Runtime.ExecutionContextId.t;
          [@key "executionContextId"] [@ocaml.doc "Id of the destroyed context"]
      executionContextUniqueId : string;
          [@key "executionContextUniqueId"]
          [@ocaml.doc "Unique Id of the destroyed context"]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when all executionContexts were cleared in browser *)
  module ExecutionContextsCleared = struct
    let name = "Runtime.executionContextsCleared"

    type result = Types.empty [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end

  (* Issued when object should be inspected (for example, as a result of inspect() command line API
     call). *)
  module InspectRequested = struct
    let name = "Runtime.inspectRequested"

    type result = {
      object_ : Types.Runtime.RemoteObject.t;
          [@key "object"] [@ocaml.doc "No description provided"]
      hints : Types.assoc; [@key "hints"] [@ocaml.doc "No description provided"]
      executionContextId : Types.Runtime.ExecutionContextId.t option;
          [@key "executionContextId"]
          [@yojson.option]
          [@ocaml.doc "Identifier of the context where the call was made."]
    }
    [@@deriving yojson]

    type t = {
      method_ : string; [@key "method"]
      params : result;
      sessionId : Types.Target.SessionID.t;
    }
    [@@deriving yojson]

    let parse event = event |> Yojson.Safe.from_string |> t_of_yojson
  end
end
