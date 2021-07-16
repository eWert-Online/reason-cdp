module Accessibility = {
  /* Disables the accessibility domain. */
  module Disable = {
    let name = "Accessibility.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables the accessibility domain which causes `AXNodeId`s to remain consistent between method calls.
     This turns on accessibility for the page, which can impact performance until accessibility is disabled. */
  module Enable = {
    let name = "Accessibility.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetches the accessibility node and partial accessibility tree for this DOM node, if it exists. */
  module GetPartialAXTree = {
    let name = "Accessibility.getPartialAXTree";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to get the partial accessibility tree for. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to get the partial accessibility tree for. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper to get the partial accessibility tree for. */
      [@yojson.option]
      fetchRelatives: option(bool) /* Whether to fetch this nodes ancestors, siblings and children. Defaults to true. */,
    };

    [@deriving yojson]
    type result = {
      nodes: array(Types.Accessibility.AXNode.t) /* The `Accessibility.AXNode` for this DOM node, if it exists, plus its ancestors, siblings and
children, if requested. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetches the entire accessibility tree for the root Document */
  module GetFullAXTree = {
    let name = "Accessibility.getFullAXTree";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      max_depth: option(float) /* The maximum depth at which descendants of the root node should be retrieved.
If omitted, the full tree is returned. */,
    };

    [@deriving yojson]
    type result = {
      nodes: array(Types.Accessibility.AXNode.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetches a particular accessibility node by AXNodeId.
     Requires `enable()` to have been called previously. */
  module GetChildAXNodes = {
    let name = "Accessibility.getChildAXNodes";

    [@deriving yojson]
    type params = {
      id: Types.Accessibility.AXNodeId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      nodes: array(Types.Accessibility.AXNode.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Query a DOM node's accessibility subtree for accessible name and role.
     This command computes the name and role for all nodes in the subtree, including those that are
     ignored for accessibility, and returns those that mactch the specified name and role. If no DOM
     node is specified, or the DOM node does not exist, the command returns an error. If neither
     `accessibleName` or `role` is specified, it returns all the accessibility nodes in the subtree. */
  module QueryAXTree = {
    let name = "Accessibility.queryAXTree";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node for the root to query. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node for the root to query. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper for the root to query. */
      [@yojson.option]
      accessibleName: option(string), /* Find nodes with this computed name. */
      [@yojson.option]
      role: option(string) /* Find nodes with this computed role. */,
    };

    [@deriving yojson]
    type result = {
      nodes: array(Types.Accessibility.AXNode.t) /* A list of `Accessibility.AXNode` matching the specified attributes,
including nodes that are ignored for accessibility. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Animation = {
  /* Disables animation domain notifications. */
  module Disable = {
    let name = "Animation.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables animation domain notifications. */
  module Enable = {
    let name = "Animation.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the current time of the an animation. */
  module GetCurrentTime = {
    let name = "Animation.getCurrentTime";

    [@deriving yojson]
    type params = {id: string /* Id of animation. */};

    [@deriving yojson]
    type result = {currentTime: float /* Current time of the page. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Gets the playback rate of the document timeline. */
  module GetPlaybackRate = {
    let name = "Animation.getPlaybackRate";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      playbackRate: float /* Playback rate for animations on page. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Releases a set of animations to no longer be manipulated. */
  module ReleaseAnimations = {
    let name = "Animation.releaseAnimations";

    [@deriving yojson]
    type params = {
      animations: array(string) /* List of animation ids to seek. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Gets the remote object of the Animation. */
  module ResolveAnimation = {
    let name = "Animation.resolveAnimation";

    [@deriving yojson]
    type params = {animationId: string /* Animation id. */};

    [@deriving yojson]
    type result = {
      remoteObject: Types.Runtime.RemoteObject.t /* Corresponding remote object. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Seek a set of animations to a particular time within each animation. */
  module SeekAnimations = {
    let name = "Animation.seekAnimations";

    [@deriving yojson]
    type params = {
      animations: array(string), /* List of animation ids to seek. */
      currentTime: float /* Set the current time of each animation. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets the paused state of a set of animations. */
  module SetPaused = {
    let name = "Animation.setPaused";

    [@deriving yojson]
    type params = {
      animations: array(string), /* Animations to set the pause state of. */
      paused: bool /* Paused state to set to. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets the playback rate of the document timeline. */
  module SetPlaybackRate = {
    let name = "Animation.setPlaybackRate";

    [@deriving yojson]
    type params = {
      playbackRate: float /* Playback rate for animations on page */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets the timing of an animation node. */
  module SetTiming = {
    let name = "Animation.setTiming";

    [@deriving yojson]
    type params = {
      animationId: string, /* Animation id. */
      duration: float, /* Duration of the animation. */
      delay: float /* Delay of the animation. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module ApplicationCache = {
  /* Enables application cache domain notifications. */
  module Enable = {
    let name = "ApplicationCache.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns relevant application cache data for the document in given frame. */
  module GetApplicationCacheForFrame = {
    let name = "ApplicationCache.getApplicationCacheForFrame";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t /* Identifier of the frame containing document whose application cache is retrieved. */,
    };

    [@deriving yojson]
    type result = {
      applicationCache: Types.ApplicationCache.ApplicationCache.t /* Relevant application cache data for the document in given frame. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns array of frame identifiers with manifest urls for each frame containing a document
     associated with some application cache. */
  module GetFramesWithManifests = {
    let name = "ApplicationCache.getFramesWithManifests";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      frameIds: array(Types.ApplicationCache.FrameWithManifest.t) /* Array of frame identifiers with manifest urls for each frame containing a document
associated with some application cache. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns manifest URL for document in the given frame. */
  module GetManifestForFrame = {
    let name = "ApplicationCache.getManifestForFrame";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t /* Identifier of the frame containing document whose manifest is retrieved. */,
    };

    [@deriving yojson]
    type result = {
      manifestURL: string /* Manifest URL for document in the given frame. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Audits = {
  /* Returns the response body and size if it were re-encoded with the specified settings. Only
     applies to images. */
  module GetEncodedResponse = {
    let name = "Audits.getEncodedResponse";

    [@deriving yojson]
    type params = {
      requestId: Types.Network.RequestId.t, /* Identifier of the network request to get content for. */
      encoding: string, /* The encoding to use. */
      [@yojson.option]
      quality: option(float), /* The quality of the encoding (0-1). (defaults to 1) */
      [@yojson.option]
      sizeOnly: option(bool) /* Whether to only return the size information (defaults to false). */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      body: option(string), /* The encoded body as a base64 string. Omitted if sizeOnly is true. (Encoded as a base64 string when passed over JSON) */
      originalSize: float, /* Size before re-encoding. */
      encodedSize: float /* Size after re-encoding. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables issues domain, prevents further issues from being reported to the client. */
  module Disable = {
    let name = "Audits.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables issues domain, sends the issues collected so far to the client by means of the
     `issueAdded` event. */
  module Enable = {
    let name = "Audits.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Runs the contrast check for the target page. Found issues are reported
     using Audits.issueAdded event. */
  module CheckContrast = {
    let name = "Audits.checkContrast";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      reportAAA: option(bool) /* Whether to report WCAG AAA level issues. Default is false. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module BackgroundService = {
  /* Enables event updates for the service. */
  module StartObserving = {
    let name = "BackgroundService.startObserving";

    [@deriving yojson]
    type params = {
      service: Types.BackgroundService.ServiceName.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables event updates for the service. */
  module StopObserving = {
    let name = "BackgroundService.stopObserving";

    [@deriving yojson]
    type params = {
      service: Types.BackgroundService.ServiceName.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set the recording state for the service. */
  module SetRecording = {
    let name = "BackgroundService.setRecording";

    [@deriving yojson]
    type params = {
      shouldRecord: bool, /* No description provided */
      service: Types.BackgroundService.ServiceName.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears all stored data for the service. */
  module ClearEvents = {
    let name = "BackgroundService.clearEvents";

    [@deriving yojson]
    type params = {
      service: Types.BackgroundService.ServiceName.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Browser = {
  /* Set permission settings for given origin. */
  module SetPermission = {
    let name = "Browser.setPermission";

    [@deriving yojson]
    type params = {
      permission: Types.Browser.PermissionDescriptor.t, /* Descriptor of permission to override. */
      setting: Types.Browser.PermissionSetting.t, /* Setting of the permission. */
      [@yojson.option]
      origin: option(string), /* Origin the permission applies to, all origins if not specified. */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* Context to override. When omitted, default browser context is used. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Grant specific permissions to the given origin and reject all others. */
  module GrantPermissions = {
    let name = "Browser.grantPermissions";

    [@deriving yojson]
    type params = {
      permissions: array(Types.Browser.PermissionType.t), /* No description provided */
      [@yojson.option]
      origin: option(string), /* Origin the permission applies to, all origins if not specified. */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to override permissions. When omitted, default browser context is used. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Reset all permission management for all origins. */
  module ResetPermissions = {
    let name = "Browser.resetPermissions";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to reset permissions. When omitted, default browser context is used. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set the behavior when downloading a file. */
  module SetDownloadBehavior = {
    let name = "Browser.setDownloadBehavior";

    [@deriving yojson]
    type params = {
      behavior: string, /* Whether to allow all or deny all download requests, or use default Chrome behavior if
available (otherwise deny). |allowAndName| allows download and names files according to
their dowmload guids. */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t), /* BrowserContext to set download behavior. When omitted, default browser context is used. */
      [@yojson.option]
      downloadPath: option(string), /* The default path to save downloaded files to. This is required if behavior is set to 'allow'
or 'allowAndName'. */
      [@yojson.option]
      eventsEnabled: option(bool) /* Whether to emit download events (defaults to false). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Cancel a download if in progress */
  module CancelDownload = {
    let name = "Browser.cancelDownload";

    [@deriving yojson]
    type params = {
      guid: string, /* Global unique identifier of the download. */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to perform the action in. When omitted, default browser context is used. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Close browser gracefully. */
  module Close = {
    let name = "Browser.close";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Crashes browser on the main thread. */
  module Crash = {
    let name = "Browser.crash";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Crashes GPU process. */
  module CrashGpuProcess = {
    let name = "Browser.crashGpuProcess";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns version information. */
  module GetVersion = {
    let name = "Browser.getVersion";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      protocolVersion: string, /* Protocol version. */
      product: string, /* Product name. */
      revision: string, /* Product revision. */
      userAgent: string, /* User-Agent. */
      jsVersion: string /* V8 version. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the command line switches for the browser process if, and only if
     --enable-automation is on the commandline. */
  module GetBrowserCommandLine = {
    let name = "Browser.getBrowserCommandLine";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {arguments: array(string) /* Commandline parameters */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Get Chrome histograms. */
  module GetHistograms = {
    let name = "Browser.getHistograms";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      query: option(string), /* Requested substring in name. Only histograms which have query as a
substring in their name are extracted. An empty or absent query returns
all histograms. */
      [@yojson.option]
      delta: option(bool) /* If true, retrieve delta since last call. */,
    };

    [@deriving yojson]
    type result = {
      histograms: array(Types.Browser.Histogram.t) /* Histograms. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Get a Chrome histogram by name. */
  module GetHistogram = {
    let name = "Browser.getHistogram";

    [@deriving yojson]
    type params = {
      name: string, /* Requested histogram name. */
      [@yojson.option]
      delta: option(bool) /* If true, retrieve delta since last call. */,
    };

    [@deriving yojson]
    type result = {histogram: Types.Browser.Histogram.t /* Histogram. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Get position and size of the browser window. */
  module GetWindowBounds = {
    let name = "Browser.getWindowBounds";

    [@deriving yojson]
    type params = {
      windowId: Types.Browser.WindowID.t /* Browser window id. */,
    };

    [@deriving yojson]
    type result = {
      bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Get the browser window that contains the devtools target. */
  module GetWindowForTarget = {
    let name = "Browser.getWindowForTarget";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      targetId: option(Types.Target.TargetID.t) /* Devtools agent host id. If called as a part of the session, associated targetId is used. */,
    };

    [@deriving yojson]
    type result = {
      windowId: Types.Browser.WindowID.t, /* Browser window id. */
      bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set position and/or size of the browser window. */
  module SetWindowBounds = {
    let name = "Browser.setWindowBounds";

    [@deriving yojson]
    type params = {
      windowId: Types.Browser.WindowID.t, /* Browser window id. */
      bounds: Types.Browser.Bounds.t /* New window bounds. The 'minimized', 'maximized' and 'fullscreen' states cannot be combined
with 'left', 'top', 'width' or 'height'. Leaves unspecified fields unchanged. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set dock tile details, platform-specific. */
  module SetDockTile = {
    let name = "Browser.setDockTile";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      badgeLabel: option(string), /* No description provided */
      [@yojson.option]
      image: option(string) /* Png encoded image. (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Invoke custom browser commands used by telemetry. */
  module ExecuteBrowserCommand = {
    let name = "Browser.executeBrowserCommand";

    [@deriving yojson]
    type params = {
      commandId: Types.Browser.BrowserCommandId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module CSS = {
  /* Inserts a new rule with the given `ruleText` in a stylesheet with given `styleSheetId`, at the
     position specified by `location`. */
  module AddRule = {
    let name = "CSS.addRule";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t, /* The css style sheet identifier where a new rule should be inserted. */
      ruleText: string, /* The text of a new rule. */
      location: Types.CSS.SourceRange.t /* Text position of a new rule in the target style sheet. */,
    };

    [@deriving yojson]
    type result = {rule: Types.CSS.CSSRule.t /* The newly created rule. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all class names from specified stylesheet. */
  module CollectClassNames = {
    let name = "CSS.collectClassNames";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {classNames: array(string) /* Class name list. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates a new special "via-inspector" stylesheet in the frame with given `frameId`. */
  module CreateStyleSheet = {
    let name = "CSS.createStyleSheet";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t /* Identifier of the frame where "via-inspector" stylesheet should be created. */,
    };

    [@deriving yojson]
    type result = {
      styleSheetId: Types.CSS.StyleSheetId.t /* Identifier of the created "via-inspector" stylesheet. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables the CSS agent for the given page. */
  module Disable = {
    let name = "CSS.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables the CSS agent for the given page. Clients should not assume that the CSS agent has been
     enabled until the result of this command is received. */
  module Enable = {
    let name = "CSS.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Ensures that the given node will have specified pseudo-classes whenever its style is computed by
     the browser. */
  module ForcePseudoState = {
    let name = "CSS.forcePseudoState";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* The element id for which to force the pseudo state. */
      forcedPseudoClasses: array(string) /* Element pseudo classes to force when computing the element's style. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetBackgroundColors = {
    let name = "CSS.getBackgroundColors";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to get background colors for. */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      backgroundColors: option(array(string)), /* The range of background colors behind this element, if it contains any visible text. If no
visible text is present, this will be undefined. In the case of a flat background color,
this will consist of simply that color. In the case of a gradient, this will consist of each
of the color stops. For anything more complicated, this will be an empty array. Images will
be ignored (as if the image had failed to load). */
      [@yojson.option]
      computedFontSize: option(string), /* The computed font size for this node, as a CSS computed value string (e.g. '12px'). */
      [@yojson.option]
      computedFontWeight: option(string) /* The computed font weight for this node, as a CSS computed value string (e.g. 'normal' or
'100'). */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the computed style for a DOM node identified by `nodeId`. */
  module GetComputedStyleForNode = {
    let name = "CSS.getComputedStyleForNode";

    [@deriving yojson]
    type params = {nodeId: Types.DOM.NodeId.t /* No description provided */};

    [@deriving yojson]
    type result = {
      computedStyle: array(Types.CSS.CSSComputedStyleProperty.t) /* Computed style for the specified DOM node. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the styles defined inline (explicitly in the "style" attribute and implicitly, using DOM
     attributes) for a DOM node identified by `nodeId`. */
  module GetInlineStylesForNode = {
    let name = "CSS.getInlineStylesForNode";

    [@deriving yojson]
    type params = {nodeId: Types.DOM.NodeId.t /* No description provided */};

    [@deriving yojson]
    type result = {
      [@yojson.option]
      inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
      [@yojson.option]
      attributesStyle: option(Types.CSS.CSSStyle.t) /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns requested styles for a DOM node identified by `nodeId`. */
  module GetMatchedStylesForNode = {
    let name = "CSS.getMatchedStylesForNode";

    [@deriving yojson]
    type params = {nodeId: Types.DOM.NodeId.t /* No description provided */};

    [@deriving yojson]
    type result = {
      [@yojson.option]
      inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
      [@yojson.option]
      attributesStyle: option(Types.CSS.CSSStyle.t), /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */
      [@yojson.option]
      matchedCSSRules: option(array(Types.CSS.RuleMatch.t)), /* CSS rules matching this node, from all applicable stylesheets. */
      [@yojson.option]
      pseudoElements: option(array(Types.CSS.PseudoElementMatches.t)), /* Pseudo style matches for this node. */
      [@yojson.option]
      inherited: option(array(Types.CSS.InheritedStyleEntry.t)), /* A chain of inherited styles (from the immediate node parent up to the DOM tree root). */
      [@yojson.option]
      cssKeyframesRules: option(array(Types.CSS.CSSKeyframesRule.t)) /* A list of CSS keyframed animations matching this node. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all media queries parsed by the rendering engine. */
  module GetMediaQueries = {
    let name = "CSS.getMediaQueries";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      medias: array(Types.CSS.CSSMedia.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests information about platform fonts which we used to render child TextNodes in the given
     node. */
  module GetPlatformFontsForNode = {
    let name = "CSS.getPlatformFontsForNode";

    [@deriving yojson]
    type params = {nodeId: Types.DOM.NodeId.t /* No description provided */};

    [@deriving yojson]
    type result = {
      fonts: array(Types.CSS.PlatformFontUsage.t) /* Usage statistics for every employed platform font. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the current textual content for a stylesheet. */
  module GetStyleSheetText = {
    let name = "CSS.getStyleSheetText";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {text: string /* The stylesheet text. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Starts tracking the given computed styles for updates. The specified array of properties
     replaces the one previously specified. Pass empty array to disable tracking.
     Use takeComputedStyleUpdates to retrieve the list of nodes that had properties modified.
     The changes to computed style properties are only tracked for nodes pushed to the front-end
     by the DOM agent. If no changes to the tracked properties occur after the node has been pushed
     to the front-end, no updates will be issued for the node. */
  module TrackComputedStyleUpdates = {
    let name = "CSS.trackComputedStyleUpdates";

    [@deriving yojson]
    type params = {
      propertiesToTrack: array(Types.CSS.CSSComputedStyleProperty.t) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Polls the next batch of computed style updates. */
  module TakeComputedStyleUpdates = {
    let name = "CSS.takeComputedStyleUpdates";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      nodeIds: array(Types.DOM.NodeId.t) /* The list of node Ids that have their tracked computed styles updated */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Find a rule with the given active property for the given node and set the new value for this
     property */
  module SetEffectivePropertyValueForNode = {
    let name = "CSS.setEffectivePropertyValueForNode";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* The element id for which to set property. */
      propertyName: string, /* No description provided */
      value: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Modifies the keyframe rule key text. */
  module SetKeyframeKey = {
    let name = "CSS.setKeyframeKey";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
      range: Types.CSS.SourceRange.t, /* No description provided */
      keyText: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      keyText: Types.CSS.Value.t /* The resulting key text after modification. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Modifies the rule selector. */
  module SetMediaText = {
    let name = "CSS.setMediaText";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
      range: Types.CSS.SourceRange.t, /* No description provided */
      text: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      media: Types.CSS.CSSMedia.t /* The resulting CSS media rule after modification. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Modifies the rule selector. */
  module SetRuleSelector = {
    let name = "CSS.setRuleSelector";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
      range: Types.CSS.SourceRange.t, /* No description provided */
      selector: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      selectorList: Types.CSS.SelectorList.t /* The resulting selector list after modification. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets the new stylesheet text. */
  module SetStyleSheetText = {
    let name = "CSS.setStyleSheetText";

    [@deriving yojson]
    type params = {
      styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
      text: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      sourceMapURL: option(string) /* URL of source map associated with script (if any). */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Applies specified style edits one after another in the given order. */
  module SetStyleTexts = {
    let name = "CSS.setStyleTexts";

    [@deriving yojson]
    type params = {
      edits: array(Types.CSS.StyleDeclarationEdit.t) /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      styles: array(Types.CSS.CSSStyle.t) /* The resulting styles after modification. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables the selector recording. */
  module StartRuleUsageTracking = {
    let name = "CSS.startRuleUsageTracking";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stop tracking rule usage and return the list of rules that were used since last call to
     `takeCoverageDelta` (or since start of coverage instrumentation) */
  module StopRuleUsageTracking = {
    let name = "CSS.stopRuleUsageTracking";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      ruleUsage: array(Types.CSS.RuleUsage.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Obtain list of rules that became used since last call to this method (or since start of coverage
     instrumentation) */
  module TakeCoverageDelta = {
    let name = "CSS.takeCoverageDelta";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      coverage: array(Types.CSS.RuleUsage.t), /* No description provided */
      timestamp: float /* Monotonically increasing time, in seconds. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables/disables rendering of local CSS fonts (enabled by default). */
  module SetLocalFontsEnabled = {
    let name = "CSS.setLocalFontsEnabled";

    [@deriving yojson]
    type params = {
      enabled: bool /* Whether rendering of local fonts is enabled. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module CacheStorage = {
  /* Deletes a cache. */
  module DeleteCache = {
    let name = "CacheStorage.deleteCache";

    [@deriving yojson]
    type params = {
      cacheId: Types.CacheStorage.CacheId.t /* Id of cache for deletion. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deletes a cache entry. */
  module DeleteEntry = {
    let name = "CacheStorage.deleteEntry";

    [@deriving yojson]
    type params = {
      cacheId: Types.CacheStorage.CacheId.t, /* Id of cache where the entry will be deleted. */
      request: string /* URL spec of the request. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests cache names. */
  module RequestCacheNames = {
    let name = "CacheStorage.requestCacheNames";

    [@deriving yojson]
    type params = {securityOrigin: string /* Security origin. */};

    [@deriving yojson]
    type result = {
      caches: array(Types.CacheStorage.Cache.t) /* Caches for the security origin. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetches cache entry. */
  module RequestCachedResponse = {
    let name = "CacheStorage.requestCachedResponse";

    [@deriving yojson]
    type params = {
      cacheId: Types.CacheStorage.CacheId.t, /* Id of cache that contains the entry. */
      requestURL: string, /* URL spec of the request. */
      requestHeaders: array(Types.CacheStorage.Header.t) /* headers of the request. */,
    };

    [@deriving yojson]
    type result = {
      response: Types.CacheStorage.CachedResponse.t /* Response read from the cache. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests data from cache. */
  module RequestEntries = {
    let name = "CacheStorage.requestEntries";

    [@deriving yojson]
    type params = {
      cacheId: Types.CacheStorage.CacheId.t, /* ID of cache to get entries from. */
      [@yojson.option]
      skipCount: option(float), /* Number of records to skip. */
      [@yojson.option]
      pageSize: option(float), /* Number of records to fetch. */
      [@yojson.option]
      pathFilter: option(string) /* If present, only return the entries containing this substring in the path */,
    };

    [@deriving yojson]
    type result = {
      cacheDataEntries: array(Types.CacheStorage.DataEntry.t), /* Array of object store data entries. */
      returnCount: float /* Count of returned entries from this storage. If pathFilter is empty, it
is the count of all entries from this storage. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Cast = {
  /* Starts observing for sinks that can be used for tab mirroring, and if set,
     sinks compatible with |presentationUrl| as well. When sinks are found, a
     |sinksUpdated| event is fired.
     Also starts observing for issue messages. When an issue is added or removed,
     an |issueUpdated| event is fired. */
  module Enable = {
    let name = "Cast.enable";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      presentationUrl: option(string) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stops observing for sinks and issues. */
  module Disable = {
    let name = "Cast.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets a sink to be used when the web page requests the browser to choose a
     sink via Presentation API, Remote Playback API, or Cast SDK. */
  module SetSinkToUse = {
    let name = "Cast.setSinkToUse";

    [@deriving yojson]
    type params = {sinkName: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Starts mirroring the tab to the sink. */
  module StartTabMirroring = {
    let name = "Cast.startTabMirroring";

    [@deriving yojson]
    type params = {sinkName: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stops the active Cast session on the sink. */
  module StopCasting = {
    let name = "Cast.stopCasting";

    [@deriving yojson]
    type params = {sinkName: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Console = {
  /* Does nothing. */
  module ClearMessages = {
    let name = "Console.clearMessages";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables console domain, prevents further console messages from being reported to the client. */
  module Disable = {
    let name = "Console.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables console domain, sends the messages collected so far to the client by means of the
     `messageAdded` notification. */
  module Enable = {
    let name = "Console.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Debugger = {
  /* Continues execution until specific location is reached. */
  module ContinueToLocation = {
    let name = "Debugger.continueToLocation";

    [@deriving yojson]
    type params = {
      location: Types.Debugger.Location.t, /* Location to continue to. */
      [@yojson.option]
      targetCallFrames: option(string) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables debugger for given page. */
  module Disable = {
    let name = "Debugger.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables debugger for the given page. Clients should not assume that the debugging has been
     enabled until the result for this command is received. */
  module Enable = {
    let name = "Debugger.enable";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      maxScriptsCacheSize: option(float) /* The maximum size in bytes of collected scripts (not referenced by other heap objects)
the debugger can hold. Puts no limit if paramter is omitted. */,
    };

    [@deriving yojson]
    type result = {
      debuggerId: Types.Runtime.UniqueDebuggerId.t /* Unique identifier of the debugger. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Evaluates expression on a given call frame. */
  module EvaluateOnCallFrame = {
    let name = "Debugger.evaluateOnCallFrame";

    [@deriving yojson]
    type params = {
      callFrameId: Types.Debugger.CallFrameId.t, /* Call frame identifier to evaluate on. */
      expression: string, /* Expression to evaluate. */
      [@yojson.option]
      objectGroup: option(string), /* String object group name to put result into (allows rapid releasing resulting object handles
using `releaseObjectGroup`). */
      [@yojson.option]
      includeCommandLineAPI: option(bool), /* Specifies whether command line API should be available to the evaluated expression, defaults
to false. */
      [@yojson.option]
      silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
      [@yojson.option]
      returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
      [@yojson.option]
      generatePreview: option(bool), /* Whether preview should be generated for the result. */
      [@yojson.option]
      throwOnSideEffect: option(bool), /* Whether to throw an exception if side effect cannot be ruled out during evaluation. */
      [@yojson.option]
      timeout: option(Types.Runtime.TimeDelta.t) /* Terminate execution after timing out (number of milliseconds). */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t, /* Object wrapper for the evaluation result. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns possible locations for breakpoint. scriptId in start and end range locations should be
     the same. */
  module GetPossibleBreakpoints = {
    let name = "Debugger.getPossibleBreakpoints";

    [@deriving yojson]
    type params = {
      start: Types.Debugger.Location.t, /* Start of range to search possible breakpoint locations in. */
      [@yojson.option] [@key "end"]
      end_: option(Types.Debugger.Location.t), /* End of range to search possible breakpoint locations in (excluding). When not specified, end
of scripts is used as end of range. */
      [@yojson.option]
      restrictToFunction: option(bool) /* Only consider locations which are in the same (non-nested) function as start. */,
    };

    [@deriving yojson]
    type result = {
      locations: array(Types.Debugger.BreakLocation.t) /* List of the possible breakpoint locations. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns source for the script with given id. */
  module GetScriptSource = {
    let name = "Debugger.getScriptSource";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t /* Id of the script to get source for. */,
    };

    [@deriving yojson]
    type result = {
      scriptSource: string, /* Script source (empty in case of Wasm bytecode). */
      [@yojson.option]
      bytecode: option(string) /* Wasm bytecode. (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* This command is deprecated. Use getScriptSource instead. */
  module GetWasmBytecode = {
    let name = "Debugger.getWasmBytecode";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t /* Id of the Wasm script to get source for. */,
    };

    [@deriving yojson]
    type result = {
      bytecode: string /* Script source. (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns stack trace with given `stackTraceId`. */
  module GetStackTrace = {
    let name = "Debugger.getStackTrace";

    [@deriving yojson]
    type params = {
      stackTraceId: Types.Runtime.StackTraceId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      stackTrace: Types.Runtime.StackTrace.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stops on the next JavaScript statement. */
  module Pause = {
    let name = "Debugger.pause";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module PauseOnAsyncCall = {
    let name = "Debugger.pauseOnAsyncCall";

    [@deriving yojson]
    type params = {
      parentStackTraceId: Types.Runtime.StackTraceId.t /* Debugger will pause when async call with given stack trace is started. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes JavaScript breakpoint. */
  module RemoveBreakpoint = {
    let name = "Debugger.removeBreakpoint";

    [@deriving yojson]
    type params = {
      breakpointId: Types.Debugger.BreakpointId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Restarts particular call frame from the beginning. */
  module RestartFrame = {
    let name = "Debugger.restartFrame";

    [@deriving yojson]
    type params = {
      callFrameId: Types.Debugger.CallFrameId.t /* Call frame identifier to evaluate on. */,
    };

    [@deriving yojson]
    type result = {
      callFrames: array(Types.Debugger.CallFrame.t), /* New stack trace. */
      [@yojson.option]
      asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
      [@yojson.option]
      asyncStackTraceId: option(Types.Runtime.StackTraceId.t) /* Async stack trace, if any. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Resumes JavaScript execution. */
  module Resume = {
    let name = "Debugger.resume";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      terminateOnResume: option(bool) /* Set to true to terminate execution upon resuming execution. In contrast
to Runtime.terminateExecution, this will allows to execute further
JavaScript (i.e. via evaluation) until execution of the paused code
is actually resumed, at which point termination is triggered.
If execution is currently not paused, this parameter has no effect. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Searches for given string in script content. */
  module SearchInContent = {
    let name = "Debugger.searchInContent";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t, /* Id of the script to search in. */
      query: string, /* String to search for. */
      [@yojson.option]
      caseSensitive: option(bool), /* If true, search is case sensitive. */
      [@yojson.option]
      isRegex: option(bool) /* If true, treats string parameter as regex. */,
    };

    [@deriving yojson]
    type result = {
      result: array(Types.Debugger.SearchMatch.t) /* List of search matches. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables or disables async call stacks tracking. */
  module SetAsyncCallStackDepth = {
    let name = "Debugger.setAsyncCallStackDepth";

    [@deriving yojson]
    type params = {
      maxDepth: float /* Maximum depth of async call stacks. Setting to `0` will effectively disable collecting async
call stacks (default). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Replace previous blackbox patterns with passed ones. Forces backend to skip stepping/pausing in
     scripts with url matching one of the patterns. VM will try to leave blackboxed script by
     performing 'step in' several times, finally resorting to 'step out' if unsuccessful. */
  module SetBlackboxPatterns = {
    let name = "Debugger.setBlackboxPatterns";

    [@deriving yojson]
    type params = {
      patterns: array(string) /* Array of regexps that will be used to check script url for blackbox state. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Makes backend skip steps in the script in blackboxed ranges. VM will try leave blacklisted
     scripts by performing 'step in' several times, finally resorting to 'step out' if unsuccessful.
     Positions array contains positions where blackbox state is changed. First interval isn't
     blackboxed. Array should be sorted. */
  module SetBlackboxedRanges = {
    let name = "Debugger.setBlackboxedRanges";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t, /* Id of the script. */
      positions: array(Types.Debugger.ScriptPosition.t) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets JavaScript breakpoint at a given location. */
  module SetBreakpoint = {
    let name = "Debugger.setBreakpoint";

    [@deriving yojson]
    type params = {
      location: Types.Debugger.Location.t, /* Location to set breakpoint in. */
      [@yojson.option]
      condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will only stop on the
breakpoint if this expression evaluates to true. */,
    };

    [@deriving yojson]
    type result = {
      breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
      actualLocation: Types.Debugger.Location.t /* Location this breakpoint resolved into. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets instrumentation breakpoint. */
  module SetInstrumentationBreakpoint = {
    let name = "Debugger.setInstrumentationBreakpoint";

    [@deriving yojson]
    type params = {instrumentation: string /* Instrumentation name. */};

    [@deriving yojson]
    type result = {
      breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets JavaScript breakpoint at given location specified either by URL or URL regex. Once this
     command is issued, all existing parsed scripts will have breakpoints resolved and returned in
     `locations` property. Further matching script parsing will result in subsequent
     `breakpointResolved` events issued. This logical breakpoint will survive page reloads. */
  module SetBreakpointByUrl = {
    let name = "Debugger.setBreakpointByUrl";

    [@deriving yojson]
    type params = {
      lineNumber: float, /* Line number to set breakpoint at. */
      [@yojson.option]
      url: option(string), /* URL of the resources to set breakpoint on. */
      [@yojson.option]
      urlRegex: option(string), /* Regex pattern for the URLs of the resources to set breakpoints on. Either `url` or
`urlRegex` must be specified. */
      [@yojson.option]
      scriptHash: option(string), /* Script hash of the resources to set breakpoint on. */
      [@yojson.option]
      columnNumber: option(float), /* Offset in the line to set breakpoint at. */
      [@yojson.option]
      condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will only stop on the
breakpoint if this expression evaluates to true. */,
    };

    [@deriving yojson]
    type result = {
      breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
      locations: array(Types.Debugger.Location.t) /* List of the locations this breakpoint resolved into upon addition. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets JavaScript breakpoint before each call to the given function.
     If another function was created from the same source as a given one,
     calling it will also trigger the breakpoint. */
  module SetBreakpointOnFunctionCall = {
    let name = "Debugger.setBreakpointOnFunctionCall";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t, /* Function object id. */
      [@yojson.option]
      condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will
stop on the breakpoint if this expression evaluates to true. */,
    };

    [@deriving yojson]
    type result = {
      breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Activates / deactivates all breakpoints on the page. */
  module SetBreakpointsActive = {
    let name = "Debugger.setBreakpointsActive";

    [@deriving yojson]
    type params = {
      active: bool /* New value for breakpoints active state. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Defines pause on exceptions state. Can be set to stop on all exceptions, uncaught exceptions or
     no exceptions. Initial pause on exceptions state is `none`. */
  module SetPauseOnExceptions = {
    let name = "Debugger.setPauseOnExceptions";

    [@deriving yojson]
    type params = {state: string /* Pause on exceptions mode. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Changes return value in top frame. Available only at return break position. */
  module SetReturnValue = {
    let name = "Debugger.setReturnValue";

    [@deriving yojson]
    type params = {
      newValue: Types.Runtime.CallArgument.t /* New return value. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Edits JavaScript source live. */
  module SetScriptSource = {
    let name = "Debugger.setScriptSource";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t, /* Id of the script to edit. */
      scriptSource: string, /* New content of the script. */
      [@yojson.option]
      dryRun: option(bool) /* If true the change will not actually be applied. Dry run may be used to get result
description without actually modifying the code. */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      callFrames: option(array(Types.Debugger.CallFrame.t)), /* New stack trace in case editing has happened while VM was stopped. */
      [@yojson.option]
      stackChanged: option(bool), /* Whether current call stack  was modified after applying the changes. */
      [@yojson.option]
      asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
      [@yojson.option]
      asyncStackTraceId: option(Types.Runtime.StackTraceId.t), /* Async stack trace, if any. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if any. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Makes page not interrupt on any pauses (breakpoint, exception, dom exception etc). */
  module SetSkipAllPauses = {
    let name = "Debugger.setSkipAllPauses";

    [@deriving yojson]
    type params = {skip: bool /* New value for skip pauses state. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Changes value of variable in a callframe. Object-based scopes are not supported and must be
     mutated manually. */
  module SetVariableValue = {
    let name = "Debugger.setVariableValue";

    [@deriving yojson]
    type params = {
      scopeNumber: float, /* 0-based number of scope as was listed in scope chain. Only 'local', 'closure' and 'catch'
scope types are allowed. Other scopes could be manipulated manually. */
      variableName: string, /* Variable name. */
      newValue: Types.Runtime.CallArgument.t, /* New variable value. */
      callFrameId: Types.Debugger.CallFrameId.t /* Id of callframe that holds variable. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Steps into the function call. */
  module StepInto = {
    let name = "Debugger.stepInto";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      breakOnAsyncCall: option(bool), /* Debugger will pause on the execution of the first async task which was scheduled
before next pause. */
      [@yojson.option]
      skipList: option(array(Types.Debugger.LocationRange.t)) /* The skipList specifies location ranges that should be skipped on step into. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Steps out of the function call. */
  module StepOut = {
    let name = "Debugger.stepOut";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Steps over the statement. */
  module StepOver = {
    let name = "Debugger.stepOver";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      skipList: option(array(Types.Debugger.LocationRange.t)) /* The skipList specifies location ranges that should be skipped on step over. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module DOM = {
  /* Collects class names for the node with given id and all of it's child nodes. */
  module CollectClassNamesFromSubtree = {
    let name = "DOM.collectClassNamesFromSubtree";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to collect class names. */,
    };

    [@deriving yojson]
    type result = {classNames: array(string) /* Class name list. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates a deep copy of the specified node and places it into the target container before the
     given anchor. */
  module CopyTo = {
    let name = "DOM.copyTo";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to copy. */
      targetNodeId: Types.DOM.NodeId.t, /* Id of the element to drop the copy into. */
      [@yojson.option]
      insertBeforeNodeId: option(Types.DOM.NodeId.t) /* Drop the copy before this node (if absent, the copy becomes the last child of
`targetNodeId`). */,
    };

    [@deriving yojson]
    type result = {nodeId: Types.DOM.NodeId.t /* Id of the node clone. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Describes node given its id, does not require domain to be enabled. Does not start tracking any
     objects, can be used for automation. */
  module DescribeNode = {
    let name = "DOM.describeNode";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper. */
      [@yojson.option]
      depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
    };

    [@deriving yojson]
    type result = {node: Types.DOM.Node.t /* Node description. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Scrolls the specified rect of the given node into view if not already visible.
     Note: exactly one between nodeId, backendNodeId and objectId should be passed
     to identify the node. */
  module ScrollIntoViewIfNeeded = {
    let name = "DOM.scrollIntoViewIfNeeded";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper. */
      [@yojson.option]
      rect: option(Types.DOM.Rect.t) /* The rect to be scrolled into view, relative to the node's border box, in CSS pixels.
When omitted, center of the node will be used, similar to Element.scrollIntoView. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables DOM agent for the given page. */
  module Disable = {
    let name = "DOM.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Discards search results from the session with the given id. `getSearchResults` should no longer
     be called for that search. */
  module DiscardSearchResults = {
    let name = "DOM.discardSearchResults";

    [@deriving yojson]
    type params = {searchId: string /* Unique search session identifier. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables DOM agent for the given page. */
  module Enable = {
    let name = "DOM.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Focuses the given element. */
  module Focus = {
    let name = "DOM.focus";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns attributes for the specified node. */
  module GetAttributes = {
    let name = "DOM.getAttributes";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to retrieve attibutes for. */,
    };

    [@deriving yojson]
    type result = {
      attributes: array(string) /* An interleaved array of node attribute names and values. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns boxes for the given node. */
  module GetBoxModel = {
    let name = "DOM.getBoxModel";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = {model: Types.DOM.BoxModel.t /* Box model for the node. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns quads that describe node position on the page. This method
     might return multiple quads for inline nodes. */
  module GetContentQuads = {
    let name = "DOM.getContentQuads";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = {
      quads: array(Types.DOM.Quad.t) /* Quads that describe node layout relative to viewport. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the root DOM node (and optionally the subtree) to the caller. */
  module GetDocument = {
    let name = "DOM.getDocument";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
    };

    [@deriving yojson]
    type result = {root: Types.DOM.Node.t /* Resulting node. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the root DOM node (and optionally the subtree) to the caller.
     Deprecated, as it is not designed to work well with the rest of the DOM agent.
     Use DOMSnapshot.captureSnapshot instead. */
  module GetFlattenedDocument = {
    let name = "DOM.getFlattenedDocument";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
    };

    [@deriving yojson]
    type result = {nodes: array(Types.DOM.Node.t) /* Resulting node. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Finds nodes with a given computed style in a subtree. */
  module GetNodesForSubtreeByStyle = {
    let name = "DOM.getNodesForSubtreeByStyle";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Node ID pointing to the root of a subtree. */
      computedStyles: array(Types.DOM.CSSComputedStyleProperty.t), /* The style to filter nodes by (includes nodes if any of properties matches). */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots in the same target should be traversed when returning the
results (default is false). */,
    };

    [@deriving yojson]
    type result = {
      nodeIds: array(Types.DOM.NodeId.t) /* Resulting nodes. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns node id at given location. Depending on whether DOM domain is enabled, nodeId is
     either returned or not. */
  module GetNodeForLocation = {
    let name = "DOM.getNodeForLocation";

    [@deriving yojson]
    type params = {
      x: float, /* X coordinate. */
      y: float, /* Y coordinate. */
      [@yojson.option]
      includeUserAgentShadowDOM: option(bool), /* False to skip to the nearest non-UA shadow root ancestor (default: false). */
      [@yojson.option]
      ignorePointerEventsNone: option(bool) /* Whether to ignore pointer-events: none on elements and hit test them. */,
    };

    [@deriving yojson]
    type result = {
      backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
      frameId: Types.Page.FrameId.t, /* Frame this node belongs to. */
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns node's HTML markup. */
  module GetOuterHTML = {
    let name = "DOM.getOuterHTML";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = {outerHTML: string /* Outer HTML markup. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the id of the nearest ancestor that is a relayout boundary. */
  module GetRelayoutBoundary = {
    let name = "DOM.getRelayoutBoundary";

    [@deriving yojson]
    type params = {nodeId: Types.DOM.NodeId.t /* Id of the node. */};

    [@deriving yojson]
    type result = {
      nodeId: Types.DOM.NodeId.t /* Relayout boundary node id for the given node. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns search results from given `fromIndex` to given `toIndex` from the search with the given
     identifier. */
  module GetSearchResults = {
    let name = "DOM.getSearchResults";

    [@deriving yojson]
    type params = {
      searchId: string, /* Unique search session identifier. */
      fromIndex: float, /* Start index of the search result to be returned. */
      toIndex: float /* End index of the search result to be returned. */,
    };

    [@deriving yojson]
    type result = {
      nodeIds: array(Types.DOM.NodeId.t) /* Ids of the search result nodes. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Hides any highlight. */
  module HideHighlight = {
    let name = "DOM.hideHighlight";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights DOM node. */
  module HighlightNode = {
    let name = "DOM.highlightNode";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights given rectangle. */
  module HighlightRect = {
    let name = "DOM.highlightRect";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Marks last undoable state. */
  module MarkUndoableState = {
    let name = "DOM.markUndoableState";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Moves node into the new container, places it before the given anchor. */
  module MoveTo = {
    let name = "DOM.moveTo";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to move. */
      targetNodeId: Types.DOM.NodeId.t, /* Id of the element to drop the moved node into. */
      [@yojson.option]
      insertBeforeNodeId: option(Types.DOM.NodeId.t) /* Drop node before this one (if absent, the moved node becomes the last child of
`targetNodeId`). */,
    };

    [@deriving yojson]
    type result = {
      nodeId: Types.DOM.NodeId.t /* New id of the moved node. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Searches for a given string in the DOM tree. Use `getSearchResults` to access search results or
     `cancelSearch` to end this search session. */
  module PerformSearch = {
    let name = "DOM.performSearch";

    [@deriving yojson]
    type params = {
      query: string, /* Plain text or query selector or XPath search query. */
      [@yojson.option]
      includeUserAgentShadowDOM: option(bool) /* True to search in user agent shadow DOM. */,
    };

    [@deriving yojson]
    type result = {
      searchId: string, /* Unique search session identifier. */
      resultCount: float /* Number of search results. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that the node is sent to the caller given its path. // FIXME, use XPath */
  module PushNodeByPathToFrontend = {
    let name = "DOM.pushNodeByPathToFrontend";

    [@deriving yojson]
    type params = {
      path: string /* Path to node in the proprietary format. */,
    };

    [@deriving yojson]
    type result = {
      nodeId: Types.DOM.NodeId.t /* Id of the node for given path. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that a batch of nodes is sent to the caller given their backend node ids. */
  module PushNodesByBackendIdsToFrontend = {
    let name = "DOM.pushNodesByBackendIdsToFrontend";

    [@deriving yojson]
    type params = {
      backendNodeIds: array(Types.DOM.BackendNodeId.t) /* The array of backend node ids. */,
    };

    [@deriving yojson]
    type result = {
      nodeIds: array(Types.DOM.NodeId.t) /* The array of ids of pushed nodes that correspond to the backend ids specified in
backendNodeIds. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Executes `querySelector` on a given node. */
  module QuerySelector = {
    let name = "DOM.querySelector";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to query upon. */
      selector: string /* Selector string. */,
    };

    [@deriving yojson]
    type result = {nodeId: Types.DOM.NodeId.t /* Query selector result. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Executes `querySelectorAll` on a given node. */
  module QuerySelectorAll = {
    let name = "DOM.querySelectorAll";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to query upon. */
      selector: string /* Selector string. */,
    };

    [@deriving yojson]
    type result = {
      nodeIds: array(Types.DOM.NodeId.t) /* Query selector result. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Re-does the last undone action. */
  module Redo = {
    let name = "DOM.redo";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes attribute with given name from an element with given id. */
  module RemoveAttribute = {
    let name = "DOM.removeAttribute";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the element to remove attribute from. */
      name: string /* Name of the attribute to remove. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes node with given id. */
  module RemoveNode = {
    let name = "DOM.removeNode";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to remove. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that children of the node with given id are returned to the caller in form of
     `setChildNodes` events where not only immediate children are retrieved, but all children down to
     the specified depth. */
  module RequestChildNodes = {
    let name = "DOM.requestChildNodes";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to get children for. */
      [@yojson.option]
      depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the sub-tree
(default is false). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that the node is sent to the caller given the JavaScript node object reference. All
     nodes that form the path from the node to the root are also sent to the client as a series of
     `setChildNodes` notifications. */
  module RequestNode = {
    let name = "DOM.requestNode";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t /* JavaScript object id to convert into node. */,
    };

    [@deriving yojson]
    type result = {
      nodeId: Types.DOM.NodeId.t /* Node id for given object. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Resolves the JavaScript node object for a given NodeId or BackendNodeId. */
  module ResolveNode = {
    let name = "DOM.resolveNode";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Id of the node to resolve. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Backend identifier of the node to resolve. */
      [@yojson.option]
      objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Execution context in which to resolve the node. */,
    };

    [@deriving yojson]
    type result = {
      [@key "object"]
      object_: Types.Runtime.RemoteObject.t /* JavaScript object wrapper for given node. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets attribute for an element with given id. */
  module SetAttributeValue = {
    let name = "DOM.setAttributeValue";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the element to set attribute for. */
      name: string, /* Attribute name. */
      value: string /* Attribute value. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets attributes on element with given id. This method is useful when user edits some existing
     attribute value and types in several attribute name/value pairs. */
  module SetAttributesAsText = {
    let name = "DOM.setAttributesAsText";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the element to set attributes for. */
      text: string, /* Text with a number of attributes. Will parse this text using HTML parser. */
      [@yojson.option]
      name: option(string) /* Attribute name to replace with new attributes derived from text in case text parsed
successfully. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets files for the given file input element. */
  module SetFileInputFiles = {
    let name = "DOM.setFileInputFiles";

    [@deriving yojson]
    type params = {
      files: array(string), /* Array of file paths to set. */
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets if stack traces should be captured for Nodes. See `Node.getNodeStackTraces`. Default is disabled. */
  module SetNodeStackTracesEnabled = {
    let name = "DOM.setNodeStackTracesEnabled";

    [@deriving yojson]
    type params = {enable: bool /* Enable or disable. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Gets stack traces associated with a Node. As of now, only provides stack trace for Node creation. */
  module GetNodeStackTraces = {
    let name = "DOM.getNodeStackTraces";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to get stack traces for. */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      creation: option(Types.Runtime.StackTrace.t) /* Creation stack trace, if available. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns file information for the given
     File wrapper. */
  module GetFileInfo = {
    let name = "DOM.getFileInfo";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t /* JavaScript object id of the node wrapper. */,
    };

    [@deriving yojson]
    type result = {path: string /* No description provided */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables console to refer to the node with given id via $x (see Command Line API for more details
     $x functions). */
  module SetInspectedNode = {
    let name = "DOM.setInspectedNode";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* DOM node id to be accessible by means of $x command line API. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets node name for a node with given id. */
  module SetNodeName = {
    let name = "DOM.setNodeName";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to set name for. */
      name: string /* New node's name. */,
    };

    [@deriving yojson]
    type result = {nodeId: Types.DOM.NodeId.t /* New node's id. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets node value for a node with given id. */
  module SetNodeValue = {
    let name = "DOM.setNodeValue";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to set value for. */
      value: string /* New node's value. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets node HTML markup, returns new node id. */
  module SetOuterHTML = {
    let name = "DOM.setOuterHTML";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to set markup for. */
      outerHTML: string /* Outer HTML markup to set. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Undoes the last performed action. */
  module Undo = {
    let name = "DOM.undo";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns iframe node that owns iframe with the given domain. */
  module GetFrameOwner = {
    let name = "DOM.getFrameOwner";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module DOMDebugger = {
  /* Returns event listeners of the given object. */
  module GetEventListeners = {
    let name = "DOMDebugger.getEventListeners";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the object to return listeners for. */
      [@yojson.option]
      depth: option(float), /* The maximum depth at which Node children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
      [@yojson.option]
      pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). Reports listeners for all contexts if pierce is enabled. */,
    };

    [@deriving yojson]
    type result = {
      listeners: array(Types.DOMDebugger.EventListener.t) /* Array of relevant listeners. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes DOM breakpoint that was set using `setDOMBreakpoint`. */
  module RemoveDOMBreakpoint = {
    let name = "DOMDebugger.removeDOMBreakpoint";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Identifier of the node to remove breakpoint from. */
      [@key "type"]
      type_: Types.DOMDebugger.DOMBreakpointType.t /* Type of the breakpoint to remove. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes breakpoint on particular DOM event. */
  module RemoveEventListenerBreakpoint = {
    let name = "DOMDebugger.removeEventListenerBreakpoint";

    [@deriving yojson]
    type params = {
      eventName: string, /* Event name. */
      [@yojson.option]
      targetName: option(string) /* EventTarget interface name. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes breakpoint on particular native event. */
  module RemoveInstrumentationBreakpoint = {
    let name = "DOMDebugger.removeInstrumentationBreakpoint";

    [@deriving yojson]
    type params = {eventName: string /* Instrumentation name to stop on. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes breakpoint from XMLHttpRequest. */
  module RemoveXHRBreakpoint = {
    let name = "DOMDebugger.removeXHRBreakpoint";

    [@deriving yojson]
    type params = {url: string /* Resource URL substring. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets breakpoint on particular CSP violations. */
  module SetBreakOnCSPViolation = {
    let name = "DOMDebugger.setBreakOnCSPViolation";

    [@deriving yojson]
    type params = {
      violationTypes: array(Types.DOMDebugger.CSPViolationType.t) /* CSP Violations to stop upon. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets breakpoint on particular operation with DOM. */
  module SetDOMBreakpoint = {
    let name = "DOMDebugger.setDOMBreakpoint";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Identifier of the node to set breakpoint on. */
      [@key "type"]
      type_: Types.DOMDebugger.DOMBreakpointType.t /* Type of the operation to stop upon. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets breakpoint on particular DOM event. */
  module SetEventListenerBreakpoint = {
    let name = "DOMDebugger.setEventListenerBreakpoint";

    [@deriving yojson]
    type params = {
      eventName: string, /* DOM Event name to stop on (any DOM event will do). */
      [@yojson.option]
      targetName: option(string) /* EventTarget interface name to stop on. If equal to `"*"` or not provided, will stop on any
EventTarget. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets breakpoint on particular native event. */
  module SetInstrumentationBreakpoint = {
    let name = "DOMDebugger.setInstrumentationBreakpoint";

    [@deriving yojson]
    type params = {eventName: string /* Instrumentation name to stop on. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets breakpoint on XMLHttpRequest. */
  module SetXHRBreakpoint = {
    let name = "DOMDebugger.setXHRBreakpoint";

    [@deriving yojson]
    type params = {
      url: string /* Resource URL substring. All XHRs having this substring in the URL will get stopped upon. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module DOMSnapshot = {
  /* Disables DOM snapshot agent for the given page. */
  module Disable = {
    let name = "DOMSnapshot.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables DOM snapshot agent for the given page. */
  module Enable = {
    let name = "DOMSnapshot.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a document snapshot, including the full DOM tree of the root node (including iframes,
     template contents, and imported documents) in a flattened array, as well as layout and
     white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
     flattened. */
  module GetSnapshot = {
    let name = "DOMSnapshot.getSnapshot";

    [@deriving yojson]
    type params = {
      computedStyleWhitelist: array(string), /* Whitelist of computed styles to return. */
      [@yojson.option]
      includeEventListeners: option(bool), /* Whether or not to retrieve details of DOM listeners (default false). */
      [@yojson.option]
      includePaintOrder: option(bool), /* Whether to determine and include the paint order index of LayoutTreeNodes (default false). */
      [@yojson.option]
      includeUserAgentShadowTree: option(bool) /* Whether to include UA shadow tree in the snapshot (default false). */,
    };

    [@deriving yojson]
    type result = {
      domNodes: array(Types.DOMSnapshot.DOMNode.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
      layoutTreeNodes: array(Types.DOMSnapshot.LayoutTreeNode.t), /* The nodes in the layout tree. */
      computedStyles: array(Types.DOMSnapshot.ComputedStyle.t) /* Whitelisted ComputedStyle properties for each node in the layout tree. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a document snapshot, including the full DOM tree of the root node (including iframes,
     template contents, and imported documents) in a flattened array, as well as layout and
     white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
     flattened. */
  module CaptureSnapshot = {
    let name = "DOMSnapshot.captureSnapshot";

    [@deriving yojson]
    type params = {
      computedStyles: array(string), /* Whitelist of computed styles to return. */
      [@yojson.option]
      includePaintOrder: option(bool), /* Whether to include layout object paint orders into the snapshot. */
      [@yojson.option]
      includeDOMRects: option(bool), /* Whether to include DOM rectangles (offsetRects, clientRects, scrollRects) into the snapshot */
      [@yojson.option]
      includeBlendedBackgroundColors: option(bool), /* Whether to include blended background colors in the snapshot (default: false).
Blended background color is achieved by blending background colors of all elements
that overlap with the current element. */
      [@yojson.option]
      includeTextColorOpacities: option(bool) /* Whether to include text color opacity in the snapshot (default: false).
An element might have the opacity property set that affects the text color of the element.
The final text color opacity is computed based on the opacity of all overlapping elements. */,
    };

    [@deriving yojson]
    type result = {
      documents: array(Types.DOMSnapshot.DocumentSnapshot.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
      strings: array(string) /* Shared string table that all string properties refer to with indexes. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module DOMStorage = {
  /* No description provided */
  module Clear = {
    let name = "DOMStorage.clear";

    [@deriving yojson]
    type params = {
      storageId: Types.DOMStorage.StorageId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables storage tracking, prevents storage events from being sent to the client. */
  module Disable = {
    let name = "DOMStorage.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables storage tracking, storage events will now be delivered to the client. */
  module Enable = {
    let name = "DOMStorage.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetDOMStorageItems = {
    let name = "DOMStorage.getDOMStorageItems";

    [@deriving yojson]
    type params = {
      storageId: Types.DOMStorage.StorageId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      entries: array(Types.DOMStorage.Item.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module RemoveDOMStorageItem = {
    let name = "DOMStorage.removeDOMStorageItem";

    [@deriving yojson]
    type params = {
      storageId: Types.DOMStorage.StorageId.t, /* No description provided */
      key: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetDOMStorageItem = {
    let name = "DOMStorage.setDOMStorageItem";

    [@deriving yojson]
    type params = {
      storageId: Types.DOMStorage.StorageId.t, /* No description provided */
      key: string, /* No description provided */
      value: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Database = {
  /* Disables database tracking, prevents database events from being sent to the client. */
  module Disable = {
    let name = "Database.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables database tracking, database events will now be delivered to the client. */
  module Enable = {
    let name = "Database.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module ExecuteSQL = {
    let name = "Database.executeSQL";

    [@deriving yojson]
    type params = {
      databaseId: Types.Database.DatabaseId.t, /* No description provided */
      query: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      columnNames: option(array(string)), /* No description provided */
      [@yojson.option]
      values: option(array(string)), /* No description provided */
      [@yojson.option]
      sqlError: option(Types.Database.Error.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetDatabaseTableNames = {
    let name = "Database.getDatabaseTableNames";

    [@deriving yojson]
    type params = {
      databaseId: Types.Database.DatabaseId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {tableNames: array(string) /* No description provided */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module DeviceOrientation = {
  /* Clears the overridden Device Orientation. */
  module ClearDeviceOrientationOverride = {
    let name = "DeviceOrientation.clearDeviceOrientationOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the Device Orientation. */
  module SetDeviceOrientationOverride = {
    let name = "DeviceOrientation.setDeviceOrientationOverride";

    [@deriving yojson]
    type params = {
      alpha: float, /* Mock alpha */
      beta: float, /* Mock beta */
      gamma: float /* Mock gamma */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Emulation = {
  /* Tells whether emulation is supported. */
  module CanEmulate = {
    let name = "Emulation.canEmulate";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {result: bool /* True if emulation is supported. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears the overridden device metrics. */
  module ClearDeviceMetricsOverride = {
    let name = "Emulation.clearDeviceMetricsOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears the overridden Geolocation Position and Error. */
  module ClearGeolocationOverride = {
    let name = "Emulation.clearGeolocationOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that page scale factor is reset to initial values. */
  module ResetPageScaleFactor = {
    let name = "Emulation.resetPageScaleFactor";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables or disables simulating a focused and active page. */
  module SetFocusEmulationEnabled = {
    let name = "Emulation.setFocusEmulationEnabled";

    [@deriving yojson]
    type params = {
      enabled: bool /* Whether to enable to disable focus emulation. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables CPU throttling to emulate slow CPUs. */
  module SetCPUThrottlingRate = {
    let name = "Emulation.setCPUThrottlingRate";

    [@deriving yojson]
    type params = {
      rate: float /* Throttling rate as a slowdown factor (1 is no throttle, 2 is 2x slowdown, etc). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets or clears an override of the default background color of the frame. This override is used
     if the content does not specify one. */
  module SetDefaultBackgroundColorOverride = {
    let name = "Emulation.setDefaultBackgroundColorOverride";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      color: option(Types.DOM.RGBA.t) /* RGBA of the default background color. If not specified, any existing override will be
cleared. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the values of device screen dimensions (window.screen.width, window.screen.height,
     window.innerWidth, window.innerHeight, and "device-width"/"device-height"-related CSS media
     query results). */
  module SetDeviceMetricsOverride = {
    let name = "Emulation.setDeviceMetricsOverride";

    [@deriving yojson]
    type params = {
      width: float, /* Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
      height: float, /* Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
      deviceScaleFactor: float, /* Overriding device scale factor value. 0 disables the override. */
      mobile: bool, /* Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
autosizing and more. */
      [@yojson.option]
      scale: option(float), /* Scale to apply to resulting view image. */
      [@yojson.option]
      screenWidth: option(float), /* Overriding screen width value in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      screenHeight: option(float), /* Overriding screen height value in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      positionX: option(float), /* Overriding view X position on screen in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      positionY: option(float), /* Overriding view Y position on screen in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      dontSetVisibleSize: option(bool), /* Do not set visible view size, rely upon explicit setVisibleSize call. */
      [@yojson.option]
      screenOrientation: option(Types.Emulation.ScreenOrientation.t), /* Screen orientation override. */
      [@yojson.option]
      viewport: option(Types.Page.Viewport.t), /* If set, the visible area of the page will be overridden to this viewport. This viewport
change is not observed by the page, e.g. viewport-relative elements do not change positions. */
      [@yojson.option]
      displayFeature: option(Types.Emulation.DisplayFeature.t) /* If set, the display feature of a multi-segment screen. If not set, multi-segment support
is turned-off. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetScrollbarsHidden = {
    let name = "Emulation.setScrollbarsHidden";

    [@deriving yojson]
    type params = {
      hidden: bool /* Whether scrollbars should be always hidden. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetDocumentCookieDisabled = {
    let name = "Emulation.setDocumentCookieDisabled";

    [@deriving yojson]
    type params = {
      disabled: bool /* Whether document.coookie API should be disabled. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetEmitTouchEventsForMouse = {
    let name = "Emulation.setEmitTouchEventsForMouse";

    [@deriving yojson]
    type params = {
      enabled: bool, /* Whether touch emulation based on mouse input should be enabled. */
      [@yojson.option]
      configuration: option(string) /* Touch/gesture events configuration. Default: current platform. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Emulates the given media type or media feature for CSS media queries. */
  module SetEmulatedMedia = {
    let name = "Emulation.setEmulatedMedia";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      media: option(string), /* Media type to emulate. Empty string disables the override. */
      [@yojson.option]
      features: option(array(Types.Emulation.MediaFeature.t)) /* Media features to emulate. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Emulates the given vision deficiency. */
  module SetEmulatedVisionDeficiency = {
    let name = "Emulation.setEmulatedVisionDeficiency";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string /* Vision deficiency to emulate. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the Geolocation Position or Error. Omitting any of the parameters emulates position
     unavailable. */
  module SetGeolocationOverride = {
    let name = "Emulation.setGeolocationOverride";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      latitude: option(float), /* Mock latitude */
      [@yojson.option]
      longitude: option(float), /* Mock longitude */
      [@yojson.option]
      accuracy: option(float) /* Mock accuracy */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the Idle state. */
  module SetIdleOverride = {
    let name = "Emulation.setIdleOverride";

    [@deriving yojson]
    type params = {
      isUserActive: bool, /* Mock isUserActive */
      isScreenUnlocked: bool /* Mock isScreenUnlocked */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears Idle state overrides. */
  module ClearIdleOverride = {
    let name = "Emulation.clearIdleOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides value returned by the javascript navigator object. */
  module SetNavigatorOverrides = {
    let name = "Emulation.setNavigatorOverrides";

    [@deriving yojson]
    type params = {
      platform: string /* The platform navigator.platform should return. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets a specified page scale factor. */
  module SetPageScaleFactor = {
    let name = "Emulation.setPageScaleFactor";

    [@deriving yojson]
    type params = {pageScaleFactor: float /* Page scale factor. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Switches script execution in the page. */
  module SetScriptExecutionDisabled = {
    let name = "Emulation.setScriptExecutionDisabled";

    [@deriving yojson]
    type params = {
      value: bool /* Whether script execution should be disabled in the page. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables touch on platforms which do not support them. */
  module SetTouchEmulationEnabled = {
    let name = "Emulation.setTouchEmulationEnabled";

    [@deriving yojson]
    type params = {
      enabled: bool, /* Whether the touch event emulation should be enabled. */
      [@yojson.option]
      maxTouchPoints: option(float) /* Maximum touch points supported. Defaults to one. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Turns on virtual time for all frames (replacing real-time with a synthetic time source) and sets
     the current virtual time policy.  Note this supersedes any previous time budget. */
  module SetVirtualTimePolicy = {
    let name = "Emulation.setVirtualTimePolicy";

    [@deriving yojson]
    type params = {
      policy: Types.Emulation.VirtualTimePolicy.t, /* No description provided */
      [@yojson.option]
      budget: option(float), /* If set, after this many virtual milliseconds have elapsed virtual time will be paused and a
virtualTimeBudgetExpired event is sent. */
      [@yojson.option]
      maxVirtualTimeTaskStarvationCount: option(float), /* If set this specifies the maximum number of tasks that can be run before virtual is forced
forwards to prevent deadlock. */
      [@yojson.option]
      waitForNavigation: option(bool), /* If set the virtual time policy change should be deferred until any frame starts navigating.
Note any previous deferred policy change is superseded. */
      [@yojson.option]
      initialVirtualTime: option(Types.Network.TimeSinceEpoch.t) /* If set, base::Time::Now will be overridden to initially return this value. */,
    };

    [@deriving yojson]
    type result = {
      virtualTimeTicksBase: float /* Absolute timestamp at which virtual time was first enabled (up time in milliseconds). */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides default host system locale with the specified one. */
  module SetLocaleOverride = {
    let name = "Emulation.setLocaleOverride";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      locale: option(string) /* ICU style C locale (e.g. "en_US"). If not specified or empty, disables the override and
restores default host system locale. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides default host system timezone with the specified one. */
  module SetTimezoneOverride = {
    let name = "Emulation.setTimezoneOverride";

    [@deriving yojson]
    type params = {
      timezoneId: string /* The timezone identifier. If empty, disables the override and
restores default host system timezone. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Resizes the frame/viewport of the page. Note that this does not affect the frame's container
     (e.g. browser window). Can be used to produce screenshots of the specified size. Not supported
     on Android. */
  module SetVisibleSize = {
    let name = "Emulation.setVisibleSize";

    [@deriving yojson]
    type params = {
      width: float, /* Frame width (DIP). */
      height: float /* Frame height (DIP). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetDisabledImageTypes = {
    let name = "Emulation.setDisabledImageTypes";

    [@deriving yojson]
    type params = {
      imageTypes: array(Types.Emulation.DisabledImageType.t) /* Image types to disable. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Allows overriding user agent with the given string. */
  module SetUserAgentOverride = {
    let name = "Emulation.setUserAgentOverride";

    [@deriving yojson]
    type params = {
      userAgent: string, /* User agent to use. */
      [@yojson.option]
      acceptLanguage: option(string), /* Browser langugage to emulate. */
      [@yojson.option]
      platform: option(string), /* The platform navigator.platform should return. */
      [@yojson.option]
      userAgentMetadata: option(Types.Emulation.UserAgentMetadata.t) /* To be sent in Sec-CH-UA-* headers and returned in navigator.userAgentData */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module HeadlessExperimental = {
  /* Sends a BeginFrame to the target and returns when the frame was completed. Optionally captures a
     screenshot from the resulting frame. Requires that the target was created with enabled
     BeginFrameControl. Designed for use with --run-all-compositor-stages-before-draw, see also
     https://goo.gl/3zHXhB for more background. */
  module BeginFrame = {
    let name = "HeadlessExperimental.beginFrame";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      frameTimeTicks: option(float), /* Timestamp of this BeginFrame in Renderer TimeTicks (milliseconds of uptime). If not set,
the current time will be used. */
      [@yojson.option]
      interval: option(float), /* The interval between BeginFrames that is reported to the compositor, in milliseconds.
Defaults to a 60 frames/second interval, i.e. about 16.666 milliseconds. */
      [@yojson.option]
      noDisplayUpdates: option(bool), /* Whether updates should not be committed and drawn onto the display. False by default. If
true, only side effects of the BeginFrame will be run, such as layout and animations, but
any visual updates may not be visible on the display or in screenshots. */
      [@yojson.option]
      screenshot: option(Types.HeadlessExperimental.ScreenshotParams.t) /* If set, a screenshot of the frame will be captured and returned in the response. Otherwise,
no screenshot will be captured. Note that capturing a screenshot can fail, for example,
during renderer initialization. In such a case, no screenshot data will be returned. */,
    };

    [@deriving yojson]
    type result = {
      hasDamage: bool, /* Whether the BeginFrame resulted in damage and, thus, a new frame was committed to the
display. Reported for diagnostic uses, may be removed in the future. */
      [@yojson.option]
      screenshotData: option(string) /* Base64-encoded image data of the screenshot, if one was requested and successfully taken. (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables headless events for the target. */
  module Disable = {
    let name = "HeadlessExperimental.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables headless events for the target. */
  module Enable = {
    let name = "HeadlessExperimental.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module HeapProfiler = {
  /* Enables console to refer to the node with given id via $x (see Command Line API for more details
     $x functions). */
  module AddInspectedHeapObject = {
    let name = "HeapProfiler.addInspectedHeapObject";

    [@deriving yojson]
    type params = {
      heapObjectId: Types.HeapProfiler.HeapSnapshotObjectId.t /* Heap snapshot object id to be accessible by means of $x command line API. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module CollectGarbage = {
    let name = "HeapProfiler.collectGarbage";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Disable = {
    let name = "HeapProfiler.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Enable = {
    let name = "HeapProfiler.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetHeapObjectId = {
    let name = "HeapProfiler.getHeapObjectId";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t /* Identifier of the object to get heap object id for. */,
    };

    [@deriving yojson]
    type result = {
      heapSnapshotObjectId: Types.HeapProfiler.HeapSnapshotObjectId.t /* Id of the heap snapshot object corresponding to the passed remote object id. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetObjectByHeapObjectId = {
    let name = "HeapProfiler.getObjectByHeapObjectId";

    [@deriving yojson]
    type params = {
      objectId: Types.HeapProfiler.HeapSnapshotObjectId.t, /* No description provided */
      [@yojson.option]
      objectGroup: option(string) /* Symbolic group name that can be used to release multiple objects. */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t /* Evaluation result. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetSamplingProfile = {
    let name = "HeapProfiler.getSamplingProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      profile: Types.HeapProfiler.SamplingHeapProfile.t /* Return the sampling profile being collected. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StartSampling = {
    let name = "HeapProfiler.startSampling";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      samplingInterval: option(float) /* Average sample interval in bytes. Poisson distribution is used for the intervals. The
default value is 32768 bytes. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StartTrackingHeapObjects = {
    let name = "HeapProfiler.startTrackingHeapObjects";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      trackAllocations: option(bool) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StopSampling = {
    let name = "HeapProfiler.stopSampling";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      profile: Types.HeapProfiler.SamplingHeapProfile.t /* Recorded sampling heap profile. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StopTrackingHeapObjects = {
    let name = "HeapProfiler.stopTrackingHeapObjects";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      reportProgress: option(bool), /* If true 'reportHeapSnapshotProgress' events will be generated while snapshot is being taken
when the tracking is stopped. */
      [@yojson.option]
      treatGlobalObjectsAsRoots: option(bool) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module TakeHeapSnapshot = {
    let name = "HeapProfiler.takeHeapSnapshot";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      reportProgress: option(bool), /* If true 'reportHeapSnapshotProgress' events will be generated while snapshot is being taken. */
      [@yojson.option]
      treatGlobalObjectsAsRoots: option(bool) /* If true, a raw snapshot without artifical roots will be generated */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module IO = {
  /* Close the stream, discard any temporary backing storage. */
  module Close = {
    let name = "IO.close";

    [@deriving yojson]
    type params = {
      handle: Types.IO.StreamHandle.t /* Handle of the stream to close. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Read a chunk of the stream */
  module Read = {
    let name = "IO.read";

    [@deriving yojson]
    type params = {
      handle: Types.IO.StreamHandle.t, /* Handle of the stream to read. */
      [@yojson.option]
      offset: option(float), /* Seek to the specified offset before reading (if not specificed, proceed with offset
following the last read). Some types of streams may only support sequential reads. */
      [@yojson.option]
      size: option(float) /* Maximum number of bytes to read (left upon the agent discretion if not specified). */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      base64Encoded: option(bool), /* Set if the data is base64-encoded */
      data: string, /* Data that were read. */
      eof: bool /* Set if the end-of-file condition occurred while reading. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Return UUID of Blob object specified by a remote object id. */
  module ResolveBlob = {
    let name = "IO.resolveBlob";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t /* Object id of a Blob object wrapper. */,
    };

    [@deriving yojson]
    type result = {uuid: string /* UUID of the specified Blob. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module IndexedDB = {
  /* Clears all entries from an object store. */
  module ClearObjectStore = {
    let name = "IndexedDB.clearObjectStore";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* Security origin. */
      databaseName: string, /* Database name. */
      objectStoreName: string /* Object store name. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deletes a database. */
  module DeleteDatabase = {
    let name = "IndexedDB.deleteDatabase";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* Security origin. */
      databaseName: string /* Database name. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Delete a range of entries from an object store */
  module DeleteObjectStoreEntries = {
    let name = "IndexedDB.deleteObjectStoreEntries";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* No description provided */
      databaseName: string, /* No description provided */
      objectStoreName: string, /* No description provided */
      keyRange: Types.IndexedDB.KeyRange.t /* Range of entry keys to delete */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables events from backend. */
  module Disable = {
    let name = "IndexedDB.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables events from backend. */
  module Enable = {
    let name = "IndexedDB.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests data from object store or index. */
  module RequestData = {
    let name = "IndexedDB.requestData";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* Security origin. */
      databaseName: string, /* Database name. */
      objectStoreName: string, /* Object store name. */
      indexName: string, /* Index name, empty string for object store data requests. */
      skipCount: float, /* Number of records to skip. */
      pageSize: float, /* Number of records to fetch. */
      [@yojson.option]
      keyRange: option(Types.IndexedDB.KeyRange.t) /* Key range. */,
    };

    [@deriving yojson]
    type result = {
      objectStoreDataEntries: array(Types.IndexedDB.DataEntry.t), /* Array of object store data entries. */
      hasMore: bool /* If true, there are more entries to fetch in the given range. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Gets metadata of an object store */
  module GetMetadata = {
    let name = "IndexedDB.getMetadata";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* Security origin. */
      databaseName: string, /* Database name. */
      objectStoreName: string /* Object store name. */,
    };

    [@deriving yojson]
    type result = {
      entriesCount: float, /* the entries count */
      keyGeneratorValue: float /* the current value of key generator, to become the next inserted
key into the object store. Valid if objectStore.autoIncrement
is true. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests database with given name in given frame. */
  module RequestDatabase = {
    let name = "IndexedDB.requestDatabase";

    [@deriving yojson]
    type params = {
      securityOrigin: string, /* Security origin. */
      databaseName: string /* Database name. */,
    };

    [@deriving yojson]
    type result = {
      databaseWithObjectStores: Types.IndexedDB.DatabaseWithObjectStores.t /* Database with an array of object stores. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests database names for given security origin. */
  module RequestDatabaseNames = {
    let name = "IndexedDB.requestDatabaseNames";

    [@deriving yojson]
    type params = {securityOrigin: string /* Security origin. */};

    [@deriving yojson]
    type result = {
      databaseNames: array(string) /* Database names for origin. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Input = {
  /* Dispatches a drag event into the page. */
  module DispatchDragEvent = {
    let name = "Input.dispatchDragEvent";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string, /* Type of the drag event. */
      x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
      y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
      data: Types.Input.DragData.t, /* No description provided */
      [@yojson.option]
      modifiers: option(float) /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Dispatches a key event to the page. */
  module DispatchKeyEvent = {
    let name = "Input.dispatchKeyEvent";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string, /* Type of the key event. */
      [@yojson.option]
      modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
      [@yojson.option]
      timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred. */
      [@yojson.option]
      text: option(string), /* Text as generated by processing a virtual key code with a keyboard layout. Not needed for
for `keyUp` and `rawKeyDown` events (default: "") */
      [@yojson.option]
      unmodifiedText: option(string), /* Text that would have been generated by the keyboard if no modifiers were pressed (except for
shift). Useful for shortcut (accelerator) key handling (default: ""). */
      [@yojson.option]
      keyIdentifier: option(string), /* Unique key identifier (e.g., 'U+0041') (default: ""). */
      [@yojson.option]
      code: option(string), /* Unique DOM defined string value for each physical key (e.g., 'KeyA') (default: ""). */
      [@yojson.option]
      key: option(string), /* Unique DOM defined string value describing the meaning of the key in the context of active
modifiers, keyboard layout, etc (e.g., 'AltGr') (default: ""). */
      [@yojson.option]
      windowsVirtualKeyCode: option(float), /* Windows virtual key code (default: 0). */
      [@yojson.option]
      nativeVirtualKeyCode: option(float), /* Native virtual key code (default: 0). */
      [@yojson.option]
      autoRepeat: option(bool), /* Whether the event was generated from auto repeat (default: false). */
      [@yojson.option]
      isKeypad: option(bool), /* Whether the event was generated from the keypad (default: false). */
      [@yojson.option]
      isSystemKey: option(bool), /* Whether the event was a system key event (default: false). */
      [@yojson.option]
      location: option(float), /* Whether the event was from the left or right side of the keyboard. 1=Left, 2=Right (default:
0). */
      [@yojson.option]
      commands: option(array(string)) /* Editing commands to send with the key event (e.g., 'selectAll') (default: []).
These are related to but not equal the command names used in `document.execCommand` and NSStandardKeyBindingResponding.
See https://source.chromium.org/chromium/chromium/src/+/master:third_party/blink/renderer/core/editing/commands/editor_command_names.h for valid command names. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* This method emulates inserting text that doesn't come from a key press,
     for example an emoji keyboard or an IME. */
  module InsertText = {
    let name = "Input.insertText";

    [@deriving yojson]
    type params = {text: string /* The text to insert. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Dispatches a mouse event to the page. */
  module DispatchMouseEvent = {
    let name = "Input.dispatchMouseEvent";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string, /* Type of the mouse event. */
      x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
      y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
      [@yojson.option]
      modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
      [@yojson.option]
      timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred. */
      [@yojson.option]
      button: option(Types.Input.MouseButton.t), /* Mouse button (default: "none"). */
      [@yojson.option]
      buttons: option(float), /* A number indicating which buttons are pressed on the mouse when a mouse event is triggered.
Left=1, Right=2, Middle=4, Back=8, Forward=16, None=0. */
      [@yojson.option]
      clickCount: option(float), /* Number of times the mouse button was clicked (default: 0). */
      [@yojson.option]
      force: option(float), /* The normalized pressure, which has a range of [0,1] (default: 0). */
      [@yojson.option]
      tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
      [@yojson.option]
      tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0). */
      [@yojson.option]
      tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
      [@yojson.option]
      twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
      [@yojson.option]
      deltaX: option(float), /* X delta in CSS pixels for mouse wheel event (default: 0). */
      [@yojson.option]
      deltaY: option(float), /* Y delta in CSS pixels for mouse wheel event (default: 0). */
      [@yojson.option]
      pointerType: option(string) /* Pointer type (default: "mouse"). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Dispatches a touch event to the page. */
  module DispatchTouchEvent = {
    let name = "Input.dispatchTouchEvent";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string, /* Type of the touch event. TouchEnd and TouchCancel must not contain any touch points, while
TouchStart and TouchMove must contains at least one. */
      touchPoints: array(Types.Input.TouchPoint.t), /* Active touch points on the touch device. One event per any changed point (compared to
previous touch event in a sequence) is generated, emulating pressing/moving/releasing points
one by one. */
      [@yojson.option]
      modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
      [@yojson.option]
      timestamp: option(Types.Input.TimeSinceEpoch.t) /* Time at which the event occurred. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Emulates touch event from the mouse event parameters. */
  module EmulateTouchFromMouseEvent = {
    let name = "Input.emulateTouchFromMouseEvent";

    [@deriving yojson]
    type params = {
      [@key "type"]
      type_: string, /* Type of the mouse event. */
      x: float, /* X coordinate of the mouse pointer in DIP. */
      y: float, /* Y coordinate of the mouse pointer in DIP. */
      button: Types.Input.MouseButton.t, /* Mouse button. Only "none", "left", "right" are supported. */
      [@yojson.option]
      timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred (default: current time). */
      [@yojson.option]
      deltaX: option(float), /* X delta in DIP for mouse wheel event (default: 0). */
      [@yojson.option]
      deltaY: option(float), /* Y delta in DIP for mouse wheel event (default: 0). */
      [@yojson.option]
      modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
      [@yojson.option]
      clickCount: option(float) /* Number of times the mouse button was clicked (default: 0). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Ignores input events (useful while auditing page). */
  module SetIgnoreInputEvents = {
    let name = "Input.setIgnoreInputEvents";

    [@deriving yojson]
    type params = {
      ignore: bool /* Ignores input events processing when set to true. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Prevents default drag and drop behavior and instead emits `Input.dragIntercepted` events.
     Drag and drop behavior can be directly controlled via `Input.dispatchDragEvent`. */
  module SetInterceptDrags = {
    let name = "Input.setInterceptDrags";

    [@deriving yojson]
    type params = {enabled: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Synthesizes a pinch gesture over a time period by issuing appropriate touch events. */
  module SynthesizePinchGesture = {
    let name = "Input.synthesizePinchGesture";

    [@deriving yojson]
    type params = {
      x: float, /* X coordinate of the start of the gesture in CSS pixels. */
      y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
      scaleFactor: float, /* Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out). */
      [@yojson.option]
      relativeSpeed: option(float), /* Relative pointer speed in pixels per second (default: 800). */
      [@yojson.option]
      gestureSourceType: option(Types.Input.GestureSourceType.t) /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Synthesizes a scroll gesture over a time period by issuing appropriate touch events. */
  module SynthesizeScrollGesture = {
    let name = "Input.synthesizeScrollGesture";

    [@deriving yojson]
    type params = {
      x: float, /* X coordinate of the start of the gesture in CSS pixels. */
      y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
      [@yojson.option]
      xDistance: option(float), /* The distance to scroll along the X axis (positive to scroll left). */
      [@yojson.option]
      yDistance: option(float), /* The distance to scroll along the Y axis (positive to scroll up). */
      [@yojson.option]
      xOverscroll: option(float), /* The number of additional pixels to scroll back along the X axis, in addition to the given
distance. */
      [@yojson.option]
      yOverscroll: option(float), /* The number of additional pixels to scroll back along the Y axis, in addition to the given
distance. */
      [@yojson.option]
      preventFling: option(bool), /* Prevent fling (default: true). */
      [@yojson.option]
      speed: option(float), /* Swipe speed in pixels per second (default: 800). */
      [@yojson.option]
      gestureSourceType: option(Types.Input.GestureSourceType.t), /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */
      [@yojson.option]
      repeatCount: option(float), /* The number of times to repeat the gesture (default: 0). */
      [@yojson.option]
      repeatDelayMs: option(float), /* The number of milliseconds delay between each repeat. (default: 250). */
      [@yojson.option]
      interactionMarkerName: option(string) /* The name of the interaction markers to generate, if not empty (default: ""). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Synthesizes a tap gesture over a time period by issuing appropriate touch events. */
  module SynthesizeTapGesture = {
    let name = "Input.synthesizeTapGesture";

    [@deriving yojson]
    type params = {
      x: float, /* X coordinate of the start of the gesture in CSS pixels. */
      y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
      [@yojson.option]
      duration: option(float), /* Duration between touchdown and touchup events in ms (default: 50). */
      [@yojson.option]
      tapCount: option(float), /* Number of times to perform the tap (e.g. 2 for double tap, default: 1). */
      [@yojson.option]
      gestureSourceType: option(Types.Input.GestureSourceType.t) /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Inspector = {
  /* Disables inspector domain notifications. */
  module Disable = {
    let name = "Inspector.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables inspector domain notifications. */
  module Enable = {
    let name = "Inspector.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module LayerTree = {
  /* Provides the reasons why the given layer was composited. */
  module CompositingReasons = {
    let name = "LayerTree.compositingReasons";

    [@deriving yojson]
    type params = {
      layerId: Types.LayerTree.LayerId.t /* The id of the layer for which we want to get the reasons it was composited. */,
    };

    [@deriving yojson]
    type result = {
      compositingReasons: array(string), /* A list of strings specifying reasons for the given layer to become composited. */
      compositingReasonIds: array(string) /* A list of strings specifying reason IDs for the given layer to become composited. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables compositing tree inspection. */
  module Disable = {
    let name = "LayerTree.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables compositing tree inspection. */
  module Enable = {
    let name = "LayerTree.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the snapshot identifier. */
  module LoadSnapshot = {
    let name = "LayerTree.loadSnapshot";

    [@deriving yojson]
    type params = {
      tiles: array(Types.LayerTree.PictureTile.t) /* An array of tiles composing the snapshot. */,
    };

    [@deriving yojson]
    type result = {
      snapshotId: Types.LayerTree.SnapshotId.t /* The id of the snapshot. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the layer snapshot identifier. */
  module MakeSnapshot = {
    let name = "LayerTree.makeSnapshot";

    [@deriving yojson]
    type params = {
      layerId: Types.LayerTree.LayerId.t /* The id of the layer. */,
    };

    [@deriving yojson]
    type result = {
      snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module ProfileSnapshot = {
    let name = "LayerTree.profileSnapshot";

    [@deriving yojson]
    type params = {
      snapshotId: Types.LayerTree.SnapshotId.t, /* The id of the layer snapshot. */
      [@yojson.option]
      minRepeatCount: option(float), /* The maximum number of times to replay the snapshot (1, if not specified). */
      [@yojson.option]
      minDuration: option(float), /* The minimum duration (in seconds) to replay the snapshot. */
      [@yojson.option]
      clipRect: option(Types.DOM.Rect.t) /* The clip rectangle to apply when replaying the snapshot. */,
    };

    [@deriving yojson]
    type result = {
      timings: array(Types.LayerTree.PaintProfile.t) /* The array of paint profiles, one per run. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Releases layer snapshot captured by the back-end. */
  module ReleaseSnapshot = {
    let name = "LayerTree.releaseSnapshot";

    [@deriving yojson]
    type params = {
      snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Replays the layer snapshot and returns the resulting bitmap. */
  module ReplaySnapshot = {
    let name = "LayerTree.replaySnapshot";

    [@deriving yojson]
    type params = {
      snapshotId: Types.LayerTree.SnapshotId.t, /* The id of the layer snapshot. */
      [@yojson.option]
      fromStep: option(float), /* The first step to replay from (replay from the very start if not specified). */
      [@yojson.option]
      toStep: option(float), /* The last step to replay to (replay till the end if not specified). */
      [@yojson.option]
      scale: option(float) /* The scale to apply while replaying (defaults to 1). */,
    };

    [@deriving yojson]
    type result = {dataURL: string /* A data: URL for resulting image. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Replays the layer snapshot and returns canvas log. */
  module SnapshotCommandLog = {
    let name = "LayerTree.snapshotCommandLog";

    [@deriving yojson]
    type params = {
      snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
    };

    [@deriving yojson]
    type result = {
      commandLog: array(Types.assoc) /* The array of canvas function calls. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Log = {
  /* Clears the log. */
  module Clear = {
    let name = "Log.clear";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables log domain, prevents further log entries from being reported to the client. */
  module Disable = {
    let name = "Log.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables log domain, sends the entries collected so far to the client by means of the
     `entryAdded` notification. */
  module Enable = {
    let name = "Log.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* start violation reporting. */
  module StartViolationsReport = {
    let name = "Log.startViolationsReport";

    [@deriving yojson]
    type params = {
      config: array(Types.Log.ViolationSetting.t) /* Configuration for violations. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stop violation reporting. */
  module StopViolationsReport = {
    let name = "Log.stopViolationsReport";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Memory = {
  /* No description provided */
  module GetDOMCounters = {
    let name = "Memory.getDOMCounters";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      documents: float, /* No description provided */
      nodes: float, /* No description provided */
      jsEventListeners: float /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module PrepareForLeakDetection = {
    let name = "Memory.prepareForLeakDetection";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Simulate OomIntervention by purging V8 memory. */
  module ForciblyPurgeJavaScriptMemory = {
    let name = "Memory.forciblyPurgeJavaScriptMemory";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable/disable suppressing memory pressure notifications in all processes. */
  module SetPressureNotificationsSuppressed = {
    let name = "Memory.setPressureNotificationsSuppressed";

    [@deriving yojson]
    type params = {
      suppressed: bool /* If true, memory pressure notifications will be suppressed. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Simulate a memory pressure notification in all processes. */
  module SimulatePressureNotification = {
    let name = "Memory.simulatePressureNotification";

    [@deriving yojson]
    type params = {
      level: Types.Memory.PressureLevel.t /* Memory pressure level of the notification. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Start collecting native memory profile. */
  module StartSampling = {
    let name = "Memory.startSampling";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      samplingInterval: option(float), /* Average number of bytes between samples. */
      [@yojson.option]
      suppressRandomness: option(bool) /* Do not randomize intervals between samples. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stop collecting native memory profile. */
  module StopSampling = {
    let name = "Memory.stopSampling";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve native memory allocations profile
     collected since renderer process startup. */
  module GetAllTimeSamplingProfile = {
    let name = "Memory.getAllTimeSamplingProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      profile: Types.Memory.SamplingProfile.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve native memory allocations profile
     collected since browser process startup. */
  module GetBrowserSamplingProfile = {
    let name = "Memory.getBrowserSamplingProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      profile: Types.Memory.SamplingProfile.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve native memory allocations profile collected since last
     `startSampling` call. */
  module GetSamplingProfile = {
    let name = "Memory.getSamplingProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      profile: Types.Memory.SamplingProfile.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Network = {
  /* Sets a list of content encodings that will be accepted. Empty list means no encoding is accepted. */
  module SetAcceptedEncodings = {
    let name = "Network.setAcceptedEncodings";

    [@deriving yojson]
    type params = {
      encodings: array(Types.Network.ContentEncoding.t) /* List of accepted content encodings. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears accepted encodings set by setAcceptedEncodings */
  module ClearAcceptedEncodingsOverride = {
    let name = "Network.clearAcceptedEncodingsOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tells whether clearing browser cache is supported. */
  module CanClearBrowserCache = {
    let name = "Network.canClearBrowserCache";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {result: bool /* True if browser cache can be cleared. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tells whether clearing browser cookies is supported. */
  module CanClearBrowserCookies = {
    let name = "Network.canClearBrowserCookies";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: bool /* True if browser cookies can be cleared. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tells whether emulation of network conditions is supported. */
  module CanEmulateNetworkConditions = {
    let name = "Network.canEmulateNetworkConditions";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: bool /* True if emulation of network conditions is supported. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears browser cache. */
  module ClearBrowserCache = {
    let name = "Network.clearBrowserCache";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears browser cookies. */
  module ClearBrowserCookies = {
    let name = "Network.clearBrowserCookies";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Response to Network.requestIntercepted which either modifies the request to continue with any
     modifications, or blocks it, or completes it with the provided response bytes. If a network
     fetch occurs as a result which encounters a redirect an additional Network.requestIntercepted
     event will be sent with the same InterceptionId.
     Deprecated, use Fetch.continueRequest, Fetch.fulfillRequest and Fetch.failRequest instead. */
  module ContinueInterceptedRequest = {
    let name = "Network.continueInterceptedRequest";

    [@deriving yojson]
    type params = {
      interceptionId: Types.Network.InterceptionId.t, /* No description provided */
      [@yojson.option]
      errorReason: option(Types.Network.ErrorReason.t), /* If set this causes the request to fail with the given reason. Passing `Aborted` for requests
marked with `isNavigationRequest` also cancels the navigation. Must not be set in response
to an authChallenge. */
      [@yojson.option]
      rawResponse: option(string), /* If set the requests completes using with the provided base64 encoded raw response, including
HTTP status line and headers etc... Must not be set in response to an authChallenge. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      url: option(string), /* If set the request url will be modified in a way that's not observable by page. Must not be
set in response to an authChallenge. */
      [@yojson.option]
      method: option(string), /* If set this allows the request method to be overridden. Must not be set in response to an
authChallenge. */
      [@yojson.option]
      postData: option(string), /* If set this allows postData to be set. Must not be set in response to an authChallenge. */
      [@yojson.option]
      headers: option(Types.Network.Headers.t), /* If set this allows the request headers to be changed. Must not be set in response to an
authChallenge. */
      [@yojson.option]
      authChallengeResponse: option(Types.Network.AuthChallengeResponse.t) /* Response to a requestIntercepted with an authChallenge. Must not be set otherwise. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deletes browser cookies with matching name and url or domain/path pair. */
  module DeleteCookies = {
    let name = "Network.deleteCookies";

    [@deriving yojson]
    type params = {
      name: string, /* Name of the cookies to remove. */
      [@yojson.option]
      url: option(string), /* If specified, deletes all the cookies with the given name where domain and path match
provided URL. */
      [@yojson.option]
      domain: option(string), /* If specified, deletes only cookies with the exact domain. */
      [@yojson.option]
      path: option(string) /* If specified, deletes only cookies with the exact path. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables network tracking, prevents network events from being sent to the client. */
  module Disable = {
    let name = "Network.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Activates emulation of network conditions. */
  module EmulateNetworkConditions = {
    let name = "Network.emulateNetworkConditions";

    [@deriving yojson]
    type params = {
      offline: bool, /* True to emulate internet disconnection. */
      latency: float, /* Minimum latency from request sent to response headers received (ms). */
      downloadThroughput: float, /* Maximal aggregated download throughput (bytes/sec). -1 disables download throttling. */
      uploadThroughput: float, /* Maximal aggregated upload throughput (bytes/sec).  -1 disables upload throttling. */
      [@yojson.option]
      connectionType: option(Types.Network.ConnectionType.t) /* Connection type if known. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables network tracking, network events will now be delivered to the client. */
  module Enable = {
    let name = "Network.enable";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      maxTotalBufferSize: option(float), /* Buffer size in bytes to use when preserving network payloads (XHRs, etc). */
      [@yojson.option]
      maxResourceBufferSize: option(float), /* Per-resource buffer size in bytes to use when preserving network payloads (XHRs, etc). */
      [@yojson.option]
      maxPostDataSize: option(float) /* Longest post body size (in bytes) that would be included in requestWillBeSent notification */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all browser cookies. Depending on the backend support, will return detailed cookie
     information in the `cookies` field. */
  module GetAllCookies = {
    let name = "Network.getAllCookies";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      cookies: array(Types.Network.Cookie.t) /* Array of cookie objects. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the DER-encoded certificate. */
  module GetCertificate = {
    let name = "Network.getCertificate";

    [@deriving yojson]
    type params = {origin: string /* Origin to get certificate for. */};

    [@deriving yojson]
    type result = {tableNames: array(string) /* No description provided */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all browser cookies for the current URL. Depending on the backend support, will return
     detailed cookie information in the `cookies` field. */
  module GetCookies = {
    let name = "Network.getCookies";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      urls: option(array(string)) /* The list of URLs for which applicable cookies will be fetched.
If not specified, it's assumed to be set to the list containing
the URLs of the page and all of its subframes. */,
    };

    [@deriving yojson]
    type result = {
      cookies: array(Types.Network.Cookie.t) /* Array of cookie objects. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns content served for the given request. */
  module GetResponseBody = {
    let name = "Network.getResponseBody";

    [@deriving yojson]
    type params = {
      requestId: Types.Network.RequestId.t /* Identifier of the network request to get content for. */,
    };

    [@deriving yojson]
    type result = {
      body: string, /* Response body. */
      base64Encoded: bool /* True, if content was sent as base64. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns post data sent with the request. Returns an error when no data was sent with the request. */
  module GetRequestPostData = {
    let name = "Network.getRequestPostData";

    [@deriving yojson]
    type params = {
      requestId: Types.Network.RequestId.t /* Identifier of the network request to get content for. */,
    };

    [@deriving yojson]
    type result = {
      postData: string /* Request body string, omitting files from multipart requests */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns content served for the given currently intercepted request. */
  module GetResponseBodyForInterception = {
    let name = "Network.getResponseBodyForInterception";

    [@deriving yojson]
    type params = {
      interceptionId: Types.Network.InterceptionId.t /* Identifier for the intercepted request to get body for. */,
    };

    [@deriving yojson]
    type result = {
      body: string, /* Response body. */
      base64Encoded: bool /* True, if content was sent as base64. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a handle to the stream representing the response body. Note that after this command,
     the intercepted request can't be continued as is -- you either need to cancel it or to provide
     the response body. The stream only supports sequential read, IO.read will fail if the position
     is specified. */
  module TakeResponseBodyForInterceptionAsStream = {
    let name = "Network.takeResponseBodyForInterceptionAsStream";

    [@deriving yojson]
    type params = {
      interceptionId: Types.Network.InterceptionId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      stream: Types.IO.StreamHandle.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* This method sends a new XMLHttpRequest which is identical to the original one. The following
     parameters should be identical: method, url, async, request body, extra headers, withCredentials
     attribute, user, password. */
  module ReplayXHR = {
    let name = "Network.replayXHR";

    [@deriving yojson]
    type params = {
      requestId: Types.Network.RequestId.t /* Identifier of XHR to replay. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Searches for given string in response content. */
  module SearchInResponseBody = {
    let name = "Network.searchInResponseBody";

    [@deriving yojson]
    type params = {
      requestId: Types.Network.RequestId.t, /* Identifier of the network response to search. */
      query: string, /* String to search for. */
      [@yojson.option]
      caseSensitive: option(bool), /* If true, search is case sensitive. */
      [@yojson.option]
      isRegex: option(bool) /* If true, treats string parameter as regex. */,
    };

    [@deriving yojson]
    type result = {
      result: array(Types.Debugger.SearchMatch.t) /* List of search matches. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Blocks URLs from loading. */
  module SetBlockedURLs = {
    let name = "Network.setBlockedURLs";

    [@deriving yojson]
    type params = {
      urls: array(string) /* URL patterns to block. Wildcards ('*') are allowed. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Toggles ignoring of service worker for each request. */
  module SetBypassServiceWorker = {
    let name = "Network.setBypassServiceWorker";

    [@deriving yojson]
    type params = {
      bypass: bool /* Bypass service worker and load from network. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Toggles ignoring cache for each request. If `true`, cache will not be used. */
  module SetCacheDisabled = {
    let name = "Network.setCacheDisabled";

    [@deriving yojson]
    type params = {cacheDisabled: bool /* Cache disabled state. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets a cookie with the given cookie data; may overwrite equivalent cookies if they exist. */
  module SetCookie = {
    let name = "Network.setCookie";

    [@deriving yojson]
    type params = {
      name: string, /* Cookie name. */
      value: string, /* Cookie value. */
      [@yojson.option]
      url: option(string), /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
      [@yojson.option]
      domain: option(string), /* Cookie domain. */
      [@yojson.option]
      path: option(string), /* Cookie path. */
      [@yojson.option]
      secure: option(bool), /* True if cookie is secure. */
      [@yojson.option]
      httpOnly: option(bool), /* True if cookie is http-only. */
      [@yojson.option]
      sameSite: option(Types.Network.CookieSameSite.t), /* Cookie SameSite type. */
      [@yojson.option]
      expires: option(Types.Network.TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
      [@yojson.option]
      priority: option(Types.Network.CookiePriority.t), /* Cookie Priority type. */
      [@yojson.option]
      sameParty: option(bool), /* True if cookie is SameParty. */
      [@yojson.option]
      sourceScheme: option(Types.Network.CookieSourceScheme.t), /* Cookie source scheme type. */
      [@yojson.option]
      sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
    };

    [@deriving yojson]
    type result = {
      success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets given cookies. */
  module SetCookies = {
    let name = "Network.setCookies";

    [@deriving yojson]
    type params = {
      cookies: array(Types.Network.CookieParam.t) /* Cookies to be set. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* For testing. */
  module SetDataSizeLimitsForTest = {
    let name = "Network.setDataSizeLimitsForTest";

    [@deriving yojson]
    type params = {
      maxTotalSize: float, /* Maximum total buffer size. */
      maxResourceSize: float /* Maximum per-resource size. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Specifies whether to always send extra HTTP headers with the requests from this page. */
  module SetExtraHTTPHeaders = {
    let name = "Network.setExtraHTTPHeaders";

    [@deriving yojson]
    type params = {
      headers: Types.Network.Headers.t /* Map with extra HTTP headers. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Specifies whether to attach a page script stack id in requests */
  module SetAttachDebugStack = {
    let name = "Network.setAttachDebugStack";

    [@deriving yojson]
    type params = {
      enabled: bool /* Whether to attach a page script stack for debugging purpose. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets the requests to intercept that match the provided patterns and optionally resource types.
     Deprecated, please use Fetch.enable instead. */
  module SetRequestInterception = {
    let name = "Network.setRequestInterception";

    [@deriving yojson]
    type params = {
      patterns: array(Types.Network.RequestPattern.t) /* Requests matching any of these patterns will be forwarded and wait for the corresponding
continueInterceptedRequest call. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Allows overriding user agent with the given string. */
  module SetUserAgentOverride = {
    let name = "Network.setUserAgentOverride";

    [@deriving yojson]
    type params = {
      userAgent: string, /* User agent to use. */
      [@yojson.option]
      acceptLanguage: option(string), /* Browser langugage to emulate. */
      [@yojson.option]
      platform: option(string), /* The platform navigator.platform should return. */
      [@yojson.option]
      userAgentMetadata: option(Types.Emulation.UserAgentMetadata.t) /* To be sent in Sec-CH-UA-* headers and returned in navigator.userAgentData */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns information about the COEP/COOP isolation status. */
  module GetSecurityIsolationStatus = {
    let name = "Network.getSecurityIsolationStatus";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      frameId: option(Types.Page.FrameId.t) /* If no frameId is provided, the status of the target is provided. */,
    };

    [@deriving yojson]
    type result = {
      status: Types.Network.SecurityIsolationStatus.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetches the resource and returns the content. */
  module LoadNetworkResource = {
    let name = "Network.loadNetworkResource";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Frame id to get the resource for. */
      url: string, /* URL of the resource to get content for. */
      options: Types.Network.LoadNetworkResourceOptions.t /* Options for the request. */,
    };

    [@deriving yojson]
    type result = {
      resource: Types.Network.LoadNetworkResourcePageResult.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Overlay = {
  /* Disables domain notifications. */
  module Disable = {
    let name = "Overlay.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables domain notifications. */
  module Enable = {
    let name = "Overlay.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* For testing. */
  module GetHighlightObjectForTest = {
    let name = "Overlay.getHighlightObjectForTest";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t, /* Id of the node to get highlight object for. */
      [@yojson.option]
      includeDistance: option(bool), /* Whether to include distance info. */
      [@yojson.option]
      includeStyle: option(bool), /* Whether to include style info. */
      [@yojson.option]
      colorFormat: option(Types.Overlay.ColorFormat.t), /* The color format to get config with (default: hex). */
      [@yojson.option]
      showAccessibilityInfo: option(bool) /* Whether to show accessibility info (default: true). */,
    };

    [@deriving yojson]
    type result = {highlight: Types.assoc /* Highlight data for the node. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* For Persistent Grid testing. */
  module GetGridHighlightObjectsForTest = {
    let name = "Overlay.getGridHighlightObjectsForTest";

    [@deriving yojson]
    type params = {
      nodeIds: array(Types.DOM.NodeId.t) /* Ids of the node to get highlight object for. */,
    };

    [@deriving yojson]
    type result = {
      highlights: Types.assoc /* Grid Highlight data for the node ids provided. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* For Source Order Viewer testing. */
  module GetSourceOrderHighlightObjectForTest = {
    let name = "Overlay.getSourceOrderHighlightObjectForTest";

    [@deriving yojson]
    type params = {
      nodeId: Types.DOM.NodeId.t /* Id of the node to highlight. */,
    };

    [@deriving yojson]
    type result = {
      highlight: Types.assoc /* Source order highlight data for the node id provided. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Hides any highlight. */
  module HideHighlight = {
    let name = "Overlay.hideHighlight";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights owner element of the frame with given id. */
  module HighlightFrame = {
    let name = "Overlay.highlightFrame";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Identifier of the frame to highlight. */
      [@yojson.option]
      contentColor: option(Types.DOM.RGBA.t), /* The content box highlight fill color (default: transparent). */
      [@yojson.option]
      contentOutlineColor: option(Types.DOM.RGBA.t) /* The content box highlight outline color (default: transparent). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights DOM node with given id or with the given JavaScript object wrapper. Either nodeId or
     objectId must be specified. */
  module HighlightNode = {
    let name = "Overlay.highlightNode";

    [@deriving yojson]
    type params = {
      highlightConfig: Types.Overlay.HighlightConfig.t, /* A descriptor for the highlight appearance. */
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to highlight. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to highlight. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node to be highlighted. */
      [@yojson.option]
      selector: option(string) /* Selectors to highlight relevant nodes. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights given quad. Coordinates are absolute with respect to the main frame viewport. */
  module HighlightQuad = {
    let name = "Overlay.highlightQuad";

    [@deriving yojson]
    type params = {
      quad: Types.DOM.Quad.t, /* Quad to highlight */
      [@yojson.option]
      color: option(Types.DOM.RGBA.t), /* The highlight fill color (default: transparent). */
      [@yojson.option]
      outlineColor: option(Types.DOM.RGBA.t) /* The highlight outline color (default: transparent). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights given rectangle. Coordinates are absolute with respect to the main frame viewport. */
  module HighlightRect = {
    let name = "Overlay.highlightRect";

    [@deriving yojson]
    type params = {
      x: float, /* X coordinate */
      y: float, /* Y coordinate */
      width: float, /* Rectangle width */
      height: float, /* Rectangle height */
      [@yojson.option]
      color: option(Types.DOM.RGBA.t), /* The highlight fill color (default: transparent). */
      [@yojson.option]
      outlineColor: option(Types.DOM.RGBA.t) /* The highlight outline color (default: transparent). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights the source order of the children of the DOM node with given id or with the given
     JavaScript object wrapper. Either nodeId or objectId must be specified. */
  module HighlightSourceOrder = {
    let name = "Overlay.highlightSourceOrder";

    [@deriving yojson]
    type params = {
      sourceOrderConfig: Types.Overlay.SourceOrderConfig.t, /* A descriptor for the appearance of the overlay drawing. */
      [@yojson.option]
      nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to highlight. */
      [@yojson.option]
      backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to highlight. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node to be highlighted. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enters the 'inspect' mode. In this mode, elements that user is hovering over are highlighted.
     Backend then generates 'inspectNodeRequested' event upon element selection. */
  module SetInspectMode = {
    let name = "Overlay.setInspectMode";

    [@deriving yojson]
    type params = {
      mode: Types.Overlay.InspectMode.t, /* Set an inspection mode. */
      [@yojson.option]
      highlightConfig: option(Types.Overlay.HighlightConfig.t) /* A descriptor for the highlight appearance of hovered-over nodes. May be omitted if `enabled
== false`. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlights owner element of all frames detected to be ads. */
  module SetShowAdHighlights = {
    let name = "Overlay.setShowAdHighlights";

    [@deriving yojson]
    type params = {show: bool /* True for showing ad highlights */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetPausedInDebuggerMessage = {
    let name = "Overlay.setPausedInDebuggerMessage";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      message: option(string) /* The message to display, also triggers resume and step over controls. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows debug borders on layers */
  module SetShowDebugBorders = {
    let name = "Overlay.setShowDebugBorders";

    [@deriving yojson]
    type params = {show: bool /* True for showing debug borders */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows the FPS counter */
  module SetShowFPSCounter = {
    let name = "Overlay.setShowFPSCounter";

    [@deriving yojson]
    type params = {show: bool /* True for showing the FPS counter */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Highlight multiple elements with the CSS Grid overlay. */
  module SetShowGridOverlays = {
    let name = "Overlay.setShowGridOverlays";

    [@deriving yojson]
    type params = {
      gridNodeHighlightConfigs: array(Types.Overlay.GridNodeHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetShowFlexOverlays = {
    let name = "Overlay.setShowFlexOverlays";

    [@deriving yojson]
    type params = {
      flexNodeHighlightConfigs: array(Types.Overlay.FlexNodeHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetShowScrollSnapOverlays = {
    let name = "Overlay.setShowScrollSnapOverlays";

    [@deriving yojson]
    type params = {
      scrollSnapHighlightConfigs:
        array(Types.Overlay.ScrollSnapHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows paint rectangles */
  module SetShowPaintRects = {
    let name = "Overlay.setShowPaintRects";

    [@deriving yojson]
    type params = {result: bool /* True for showing paint rectangles */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows layout shift regions */
  module SetShowLayoutShiftRegions = {
    let name = "Overlay.setShowLayoutShiftRegions";

    [@deriving yojson]
    type params = {result: bool /* True for showing layout shift regions */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows scroll bottleneck rects */
  module SetShowScrollBottleneckRects = {
    let name = "Overlay.setShowScrollBottleneckRects";

    [@deriving yojson]
    type params = {show: bool /* True for showing scroll bottleneck rects */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests that backend shows hit-test borders on layers */
  module SetShowHitTestBorders = {
    let name = "Overlay.setShowHitTestBorders";

    [@deriving yojson]
    type params = {show: bool /* True for showing hit-test borders */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Request that backend shows an overlay with web vital metrics. */
  module SetShowWebVitals = {
    let name = "Overlay.setShowWebVitals";

    [@deriving yojson]
    type params = {show: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Paints viewport size upon main frame resize. */
  module SetShowViewportSizeOnResize = {
    let name = "Overlay.setShowViewportSizeOnResize";

    [@deriving yojson]
    type params = {show: bool /* Whether to paint size or not. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Add a dual screen device hinge */
  module SetShowHinge = {
    let name = "Overlay.setShowHinge";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      hingeConfig: option(Types.Overlay.HingeConfig.t) /* hinge data, null means hideHinge */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Page = {
  /* Deprecated, please use addScriptToEvaluateOnNewDocument instead. */
  module AddScriptToEvaluateOnLoad = {
    let name = "Page.addScriptToEvaluateOnLoad";

    [@deriving yojson]
    type params = {scriptSource: string /* No description provided */};

    [@deriving yojson]
    type result = {
      identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Evaluates given script in every frame upon creation (before loading frame's scripts). */
  module AddScriptToEvaluateOnNewDocument = {
    let name = "Page.addScriptToEvaluateOnNewDocument";

    [@deriving yojson]
    type params = {
      source: string, /* No description provided */
      [@yojson.option]
      worldName: option(string), /* If specified, creates an isolated world with the given name and evaluates given script in it.
This world name will be used as the ExecutionContextDescription::name when the corresponding
event is emitted. */
      [@yojson.option]
      includeCommandLineAPI: option(bool) /* Specifies whether command line API should be available to the script, defaults
to false. */,
    };

    [@deriving yojson]
    type result = {
      identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Brings page to front (activates tab). */
  module BringToFront = {
    let name = "Page.bringToFront";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Capture page screenshot. */
  module CaptureScreenshot = {
    let name = "Page.captureScreenshot";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      format: option(string), /* Image compression format (defaults to png). */
      [@yojson.option]
      quality: option(float), /* Compression quality from range [0..100] (jpeg only). */
      [@yojson.option]
      clip: option(Types.Page.Viewport.t), /* Capture the screenshot of a given region only. */
      [@yojson.option]
      fromSurface: option(bool), /* Capture the screenshot from the surface, rather than the view. Defaults to true. */
      [@yojson.option]
      captureBeyondViewport: option(bool) /* Capture the screenshot beyond the viewport. Defaults to false. */,
    };

    [@deriving yojson]
    type result = {
      data: string /* Base64-encoded image data. (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a snapshot of the page as a string. For MHTML format, the serialization includes
     iframes, shadow DOM, external resources, and element-inline styles. */
  module CaptureSnapshot = {
    let name = "Page.captureSnapshot";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      format: option(string) /* Format (defaults to mhtml). */,
    };

    [@deriving yojson]
    type result = {data: string /* Serialized page data. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears the overridden device metrics. */
  module ClearDeviceMetricsOverride = {
    let name = "Page.clearDeviceMetricsOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears the overridden Device Orientation. */
  module ClearDeviceOrientationOverride = {
    let name = "Page.clearDeviceOrientationOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears the overridden Geolocation Position and Error. */
  module ClearGeolocationOverride = {
    let name = "Page.clearGeolocationOverride";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates an isolated world for the given frame. */
  module CreateIsolatedWorld = {
    let name = "Page.createIsolatedWorld";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Id of the frame in which the isolated world should be created. */
      [@yojson.option]
      worldName: option(string), /* An optional name which is reported in the Execution Context. */
      [@yojson.option]
      grantUniveralAccess: option(bool) /* Whether or not universal access should be granted to the isolated world. This is a powerful
option, use with caution. */,
    };

    [@deriving yojson]
    type result = {
      executionContextId: Types.Runtime.ExecutionContextId.t /* Execution context of the isolated world. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deletes browser cookie with given name, domain and path. */
  module DeleteCookie = {
    let name = "Page.deleteCookie";

    [@deriving yojson]
    type params = {
      cookieName: string, /* Name of the cookie to remove. */
      url: string /* URL to match cooke domain and path. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables page domain notifications. */
  module Disable = {
    let name = "Page.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables page domain notifications. */
  module Enable = {
    let name = "Page.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetAppManifest = {
    let name = "Page.getAppManifest";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      url: string, /* Manifest location. */
      errors: array(Types.Page.AppManifestError.t), /* No description provided */
      [@yojson.option]
      data: option(string), /* Manifest content. */
      [@yojson.option]
      parsed: option(Types.Page.AppManifestParsedProperties.t) /* Parsed manifest properties */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetInstallabilityErrors = {
    let name = "Page.getInstallabilityErrors";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      installabilityErrors: array(Types.Page.InstallabilityError.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module GetManifestIcons = {
    let name = "Page.getManifestIcons";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      [@yojson.option]
      primaryIcon: option(string) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all browser cookies. Depending on the backend support, will return detailed cookie
     information in the `cookies` field. */
  module GetCookies = {
    let name = "Page.getCookies";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      cookies: array(Types.Network.Cookie.t) /* Array of cookie objects. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns present frame tree structure. */
  module GetFrameTree = {
    let name = "Page.getFrameTree";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      frameTree: Types.Page.FrameTree.t /* Present frame tree structure. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns metrics relating to the layouting of the page, such as viewport bounds/scale. */
  module GetLayoutMetrics = {
    let name = "Page.getLayoutMetrics";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      layoutViewport: Types.Page.LayoutViewport.t, /* Deprecated metrics relating to the layout viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssLayoutViewport` instead. */
      visualViewport: Types.Page.VisualViewport.t, /* Deprecated metrics relating to the visual viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssVisualViewport` instead. */
      contentSize: Types.DOM.Rect.t, /* Deprecated size of scrollable area. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssContentSize` instead. */
      cssLayoutViewport: Types.Page.LayoutViewport.t, /* Metrics relating to the layout viewport in CSS pixels. */
      cssVisualViewport: Types.Page.VisualViewport.t, /* Metrics relating to the visual viewport in CSS pixels. */
      cssContentSize: Types.DOM.Rect.t /* Size of scrollable area in CSS pixels. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns navigation history for the current page. */
  module GetNavigationHistory = {
    let name = "Page.getNavigationHistory";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      currentIndex: float, /* Index of the current navigation history entry. */
      entries: array(Types.Page.NavigationEntry.t) /* Array of navigation history entries. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Resets navigation history for the current page. */
  module ResetNavigationHistory = {
    let name = "Page.resetNavigationHistory";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns content of the given resource. */
  module GetResourceContent = {
    let name = "Page.getResourceContent";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Frame id to get resource for. */
      url: string /* URL of the resource to get content for. */,
    };

    [@deriving yojson]
    type result = {
      content: string, /* Resource content. */
      base64Encoded: bool /* True, if content was served as base64. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns present frame / resource tree structure. */
  module GetResourceTree = {
    let name = "Page.getResourceTree";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      frameTree: Types.Page.FrameResourceTree.t /* Present frame / resource tree structure. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Accepts or dismisses a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload). */
  module HandleJavaScriptDialog = {
    let name = "Page.handleJavaScriptDialog";

    [@deriving yojson]
    type params = {
      accept: bool, /* Whether to accept or dismiss the dialog. */
      [@yojson.option]
      promptText: option(string) /* The text to enter into the dialog prompt before accepting. Used only if this is a prompt
dialog. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Navigates current page to the given URL. */
  module Navigate = {
    let name = "Page.navigate";

    [@deriving yojson]
    type params = {
      url: string, /* URL to navigate the page to. */
      [@yojson.option]
      referrer: option(string), /* Referrer URL. */
      [@yojson.option]
      transitionType: option(Types.Page.TransitionType.t), /* Intended transition type. */
      [@yojson.option]
      frameId: option(Types.Page.FrameId.t), /* Frame id to navigate, if not specified navigates the top frame. */
      [@yojson.option]
      referrerPolicy: option(Types.Page.ReferrerPolicy.t) /* Referrer-policy used for the navigation. */,
    };

    [@deriving yojson]
    type result = {
      frameId: Types.Page.FrameId.t, /* Frame id that has navigated (or failed to navigate) */
      [@yojson.option]
      loaderId: option(Types.Network.LoaderId.t), /* Loader identifier. */
      [@yojson.option]
      errorText: option(string) /* User friendly error message, present if and only if navigation has failed. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Navigates current page to the given history entry. */
  module NavigateToHistoryEntry = {
    let name = "Page.navigateToHistoryEntry";

    [@deriving yojson]
    type params = {
      entryId: float /* Unique id of the entry to navigate to. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Print page as PDF. */
  module PrintToPDF = {
    let name = "Page.printToPDF";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      landscape: option(bool), /* Paper orientation. Defaults to false. */
      [@yojson.option]
      displayHeaderFooter: option(bool), /* Display header and footer. Defaults to false. */
      [@yojson.option]
      printBackground: option(bool), /* Print background graphics. Defaults to false. */
      [@yojson.option]
      scale: option(float), /* Scale of the webpage rendering. Defaults to 1. */
      [@yojson.option]
      paperWidth: option(float), /* Paper width in inches. Defaults to 8.5 inches. */
      [@yojson.option]
      paperHeight: option(float), /* Paper height in inches. Defaults to 11 inches. */
      [@yojson.option]
      marginTop: option(float), /* Top margin in inches. Defaults to 1cm (~0.4 inches). */
      [@yojson.option]
      marginBottom: option(float), /* Bottom margin in inches. Defaults to 1cm (~0.4 inches). */
      [@yojson.option]
      marginLeft: option(float), /* Left margin in inches. Defaults to 1cm (~0.4 inches). */
      [@yojson.option]
      marginRight: option(float), /* Right margin in inches. Defaults to 1cm (~0.4 inches). */
      [@yojson.option]
      pageRanges: option(string), /* Paper ranges to print, e.g., '1-5, 8, 11-13'. Defaults to the empty string, which means
print all pages. */
      [@yojson.option]
      ignoreInvalidPageRanges: option(bool), /* Whether to silently ignore invalid but successfully parsed page ranges, such as '3-2'.
Defaults to false. */
      [@yojson.option]
      headerTemplate: option(string), /* HTML template for the print header. Should be valid HTML markup with following
classes used to inject printing values into them:
- `date`: formatted print date
- `title`: document title
- `url`: document location
- `pageNumber`: current page number
- `totalPages`: total pages in the document

For example, `<span class=title></span>` would generate span containing the title. */
      [@yojson.option]
      footerTemplate: option(string), /* HTML template for the print footer. Should use the same format as the `headerTemplate`. */
      [@yojson.option]
      preferCSSPageSize: option(bool), /* Whether or not to prefer page size as defined by css. Defaults to false,
in which case the content will be scaled to fit the paper size. */
      [@yojson.option]
      transferMode: option(string) /* return as stream */,
    };

    [@deriving yojson]
    type result = {
      data: string, /* Base64-encoded pdf data. Empty if |returnAsStream| is specified. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      stream: option(Types.IO.StreamHandle.t) /* A handle of the stream that holds resulting PDF data. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Reloads given page optionally ignoring the cache. */
  module Reload = {
    let name = "Page.reload";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      ignoreCache: option(bool), /* If true, browser cache is ignored (as if the user pressed Shift+refresh). */
      [@yojson.option]
      scriptToEvaluateOnLoad: option(string) /* If set, the script will be injected into all frames of the inspected page after reload.
Argument will be ignored if reloading dataURL origin. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deprecated, please use removeScriptToEvaluateOnNewDocument instead. */
  module RemoveScriptToEvaluateOnLoad = {
    let name = "Page.removeScriptToEvaluateOnLoad";

    [@deriving yojson]
    type params = {
      identifier: Types.Page.ScriptIdentifier.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes given script from the list. */
  module RemoveScriptToEvaluateOnNewDocument = {
    let name = "Page.removeScriptToEvaluateOnNewDocument";

    [@deriving yojson]
    type params = {
      identifier: Types.Page.ScriptIdentifier.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Acknowledges that a screencast frame has been received by the frontend. */
  module ScreencastFrameAck = {
    let name = "Page.screencastFrameAck";

    [@deriving yojson]
    type params = {sessionId: float /* Frame number. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Searches for given string in resource content. */
  module SearchInResource = {
    let name = "Page.searchInResource";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Frame id for resource to search in. */
      url: string, /* URL of the resource to search in. */
      query: string, /* String to search for. */
      [@yojson.option]
      caseSensitive: option(bool), /* If true, search is case sensitive. */
      [@yojson.option]
      isRegex: option(bool) /* If true, treats string parameter as regex. */,
    };

    [@deriving yojson]
    type result = {
      result: array(Types.Debugger.SearchMatch.t) /* List of search matches. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable Chrome's experimental ad filter on all sites. */
  module SetAdBlockingEnabled = {
    let name = "Page.setAdBlockingEnabled";

    [@deriving yojson]
    type params = {enabled: bool /* Whether to block ads. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable page Content Security Policy by-passing. */
  module SetBypassCSP = {
    let name = "Page.setBypassCSP";

    [@deriving yojson]
    type params = {enabled: bool /* Whether to bypass page CSP. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Get Permissions Policy state on given frame. */
  module GetPermissionsPolicyState = {
    let name = "Page.getPermissionsPolicyState";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      states: array(Types.Page.PermissionsPolicyFeatureState.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the values of device screen dimensions (window.screen.width, window.screen.height,
     window.innerWidth, window.innerHeight, and "device-width"/"device-height"-related CSS media
     query results). */
  module SetDeviceMetricsOverride = {
    let name = "Page.setDeviceMetricsOverride";

    [@deriving yojson]
    type params = {
      width: float, /* Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
      height: float, /* Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
      deviceScaleFactor: float, /* Overriding device scale factor value. 0 disables the override. */
      mobile: bool, /* Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
autosizing and more. */
      [@yojson.option]
      scale: option(float), /* Scale to apply to resulting view image. */
      [@yojson.option]
      screenWidth: option(float), /* Overriding screen width value in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      screenHeight: option(float), /* Overriding screen height value in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      positionX: option(float), /* Overriding view X position on screen in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      positionY: option(float), /* Overriding view Y position on screen in pixels (minimum 0, maximum 10000000). */
      [@yojson.option]
      dontSetVisibleSize: option(bool), /* Do not set visible view size, rely upon explicit setVisibleSize call. */
      [@yojson.option]
      screenOrientation: option(Types.Emulation.ScreenOrientation.t), /* Screen orientation override. */
      [@yojson.option]
      viewport: option(Types.Page.Viewport.t) /* The viewport dimensions and scale. If not set, the override is cleared. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the Device Orientation. */
  module SetDeviceOrientationOverride = {
    let name = "Page.setDeviceOrientationOverride";

    [@deriving yojson]
    type params = {
      alpha: float, /* Mock alpha */
      beta: float, /* Mock beta */
      gamma: float /* Mock gamma */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set generic font families. */
  module SetFontFamilies = {
    let name = "Page.setFontFamilies";

    [@deriving yojson]
    type params = {
      fontFamilies: Types.Page.FontFamilies.t /* Specifies font families to set. If a font family is not specified, it won't be changed. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set default font sizes. */
  module SetFontSizes = {
    let name = "Page.setFontSizes";

    [@deriving yojson]
    type params = {
      fontSizes: Types.Page.FontSizes.t /* Specifies font sizes to set. If a font size is not specified, it won't be changed. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets given markup as the document's HTML. */
  module SetDocumentContent = {
    let name = "Page.setDocumentContent";

    [@deriving yojson]
    type params = {
      frameId: Types.Page.FrameId.t, /* Frame id to set HTML for. */
      html: string /* HTML content to set. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Set the behavior when downloading a file. */
  module SetDownloadBehavior = {
    let name = "Page.setDownloadBehavior";

    [@deriving yojson]
    type params = {
      behavior: string, /* Whether to allow all or deny all download requests, or use default Chrome behavior if
available (otherwise deny). */
      [@yojson.option]
      downloadPath: option(string) /* The default path to save downloaded files to. This is required if behavior is set to 'allow' */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Overrides the Geolocation Position or Error. Omitting any of the parameters emulates position
     unavailable. */
  module SetGeolocationOverride = {
    let name = "Page.setGeolocationOverride";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      latitude: option(float), /* Mock latitude */
      [@yojson.option]
      longitude: option(float), /* Mock longitude */
      [@yojson.option]
      accuracy: option(float) /* Mock accuracy */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Controls whether page will emit lifecycle events. */
  module SetLifecycleEventsEnabled = {
    let name = "Page.setLifecycleEventsEnabled";

    [@deriving yojson]
    type params = {
      enabled: bool /* If true, starts emitting lifecycle events. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Toggles mouse event-based touch event emulation. */
  module SetTouchEmulationEnabled = {
    let name = "Page.setTouchEmulationEnabled";

    [@deriving yojson]
    type params = {
      enabled: bool, /* Whether the touch event emulation should be enabled. */
      [@yojson.option]
      configuration: option(string) /* Touch/gesture events configuration. Default: current platform. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Starts sending each frame using the `screencastFrame` event. */
  module StartScreencast = {
    let name = "Page.startScreencast";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      format: option(string), /* Image compression format. */
      [@yojson.option]
      quality: option(float), /* Compression quality from range [0..100]. */
      [@yojson.option]
      maxWidth: option(float), /* Maximum screenshot width. */
      [@yojson.option]
      maxHeight: option(float), /* Maximum screenshot height. */
      [@yojson.option]
      everyNthFrame: option(float) /* Send every n-th frame. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Force the page stop all navigations and pending resource fetches. */
  module StopLoading = {
    let name = "Page.stopLoading";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Crashes renderer on the IO thread, generates minidumps. */
  module Crash = {
    let name = "Page.crash";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tries to close page, running its beforeunload hooks, if any. */
  module Close = {
    let name = "Page.close";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tries to update the web lifecycle state of the page.
     It will transition the page to the given state according to:
     https://github.com/WICG/web-lifecycle/ */
  module SetWebLifecycleState = {
    let name = "Page.setWebLifecycleState";

    [@deriving yojson]
    type params = {state: string /* Target lifecycle state */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Stops sending each frame in the `screencastFrame`. */
  module StopScreencast = {
    let name = "Page.stopScreencast";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Forces compilation cache to be generated for every subresource script.
     See also: `Page.produceCompilationCache`. */
  module SetProduceCompilationCache = {
    let name = "Page.setProduceCompilationCache";

    [@deriving yojson]
    type params = {enabled: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Requests backend to produce compilation cache for the specified scripts.
     Unlike setProduceCompilationCache, this allows client to only produce cache
     for specific scripts. `scripts` are appeneded to the list of scripts
     for which the cache for would produced. Disabling compilation cache with
     `setProduceCompilationCache` would reset all pending cache requests.
     The list may also be reset during page navigation.
     When script with a matching URL is encountered, the cache is optionally
     produced upon backend discretion, based on internal heuristics.
     See also: `Page.compilationCacheProduced`. */
  module ProduceCompilationCache = {
    let name = "Page.produceCompilationCache";

    [@deriving yojson]
    type params = {
      scripts: array(Types.Page.CompilationCacheParams.t) /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Seeds compilation cache for given url. Compilation cache does not survive
     cross-process navigation. */
  module AddCompilationCache = {
    let name = "Page.addCompilationCache";

    [@deriving yojson]
    type params = {
      url: string, /* No description provided */
      data: string /* Base64-encoded data (Encoded as a base64 string when passed over JSON) */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears seeded compilation cache. */
  module ClearCompilationCache = {
    let name = "Page.clearCompilationCache";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Generates a report for testing. */
  module GenerateTestReport = {
    let name = "Page.generateTestReport";

    [@deriving yojson]
    type params = {
      message: string, /* Message to be displayed in the report. */
      [@yojson.option]
      group: option(string) /* Specifies the endpoint group to deliver the report to. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Pauses page execution. Can be resumed using generic Runtime.runIfWaitingForDebugger. */
  module WaitForDebugger = {
    let name = "Page.waitForDebugger";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Intercept file chooser requests and transfer control to protocol clients.
     When file chooser interception is enabled, native file chooser dialog is not shown.
     Instead, a protocol event `Page.fileChooserOpened` is emitted. */
  module SetInterceptFileChooserDialog = {
    let name = "Page.setInterceptFileChooserDialog";

    [@deriving yojson]
    type params = {enabled: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Performance = {
  /* Disable collecting and reporting metrics. */
  module Disable = {
    let name = "Performance.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable collecting and reporting metrics. */
  module Enable = {
    let name = "Performance.enable";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      timeDomain: option(string) /* Time domain to use for collecting and reporting duration metrics. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets time domain to use for collecting and reporting duration metrics.
     Note that this must be called before enabling metrics collection. Calling
     this method while metrics collection is enabled returns an error. */
  module SetTimeDomain = {
    let name = "Performance.setTimeDomain";

    [@deriving yojson]
    type params = {timeDomain: string /* Time domain */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve current values of run-time metrics. */
  module GetMetrics = {
    let name = "Performance.getMetrics";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      metrics: array(Types.Performance.Metric.t) /* Current values for run-time metrics. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module PerformanceTimeline = {
  /* Previously buffered events would be reported before method returns.
     See also: timelineEventAdded */
  module Enable = {
    let name = "PerformanceTimeline.enable";

    [@deriving yojson]
    type params = {
      eventTypes: array(string) /* The types of event to report, as specified in
https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
The specified filter overrides any previous filters, passing empty
filter disables recording.
Note that not all types exposed to the web platform are currently supported. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Profiler = {
  /* No description provided */
  module Disable = {
    let name = "Profiler.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Enable = {
    let name = "Profiler.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Collect coverage data for the current isolate. The coverage data may be incomplete due to
     garbage collection. */
  module GetBestEffortCoverage = {
    let name = "Profiler.getBestEffortCoverage";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: array(Types.Profiler.ScriptCoverage.t) /* Coverage data for the current isolate. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Changes CPU profiler sampling interval. Must be called before CPU profiles recording started. */
  module SetSamplingInterval = {
    let name = "Profiler.setSamplingInterval";

    [@deriving yojson]
    type params = {
      interval: float /* New sampling interval in microseconds. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Start = {
    let name = "Profiler.start";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable precise code coverage. Coverage data for JavaScript executed before enabling precise code
     coverage may be incomplete. Enabling prevents running optimized code and resets execution
     counters. */
  module StartPreciseCoverage = {
    let name = "Profiler.startPreciseCoverage";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      callCount: option(bool), /* Collect accurate call counts beyond simple 'covered' or 'not covered'. */
      [@yojson.option]
      detailed: option(bool), /* Collect block-based coverage. */
      [@yojson.option]
      allowTriggeredUpdates: option(bool) /* Allow the backend to send updates on its own initiative */,
    };

    [@deriving yojson]
    type result = {
      timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable type profile. */
  module StartTypeProfile = {
    let name = "Profiler.startTypeProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Stop = {
    let name = "Profiler.stop";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {profile: Types.Profiler.Profile.t /* Recorded profile. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disable precise code coverage. Disabling releases unnecessary execution count records and allows
     executing optimized code. */
  module StopPreciseCoverage = {
    let name = "Profiler.stopPreciseCoverage";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disable type profile. Disabling releases type profile data collected so far. */
  module StopTypeProfile = {
    let name = "Profiler.stopTypeProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Collect coverage data for the current isolate, and resets execution counters. Precise code
     coverage needs to have started. */
  module TakePreciseCoverage = {
    let name = "Profiler.takePreciseCoverage";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: array(Types.Profiler.ScriptCoverage.t), /* Coverage data for the current isolate. */
      timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Collect type profile. */
  module TakeTypeProfile = {
    let name = "Profiler.takeTypeProfile";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: array(Types.Profiler.ScriptTypeProfile.t) /* Type profile for all scripts since startTypeProfile() was turned on. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable counters collection. */
  module EnableCounters = {
    let name = "Profiler.enableCounters";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disable counters collection. */
  module DisableCounters = {
    let name = "Profiler.disableCounters";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve counters. */
  module GetCounters = {
    let name = "Profiler.getCounters";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: array(Types.Profiler.CounterInfo.t) /* Collected counters information. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable run time call stats collection. */
  module EnableRuntimeCallStats = {
    let name = "Profiler.enableRuntimeCallStats";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disable run time call stats collection. */
  module DisableRuntimeCallStats = {
    let name = "Profiler.disableRuntimeCallStats";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieve run time call stats. */
  module GetRuntimeCallStats = {
    let name = "Profiler.getRuntimeCallStats";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      result: array(Types.Profiler.RuntimeCallCounterInfo.t) /* Collected runtime call counter information. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Runtime = {
  /* Add handler to promise with given promise object id. */
  module AwaitPromise = {
    let name = "Runtime.awaitPromise";

    [@deriving yojson]
    type params = {
      promiseObjectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the promise. */
      [@yojson.option]
      returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
      [@yojson.option]
      generatePreview: option(bool) /* Whether preview should be generated for the result. */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t, /* Promise result. Will contain rejected value if promise was rejected. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if stack strace is available. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Calls function with given declaration on the given object. Object group of the result is
     inherited from the target object. */
  module CallFunctionOn = {
    let name = "Runtime.callFunctionOn";

    [@deriving yojson]
    type params = {
      functionDeclaration: string, /* Declaration of the function to call. */
      [@yojson.option]
      objectId: option(Types.Runtime.RemoteObjectId.t), /* Identifier of the object to call function on. Either objectId or executionContextId should
be specified. */
      [@yojson.option]
      arguments: option(array(Types.Runtime.CallArgument.t)), /* Call arguments. All call arguments must belong to the same JavaScript world as the target
object. */
      [@yojson.option]
      silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
      [@yojson.option]
      returnByValue: option(bool), /* Whether the result is expected to be a JSON object which should be sent by value. */
      [@yojson.option]
      generatePreview: option(bool), /* Whether preview should be generated for the result. */
      [@yojson.option]
      userGesture: option(bool), /* Whether execution should be treated as initiated by user in the UI. */
      [@yojson.option]
      awaitPromise: option(bool), /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies execution context which global object will be used to call function on. Either
executionContextId or objectId should be specified. */
      [@yojson.option]
      objectGroup: option(string) /* Symbolic group name that can be used to release multiple objects. If objectGroup is not
specified and objectId is, objectGroup will be inherited from object. */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t, /* Call result. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Compiles expression. */
  module CompileScript = {
    let name = "Runtime.compileScript";

    [@deriving yojson]
    type params = {
      expression: string, /* Expression to compile. */
      sourceURL: string, /* Source url to be set for the script. */
      persistScript: bool, /* Specifies whether the compiled script should be persisted. */
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Specifies in which execution context to perform script run. If the parameter is omitted the
evaluation will be performed in the context of the inspected page. */,
    };

    [@deriving yojson]
    type result = {
      [@yojson.option]
      scriptId: option(Types.Runtime.ScriptId.t), /* Id of the script. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables reporting of execution contexts creation. */
  module Disable = {
    let name = "Runtime.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Discards collected exceptions and console API calls. */
  module DiscardConsoleEntries = {
    let name = "Runtime.discardConsoleEntries";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables reporting of execution contexts creation by means of `executionContextCreated` event.
     When the reporting gets enabled the event will be sent immediately for each existing execution
     context. */
  module Enable = {
    let name = "Runtime.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Evaluates expression on global object. */
  module Evaluate = {
    let name = "Runtime.evaluate";

    [@deriving yojson]
    type params = {
      expression: string, /* Expression to evaluate. */
      [@yojson.option]
      objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
      [@yojson.option]
      includeCommandLineAPI: option(bool), /* Determines whether Command Line API should be available during the evaluation. */
      [@yojson.option]
      silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
      [@yojson.option]
      contextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies in which execution context to perform evaluation. If the parameter is omitted the
evaluation will be performed in the context of the inspected page.
This is mutually exclusive with `uniqueContextId`, which offers an
alternative way to identify the execution context that is more reliable
in a multi-process environment. */
      [@yojson.option]
      returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
      [@yojson.option]
      generatePreview: option(bool), /* Whether preview should be generated for the result. */
      [@yojson.option]
      userGesture: option(bool), /* Whether execution should be treated as initiated by user in the UI. */
      [@yojson.option]
      awaitPromise: option(bool), /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */
      [@yojson.option]
      throwOnSideEffect: option(bool), /* Whether to throw an exception if side effect cannot be ruled out during evaluation.
This implies `disableBreaks` below. */
      [@yojson.option]
      timeout: option(Types.Runtime.TimeDelta.t), /* Terminate execution after timing out (number of milliseconds). */
      [@yojson.option]
      disableBreaks: option(bool), /* Disable breakpoints during execution. */
      [@yojson.option]
      replMode: option(bool), /* Setting this flag to true enables `let` re-declaration and top-level `await`.
Note that `let` variables can only be re-declared if they originate from
`replMode` themselves. */
      [@yojson.option]
      allowUnsafeEvalBlockedByCSP: option(bool), /* The Content Security Policy (CSP) for the target might block 'unsafe-eval'
which includes eval(), Function(), setTimeout() and setInterval()
when called with non-callable arguments. This flag bypasses CSP for this
evaluation and allows unsafe-eval. Defaults to true. */
      [@yojson.option]
      uniqueContextId: option(string) /* An alternative way to specify the execution context to evaluate in.
Compared to contextId that may be reused accross processes, this is guaranteed to be
system-unique, so it can be used to prevent accidental evaluation of the expression
in context different than intended (e.g. as a result of navigation accross process
boundaries).
This is mutually exclusive with `contextId`. */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t, /* Evaluation result. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the isolate id. */
  module GetIsolateId = {
    let name = "Runtime.getIsolateId";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {id: string /* The isolate id. */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the JavaScript heap usage.
     It is the total usage of the corresponding isolate not scoped to a particular Runtime. */
  module GetHeapUsage = {
    let name = "Runtime.getHeapUsage";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      usedSize: float, /* Used heap size in bytes. */
      totalSize: float /* Allocated heap size in bytes. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns properties of a given object. Object group of the result is inherited from the target
     object. */
  module GetProperties = {
    let name = "Runtime.getProperties";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the object to return properties for. */
      [@yojson.option]
      ownProperties: option(bool), /* If true, returns properties belonging only to the element itself, not to its prototype
chain. */
      [@yojson.option]
      accessorPropertiesOnly: option(bool), /* If true, returns accessor properties (with getter/setter) only; internal properties are not
returned either. */
      [@yojson.option]
      generatePreview: option(bool) /* Whether preview should be generated for the results. */,
    };

    [@deriving yojson]
    type result = {
      result: array(Types.Runtime.PropertyDescriptor.t), /* Object properties. */
      [@yojson.option]
      internalProperties:
        option(array(Types.Runtime.InternalPropertyDescriptor.t)), /* Internal object properties (only of the element itself). */
      [@yojson.option]
      privateProperties:
        option(array(Types.Runtime.PrivatePropertyDescriptor.t)), /* Object private properties. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all let, const and class variables from global scope. */
  module GlobalLexicalScopeNames = {
    let name = "Runtime.globalLexicalScopeNames";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Specifies in which execution context to lookup global scope variables. */,
    };

    [@deriving yojson]
    type result = {names: array(string) /* No description provided */};

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module QueryObjects = {
    let name = "Runtime.queryObjects";

    [@deriving yojson]
    type params = {
      prototypeObjectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the prototype to return objects for. */
      [@yojson.option]
      objectGroup: option(string) /* Symbolic group name that can be used to release the results. */,
    };

    [@deriving yojson]
    type result = {
      objects: Types.Runtime.RemoteObject.t /* Array with objects. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Releases remote object with given id. */
  module ReleaseObject = {
    let name = "Runtime.releaseObject";

    [@deriving yojson]
    type params = {
      objectId: Types.Runtime.RemoteObjectId.t /* Identifier of the object to release. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Releases all remote objects that belong to a given group. */
  module ReleaseObjectGroup = {
    let name = "Runtime.releaseObjectGroup";

    [@deriving yojson]
    type params = {objectGroup: string /* Symbolic object group name. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Tells inspected instance to run if it was waiting for debugger to attach. */
  module RunIfWaitingForDebugger = {
    let name = "Runtime.runIfWaitingForDebugger";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Runs script with given id in a given context. */
  module RunScript = {
    let name = "Runtime.runScript";

    [@deriving yojson]
    type params = {
      scriptId: Types.Runtime.ScriptId.t, /* Id of the script to run. */
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies in which execution context to perform script run. If the parameter is omitted the
evaluation will be performed in the context of the inspected page. */
      [@yojson.option]
      objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
      [@yojson.option]
      silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
      [@yojson.option]
      includeCommandLineAPI: option(bool), /* Determines whether Command Line API should be available during the evaluation. */
      [@yojson.option]
      returnByValue: option(bool), /* Whether the result is expected to be a JSON object which should be sent by value. */
      [@yojson.option]
      generatePreview: option(bool), /* Whether preview should be generated for the result. */
      [@yojson.option]
      awaitPromise: option(bool) /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */,
    };

    [@deriving yojson]
    type result = {
      result: Types.Runtime.RemoteObject.t, /* Run result. */
      [@yojson.option]
      exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables or disables async call stacks tracking. */
  module SetAsyncCallStackDepth = {
    let name = "Runtime.setAsyncCallStackDepth";

    [@deriving yojson]
    type params = {
      maxDepth: float /* Maximum depth of async call stacks. Setting to `0` will effectively disable collecting async
call stacks (default). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetCustomObjectFormatterEnabled = {
    let name = "Runtime.setCustomObjectFormatterEnabled";

    [@deriving yojson]
    type params = {enabled: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetMaxCallStackSizeToCapture = {
    let name = "Runtime.setMaxCallStackSizeToCapture";

    [@deriving yojson]
    type params = {size: float /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Terminate current or next JavaScript execution.
     Will cancel the termination when the outer-most script execution ends. */
  module TerminateExecution = {
    let name = "Runtime.terminateExecution";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* If executionContextId is empty, adds binding with the given name on the
     global objects of all inspected contexts, including those created later,
     bindings survive reloads.
     Binding function takes exactly one argument, this argument should be string,
     in case of any other input, function throws an exception.
     Each binding function call produces Runtime.bindingCalled notification. */
  module AddBinding = {
    let name = "Runtime.addBinding";

    [@deriving yojson]
    type params = {
      name: string, /* No description provided */
      [@yojson.option]
      executionContextId: option(Types.Runtime.ExecutionContextId.t), /* If specified, the binding would only be exposed to the specified
execution context. If omitted and `executionContextName` is not set,
the binding is exposed to all execution contexts of the target.
This parameter is mutually exclusive with `executionContextName`. */
      [@yojson.option]
      executionContextName: option(string) /* If specified, the binding is exposed to the executionContext with
matching name, even for contexts created after the binding is added.
See also `ExecutionContext.name` and `worldName` parameter to
`Page.addScriptToEvaluateOnNewDocument`.
This parameter is mutually exclusive with `executionContextId`. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* This method does not remove binding function from global object but
     unsubscribes current runtime agent from Runtime.bindingCalled notifications. */
  module RemoveBinding = {
    let name = "Runtime.removeBinding";

    [@deriving yojson]
    type params = {name: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Schema = {
  /* Returns supported domains. */
  module GetDomains = {
    let name = "Schema.getDomains";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      domains: array(Types.Schema.Domain.t) /* List of supported domains. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Security = {
  /* Disables tracking security state changes. */
  module Disable = {
    let name = "Security.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables tracking security state changes. */
  module Enable = {
    let name = "Security.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable/disable whether all certificate errors should be ignored. */
  module SetIgnoreCertificateErrors = {
    let name = "Security.setIgnoreCertificateErrors";

    [@deriving yojson]
    type params = {
      ignore: bool /* If true, all certificate errors will be ignored. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Handles a certificate error that fired a certificateError event. */
  module HandleCertificateError = {
    let name = "Security.handleCertificateError";

    [@deriving yojson]
    type params = {
      eventId: float, /* The ID of the event. */
      action: Types.Security.CertificateErrorAction.t /* The action to take on the certificate error. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enable/disable overriding certificate errors. If enabled, all certificate error events need to
     be handled by the DevTools client and should be answered with `handleCertificateError` commands. */
  module SetOverrideCertificateErrors = {
    let name = "Security.setOverrideCertificateErrors";

    [@deriving yojson]
    type params = {
      override: bool /* If true, certificate errors will be overridden. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module ServiceWorker = {
  /* No description provided */
  module DeliverPushMessage = {
    let name = "ServiceWorker.deliverPushMessage";

    [@deriving yojson]
    type params = {
      origin: string, /* No description provided */
      registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
      data: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Disable = {
    let name = "ServiceWorker.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module DispatchSyncEvent = {
    let name = "ServiceWorker.dispatchSyncEvent";

    [@deriving yojson]
    type params = {
      origin: string, /* No description provided */
      registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
      tag: string, /* No description provided */
      lastChance: bool /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module DispatchPeriodicSyncEvent = {
    let name = "ServiceWorker.dispatchPeriodicSyncEvent";

    [@deriving yojson]
    type params = {
      origin: string, /* No description provided */
      registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
      tag: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Enable = {
    let name = "ServiceWorker.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module InspectWorker = {
    let name = "ServiceWorker.inspectWorker";

    [@deriving yojson]
    type params = {versionId: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SetForceUpdateOnPageLoad = {
    let name = "ServiceWorker.setForceUpdateOnPageLoad";

    [@deriving yojson]
    type params = {forceUpdateOnPageLoad: bool /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module SkipWaiting = {
    let name = "ServiceWorker.skipWaiting";

    [@deriving yojson]
    type params = {scopeURL: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StartWorker = {
    let name = "ServiceWorker.startWorker";

    [@deriving yojson]
    type params = {scopeURL: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StopAllWorkers = {
    let name = "ServiceWorker.stopAllWorkers";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module StopWorker = {
    let name = "ServiceWorker.stopWorker";

    [@deriving yojson]
    type params = {versionId: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module Unregister = {
    let name = "ServiceWorker.unregister";

    [@deriving yojson]
    type params = {scopeURL: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* No description provided */
  module UpdateRegistration = {
    let name = "ServiceWorker.updateRegistration";

    [@deriving yojson]
    type params = {scopeURL: string /* No description provided */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Storage = {
  /* Clears storage for origin. */
  module ClearDataForOrigin = {
    let name = "Storage.clearDataForOrigin";

    [@deriving yojson]
    type params = {
      origin: string, /* Security origin. */
      storageTypes: string /* Comma separated list of StorageType to clear. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all browser cookies. */
  module GetCookies = {
    let name = "Storage.getCookies";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
    };

    [@deriving yojson]
    type result = {
      cookies: array(Types.Network.Cookie.t) /* Array of cookie objects. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets given cookies. */
  module SetCookies = {
    let name = "Storage.setCookies";

    [@deriving yojson]
    type params = {
      cookies: array(Types.Network.CookieParam.t), /* Cookies to be set. */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears cookies. */
  module ClearCookies = {
    let name = "Storage.clearCookies";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns usage and quota in bytes. */
  module GetUsageAndQuota = {
    let name = "Storage.getUsageAndQuota";

    [@deriving yojson]
    type params = {origin: string /* Security origin. */};

    [@deriving yojson]
    type result = {
      usage: float, /* Storage usage (bytes). */
      quota: float, /* Storage quota (bytes). */
      overrideActive: bool, /* Whether or not the origin has an active storage quota override */
      usageBreakdown: array(Types.Storage.UsageForType.t) /* Storage usage per type (bytes). */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Override quota for the specified origin */
  module OverrideQuotaForOrigin = {
    let name = "Storage.overrideQuotaForOrigin";

    [@deriving yojson]
    type params = {
      origin: string, /* Security origin. */
      [@yojson.option]
      quotaSize: option(float) /* The quota size (in bytes) to override the original quota with.
If this is called multiple times, the overridden quota will be equal to
the quotaSize provided in the final call. If this is called without
specifying a quotaSize, the quota will be reset to the default value for
the specified origin. If this is called multiple times with different
origins, the override will be maintained for each origin until it is
disabled (called without a quotaSize). */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Registers origin to be notified when an update occurs to its cache storage list. */
  module TrackCacheStorageForOrigin = {
    let name = "Storage.trackCacheStorageForOrigin";

    [@deriving yojson]
    type params = {origin: string /* Security origin. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Registers origin to be notified when an update occurs to its IndexedDB. */
  module TrackIndexedDBForOrigin = {
    let name = "Storage.trackIndexedDBForOrigin";

    [@deriving yojson]
    type params = {origin: string /* Security origin. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Unregisters origin from receiving notifications for cache storage. */
  module UntrackCacheStorageForOrigin = {
    let name = "Storage.untrackCacheStorageForOrigin";

    [@deriving yojson]
    type params = {origin: string /* Security origin. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Unregisters origin from receiving notifications for IndexedDB. */
  module UntrackIndexedDBForOrigin = {
    let name = "Storage.untrackIndexedDBForOrigin";

    [@deriving yojson]
    type params = {origin: string /* Security origin. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns the number of stored Trust Tokens per issuer for the
     current browsing context. */
  module GetTrustTokens = {
    let name = "Storage.getTrustTokens";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      tokens: array(Types.Storage.TrustTokens.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes all Trust Tokens issued by the provided issuerOrigin.
     Leaves other stored data, including the issuer's Redemption Records, intact. */
  module ClearTrustTokens = {
    let name = "Storage.clearTrustTokens";

    [@deriving yojson]
    type params = {issuerOrigin: string /* No description provided */};

    [@deriving yojson]
    type result = {
      didDeleteTokens: bool /* True if any tokens were deleted, false otherwise. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module SystemInfo = {
  /* Returns information about the system. */
  module GetInfo = {
    let name = "SystemInfo.getInfo";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      gpu: Types.SystemInfo.GPUInfo.t, /* Information about the GPUs on the system. */
      modelName: string, /* A platform-dependent description of the model of the machine. On Mac OS, this is, for
example, 'MacBookPro'. Will be the empty string if not supported. */
      modelVersion: string, /* A platform-dependent description of the version of the machine. On Mac OS, this is, for
example, '10.1'. Will be the empty string if not supported. */
      commandLine: string /* The command line string used to launch the browser. Will be the empty string if not
supported. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns information about all running processes. */
  module GetProcessInfo = {
    let name = "SystemInfo.getProcessInfo";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      processInfo: array(Types.SystemInfo.ProcessInfo.t) /* An array of process info blocks. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Target = {
  /* Activates (focuses) the target. */
  module ActivateTarget = {
    let name = "Target.activateTarget";

    [@deriving yojson]
    type params = {
      targetId: Types.Target.TargetID.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Attaches to the target with given id. */
  module AttachToTarget = {
    let name = "Target.attachToTarget";

    [@deriving yojson]
    type params = {
      targetId: Types.Target.TargetID.t, /* No description provided */
      [@yojson.option]
      flatten: option(bool) /* Enables "flat" access to the session via specifying sessionId attribute in the commands.
We plan to make this the default, deprecate non-flattened mode,
and eventually retire it. See crbug.com/991325. */,
    };

    [@deriving yojson]
    type result = {
      sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Attaches to the browser target, only uses flat sessionId mode. */
  module AttachToBrowserTarget = {
    let name = "Target.attachToBrowserTarget";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Closes the target. If the target is a page that gets closed too. */
  module CloseTarget = {
    let name = "Target.closeTarget";

    [@deriving yojson]
    type params = {
      targetId: Types.Target.TargetID.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Inject object to the target's main frame that provides a communication
     channel with browser target.

     Injected object will be available as `window[bindingName]`.

     The object has the follwing API:
     - `binding.send(json)` - a method to send messages over the remote debugging protocol
     - `binding.onmessage = json => handleMessage(json)` - a callback that will be called for the protocol notifications and command responses. */
  module ExposeDevToolsProtocol = {
    let name = "Target.exposeDevToolsProtocol";

    [@deriving yojson]
    type params = {
      targetId: Types.Target.TargetID.t, /* No description provided */
      [@yojson.option]
      bindingName: option(string) /* Binding name, 'cdp' if not specified. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates a new empty BrowserContext. Similar to an incognito profile but you can have more than
     one. */
  module CreateBrowserContext = {
    let name = "Target.createBrowserContext";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      disposeOnDetach: option(bool), /* If specified, disposes this context when debugging session disconnects. */
      [@yojson.option]
      proxyServer: option(string), /* Proxy server, similar to the one passed to --proxy-server */
      [@yojson.option]
      proxyBypassList: option(string) /* Proxy bypass list, similar to the one passed to --proxy-bypass-list */,
    };

    [@deriving yojson]
    type result = {
      browserContextId: Types.Browser.BrowserContextID.t /* The id of the context created. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all browser contexts created with `Target.createBrowserContext` method. */
  module GetBrowserContexts = {
    let name = "Target.getBrowserContexts";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      browserContextIds: array(Types.Browser.BrowserContextID.t) /* An array of browser context ids. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates a new page. */
  module CreateTarget = {
    let name = "Target.createTarget";

    [@deriving yojson]
    type params = {
      url: string, /* The initial URL the page will be navigated to. An empty string indicates about:blank. */
      [@yojson.option]
      width: option(float), /* Frame width in DIP (headless chrome only). */
      [@yojson.option]
      height: option(float), /* Frame height in DIP (headless chrome only). */
      [@yojson.option]
      browserContextId: option(Types.Browser.BrowserContextID.t), /* The browser context to create the page in. */
      [@yojson.option]
      enableBeginFrameControl: option(bool), /* Whether BeginFrames for this target will be controlled via DevTools (headless chrome only,
not supported on MacOS yet, false by default). */
      [@yojson.option]
      newWindow: option(bool), /* Whether to create a new Window or Tab (chrome-only, false by default). */
      [@yojson.option]
      background: option(bool) /* Whether to create the target in background or foreground (chrome-only,
false by default). */,
    };

    [@deriving yojson]
    type result = {
      targetId: Types.Target.TargetID.t /* The id of the page opened. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Detaches session with given id. */
  module DetachFromTarget = {
    let name = "Target.detachFromTarget";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t), /* Session to detach. */
      [@yojson.option]
      targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Deletes a BrowserContext. All the belonging pages will be closed without calling their
     beforeunload hooks. */
  module DisposeBrowserContext = {
    let name = "Target.disposeBrowserContext";

    [@deriving yojson]
    type params = {
      browserContextId: Types.Browser.BrowserContextID.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns information about a target. */
  module GetTargetInfo = {
    let name = "Target.getTargetInfo";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      targetId: option(Types.Target.TargetID.t) /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      targetInfo: Types.Target.TargetInfo.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Retrieves a list of available targets. */
  module GetTargets = {
    let name = "Target.getTargets";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      targetInfos: array(Types.Target.TargetInfo.t) /* The list of targets. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sends protocol message over session with given id.
     Consider using flat mode instead; see commands attachToTarget, setAutoAttach,
     and crbug.com/991325. */
  module SendMessageToTarget = {
    let name = "Target.sendMessageToTarget";

    [@deriving yojson]
    type params = {
      message: string, /* No description provided */
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t), /* Identifier of the session. */
      [@yojson.option]
      targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Controls whether to automatically attach to new targets which are considered to be related to
     this one. When turned on, attaches to all existing related targets as well. When turned off,
     automatically detaches from all currently attached targets. */
  module SetAutoAttach = {
    let name = "Target.setAutoAttach";

    [@deriving yojson]
    type params = {
      autoAttach: bool, /* Whether to auto-attach to related targets. */
      waitForDebuggerOnStart: bool, /* Whether to pause new targets when attaching to them. Use `Runtime.runIfWaitingForDebugger`
to run paused targets. */
      [@yojson.option]
      flatten: option(bool) /* Enables "flat" access to the session via specifying sessionId attribute in the commands.
We plan to make this the default, deprecate non-flattened mode,
and eventually retire it. See crbug.com/991325. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Controls whether to discover available targets and notify via
     `targetCreated/targetInfoChanged/targetDestroyed` events. */
  module SetDiscoverTargets = {
    let name = "Target.setDiscoverTargets";

    [@deriving yojson]
    type params = {
      discover: bool /* Whether to discover available targets. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables target discovery for the specified locations, when `setDiscoverTargets` was set to
     `true`. */
  module SetRemoteLocations = {
    let name = "Target.setRemoteLocations";

    [@deriving yojson]
    type params = {
      locations: array(Types.Target.RemoteLocation.t) /* List of remote locations. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Tethering = {
  /* Request browser port binding. */
  module Bind = {
    let name = "Tethering.bind";

    [@deriving yojson]
    type params = {port: float /* Port number to bind. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Request browser port unbinding. */
  module Unbind = {
    let name = "Tethering.unbind";

    [@deriving yojson]
    type params = {port: float /* Port number to unbind. */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Tracing = {
  /* Stop trace events collection. */
  module End = {
    let name = "Tracing.end";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Gets supported tracing categories. */
  module GetCategories = {
    let name = "Tracing.getCategories";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = {
      categories: array(string) /* A list of supported tracing categories. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Record a clock sync marker in the trace. */
  module RecordClockSyncMarker = {
    let name = "Tracing.recordClockSyncMarker";

    [@deriving yojson]
    type params = {syncId: string /* The ID of this clock sync marker */};

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Request a global memory dump. */
  module RequestMemoryDump = {
    let name = "Tracing.requestMemoryDump";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      deterministic: option(bool), /* Enables more deterministic results by forcing garbage collection */
      [@yojson.option]
      levelOfDetail: option(Types.Tracing.MemoryDumpLevelOfDetail.t) /* Specifies level of details in memory dump. Defaults to "detailed". */,
    };

    [@deriving yojson]
    type result = {
      dumpGuid: string, /* GUID of the resulting global memory dump. */
      success: bool /* True iff the global memory dump succeeded. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Start trace events collection. */
  module Start = {
    let name = "Tracing.start";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      categories: option(string), /* Category/tag filter */
      [@yojson.option]
      options: option(string), /* Tracing options */
      [@yojson.option]
      bufferUsageReportingInterval: option(float), /* If set, the agent will issue bufferUsage events at this interval, specified in milliseconds */
      [@yojson.option]
      transferMode: option(string), /* Whether to report trace events as series of dataCollected events or to save trace to a
stream (defaults to `ReportEvents`). */
      [@yojson.option]
      streamFormat: option(Types.Tracing.StreamFormat.t), /* Trace data format to use. This only applies when using `ReturnAsStream`
transfer mode (defaults to `json`). */
      [@yojson.option]
      streamCompression: option(Types.Tracing.StreamCompression.t), /* Compression format to use. This only applies when using `ReturnAsStream`
transfer mode (defaults to `none`) */
      [@yojson.option]
      traceConfig: option(Types.Tracing.TraceConfig.t), /* No description provided */
      [@yojson.option]
      perfettoConfig: option(string), /* Base64-encoded serialized perfetto.protos.TraceConfig protobuf message
When specified, the parameters `categories`, `options`, `traceConfig`
are ignored. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      tracingBackend: option(Types.Tracing.TracingBackend.t) /* Backend type (defaults to `auto`) */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Fetch = {
  /* Disables the fetch domain. */
  module Disable = {
    let name = "Fetch.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Enables issuing of requestPaused events. A request will be paused until client
     calls one of failRequest, fulfillRequest or continueRequest/continueWithAuth. */
  module Enable = {
    let name = "Fetch.enable";

    [@deriving yojson]
    type params = {
      [@yojson.option]
      patterns: option(array(Types.Fetch.RequestPattern.t)), /* If specified, only requests matching any of these patterns will produce
fetchRequested event and will be paused until clients response. If not set,
all requests will be affected. */
      [@yojson.option]
      handleAuthRequests: option(bool) /* If true, authRequired events will be issued and requests will be paused
expecting a call to continueWithAuth. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Causes the request to fail with specified reason. */
  module FailRequest = {
    let name = "Fetch.failRequest";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
      errorReason: Types.Network.ErrorReason.t /* Causes the request to fail with the given reason. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Provides response to the request. */
  module FulfillRequest = {
    let name = "Fetch.fulfillRequest";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
      responseCode: float, /* An HTTP response code. */
      [@yojson.option]
      responseHeaders: option(array(Types.Fetch.HeaderEntry.t)), /* Response headers. */
      [@yojson.option]
      binaryResponseHeaders: option(string), /* Alternative way of specifying response headers as a \0-separated
series of name: value pairs. Prefer the above method unless you
need to represent some non-UTF8 values that can't be transmitted
over the protocol as text. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      body: option(string), /* A response body. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      responsePhrase: option(string) /* A textual representation of responseCode.
If absent, a standard phrase matching responseCode is used. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Continues the request, optionally modifying some of its parameters. */
  module ContinueRequest = {
    let name = "Fetch.continueRequest";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
      [@yojson.option]
      url: option(string), /* If set, the request url will be modified in a way that's not observable by page. */
      [@yojson.option]
      method: option(string), /* If set, the request method is overridden. */
      [@yojson.option]
      postData: option(string), /* If set, overrides the post data in the request. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option]
      headers: option(array(Types.Fetch.HeaderEntry.t)) /* If set, overrides the request headers. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Continues a request supplying authChallengeResponse following authRequired event. */
  module ContinueWithAuth = {
    let name = "Fetch.continueWithAuth";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t, /* An id the client received in authRequired event. */
      authChallengeResponse: Types.Fetch.AuthChallengeResponse.t /* Response to  with an authChallenge. */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Causes the body of the response to be received from the server and
     returned as a single string. May only be issued for a request that
     is paused in the Response stage and is mutually exclusive with
     takeResponseBodyForInterceptionAsStream. Calling other methods that
     affect the request or disabling fetch domain before body is received
     results in an undefined behavior. */
  module GetResponseBody = {
    let name = "Fetch.getResponseBody";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t /* Identifier for the intercepted request to get body for. */,
    };

    [@deriving yojson]
    type result = {
      body: string, /* Response body. */
      base64Encoded: bool /* True, if content was sent as base64. */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a handle to the stream representing the response body.
     The request must be paused in the HeadersReceived stage.
     Note that after this command the request can't be continued
     as is -- client either needs to cancel it or to provide the
     response body.
     The stream only supports sequential read, IO.read will fail if the position
     is specified.
     This method is mutually exclusive with getResponseBody.
     Calling other methods that affect the request or disabling fetch
     domain before body is received results in an undefined behavior. */
  module TakeResponseBodyAsStream = {
    let name = "Fetch.takeResponseBodyAsStream";

    [@deriving yojson]
    type params = {
      requestId: Types.Fetch.RequestId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      stream: Types.IO.StreamHandle.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module WebAudio = {
  /* Enables the WebAudio domain and starts sending context lifetime events. */
  module Enable = {
    let name = "WebAudio.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables the WebAudio domain. */
  module Disable = {
    let name = "WebAudio.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Fetch the realtime data from the registered contexts. */
  module GetRealtimeData = {
    let name = "WebAudio.getRealtimeData";

    [@deriving yojson]
    type params = {
      contextId: Types.WebAudio.GraphObjectId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      realtimeData: Types.WebAudio.ContextRealtimeData.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module WebAuthn = {
  /* Enable the WebAuthn domain and start intercepting credential storage and
     retrieval with a virtual authenticator. */
  module Enable = {
    let name = "WebAuthn.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disable the WebAuthn domain. */
  module Disable = {
    let name = "WebAuthn.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Creates and adds a virtual authenticator. */
  module AddVirtualAuthenticator = {
    let name = "WebAuthn.addVirtualAuthenticator";

    [@deriving yojson]
    type params = {
      options: Types.WebAuthn.VirtualAuthenticatorOptions.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes the given authenticator. */
  module RemoveVirtualAuthenticator = {
    let name = "WebAuthn.removeVirtualAuthenticator";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Adds the credential to the specified authenticator. */
  module AddCredential = {
    let name = "WebAuthn.addCredential";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
      credential: Types.WebAuthn.Credential.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns a single credential stored in the given virtual authenticator that
     matches the credential ID. */
  module GetCredential = {
    let name = "WebAuthn.getCredential";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
      credentialId: string /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      credential: Types.WebAuthn.Credential.t /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Returns all the credentials stored in the given virtual authenticator. */
  module GetCredentials = {
    let name = "WebAuthn.getCredentials";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = {
      credentials: array(Types.WebAuthn.Credential.t) /* No description provided */,
    };

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Removes a credential from the authenticator. */
  module RemoveCredential = {
    let name = "WebAuthn.removeCredential";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
      credentialId: string /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Clears all the credentials from the specified device. */
  module ClearCredentials = {
    let name = "WebAuthn.clearCredentials";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets whether User Verification succeeds or fails for an authenticator.
     The default is true. */
  module SetUserVerified = {
    let name = "WebAuthn.setUserVerified";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
      isUserVerified: bool /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Sets whether tests of user presence will succeed immediately (if true) or fail to resolve (if false) for an authenticator.
     The default is true. */
  module SetAutomaticPresenceSimulation = {
    let name = "WebAuthn.setAutomaticPresenceSimulation";

    [@deriving yojson]
    type params = {
      authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
      enabled: bool /* No description provided */,
    };

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
module Media = {
  /* Enables the Media domain */
  module Enable = {
    let name = "Media.enable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
  /* Disables the Media domain. */
  module Disable = {
    let name = "Media.disable";

    [@deriving yojson]
    type params = Types.empty;

    [@deriving yojson]
    type result = Types.assoc;

    [@deriving yojson]
    type request = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      method: string,
      params,
    };

    [@deriving yojson]
    type response = {
      id: int,
      [@yojson.option]
      sessionId: option(Types.Target.SessionID.t),
      result,
    };

    let parse = response =>
      response |> Yojson.Safe.from_string |> response_of_yojson;
  };
};
