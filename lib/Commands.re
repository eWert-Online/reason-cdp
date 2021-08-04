module Accessibility = {
  /* Disables the accessibility domain. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Accessibility.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables the accessibility domain which causes `AXNodeId`s to remain consistent between method calls.
     This turns on accessibility for the page, which can impact performance until accessibility is disabled. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Accessibility.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetches the accessibility node and partial accessibility tree for this DOM node, if it exists. */
  module GetPartialAXTree = {
    module Response: {
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* The `Accessibility.AXNode` for this DOM node, if it exists, plus its ancestors, siblings and
children, if requested. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* The `Accessibility.AXNode` for this DOM node, if it exists, plus its ancestors, siblings and
children, if requested. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to get the partial accessibility tree for. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to get the partial accessibility tree for. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper to get the partial accessibility tree for. */
        [@yojson.option] [@key "fetchRelatives"]
        fetchRelatives: option(bool) /* Whether to fetch this nodes ancestors, siblings and children. Defaults to true. */,
      };
      let make =
          (~nodeId=?, ~backendNodeId=?, ~objectId=?, ~fetchRelatives=?, ()) => {
        {nodeId, backendNodeId, objectId, fetchRelatives};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Accessibility.getPartialAXTree", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetches the entire accessibility tree for the root Document */
  module GetFullAXTree = {
    module Response: {
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "max_depth"]
        max_depth: option(float) /* The maximum depth at which descendants of the root node should be retrieved.
If omitted, the full tree is returned. */,
      };
      let make = (~max_depth=?, ()) => {
        {max_depth: max_depth};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Accessibility.getFullAXTree", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetches a particular accessibility node by AXNodeId.
     Requires `enable()` to have been called previously. */
  module GetChildAXNodes = {
    module Response: {
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "id"]
        id: Types.Accessibility.AXNodeId.t /* No description provided */,
      };
      let make = (~id, ()) => {
        {id: id};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Accessibility.getChildAXNodes", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Query a DOM node's accessibility subtree for accessible name and role.
     This command computes the name and role for all nodes in the subtree, including those that are
     ignored for accessibility, and returns those that mactch the specified name and role. If no DOM
     node is specified, or the DOM node does not exist, the command returns an error. If neither
     `accessibleName` or `role` is specified, it returns all the accessibility nodes in the subtree. */
  module QueryAXTree = {
    module Response: {
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* A list of `Accessibility.AXNode` matching the specified attributes,
including nodes that are ignored for accessibility. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodes"]
        nodes: list(Types.Accessibility.AXNode.t) /* A list of `Accessibility.AXNode` matching the specified attributes,
including nodes that are ignored for accessibility. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node for the root to query. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node for the root to query. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper for the root to query. */
        [@yojson.option] [@key "accessibleName"]
        accessibleName: option(string), /* Find nodes with this computed name. */
        [@yojson.option] [@key "role"]
        role: option(string) /* Find nodes with this computed role. */,
      };
      let make =
          (
            ~nodeId=?,
            ~backendNodeId=?,
            ~objectId=?,
            ~accessibleName=?,
            ~role=?,
            (),
          ) => {
        {nodeId, backendNodeId, objectId, accessibleName, role};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Accessibility.queryAXTree", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Animation = {
  /* Disables animation domain notifications. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Animation.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables animation domain notifications. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Animation.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the current time of the an animation. */
  module GetCurrentTime = {
    module Response: {
      type result = {
        [@key "currentTime"]
        currentTime: float /* Current time of the page. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "currentTime"]
        currentTime: float /* Current time of the page. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "id"]
        id: string /* Id of animation. */,
      };
      let make = (~id, ()) => {
        {id: id};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.getCurrentTime", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Gets the playback rate of the document timeline. */
  module GetPlaybackRate = {
    module Response: {
      type result = {
        [@key "playbackRate"]
        playbackRate: float /* Playback rate for animations on page. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "playbackRate"]
        playbackRate: float /* Playback rate for animations on page. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Animation.getPlaybackRate", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Releases a set of animations to no longer be manipulated. */
  module ReleaseAnimations = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "animations"]
        animations: list(string) /* List of animation ids to seek. */,
      };
      let make = (~animations, ()) => {
        {animations: animations};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.releaseAnimations", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Gets the remote object of the Animation. */
  module ResolveAnimation = {
    module Response: {
      type result = {
        [@key "remoteObject"]
        remoteObject: Types.Runtime.RemoteObject.t /* Corresponding remote object. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "remoteObject"]
        remoteObject: Types.Runtime.RemoteObject.t /* Corresponding remote object. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "animationId"]
        animationId: string /* Animation id. */,
      };
      let make = (~animationId, ()) => {
        {animationId: animationId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.resolveAnimation", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Seek a set of animations to a particular time within each animation. */
  module SeekAnimations = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "animations"]
        animations: list(string), /* List of animation ids to seek. */
        [@key "currentTime"]
        currentTime: float /* Set the current time of each animation. */,
      };
      let make = (~animations, ~currentTime, ()) => {
        {animations, currentTime};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.seekAnimations", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets the paused state of a set of animations. */
  module SetPaused = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "animations"]
        animations: list(string), /* Animations to set the pause state of. */
        [@key "paused"]
        paused: bool /* Paused state to set to. */,
      };
      let make = (~animations, ~paused, ()) => {
        {animations, paused};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.setPaused", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets the playback rate of the document timeline. */
  module SetPlaybackRate = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "playbackRate"]
        playbackRate: float /* Playback rate for animations on page */,
      };
      let make = (~playbackRate, ()) => {
        {playbackRate: playbackRate};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.setPlaybackRate", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets the timing of an animation node. */
  module SetTiming = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "animationId"]
        animationId: string, /* Animation id. */
        [@key "duration"]
        duration: float, /* Duration of the animation. */
        [@key "delay"]
        delay: float /* Delay of the animation. */,
      };
      let make = (~animationId, ~duration, ~delay, ()) => {
        {animationId, duration, delay};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Animation.setTiming", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module ApplicationCache = {
  /* Enables application cache domain notifications. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "ApplicationCache.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns relevant application cache data for the document in given frame. */
  module GetApplicationCacheForFrame = {
    module Response: {
      type result = {
        [@key "applicationCache"]
        applicationCache: Types.ApplicationCache.ApplicationCache.t /* Relevant application cache data for the document in given frame. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "applicationCache"]
        applicationCache: Types.ApplicationCache.ApplicationCache.t /* Relevant application cache data for the document in given frame. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t /* Identifier of the frame containing document whose application cache is retrieved. */,
      };
      let make = (~frameId, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "ApplicationCache.getApplicationCacheForFrame",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns array of frame identifiers with manifest urls for each frame containing a document
     associated with some application cache. */
  module GetFramesWithManifests = {
    module Response: {
      type result = {
        [@key "frameIds"]
        frameIds: list(Types.ApplicationCache.FrameWithManifest.t) /* Array of frame identifiers with manifest urls for each frame containing a document
associated with some application cache. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "frameIds"]
        frameIds: list(Types.ApplicationCache.FrameWithManifest.t) /* Array of frame identifiers with manifest urls for each frame containing a document
associated with some application cache. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "ApplicationCache.getFramesWithManifests", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns manifest URL for document in the given frame. */
  module GetManifestForFrame = {
    module Response: {
      type result = {
        [@key "manifestURL"]
        manifestURL: string /* Manifest URL for document in the given frame. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "manifestURL"]
        manifestURL: string /* Manifest URL for document in the given frame. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t /* Identifier of the frame containing document whose manifest is retrieved. */,
      };
      let make = (~frameId, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "ApplicationCache.getManifestForFrame",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Audits = {
  /* Returns the response body and size if it were re-encoded with the specified settings. Only
     applies to images. */
  module GetEncodedResponse = {
    module Response: {
      type result = {
        [@yojson.option] [@key "body"]
        body: option(string), /* The encoded body as a base64 string. Omitted if sizeOnly is true. (Encoded as a base64 string when passed over JSON) */
        [@key "originalSize"]
        originalSize: float, /* Size before re-encoding. */
        [@key "encodedSize"]
        encodedSize: float /* Size after re-encoding. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "body"]
        body: option(string), /* The encoded body as a base64 string. Omitted if sizeOnly is true. (Encoded as a base64 string when passed over JSON) */
        [@key "originalSize"]
        originalSize: float, /* Size before re-encoding. */
        [@key "encodedSize"]
        encodedSize: float /* Size after re-encoding. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type getencodedresponse_encoding = [ | `webp | `jpeg | `png];
      let getencodedresponse_encoding_of_yojson =
        fun
        | `String("webp") => `webp
        | `String("jpeg") => `jpeg
        | `String("png") => `png
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_getencodedresponse_encoding =
        fun
        | `webp => `String("webp")
        | `jpeg => `String("jpeg")
        | `png => `String("png");
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Network.RequestId.t, /* Identifier of the network request to get content for. */
        [@key "encoding"]
        encoding: getencodedresponse_encoding, /* The encoding to use. */
        [@yojson.option] [@key "quality"]
        quality: option(float), /* The quality of the encoding (0-1). (defaults to 1) */
        [@yojson.option] [@key "sizeOnly"]
        sizeOnly: option(bool) /* Whether to only return the size information (defaults to false). */,
      };
      let make = (~requestId, ~encoding, ~quality=?, ~sizeOnly=?, ()) => {
        {requestId, encoding, quality, sizeOnly};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Audits.getEncodedResponse", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables issues domain, prevents further issues from being reported to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Audits.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables issues domain, sends the issues collected so far to the client by means of the
     `issueAdded` event. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Audits.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Runs the contrast check for the target page. Found issues are reported
     using Audits.issueAdded event. */
  module CheckContrast = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "reportAAA"]
        reportAAA: option(bool) /* Whether to report WCAG AAA level issues. Default is false. */,
      };
      let make = (~reportAAA=?, ()) => {
        {reportAAA: reportAAA};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Audits.checkContrast", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module BackgroundService = {
  /* Enables event updates for the service. */
  module StartObserving = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "service"]
        service: Types.BackgroundService.ServiceName.t /* No description provided */,
      };
      let make = (~service, ()) => {
        {service: service};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "BackgroundService.startObserving", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables event updates for the service. */
  module StopObserving = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "service"]
        service: Types.BackgroundService.ServiceName.t /* No description provided */,
      };
      let make = (~service, ()) => {
        {service: service};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "BackgroundService.stopObserving", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set the recording state for the service. */
  module SetRecording = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "shouldRecord"]
        shouldRecord: bool, /* No description provided */
        [@key "service"]
        service: Types.BackgroundService.ServiceName.t /* No description provided */,
      };
      let make = (~shouldRecord, ~service, ()) => {
        {shouldRecord, service};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "BackgroundService.setRecording", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears all stored data for the service. */
  module ClearEvents = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "service"]
        service: Types.BackgroundService.ServiceName.t /* No description provided */,
      };
      let make = (~service, ()) => {
        {service: service};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "BackgroundService.clearEvents", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Browser = {
  /* Set permission settings for given origin. */
  module SetPermission = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "permission"]
        permission: Types.Browser.PermissionDescriptor.t, /* Descriptor of permission to override. */
        [@key "setting"]
        setting: Types.Browser.PermissionSetting.t, /* Setting of the permission. */
        [@yojson.option] [@key "origin"]
        origin: option(string), /* Origin the permission applies to, all origins if not specified. */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* Context to override. When omitted, default browser context is used. */,
      };
      let make = (~permission, ~setting, ~origin=?, ~browserContextId=?, ()) => {
        {permission, setting, origin, browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.setPermission", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Grant specific permissions to the given origin and reject all others. */
  module GrantPermissions = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "permissions"]
        permissions: list(Types.Browser.PermissionType.t), /* No description provided */
        [@yojson.option] [@key "origin"]
        origin: option(string), /* Origin the permission applies to, all origins if not specified. */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to override permissions. When omitted, default browser context is used. */,
      };
      let make = (~permissions, ~origin=?, ~browserContextId=?, ()) => {
        {permissions, origin, browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.grantPermissions", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Reset all permission management for all origins. */
  module ResetPermissions = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to reset permissions. When omitted, default browser context is used. */,
      };
      let make = (~browserContextId=?, ()) => {
        {browserContextId: browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.resetPermissions", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set the behavior when downloading a file. */
  module SetDownloadBehavior = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setdownloadbehavior_behavior = [
        | `deny
        | `allow
        | `allowAndName
        | `default
      ];
      let setdownloadbehavior_behavior_of_yojson =
        fun
        | `String("deny") => `deny
        | `String("allow") => `allow
        | `String("allowAndName") => `allowAndName
        | `String("default") => `default
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setdownloadbehavior_behavior =
        fun
        | `deny => `String("deny")
        | `allow => `String("allow")
        | `allowAndName => `String("allowAndName")
        | `default => `String("default");
      [@deriving yojson]
      type t = {
        [@key "behavior"]
        behavior: setdownloadbehavior_behavior, /* Whether to allow all or deny all download requests, or use default Chrome behavior if
available (otherwise deny). |allowAndName| allows download and names files according to
their dowmload guids. */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t), /* BrowserContext to set download behavior. When omitted, default browser context is used. */
        [@yojson.option] [@key "downloadPath"]
        downloadPath: option(string), /* The default path to save downloaded files to. This is required if behavior is set to 'allow'
or 'allowAndName'. */
        [@yojson.option] [@key "eventsEnabled"]
        eventsEnabled: option(bool) /* Whether to emit download events (defaults to false). */,
      };
      let make =
          (
            ~behavior,
            ~browserContextId=?,
            ~downloadPath=?,
            ~eventsEnabled=?,
            (),
          ) => {
        {behavior, browserContextId, downloadPath, eventsEnabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.setDownloadBehavior", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Cancel a download if in progress */
  module CancelDownload = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "guid"]
        guid: string, /* Global unique identifier of the download. */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* BrowserContext to perform the action in. When omitted, default browser context is used. */,
      };
      let make = (~guid, ~browserContextId=?, ()) => {
        {guid, browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.cancelDownload", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Close browser gracefully. */
  module Close = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Browser.close", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Crashes browser on the main thread. */
  module Crash = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Browser.crash", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Crashes GPU process. */
  module CrashGpuProcess = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Browser.crashGpuProcess", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns version information. */
  module GetVersion = {
    module Response: {
      type result = {
        [@key "protocolVersion"]
        protocolVersion: string, /* Protocol version. */
        [@key "product"]
        product: string, /* Product name. */
        [@key "revision"]
        revision: string, /* Product revision. */
        [@key "userAgent"]
        userAgent: string, /* User-Agent. */
        [@key "jsVersion"]
        jsVersion: string /* V8 version. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "protocolVersion"]
        protocolVersion: string, /* Protocol version. */
        [@key "product"]
        product: string, /* Product name. */
        [@key "revision"]
        revision: string, /* Product revision. */
        [@key "userAgent"]
        userAgent: string, /* User-Agent. */
        [@key "jsVersion"]
        jsVersion: string /* V8 version. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Browser.getVersion", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the command line switches for the browser process if, and only if
     --enable-automation is on the commandline. */
  module GetBrowserCommandLine = {
    module Response: {
      type result = {
        [@key "arguments"]
        arguments: list(string) /* Commandline parameters */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "arguments"]
        arguments: list(string) /* Commandline parameters */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Browser.getBrowserCommandLine", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Get Chrome histograms. */
  module GetHistograms = {
    module Response: {
      type result = {
        [@key "histograms"]
        histograms: list(Types.Browser.Histogram.t) /* Histograms. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "histograms"]
        histograms: list(Types.Browser.Histogram.t) /* Histograms. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "query"]
        query: option(string), /* Requested substring in name. Only histograms which have query as a
substring in their name are extracted. An empty or absent query returns
all histograms. */
        [@yojson.option] [@key "delta"]
        delta: option(bool) /* If true, retrieve delta since last call. */,
      };
      let make = (~query=?, ~delta=?, ()) => {
        {query, delta};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.getHistograms", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Get a Chrome histogram by name. */
  module GetHistogram = {
    module Response: {
      type result = {
        [@key "histogram"]
        histogram: Types.Browser.Histogram.t /* Histogram. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "histogram"]
        histogram: Types.Browser.Histogram.t /* Histogram. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "name"]
        name: string, /* Requested histogram name. */
        [@yojson.option] [@key "delta"]
        delta: option(bool) /* If true, retrieve delta since last call. */,
      };
      let make = (~name, ~delta=?, ()) => {
        {name, delta};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.getHistogram", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Get position and size of the browser window. */
  module GetWindowBounds = {
    module Response: {
      type result = {
        [@key "bounds"]
        bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "bounds"]
        bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "windowId"]
        windowId: Types.Browser.WindowID.t /* Browser window id. */,
      };
      let make = (~windowId, ()) => {
        {windowId: windowId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.getWindowBounds", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Get the browser window that contains the devtools target. */
  module GetWindowForTarget = {
    module Response: {
      type result = {
        [@key "windowId"]
        windowId: Types.Browser.WindowID.t, /* Browser window id. */
        [@key "bounds"]
        bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "windowId"]
        windowId: Types.Browser.WindowID.t, /* Browser window id. */
        [@key "bounds"]
        bounds: Types.Browser.Bounds.t /* Bounds information of the window. When window state is 'minimized', the restored window
position and size are returned. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "targetId"]
        targetId: option(Types.Target.TargetID.t) /* Devtools agent host id. If called as a part of the session, associated targetId is used. */,
      };
      let make = (~targetId=?, ()) => {
        {targetId: targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.getWindowForTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set position and/or size of the browser window. */
  module SetWindowBounds = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "windowId"]
        windowId: Types.Browser.WindowID.t, /* Browser window id. */
        [@key "bounds"]
        bounds: Types.Browser.Bounds.t /* New window bounds. The 'minimized', 'maximized' and 'fullscreen' states cannot be combined
with 'left', 'top', 'width' or 'height'. Leaves unspecified fields unchanged. */,
      };
      let make = (~windowId, ~bounds, ()) => {
        {windowId, bounds};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.setWindowBounds", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set dock tile details, platform-specific. */
  module SetDockTile = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "badgeLabel"]
        badgeLabel: option(string), /* No description provided */
        [@yojson.option] [@key "image"]
        image: option(string) /* Png encoded image. (Encoded as a base64 string when passed over JSON) */,
      };
      let make = (~badgeLabel=?, ~image=?, ()) => {
        {badgeLabel, image};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.setDockTile", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Invoke custom browser commands used by telemetry. */
  module ExecuteBrowserCommand = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "commandId"]
        commandId: Types.Browser.BrowserCommandId.t /* No description provided */,
      };
      let make = (~commandId, ()) => {
        {commandId: commandId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Browser.executeBrowserCommand", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module CSS = {
  /* Inserts a new rule with the given `ruleText` in a stylesheet with given `styleSheetId`, at the
     position specified by `location`. */
  module AddRule = {
    module Response: {
      type result = {
        [@key "rule"]
        rule: Types.CSS.CSSRule.t /* The newly created rule. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "rule"]
        rule: Types.CSS.CSSRule.t /* The newly created rule. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* The css style sheet identifier where a new rule should be inserted. */
        [@key "ruleText"]
        ruleText: string, /* The text of a new rule. */
        [@key "location"]
        location: Types.CSS.SourceRange.t /* Text position of a new rule in the target style sheet. */,
      };
      let make = (~styleSheetId, ~ruleText, ~location, ()) => {
        {styleSheetId, ruleText, location};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.addRule", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all class names from specified stylesheet. */
  module CollectClassNames = {
    module Response: {
      type result = {
        [@key "classNames"]
        classNames: list(string) /* Class name list. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "classNames"]
        classNames: list(string) /* Class name list. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t /* No description provided */,
      };
      let make = (~styleSheetId, ()) => {
        {styleSheetId: styleSheetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.collectClassNames", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates a new special "via-inspector" stylesheet in the frame with given `frameId`. */
  module CreateStyleSheet = {
    module Response: {
      type result = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t /* Identifier of the created "via-inspector" stylesheet. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t /* Identifier of the created "via-inspector" stylesheet. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t /* Identifier of the frame where "via-inspector" stylesheet should be created. */,
      };
      let make = (~frameId, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.createStyleSheet", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables the CSS agent for the given page. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables the CSS agent for the given page. Clients should not assume that the CSS agent has been
     enabled until the result of this command is received. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Ensures that the given node will have specified pseudo-classes whenever its style is computed by
     the browser. */
  module ForcePseudoState = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* The element id for which to force the pseudo state. */
        [@key "forcedPseudoClasses"]
        forcedPseudoClasses: list(string) /* Element pseudo classes to force when computing the element's style. */,
      };
      let make = (~nodeId, ~forcedPseudoClasses, ()) => {
        {nodeId, forcedPseudoClasses};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.forcePseudoState", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetBackgroundColors = {
    module Response: {
      type result = {
        [@yojson.option] [@key "backgroundColors"]
        backgroundColors: option(list(string)), /* The range of background colors behind this element, if it contains any visible text. If no
visible text is present, this will be undefined. In the case of a flat background color,
this will consist of simply that color. In the case of a gradient, this will consist of each
of the color stops. For anything more complicated, this will be an empty array. Images will
be ignored (as if the image had failed to load). */
        [@yojson.option] [@key "computedFontSize"]
        computedFontSize: option(string), /* The computed font size for this node, as a CSS computed value string (e.g. '12px'). */
        [@yojson.option] [@key "computedFontWeight"]
        computedFontWeight: option(string) /* The computed font weight for this node, as a CSS computed value string (e.g. 'normal' or
'100'). */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "backgroundColors"]
        backgroundColors: option(list(string)), /* The range of background colors behind this element, if it contains any visible text. If no
visible text is present, this will be undefined. In the case of a flat background color,
this will consist of simply that color. In the case of a gradient, this will consist of each
of the color stops. For anything more complicated, this will be an empty array. Images will
be ignored (as if the image had failed to load). */
        [@yojson.option] [@key "computedFontSize"]
        computedFontSize: option(string), /* The computed font size for this node, as a CSS computed value string (e.g. '12px'). */
        [@yojson.option] [@key "computedFontWeight"]
        computedFontWeight: option(string) /* The computed font weight for this node, as a CSS computed value string (e.g. 'normal' or
'100'). */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to get background colors for. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getBackgroundColors", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the computed style for a DOM node identified by `nodeId`. */
  module GetComputedStyleForNode = {
    module Response: {
      type result = {
        [@key "computedStyle"]
        computedStyle: list(Types.CSS.CSSComputedStyleProperty.t) /* Computed style for the specified DOM node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "computedStyle"]
        computedStyle: list(Types.CSS.CSSComputedStyleProperty.t) /* Computed style for the specified DOM node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* No description provided */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getComputedStyleForNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the styles defined inline (explicitly in the "style" attribute and implicitly, using DOM
     attributes) for a DOM node identified by `nodeId`. */
  module GetInlineStylesForNode = {
    module Response: {
      type result = {
        [@yojson.option] [@key "inlineStyle"]
        inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
        [@yojson.option] [@key "attributesStyle"]
        attributesStyle: option(Types.CSS.CSSStyle.t) /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "inlineStyle"]
        inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
        [@yojson.option] [@key "attributesStyle"]
        attributesStyle: option(Types.CSS.CSSStyle.t) /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* No description provided */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getInlineStylesForNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns requested styles for a DOM node identified by `nodeId`. */
  module GetMatchedStylesForNode = {
    module Response: {
      type result = {
        [@yojson.option] [@key "inlineStyle"]
        inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
        [@yojson.option] [@key "attributesStyle"]
        attributesStyle: option(Types.CSS.CSSStyle.t), /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */
        [@yojson.option] [@key "matchedCSSRules"]
        matchedCSSRules: option(list(Types.CSS.RuleMatch.t)), /* CSS rules matching this node, from all applicable stylesheets. */
        [@yojson.option] [@key "pseudoElements"]
        pseudoElements: option(list(Types.CSS.PseudoElementMatches.t)), /* Pseudo style matches for this node. */
        [@yojson.option] [@key "inherited"]
        inherited: option(list(Types.CSS.InheritedStyleEntry.t)), /* A chain of inherited styles (from the immediate node parent up to the DOM tree root). */
        [@yojson.option] [@key "cssKeyframesRules"]
        cssKeyframesRules: option(list(Types.CSS.CSSKeyframesRule.t)) /* A list of CSS keyframed animations matching this node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "inlineStyle"]
        inlineStyle: option(Types.CSS.CSSStyle.t), /* Inline style for the specified DOM node. */
        [@yojson.option] [@key "attributesStyle"]
        attributesStyle: option(Types.CSS.CSSStyle.t), /* Attribute-defined element style (e.g. resulting from "width=20 height=100%"). */
        [@yojson.option] [@key "matchedCSSRules"]
        matchedCSSRules: option(list(Types.CSS.RuleMatch.t)), /* CSS rules matching this node, from all applicable stylesheets. */
        [@yojson.option] [@key "pseudoElements"]
        pseudoElements: option(list(Types.CSS.PseudoElementMatches.t)), /* Pseudo style matches for this node. */
        [@yojson.option] [@key "inherited"]
        inherited: option(list(Types.CSS.InheritedStyleEntry.t)), /* A chain of inherited styles (from the immediate node parent up to the DOM tree root). */
        [@yojson.option] [@key "cssKeyframesRules"]
        cssKeyframesRules: option(list(Types.CSS.CSSKeyframesRule.t)) /* A list of CSS keyframed animations matching this node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* No description provided */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getMatchedStylesForNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all media queries parsed by the rendering engine. */
  module GetMediaQueries = {
    module Response: {
      type result = {
        [@key "medias"]
        medias: list(Types.CSS.CSSMedia.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "medias"]
        medias: list(Types.CSS.CSSMedia.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.getMediaQueries", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests information about platform fonts which we used to render child TextNodes in the given
     node. */
  module GetPlatformFontsForNode = {
    module Response: {
      type result = {
        [@key "fonts"]
        fonts: list(Types.CSS.PlatformFontUsage.t) /* Usage statistics for every employed platform font. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "fonts"]
        fonts: list(Types.CSS.PlatformFontUsage.t) /* Usage statistics for every employed platform font. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* No description provided */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getPlatformFontsForNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the current textual content for a stylesheet. */
  module GetStyleSheetText = {
    module Response: {
      type result = {
        [@key "text"]
        text: string /* The stylesheet text. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "text"]
        text: string /* The stylesheet text. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t /* No description provided */,
      };
      let make = (~styleSheetId, ()) => {
        {styleSheetId: styleSheetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.getStyleSheetText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Starts tracking the given computed styles for updates. The specified array of properties
     replaces the one previously specified. Pass empty array to disable tracking.
     Use takeComputedStyleUpdates to retrieve the list of nodes that had properties modified.
     The changes to computed style properties are only tracked for nodes pushed to the front-end
     by the DOM agent. If no changes to the tracked properties occur after the node has been pushed
     to the front-end, no updates will be issued for the node. */
  module TrackComputedStyleUpdates = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "propertiesToTrack"]
        propertiesToTrack: list(Types.CSS.CSSComputedStyleProperty.t) /* No description provided */,
      };
      let make = (~propertiesToTrack, ()) => {
        {propertiesToTrack: propertiesToTrack};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.trackComputedStyleUpdates", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Polls the next batch of computed style updates. */
  module TakeComputedStyleUpdates = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* The list of node Ids that have their tracked computed styles updated */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* The list of node Ids that have their tracked computed styles updated */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.takeComputedStyleUpdates", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Find a rule with the given active property for the given node and set the new value for this
     property */
  module SetEffectivePropertyValueForNode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* The element id for which to set property. */
        [@key "propertyName"]
        propertyName: string, /* No description provided */
        [@key "value"]
        value: string /* No description provided */,
      };
      let make = (~nodeId, ~propertyName, ~value, ()) => {
        {nodeId, propertyName, value};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "CSS.setEffectivePropertyValueForNode",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Modifies the keyframe rule key text. */
  module SetKeyframeKey = {
    module Response: {
      type result = {
        [@key "keyText"]
        keyText: Types.CSS.Value.t /* The resulting key text after modification. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "keyText"]
        keyText: Types.CSS.Value.t /* The resulting key text after modification. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
        [@key "range"]
        range: Types.CSS.SourceRange.t, /* No description provided */
        [@key "keyText"]
        keyText: string /* No description provided */,
      };
      let make = (~styleSheetId, ~range, ~keyText, ()) => {
        {styleSheetId, range, keyText};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setKeyframeKey", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Modifies the rule selector. */
  module SetMediaText = {
    module Response: {
      type result = {
        [@key "media"]
        media: Types.CSS.CSSMedia.t /* The resulting CSS media rule after modification. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "media"]
        media: Types.CSS.CSSMedia.t /* The resulting CSS media rule after modification. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
        [@key "range"]
        range: Types.CSS.SourceRange.t, /* No description provided */
        [@key "text"]
        text: string /* No description provided */,
      };
      let make = (~styleSheetId, ~range, ~text, ()) => {
        {styleSheetId, range, text};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setMediaText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Modifies the expression of a container query. */
  module SetContainerQueryText = {
    module Response: {
      type result = {
        [@key "containerQuery"]
        containerQuery: Types.CSS.CSSContainerQuery.t /* The resulting CSS container query rule after modification. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "containerQuery"]
        containerQuery: Types.CSS.CSSContainerQuery.t /* The resulting CSS container query rule after modification. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
        [@key "range"]
        range: Types.CSS.SourceRange.t, /* No description provided */
        [@key "text"]
        text: string /* No description provided */,
      };
      let make = (~styleSheetId, ~range, ~text, ()) => {
        {styleSheetId, range, text};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setContainerQueryText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Modifies the rule selector. */
  module SetRuleSelector = {
    module Response: {
      type result = {
        [@key "selectorList"]
        selectorList: Types.CSS.SelectorList.t /* The resulting selector list after modification. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "selectorList"]
        selectorList: Types.CSS.SelectorList.t /* The resulting selector list after modification. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
        [@key "range"]
        range: Types.CSS.SourceRange.t, /* No description provided */
        [@key "selector"]
        selector: string /* No description provided */,
      };
      let make = (~styleSheetId, ~range, ~selector, ()) => {
        {styleSheetId, range, selector};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setRuleSelector", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets the new stylesheet text. */
  module SetStyleSheetText = {
    module Response: {
      type result = {
        [@yojson.option] [@key "sourceMapURL"]
        sourceMapURL: option(string) /* URL of source map associated with script (if any). */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "sourceMapURL"]
        sourceMapURL: option(string) /* URL of source map associated with script (if any). */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "styleSheetId"]
        styleSheetId: Types.CSS.StyleSheetId.t, /* No description provided */
        [@key "text"]
        text: string /* No description provided */,
      };
      let make = (~styleSheetId, ~text, ()) => {
        {styleSheetId, text};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setStyleSheetText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Applies specified style edits one after another in the given order. */
  module SetStyleTexts = {
    module Response: {
      type result = {
        [@key "styles"]
        styles: list(Types.CSS.CSSStyle.t) /* The resulting styles after modification. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "styles"]
        styles: list(Types.CSS.CSSStyle.t) /* The resulting styles after modification. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "edits"]
        edits: list(Types.CSS.StyleDeclarationEdit.t) /* No description provided */,
      };
      let make = (~edits, ()) => {
        {edits: edits};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setStyleTexts", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables the selector recording. */
  module StartRuleUsageTracking = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.startRuleUsageTracking", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stop tracking rule usage and return the list of rules that were used since last call to
     `takeCoverageDelta` (or since start of coverage instrumentation) */
  module StopRuleUsageTracking = {
    module Response: {
      type result = {
        [@key "ruleUsage"]
        ruleUsage: list(Types.CSS.RuleUsage.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "ruleUsage"]
        ruleUsage: list(Types.CSS.RuleUsage.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.stopRuleUsageTracking", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Obtain list of rules that became used since last call to this method (or since start of coverage
     instrumentation) */
  module TakeCoverageDelta = {
    module Response: {
      type result = {
        [@key "coverage"]
        coverage: list(Types.CSS.RuleUsage.t), /* No description provided */
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time, in seconds. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "coverage"]
        coverage: list(Types.CSS.RuleUsage.t), /* No description provided */
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time, in seconds. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "CSS.takeCoverageDelta", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables/disables rendering of local CSS fonts (enabled by default). */
  module SetLocalFontsEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* Whether rendering of local fonts is enabled. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CSS.setLocalFontsEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module CacheStorage = {
  /* Deletes a cache. */
  module DeleteCache = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cacheId"]
        cacheId: Types.CacheStorage.CacheId.t /* Id of cache for deletion. */,
      };
      let make = (~cacheId, ()) => {
        {cacheId: cacheId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CacheStorage.deleteCache", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deletes a cache entry. */
  module DeleteEntry = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cacheId"]
        cacheId: Types.CacheStorage.CacheId.t, /* Id of cache where the entry will be deleted. */
        [@key "request"]
        request: string /* URL spec of the request. */,
      };
      let make = (~cacheId, ~request, ()) => {
        {cacheId, request};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CacheStorage.deleteEntry", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests cache names. */
  module RequestCacheNames = {
    module Response: {
      type result = {
        [@key "caches"]
        caches: list(Types.CacheStorage.Cache.t) /* Caches for the security origin. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "caches"]
        caches: list(Types.CacheStorage.Cache.t) /* Caches for the security origin. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string /* Security origin. */,
      };
      let make = (~securityOrigin, ()) => {
        {securityOrigin: securityOrigin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CacheStorage.requestCacheNames", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetches cache entry. */
  module RequestCachedResponse = {
    module Response: {
      type result = {
        [@key "response"]
        response: Types.CacheStorage.CachedResponse.t /* Response read from the cache. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "response"]
        response: Types.CacheStorage.CachedResponse.t /* Response read from the cache. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cacheId"]
        cacheId: Types.CacheStorage.CacheId.t, /* Id of cache that contains the entry. */
        [@key "requestURL"]
        requestURL: string, /* URL spec of the request. */
        [@key "requestHeaders"]
        requestHeaders: list(Types.CacheStorage.Header.t) /* headers of the request. */,
      };
      let make = (~cacheId, ~requestURL, ~requestHeaders, ()) => {
        {cacheId, requestURL, requestHeaders};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CacheStorage.requestCachedResponse", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests data from cache. */
  module RequestEntries = {
    module Response: {
      type result = {
        [@key "cacheDataEntries"]
        cacheDataEntries: list(Types.CacheStorage.DataEntry.t), /* Array of object store data entries. */
        [@key "returnCount"]
        returnCount: float /* Count of returned entries from this storage. If pathFilter is empty, it
is the count of all entries from this storage. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "cacheDataEntries"]
        cacheDataEntries: list(Types.CacheStorage.DataEntry.t), /* Array of object store data entries. */
        [@key "returnCount"]
        returnCount: float /* Count of returned entries from this storage. If pathFilter is empty, it
is the count of all entries from this storage. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cacheId"]
        cacheId: Types.CacheStorage.CacheId.t, /* ID of cache to get entries from. */
        [@yojson.option] [@key "skipCount"]
        skipCount: option(float), /* Number of records to skip. */
        [@yojson.option] [@key "pageSize"]
        pageSize: option(float), /* Number of records to fetch. */
        [@yojson.option] [@key "pathFilter"]
        pathFilter: option(string) /* If present, only return the entries containing this substring in the path */,
      };
      let make = (~cacheId, ~skipCount=?, ~pageSize=?, ~pathFilter=?, ()) => {
        {cacheId, skipCount, pageSize, pathFilter};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "CacheStorage.requestEntries", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Cast = {
  /* Starts observing for sinks that can be used for tab mirroring, and if set,
     sinks compatible with |presentationUrl| as well. When sinks are found, a
     |sinksUpdated| event is fired.
     Also starts observing for issue messages. When an issue is added or removed,
     an |issueUpdated| event is fired. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "presentationUrl"]
        presentationUrl: option(string) /* No description provided */,
      };
      let make = (~presentationUrl=?, ()) => {
        {presentationUrl: presentationUrl};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Cast.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stops observing for sinks and issues. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Cast.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets a sink to be used when the web page requests the browser to choose a
     sink via Presentation API, Remote Playback API, or Cast SDK. */
  module SetSinkToUse = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "sinkName"]
        sinkName: string /* No description provided */,
      };
      let make = (~sinkName, ()) => {
        {sinkName: sinkName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Cast.setSinkToUse", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Starts mirroring the tab to the sink. */
  module StartTabMirroring = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "sinkName"]
        sinkName: string /* No description provided */,
      };
      let make = (~sinkName, ()) => {
        {sinkName: sinkName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Cast.startTabMirroring", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stops the active Cast session on the sink. */
  module StopCasting = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "sinkName"]
        sinkName: string /* No description provided */,
      };
      let make = (~sinkName, ()) => {
        {sinkName: sinkName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Cast.stopCasting", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module DOM = {
  /* Collects class names for the node with given id and all of it's child nodes. */
  module CollectClassNamesFromSubtree = {
    module Response: {
      type result = {
        [@key "classNames"]
        classNames: list(string) /* Class name list. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "classNames"]
        classNames: list(string) /* Class name list. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to collect class names. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.collectClassNamesFromSubtree", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates a deep copy of the specified node and places it into the target container before the
     given anchor. */
  module CopyTo = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node clone. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node clone. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to copy. */
        [@key "targetNodeId"]
        targetNodeId: Types.DOM.NodeId.t, /* Id of the element to drop the copy into. */
        [@yojson.option] [@key "insertBeforeNodeId"]
        insertBeforeNodeId: option(Types.DOM.NodeId.t) /* Drop the copy before this node (if absent, the copy becomes the last child of
`targetNodeId`). */,
      };
      let make = (~nodeId, ~targetNodeId, ~insertBeforeNodeId=?, ()) => {
        {nodeId, targetNodeId, insertBeforeNodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.copyTo", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Describes node given its id, does not require domain to be enabled. Does not start tracking any
     objects, can be used for automation. */
  module DescribeNode = {
    module Response: {
      type result = {
        [@key "node"]
        node: Types.DOM.Node.t /* Node description. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "node"]
        node: Types.DOM.Node.t /* Node description. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper. */
        [@yojson.option] [@key "depth"]
        depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
      };
      let make =
          (~nodeId=?, ~backendNodeId=?, ~objectId=?, ~depth=?, ~pierce=?, ()) => {
        {nodeId, backendNodeId, objectId, depth, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.describeNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Scrolls the specified rect of the given node into view if not already visible.
     Note: exactly one between nodeId, backendNodeId and objectId should be passed
     to identify the node. */
  module ScrollIntoViewIfNeeded = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node wrapper. */
        [@yojson.option] [@key "rect"]
        rect: option(Types.DOM.Rect.t) /* The rect to be scrolled into view, relative to the node's border box, in CSS pixels.
When omitted, center of the node will be used, similar to Element.scrollIntoView. */,
      };
      let make = (~nodeId=?, ~backendNodeId=?, ~objectId=?, ~rect=?, ()) => {
        {nodeId, backendNodeId, objectId, rect};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.scrollIntoViewIfNeeded", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables DOM agent for the given page. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Discards search results from the session with the given id. `getSearchResults` should no longer
     be called for that search. */
  module DiscardSearchResults = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "searchId"]
        searchId: string /* Unique search session identifier. */,
      };
      let make = (~searchId, ()) => {
        {searchId: searchId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.discardSearchResults", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables DOM agent for the given page. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Focuses the given element. */
  module Focus = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
      };
      let make = (~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.focus", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns attributes for the specified node. */
  module GetAttributes = {
    module Response: {
      type result = {
        [@key "attributes"]
        attributes: list(string) /* An interleaved array of node attribute names and values. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "attributes"]
        attributes: list(string) /* An interleaved array of node attribute names and values. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to retrieve attibutes for. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getAttributes", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns boxes for the given node. */
  module GetBoxModel = {
    module Response: {
      type result = {
        [@key "model"]
        model: Types.DOM.BoxModel.t /* Box model for the node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "model"]
        model: Types.DOM.BoxModel.t /* Box model for the node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
      };
      let make = (~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getBoxModel", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns quads that describe node position on the page. This method
     might return multiple quads for inline nodes. */
  module GetContentQuads = {
    module Response: {
      type result = {
        [@key "quads"]
        quads: list(Types.DOM.Quad.t) /* Quads that describe node layout relative to viewport. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "quads"]
        quads: list(Types.DOM.Quad.t) /* Quads that describe node layout relative to viewport. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
      };
      let make = (~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getContentQuads", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the root DOM node (and optionally the subtree) to the caller. */
  module GetDocument = {
    module Response: {
      type result = {
        [@key "root"]
        root: Types.DOM.Node.t /* Resulting node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "root"]
        root: Types.DOM.Node.t /* Resulting node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "depth"]
        depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
      };
      let make = (~depth=?, ~pierce=?, ()) => {
        {depth, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getDocument", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the root DOM node (and optionally the subtree) to the caller.
     Deprecated, as it is not designed to work well with the rest of the DOM agent.
     Use DOMSnapshot.captureSnapshot instead. */
  module GetFlattenedDocument = {
    module Response: {
      type result = {
        [@key "nodes"]
        nodes: list(Types.DOM.Node.t) /* Resulting node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodes"]
        nodes: list(Types.DOM.Node.t) /* Resulting node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "depth"]
        depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). */,
      };
      let make = (~depth=?, ~pierce=?, ()) => {
        {depth, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getFlattenedDocument", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Finds nodes with a given computed style in a subtree. */
  module GetNodesForSubtreeByStyle = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Resulting nodes. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Resulting nodes. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Node ID pointing to the root of a subtree. */
        [@key "computedStyles"]
        computedStyles: list(Types.DOM.CSSComputedStyleProperty.t), /* The style to filter nodes by (includes nodes if any of properties matches). */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots in the same target should be traversed when returning the
results (default is false). */,
      };
      let make = (~nodeId, ~computedStyles, ~pierce=?, ()) => {
        {nodeId, computedStyles, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getNodesForSubtreeByStyle", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns node id at given location. Depending on whether DOM domain is enabled, nodeId is
     either returned or not. */
  module GetNodeForLocation = {
    module Response: {
      type result = {
        [@key "backendNodeId"]
        backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame this node belongs to. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "backendNodeId"]
        backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame this node belongs to. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "x"]
        x: float, /* X coordinate. */
        [@key "y"]
        y: float, /* Y coordinate. */
        [@yojson.option] [@key "includeUserAgentShadowDOM"]
        includeUserAgentShadowDOM: option(bool), /* False to skip to the nearest non-UA shadow root ancestor (default: false). */
        [@yojson.option] [@key "ignorePointerEventsNone"]
        ignorePointerEventsNone: option(bool) /* Whether to ignore pointer-events: none on elements and hit test them. */,
      };
      let make =
          (
            ~x,
            ~y,
            ~includeUserAgentShadowDOM=?,
            ~ignorePointerEventsNone=?,
            (),
          ) => {
        {x, y, includeUserAgentShadowDOM, ignorePointerEventsNone};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getNodeForLocation", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns node's HTML markup. */
  module GetOuterHTML = {
    module Response: {
      type result = {
        [@key "outerHTML"]
        outerHTML: string /* Outer HTML markup. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "outerHTML"]
        outerHTML: string /* Outer HTML markup. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
      };
      let make = (~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getOuterHTML", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the id of the nearest ancestor that is a relayout boundary. */
  module GetRelayoutBoundary = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Relayout boundary node id for the given node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Relayout boundary node id for the given node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getRelayoutBoundary", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns search results from given `fromIndex` to given `toIndex` from the search with the given
     identifier. */
  module GetSearchResults = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Ids of the search result nodes. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Ids of the search result nodes. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "searchId"]
        searchId: string, /* Unique search session identifier. */
        [@key "fromIndex"]
        fromIndex: float, /* Start index of the search result to be returned. */
        [@key "toIndex"]
        toIndex: float /* End index of the search result to be returned. */,
      };
      let make = (~searchId, ~fromIndex, ~toIndex, ()) => {
        {searchId, fromIndex, toIndex};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getSearchResults", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Hides any highlight. */
  module HideHighlight = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.hideHighlight", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights DOM node. */
  module HighlightNode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.highlightNode", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights given rectangle. */
  module HighlightRect = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.highlightRect", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Marks last undoable state. */
  module MarkUndoableState = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.markUndoableState", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Moves node into the new container, places it before the given anchor. */
  module MoveTo = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* New id of the moved node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* New id of the moved node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to move. */
        [@key "targetNodeId"]
        targetNodeId: Types.DOM.NodeId.t, /* Id of the element to drop the moved node into. */
        [@yojson.option] [@key "insertBeforeNodeId"]
        insertBeforeNodeId: option(Types.DOM.NodeId.t) /* Drop node before this one (if absent, the moved node becomes the last child of
`targetNodeId`). */,
      };
      let make = (~nodeId, ~targetNodeId, ~insertBeforeNodeId=?, ()) => {
        {nodeId, targetNodeId, insertBeforeNodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.moveTo", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Searches for a given string in the DOM tree. Use `getSearchResults` to access search results or
     `cancelSearch` to end this search session. */
  module PerformSearch = {
    module Response: {
      type result = {
        [@key "searchId"]
        searchId: string, /* Unique search session identifier. */
        [@key "resultCount"]
        resultCount: float /* Number of search results. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "searchId"]
        searchId: string, /* Unique search session identifier. */
        [@key "resultCount"]
        resultCount: float /* Number of search results. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "query"]
        query: string, /* Plain text or query selector or XPath search query. */
        [@yojson.option] [@key "includeUserAgentShadowDOM"]
        includeUserAgentShadowDOM: option(bool) /* True to search in user agent shadow DOM. */,
      };
      let make = (~query, ~includeUserAgentShadowDOM=?, ()) => {
        {query, includeUserAgentShadowDOM};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.performSearch", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that the node is sent to the caller given its path. // FIXME, use XPath */
  module PushNodeByPathToFrontend = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node for given path. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node for given path. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "path"]
        path: string /* Path to node in the proprietary format. */,
      };
      let make = (~path, ()) => {
        {path: path};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.pushNodeByPathToFrontend", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that a batch of nodes is sent to the caller given their backend node ids. */
  module PushNodesByBackendIdsToFrontend = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* The array of ids of pushed nodes that correspond to the backend ids specified in
backendNodeIds. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* The array of ids of pushed nodes that correspond to the backend ids specified in
backendNodeIds. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "backendNodeIds"]
        backendNodeIds: list(Types.DOM.BackendNodeId.t) /* The array of backend node ids. */,
      };
      let make = (~backendNodeIds, ()) => {
        {backendNodeIds: backendNodeIds};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.pushNodesByBackendIdsToFrontend", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Executes `querySelector` on a given node. */
  module QuerySelector = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Query selector result. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Query selector result. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to query upon. */
        [@key "selector"]
        selector: string /* Selector string. */,
      };
      let make = (~nodeId, ~selector, ()) => {
        {nodeId, selector};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.querySelector", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Executes `querySelectorAll` on a given node. */
  module QuerySelectorAll = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Query selector result. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Query selector result. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to query upon. */
        [@key "selector"]
        selector: string /* Selector string. */,
      };
      let make = (~nodeId, ~selector, ()) => {
        {nodeId, selector};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.querySelectorAll", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Re-does the last undone action. */
  module Redo = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.redo", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes attribute with given name from an element with given id. */
  module RemoveAttribute = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the element to remove attribute from. */
        [@key "name"]
        name: string /* Name of the attribute to remove. */,
      };
      let make = (~nodeId, ~name, ()) => {
        {nodeId, name};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.removeAttribute", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes node with given id. */
  module RemoveNode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to remove. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.removeNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that children of the node with given id are returned to the caller in form of
     `setChildNodes` events where not only immediate children are retrieved, but all children down to
     the specified depth. */
  module RequestChildNodes = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to get children for. */
        [@yojson.option] [@key "depth"]
        depth: option(float), /* The maximum depth at which children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the sub-tree
(default is false). */,
      };
      let make = (~nodeId, ~depth=?, ~pierce=?, ()) => {
        {nodeId, depth, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.requestChildNodes", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that the node is sent to the caller given the JavaScript node object reference. All
     nodes that form the path from the node to the root are also sent to the client as a series of
     `setChildNodes` notifications. */
  module RequestNode = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Node id for given object. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Node id for given object. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t /* JavaScript object id to convert into node. */,
      };
      let make = (~objectId, ()) => {
        {objectId: objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.requestNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Resolves the JavaScript node object for a given NodeId or BackendNodeId. */
  module ResolveNode = {
    module Response: {
      type result = {
        [@key "object"]
        object_: Types.Runtime.RemoteObject.t /* JavaScript object wrapper for given node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "object"]
        object_: Types.Runtime.RemoteObject.t /* JavaScript object wrapper for given node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Id of the node to resolve. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Backend identifier of the node to resolve. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Execution context in which to resolve the node. */,
      };
      let make =
          (
            ~nodeId=?,
            ~backendNodeId=?,
            ~objectGroup=?,
            ~executionContextId=?,
            (),
          ) => {
        {nodeId, backendNodeId, objectGroup, executionContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.resolveNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets attribute for an element with given id. */
  module SetAttributeValue = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the element to set attribute for. */
        [@key "name"]
        name: string, /* Attribute name. */
        [@key "value"]
        value: string /* Attribute value. */,
      };
      let make = (~nodeId, ~name, ~value, ()) => {
        {nodeId, name, value};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setAttributeValue", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets attributes on element with given id. This method is useful when user edits some existing
     attribute value and types in several attribute name/value pairs. */
  module SetAttributesAsText = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the element to set attributes for. */
        [@key "text"]
        text: string, /* Text with a number of attributes. Will parse this text using HTML parser. */
        [@yojson.option] [@key "name"]
        name: option(string) /* Attribute name to replace with new attributes derived from text in case text parsed
successfully. */,
      };
      let make = (~nodeId, ~text, ~name=?, ()) => {
        {nodeId, text, name};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setAttributesAsText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets files for the given file input element. */
  module SetFileInputFiles = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "files"]
        files: list(string), /* Array of file paths to set. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node wrapper. */,
      };
      let make = (~files, ~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {files, nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setFileInputFiles", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets if stack traces should be captured for Nodes. See `Node.getNodeStackTraces`. Default is disabled. */
  module SetNodeStackTracesEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enable"]
        enable: bool /* Enable or disable. */,
      };
      let make = (~enable, ()) => {
        {enable: enable};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setNodeStackTracesEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Gets stack traces associated with a Node. As of now, only provides stack trace for Node creation. */
  module GetNodeStackTraces = {
    module Response: {
      type result = {
        [@yojson.option] [@key "creation"]
        creation: option(Types.Runtime.StackTrace.t) /* Creation stack trace, if available. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "creation"]
        creation: option(Types.Runtime.StackTrace.t) /* Creation stack trace, if available. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to get stack traces for. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getNodeStackTraces", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns file information for the given
     File wrapper. */
  module GetFileInfo = {
    module Response: {
      type result = {
        [@key "path"]
        path: string /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "path"]
        path: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t /* JavaScript object id of the node wrapper. */,
      };
      let make = (~objectId, ()) => {
        {objectId: objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getFileInfo", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables console to refer to the node with given id via $x (see Command Line API for more details
     $x functions). */
  module SetInspectedNode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* DOM node id to be accessible by means of $x command line API. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setInspectedNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets node name for a node with given id. */
  module SetNodeName = {
    module Response: {
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* New node's id. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* New node's id. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to set name for. */
        [@key "name"]
        name: string /* New node's name. */,
      };
      let make = (~nodeId, ~name, ()) => {
        {nodeId, name};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setNodeName", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets node value for a node with given id. */
  module SetNodeValue = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to set value for. */
        [@key "value"]
        value: string /* New node's value. */,
      };
      let make = (~nodeId, ~value, ()) => {
        {nodeId, value};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setNodeValue", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets node HTML markup, returns new node id. */
  module SetOuterHTML = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to set markup for. */
        [@key "outerHTML"]
        outerHTML: string /* Outer HTML markup to set. */,
      };
      let make = (~nodeId, ~outerHTML, ()) => {
        {nodeId, outerHTML};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.setOuterHTML", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Undoes the last performed action. */
  module Undo = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOM.undo", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns iframe node that owns iframe with the given domain. */
  module GetFrameOwner = {
    module Response: {
      type result = {
        [@key "backendNodeId"]
        backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "backendNodeId"]
        backendNodeId: Types.DOM.BackendNodeId.t, /* Resulting node. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* Id of the node at given coordinates, only when enabled and requested document. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t /* No description provided */,
      };
      let make = (~frameId, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getFrameOwner", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the container of the given node based on container query conditions.
     If containerName is given, it will find the nearest container with a matching name;
     otherwise it will find the nearest container regardless of its container name. */
  module GetContainerForNode = {
    module Response: {
      type result = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* The container node for the given node, or null if not found. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t) /* The container node for the given node, or null if not found. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* No description provided */
        [@yojson.option] [@key "containerName"]
        containerName: option(string) /* No description provided */,
      };
      let make = (~nodeId, ~containerName=?, ()) => {
        {nodeId, containerName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOM.getContainerForNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the descendants of a container query container that have
     container queries against this container. */
  module GetQueryingDescendantsForContainer = {
    module Response: {
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Descendant nodes with container queries against the given container. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Descendant nodes with container queries against the given container. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the container node to find querying descendants from. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DOM.getQueryingDescendantsForContainer",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module DOMDebugger = {
  /* Returns event listeners of the given object. */
  module GetEventListeners = {
    module Response: {
      type result = {
        [@key "listeners"]
        listeners: list(Types.DOMDebugger.EventListener.t) /* Array of relevant listeners. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "listeners"]
        listeners: list(Types.DOMDebugger.EventListener.t) /* Array of relevant listeners. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the object to return listeners for. */
        [@yojson.option] [@key "depth"]
        depth: option(float), /* The maximum depth at which Node children should be retrieved, defaults to 1. Use -1 for the
entire subtree or provide an integer larger than 0. */
        [@yojson.option] [@key "pierce"]
        pierce: option(bool) /* Whether or not iframes and shadow roots should be traversed when returning the subtree
(default is false). Reports listeners for all contexts if pierce is enabled. */,
      };
      let make = (~objectId, ~depth=?, ~pierce=?, ()) => {
        {objectId, depth, pierce};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.getEventListeners", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes DOM breakpoint that was set using `setDOMBreakpoint`. */
  module RemoveDOMBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Identifier of the node to remove breakpoint from. */
        [@key "type"]
        type_: Types.DOMDebugger.DOMBreakpointType.t /* Type of the breakpoint to remove. */,
      };
      let make = (~nodeId, ~type_, ()) => {
        {nodeId, type_};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.removeDOMBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes breakpoint on particular DOM event. */
  module RemoveEventListenerBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventName"]
        eventName: string, /* Event name. */
        [@yojson.option] [@key "targetName"]
        targetName: option(string) /* EventTarget interface name. */,
      };
      let make = (~eventName, ~targetName=?, ()) => {
        {eventName, targetName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DOMDebugger.removeEventListenerBreakpoint",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes breakpoint on particular native event. */
  module RemoveInstrumentationBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventName"]
        eventName: string /* Instrumentation name to stop on. */,
      };
      let make = (~eventName, ()) => {
        {eventName: eventName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DOMDebugger.removeInstrumentationBreakpoint",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes breakpoint from XMLHttpRequest. */
  module RemoveXHRBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "url"]
        url: string /* Resource URL substring. */,
      };
      let make = (~url, ()) => {
        {url: url};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.removeXHRBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets breakpoint on particular CSP violations. */
  module SetBreakOnCSPViolation = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "violationTypes"]
        violationTypes: list(Types.DOMDebugger.CSPViolationType.t) /* CSP Violations to stop upon. */,
      };
      let make = (~violationTypes, ()) => {
        {violationTypes: violationTypes};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.setBreakOnCSPViolation", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets breakpoint on particular operation with DOM. */
  module SetDOMBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Identifier of the node to set breakpoint on. */
        [@key "type"]
        type_: Types.DOMDebugger.DOMBreakpointType.t /* Type of the operation to stop upon. */,
      };
      let make = (~nodeId, ~type_, ()) => {
        {nodeId, type_};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.setDOMBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets breakpoint on particular DOM event. */
  module SetEventListenerBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventName"]
        eventName: string, /* DOM Event name to stop on (any DOM event will do). */
        [@yojson.option] [@key "targetName"]
        targetName: option(string) /* EventTarget interface name to stop on. If equal to `"*"` or not provided, will stop on any
EventTarget. */,
      };
      let make = (~eventName, ~targetName=?, ()) => {
        {eventName, targetName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DOMDebugger.setEventListenerBreakpoint",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets breakpoint on particular native event. */
  module SetInstrumentationBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventName"]
        eventName: string /* Instrumentation name to stop on. */,
      };
      let make = (~eventName, ()) => {
        {eventName: eventName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DOMDebugger.setInstrumentationBreakpoint",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets breakpoint on XMLHttpRequest. */
  module SetXHRBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "url"]
        url: string /* Resource URL substring. All XHRs having this substring in the URL will get stopped upon. */,
      };
      let make = (~url, ()) => {
        {url: url};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMDebugger.setXHRBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module DOMSnapshot = {
  /* Disables DOM snapshot agent for the given page. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOMSnapshot.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables DOM snapshot agent for the given page. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOMSnapshot.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns a document snapshot, including the full DOM tree of the root node (including iframes,
     template contents, and imported documents) in a flattened array, as well as layout and
     white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
     flattened. */
  module GetSnapshot = {
    module Response: {
      type result = {
        [@key "domNodes"]
        domNodes: list(Types.DOMSnapshot.DOMNode.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
        [@key "layoutTreeNodes"]
        layoutTreeNodes: list(Types.DOMSnapshot.LayoutTreeNode.t), /* The nodes in the layout tree. */
        [@key "computedStyles"]
        computedStyles: list(Types.DOMSnapshot.ComputedStyle.t) /* Whitelisted ComputedStyle properties for each node in the layout tree. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "domNodes"]
        domNodes: list(Types.DOMSnapshot.DOMNode.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
        [@key "layoutTreeNodes"]
        layoutTreeNodes: list(Types.DOMSnapshot.LayoutTreeNode.t), /* The nodes in the layout tree. */
        [@key "computedStyles"]
        computedStyles: list(Types.DOMSnapshot.ComputedStyle.t) /* Whitelisted ComputedStyle properties for each node in the layout tree. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "computedStyleWhitelist"]
        computedStyleWhitelist: list(string), /* Whitelist of computed styles to return. */
        [@yojson.option] [@key "includeEventListeners"]
        includeEventListeners: option(bool), /* Whether or not to retrieve details of DOM listeners (default false). */
        [@yojson.option] [@key "includePaintOrder"]
        includePaintOrder: option(bool), /* Whether to determine and include the paint order index of LayoutTreeNodes (default false). */
        [@yojson.option] [@key "includeUserAgentShadowTree"]
        includeUserAgentShadowTree: option(bool) /* Whether to include UA shadow tree in the snapshot (default false). */,
      };
      let make =
          (
            ~computedStyleWhitelist,
            ~includeEventListeners=?,
            ~includePaintOrder=?,
            ~includeUserAgentShadowTree=?,
            (),
          ) => {
        {
          computedStyleWhitelist,
          includeEventListeners,
          includePaintOrder,
          includeUserAgentShadowTree,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMSnapshot.getSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns a document snapshot, including the full DOM tree of the root node (including iframes,
     template contents, and imported documents) in a flattened array, as well as layout and
     white-listed computed style information for the nodes. Shadow DOM in the returned DOM tree is
     flattened. */
  module CaptureSnapshot = {
    module Response: {
      type result = {
        [@key "documents"]
        documents: list(Types.DOMSnapshot.DocumentSnapshot.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
        [@key "strings"]
        strings: list(string) /* Shared string table that all string properties refer to with indexes. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "documents"]
        documents: list(Types.DOMSnapshot.DocumentSnapshot.t), /* The nodes in the DOM tree. The DOMNode at index 0 corresponds to the root document. */
        [@key "strings"]
        strings: list(string) /* Shared string table that all string properties refer to with indexes. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "computedStyles"]
        computedStyles: list(string), /* Whitelist of computed styles to return. */
        [@yojson.option] [@key "includePaintOrder"]
        includePaintOrder: option(bool), /* Whether to include layout object paint orders into the snapshot. */
        [@yojson.option] [@key "includeDOMRects"]
        includeDOMRects: option(bool), /* Whether to include DOM rectangles (offsetRects, clientRects, scrollRects) into the snapshot */
        [@yojson.option] [@key "includeBlendedBackgroundColors"]
        includeBlendedBackgroundColors: option(bool), /* Whether to include blended background colors in the snapshot (default: false).
Blended background color is achieved by blending background colors of all elements
that overlap with the current element. */
        [@yojson.option] [@key "includeTextColorOpacities"]
        includeTextColorOpacities: option(bool) /* Whether to include text color opacity in the snapshot (default: false).
An element might have the opacity property set that affects the text color of the element.
The final text color opacity is computed based on the opacity of all overlapping elements. */,
      };
      let make =
          (
            ~computedStyles,
            ~includePaintOrder=?,
            ~includeDOMRects=?,
            ~includeBlendedBackgroundColors=?,
            ~includeTextColorOpacities=?,
            (),
          ) => {
        {
          computedStyles,
          includePaintOrder,
          includeDOMRects,
          includeBlendedBackgroundColors,
          includeTextColorOpacities,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMSnapshot.captureSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module DOMStorage = {
  /* No description provided */
  module Clear = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "storageId"]
        storageId: Types.DOMStorage.StorageId.t /* No description provided */,
      };
      let make = (~storageId, ()) => {
        {storageId: storageId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMStorage.clear", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables storage tracking, prevents storage events from being sent to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOMStorage.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables storage tracking, storage events will now be delivered to the client. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "DOMStorage.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetDOMStorageItems = {
    module Response: {
      type result = {
        [@key "entries"]
        entries: list(Types.DOMStorage.Item.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "entries"]
        entries: list(Types.DOMStorage.Item.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "storageId"]
        storageId: Types.DOMStorage.StorageId.t /* No description provided */,
      };
      let make = (~storageId, ()) => {
        {storageId: storageId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMStorage.getDOMStorageItems", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module RemoveDOMStorageItem = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "storageId"]
        storageId: Types.DOMStorage.StorageId.t, /* No description provided */
        [@key "key"]
        key: string /* No description provided */,
      };
      let make = (~storageId, ~key, ()) => {
        {storageId, key};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMStorage.removeDOMStorageItem", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetDOMStorageItem = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "storageId"]
        storageId: Types.DOMStorage.StorageId.t, /* No description provided */
        [@key "key"]
        key: string, /* No description provided */
        [@key "value"]
        value: string /* No description provided */,
      };
      let make = (~storageId, ~key, ~value, ()) => {
        {storageId, key, value};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "DOMStorage.setDOMStorageItem", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Database = {
  /* Disables database tracking, prevents database events from being sent to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Database.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables database tracking, database events will now be delivered to the client. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Database.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module ExecuteSQL = {
    module Response: {
      type result = {
        [@yojson.option] [@key "columnNames"]
        columnNames: option(list(string)), /* No description provided */
        [@yojson.option] [@key "values"]
        values: option(list(string)), /* No description provided */
        [@yojson.option] [@key "sqlError"]
        sqlError: option(Types.Database.Error.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "columnNames"]
        columnNames: option(list(string)), /* No description provided */
        [@yojson.option] [@key "values"]
        values: option(list(string)), /* No description provided */
        [@yojson.option] [@key "sqlError"]
        sqlError: option(Types.Database.Error.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "databaseId"]
        databaseId: Types.Database.DatabaseId.t, /* No description provided */
        [@key "query"]
        query: string /* No description provided */,
      };
      let make = (~databaseId, ~query, ()) => {
        {databaseId, query};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Database.executeSQL", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetDatabaseTableNames = {
    module Response: {
      type result = {
        [@key "tableNames"]
        tableNames: list(string) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "tableNames"]
        tableNames: list(string) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "databaseId"]
        databaseId: Types.Database.DatabaseId.t /* No description provided */,
      };
      let make = (~databaseId, ()) => {
        {databaseId: databaseId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Database.getDatabaseTableNames", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module DeviceOrientation = {
  /* Clears the overridden Device Orientation. */
  module ClearDeviceOrientationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {
          id,
          method: "DeviceOrientation.clearDeviceOrientationOverride",
          sessionId,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the Device Orientation. */
  module SetDeviceOrientationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "alpha"]
        alpha: float, /* Mock alpha */
        [@key "beta"]
        beta: float, /* Mock beta */
        [@key "gamma"]
        gamma: float /* Mock gamma */,
      };
      let make = (~alpha, ~beta, ~gamma, ()) => {
        {alpha, beta, gamma};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "DeviceOrientation.setDeviceOrientationOverride",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Emulation = {
  /* Tells whether emulation is supported. */
  module CanEmulate = {
    module Response: {
      type result = {
        [@key "result"]
        result: bool /* True if emulation is supported. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: bool /* True if emulation is supported. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Emulation.canEmulate", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears the overridden device metrics. */
  module ClearDeviceMetricsOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Emulation.clearDeviceMetricsOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears the overridden Geolocation Position and Error. */
  module ClearGeolocationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Emulation.clearGeolocationOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that page scale factor is reset to initial values. */
  module ResetPageScaleFactor = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Emulation.resetPageScaleFactor", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables or disables simulating a focused and active page. */
  module SetFocusEmulationEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* Whether to enable to disable focus emulation. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setFocusEmulationEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables CPU throttling to emulate slow CPUs. */
  module SetCPUThrottlingRate = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "rate"]
        rate: float /* Throttling rate as a slowdown factor (1 is no throttle, 2 is 2x slowdown, etc). */,
      };
      let make = (~rate, ()) => {
        {rate: rate};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setCPUThrottlingRate", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets or clears an override of the default background color of the frame. This override is used
     if the content does not specify one. */
  module SetDefaultBackgroundColorOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "color"]
        color: option(Types.DOM.RGBA.t) /* RGBA of the default background color. If not specified, any existing override will be
cleared. */,
      };
      let make = (~color=?, ()) => {
        {color: color};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Emulation.setDefaultBackgroundColorOverride",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the values of device screen dimensions (window.screen.width, window.screen.height,
     window.innerWidth, window.innerHeight, and "device-width"/"device-height"-related CSS media
     query results). */
  module SetDeviceMetricsOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "width"]
        width: float, /* Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
        [@key "height"]
        height: float, /* Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
        [@key "deviceScaleFactor"]
        deviceScaleFactor: float, /* Overriding device scale factor value. 0 disables the override. */
        [@key "mobile"]
        mobile: bool, /* Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
autosizing and more. */
        [@yojson.option] [@key "scale"]
        scale: option(float), /* Scale to apply to resulting view image. */
        [@yojson.option] [@key "screenWidth"]
        screenWidth: option(float), /* Overriding screen width value in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "screenHeight"]
        screenHeight: option(float), /* Overriding screen height value in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "positionX"]
        positionX: option(float), /* Overriding view X position on screen in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "positionY"]
        positionY: option(float), /* Overriding view Y position on screen in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "dontSetVisibleSize"]
        dontSetVisibleSize: option(bool), /* Do not set visible view size, rely upon explicit setVisibleSize call. */
        [@yojson.option] [@key "screenOrientation"]
        screenOrientation: option(Types.Emulation.ScreenOrientation.t), /* Screen orientation override. */
        [@yojson.option] [@key "viewport"]
        viewport: option(Types.Page.Viewport.t), /* If set, the visible area of the page will be overridden to this viewport. This viewport
change is not observed by the page, e.g. viewport-relative elements do not change positions. */
        [@yojson.option] [@key "displayFeature"]
        displayFeature: option(Types.Emulation.DisplayFeature.t) /* If set, the display feature of a multi-segment screen. If not set, multi-segment support
is turned-off. */,
      };
      let make =
          (
            ~width,
            ~height,
            ~deviceScaleFactor,
            ~mobile,
            ~scale=?,
            ~screenWidth=?,
            ~screenHeight=?,
            ~positionX=?,
            ~positionY=?,
            ~dontSetVisibleSize=?,
            ~screenOrientation=?,
            ~viewport=?,
            ~displayFeature=?,
            (),
          ) => {
        {
          width,
          height,
          deviceScaleFactor,
          mobile,
          scale,
          screenWidth,
          screenHeight,
          positionX,
          positionY,
          dontSetVisibleSize,
          screenOrientation,
          viewport,
          displayFeature,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setDeviceMetricsOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetScrollbarsHidden = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "hidden"]
        hidden: bool /* Whether scrollbars should be always hidden. */,
      };
      let make = (~hidden, ()) => {
        {hidden: hidden};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setScrollbarsHidden", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetDocumentCookieDisabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "disabled"]
        disabled: bool /* Whether document.coookie API should be disabled. */,
      };
      let make = (~disabled, ()) => {
        {disabled: disabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setDocumentCookieDisabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetEmitTouchEventsForMouse = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setemittoucheventsformouse_configuration = [ | `mobile | `desktop];
      let setemittoucheventsformouse_configuration_of_yojson =
        fun
        | `String("mobile") => `mobile
        | `String("desktop") => `desktop
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setemittoucheventsformouse_configuration =
        fun
        | `mobile => `String("mobile")
        | `desktop => `String("desktop");
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool, /* Whether touch emulation based on mouse input should be enabled. */
        [@yojson.option] [@key "configuration"]
        configuration: option(setemittoucheventsformouse_configuration) /* Touch/gesture events configuration. Default: current platform. */,
      };
      let make = (~enabled, ~configuration=?, ()) => {
        {enabled, configuration};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Emulation.setEmitTouchEventsForMouse",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Emulates the given media type or media feature for CSS media queries. */
  module SetEmulatedMedia = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "media"]
        media: option(string), /* Media type to emulate. Empty string disables the override. */
        [@yojson.option] [@key "features"]
        features: option(list(Types.Emulation.MediaFeature.t)) /* Media features to emulate. */,
      };
      let make = (~media=?, ~features=?, ()) => {
        {media, features};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setEmulatedMedia", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Emulates the given vision deficiency. */
  module SetEmulatedVisionDeficiency = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setemulatedvisiondeficiency_type = [
        | `none
        | `achromatopsia
        | `blurredVision
        | `deuteranopia
        | `protanopia
        | `tritanopia
      ];
      let setemulatedvisiondeficiency_type_of_yojson =
        fun
        | `String("none") => `none
        | `String("achromatopsia") => `achromatopsia
        | `String("blurredVision") => `blurredVision
        | `String("deuteranopia") => `deuteranopia
        | `String("protanopia") => `protanopia
        | `String("tritanopia") => `tritanopia
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setemulatedvisiondeficiency_type =
        fun
        | `none => `String("none")
        | `achromatopsia => `String("achromatopsia")
        | `blurredVision => `String("blurredVision")
        | `deuteranopia => `String("deuteranopia")
        | `protanopia => `String("protanopia")
        | `tritanopia => `String("tritanopia");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: setemulatedvisiondeficiency_type /* Vision deficiency to emulate. */,
      };
      let make = (~type_, ()) => {
        {type_: type_};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Emulation.setEmulatedVisionDeficiency",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the Geolocation Position or Error. Omitting any of the parameters emulates position
     unavailable. */
  module SetGeolocationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "latitude"]
        latitude: option(float), /* Mock latitude */
        [@yojson.option] [@key "longitude"]
        longitude: option(float), /* Mock longitude */
        [@yojson.option] [@key "accuracy"]
        accuracy: option(float) /* Mock accuracy */,
      };
      let make = (~latitude=?, ~longitude=?, ~accuracy=?, ()) => {
        {latitude, longitude, accuracy};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setGeolocationOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the Idle state. */
  module SetIdleOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "isUserActive"]
        isUserActive: bool, /* Mock isUserActive */
        [@key "isScreenUnlocked"]
        isScreenUnlocked: bool /* Mock isScreenUnlocked */,
      };
      let make = (~isUserActive, ~isScreenUnlocked, ()) => {
        {isUserActive, isScreenUnlocked};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setIdleOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears Idle state overrides. */
  module ClearIdleOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Emulation.clearIdleOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides value returned by the javascript navigator object. */
  module SetNavigatorOverrides = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "platform"]
        platform: string /* The platform navigator.platform should return. */,
      };
      let make = (~platform, ()) => {
        {platform: platform};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setNavigatorOverrides", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets a specified page scale factor. */
  module SetPageScaleFactor = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "pageScaleFactor"]
        pageScaleFactor: float /* Page scale factor. */,
      };
      let make = (~pageScaleFactor, ()) => {
        {pageScaleFactor: pageScaleFactor};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setPageScaleFactor", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Switches script execution in the page. */
  module SetScriptExecutionDisabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "value"]
        value: bool /* Whether script execution should be disabled in the page. */,
      };
      let make = (~value, ()) => {
        {value: value};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Emulation.setScriptExecutionDisabled",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables touch on platforms which do not support them. */
  module SetTouchEmulationEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool, /* Whether the touch event emulation should be enabled. */
        [@yojson.option] [@key "maxTouchPoints"]
        maxTouchPoints: option(float) /* Maximum touch points supported. Defaults to one. */,
      };
      let make = (~enabled, ~maxTouchPoints=?, ()) => {
        {enabled, maxTouchPoints};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setTouchEmulationEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Turns on virtual time for all frames (replacing real-time with a synthetic time source) and sets
     the current virtual time policy.  Note this supersedes any previous time budget. */
  module SetVirtualTimePolicy = {
    module Response: {
      type result = {
        [@key "virtualTimeTicksBase"]
        virtualTimeTicksBase: float /* Absolute timestamp at which virtual time was first enabled (up time in milliseconds). */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "virtualTimeTicksBase"]
        virtualTimeTicksBase: float /* Absolute timestamp at which virtual time was first enabled (up time in milliseconds). */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "policy"]
        policy: Types.Emulation.VirtualTimePolicy.t, /* No description provided */
        [@yojson.option] [@key "budget"]
        budget: option(float), /* If set, after this many virtual milliseconds have elapsed virtual time will be paused and a
virtualTimeBudgetExpired event is sent. */
        [@yojson.option] [@key "maxVirtualTimeTaskStarvationCount"]
        maxVirtualTimeTaskStarvationCount: option(float), /* If set this specifies the maximum number of tasks that can be run before virtual is forced
forwards to prevent deadlock. */
        [@yojson.option] [@key "waitForNavigation"]
        waitForNavigation: option(bool), /* If set the virtual time policy change should be deferred until any frame starts navigating.
Note any previous deferred policy change is superseded. */
        [@yojson.option] [@key "initialVirtualTime"]
        initialVirtualTime: option(Types.Network.TimeSinceEpoch.t) /* If set, base::Time::Now will be overridden to initially return this value. */,
      };
      let make =
          (
            ~policy,
            ~budget=?,
            ~maxVirtualTimeTaskStarvationCount=?,
            ~waitForNavigation=?,
            ~initialVirtualTime=?,
            (),
          ) => {
        {
          policy,
          budget,
          maxVirtualTimeTaskStarvationCount,
          waitForNavigation,
          initialVirtualTime,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setVirtualTimePolicy", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides default host system locale with the specified one. */
  module SetLocaleOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "locale"]
        locale: option(string) /* ICU style C locale (e.g. "en_US"). If not specified or empty, disables the override and
restores default host system locale. */,
      };
      let make = (~locale=?, ()) => {
        {locale: locale};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setLocaleOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides default host system timezone with the specified one. */
  module SetTimezoneOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "timezoneId"]
        timezoneId: string /* The timezone identifier. If empty, disables the override and
restores default host system timezone. */,
      };
      let make = (~timezoneId, ()) => {
        {timezoneId: timezoneId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setTimezoneOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Resizes the frame/viewport of the page. Note that this does not affect the frame's container
     (e.g. browser window). Can be used to produce screenshots of the specified size. Not supported
     on Android. */
  module SetVisibleSize = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "width"]
        width: float, /* Frame width (DIP). */
        [@key "height"]
        height: float /* Frame height (DIP). */,
      };
      let make = (~width, ~height, ()) => {
        {width, height};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setVisibleSize", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetDisabledImageTypes = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "imageTypes"]
        imageTypes: list(Types.Emulation.DisabledImageType.t) /* Image types to disable. */,
      };
      let make = (~imageTypes, ()) => {
        {imageTypes: imageTypes};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setDisabledImageTypes", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Allows overriding user agent with the given string. */
  module SetUserAgentOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "userAgent"]
        userAgent: string, /* User agent to use. */
        [@yojson.option] [@key "acceptLanguage"]
        acceptLanguage: option(string), /* Browser langugage to emulate. */
        [@yojson.option] [@key "platform"]
        platform: option(string), /* The platform navigator.platform should return. */
        [@yojson.option] [@key "userAgentMetadata"]
        userAgentMetadata: option(Types.Emulation.UserAgentMetadata.t) /* To be sent in Sec-CH-UA-* headers and returned in navigator.userAgentData */,
      };
      let make =
          (
            ~userAgent,
            ~acceptLanguage=?,
            ~platform=?,
            ~userAgentMetadata=?,
            (),
          ) => {
        {userAgent, acceptLanguage, platform, userAgentMetadata};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Emulation.setUserAgentOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module HeadlessExperimental = {
  /* Sends a BeginFrame to the target and returns when the frame was completed. Optionally captures a
     screenshot from the resulting frame. Requires that the target was created with enabled
     BeginFrameControl. Designed for use with --run-all-compositor-stages-before-draw, see also
     https://goo.gl/3zHXhB for more background. */
  module BeginFrame = {
    module Response: {
      type result = {
        [@key "hasDamage"]
        hasDamage: bool, /* Whether the BeginFrame resulted in damage and, thus, a new frame was committed to the
display. Reported for diagnostic uses, may be removed in the future. */
        [@yojson.option] [@key "screenshotData"]
        screenshotData: option(string) /* Base64-encoded image data of the screenshot, if one was requested and successfully taken. (Encoded as a base64 string when passed over JSON) */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "hasDamage"]
        hasDamage: bool, /* Whether the BeginFrame resulted in damage and, thus, a new frame was committed to the
display. Reported for diagnostic uses, may be removed in the future. */
        [@yojson.option] [@key "screenshotData"]
        screenshotData: option(string) /* Base64-encoded image data of the screenshot, if one was requested and successfully taken. (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "frameTimeTicks"]
        frameTimeTicks: option(float), /* Timestamp of this BeginFrame in Renderer TimeTicks (milliseconds of uptime). If not set,
the current time will be used. */
        [@yojson.option] [@key "interval"]
        interval: option(float), /* The interval between BeginFrames that is reported to the compositor, in milliseconds.
Defaults to a 60 frames/second interval, i.e. about 16.666 milliseconds. */
        [@yojson.option] [@key "noDisplayUpdates"]
        noDisplayUpdates: option(bool), /* Whether updates should not be committed and drawn onto the display. False by default. If
true, only side effects of the BeginFrame will be run, such as layout and animations, but
any visual updates may not be visible on the display or in screenshots. */
        [@yojson.option] [@key "screenshot"]
        screenshot: option(Types.HeadlessExperimental.ScreenshotParams.t) /* If set, a screenshot of the frame will be captured and returned in the response. Otherwise,
no screenshot will be captured. Note that capturing a screenshot can fail, for example,
during renderer initialization. In such a case, no screenshot data will be returned. */,
      };
      let make =
          (
            ~frameTimeTicks=?,
            ~interval=?,
            ~noDisplayUpdates=?,
            ~screenshot=?,
            (),
          ) => {
        {frameTimeTicks, interval, noDisplayUpdates, screenshot};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "HeadlessExperimental.beginFrame", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables headless events for the target. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeadlessExperimental.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables headless events for the target. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeadlessExperimental.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module IO = {
  /* Close the stream, discard any temporary backing storage. */
  module Close = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "handle"]
        handle: Types.IO.StreamHandle.t /* Handle of the stream to close. */,
      };
      let make = (~handle, ()) => {
        {handle: handle};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IO.close", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Read a chunk of the stream */
  module Read = {
    module Response: {
      type result = {
        [@yojson.option] [@key "base64Encoded"]
        base64Encoded: option(bool), /* Set if the data is base64-encoded */
        [@key "data"]
        data: string, /* Data that were read. */
        [@key "eof"]
        eof: bool /* Set if the end-of-file condition occurred while reading. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "base64Encoded"]
        base64Encoded: option(bool), /* Set if the data is base64-encoded */
        [@key "data"]
        data: string, /* Data that were read. */
        [@key "eof"]
        eof: bool /* Set if the end-of-file condition occurred while reading. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "handle"]
        handle: Types.IO.StreamHandle.t, /* Handle of the stream to read. */
        [@yojson.option] [@key "offset"]
        offset: option(float), /* Seek to the specified offset before reading (if not specificed, proceed with offset
following the last read). Some types of streams may only support sequential reads. */
        [@yojson.option] [@key "size"]
        size: option(float) /* Maximum number of bytes to read (left upon the agent discretion if not specified). */,
      };
      let make = (~handle, ~offset=?, ~size=?, ()) => {
        {handle, offset, size};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IO.read", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Return UUID of Blob object specified by a remote object id. */
  module ResolveBlob = {
    module Response: {
      type result = {
        [@key "uuid"]
        uuid: string /* UUID of the specified Blob. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "uuid"]
        uuid: string /* UUID of the specified Blob. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t /* Object id of a Blob object wrapper. */,
      };
      let make = (~objectId, ()) => {
        {objectId: objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IO.resolveBlob", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module IndexedDB = {
  /* Clears all entries from an object store. */
  module ClearObjectStore = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* Security origin. */
        [@key "databaseName"]
        databaseName: string, /* Database name. */
        [@key "objectStoreName"]
        objectStoreName: string /* Object store name. */,
      };
      let make = (~securityOrigin, ~databaseName, ~objectStoreName, ()) => {
        {securityOrigin, databaseName, objectStoreName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.clearObjectStore", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deletes a database. */
  module DeleteDatabase = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* Security origin. */
        [@key "databaseName"]
        databaseName: string /* Database name. */,
      };
      let make = (~securityOrigin, ~databaseName, ()) => {
        {securityOrigin, databaseName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.deleteDatabase", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Delete a range of entries from an object store */
  module DeleteObjectStoreEntries = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* No description provided */
        [@key "databaseName"]
        databaseName: string, /* No description provided */
        [@key "objectStoreName"]
        objectStoreName: string, /* No description provided */
        [@key "keyRange"]
        keyRange: Types.IndexedDB.KeyRange.t /* Range of entry keys to delete */,
      };
      let make =
          (~securityOrigin, ~databaseName, ~objectStoreName, ~keyRange, ()) => {
        {securityOrigin, databaseName, objectStoreName, keyRange};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.deleteObjectStoreEntries", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables events from backend. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "IndexedDB.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables events from backend. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "IndexedDB.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests data from object store or index. */
  module RequestData = {
    module Response: {
      type result = {
        [@key "objectStoreDataEntries"]
        objectStoreDataEntries: list(Types.IndexedDB.DataEntry.t), /* Array of object store data entries. */
        [@key "hasMore"]
        hasMore: bool /* If true, there are more entries to fetch in the given range. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "objectStoreDataEntries"]
        objectStoreDataEntries: list(Types.IndexedDB.DataEntry.t), /* Array of object store data entries. */
        [@key "hasMore"]
        hasMore: bool /* If true, there are more entries to fetch in the given range. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* Security origin. */
        [@key "databaseName"]
        databaseName: string, /* Database name. */
        [@key "objectStoreName"]
        objectStoreName: string, /* Object store name. */
        [@key "indexName"]
        indexName: string, /* Index name, empty string for object store data requests. */
        [@key "skipCount"]
        skipCount: float, /* Number of records to skip. */
        [@key "pageSize"]
        pageSize: float, /* Number of records to fetch. */
        [@yojson.option] [@key "keyRange"]
        keyRange: option(Types.IndexedDB.KeyRange.t) /* Key range. */,
      };
      let make =
          (
            ~securityOrigin,
            ~databaseName,
            ~objectStoreName,
            ~indexName,
            ~skipCount,
            ~pageSize,
            ~keyRange=?,
            (),
          ) => {
        {
          securityOrigin,
          databaseName,
          objectStoreName,
          indexName,
          skipCount,
          pageSize,
          keyRange,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.requestData", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Gets metadata of an object store */
  module GetMetadata = {
    module Response: {
      type result = {
        [@key "entriesCount"]
        entriesCount: float, /* the entries count */
        [@key "keyGeneratorValue"]
        keyGeneratorValue: float /* the current value of key generator, to become the next inserted
key into the object store. Valid if objectStore.autoIncrement
is true. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "entriesCount"]
        entriesCount: float, /* the entries count */
        [@key "keyGeneratorValue"]
        keyGeneratorValue: float /* the current value of key generator, to become the next inserted
key into the object store. Valid if objectStore.autoIncrement
is true. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* Security origin. */
        [@key "databaseName"]
        databaseName: string, /* Database name. */
        [@key "objectStoreName"]
        objectStoreName: string /* Object store name. */,
      };
      let make = (~securityOrigin, ~databaseName, ~objectStoreName, ()) => {
        {securityOrigin, databaseName, objectStoreName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.getMetadata", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests database with given name in given frame. */
  module RequestDatabase = {
    module Response: {
      type result = {
        [@key "databaseWithObjectStores"]
        databaseWithObjectStores: Types.IndexedDB.DatabaseWithObjectStores.t /* Database with an array of object stores. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "databaseWithObjectStores"]
        databaseWithObjectStores: Types.IndexedDB.DatabaseWithObjectStores.t /* Database with an array of object stores. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string, /* Security origin. */
        [@key "databaseName"]
        databaseName: string /* Database name. */,
      };
      let make = (~securityOrigin, ~databaseName, ()) => {
        {securityOrigin, databaseName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.requestDatabase", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests database names for given security origin. */
  module RequestDatabaseNames = {
    module Response: {
      type result = {
        [@key "databaseNames"]
        databaseNames: list(string) /* Database names for origin. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "databaseNames"]
        databaseNames: list(string) /* Database names for origin. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "securityOrigin"]
        securityOrigin: string /* Security origin. */,
      };
      let make = (~securityOrigin, ()) => {
        {securityOrigin: securityOrigin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "IndexedDB.requestDatabaseNames", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Input = {
  /* Dispatches a drag event into the page. */
  module DispatchDragEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type dispatchdragevent_type = [
        | `dragEnter
        | `dragOver
        | `drop
        | `dragCancel
      ];
      let dispatchdragevent_type_of_yojson =
        fun
        | `String("dragEnter") => `dragEnter
        | `String("dragOver") => `dragOver
        | `String("drop") => `drop
        | `String("dragCancel") => `dragCancel
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_dispatchdragevent_type =
        fun
        | `dragEnter => `String("dragEnter")
        | `dragOver => `String("dragOver")
        | `drop => `String("drop")
        | `dragCancel => `String("dragCancel");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: dispatchdragevent_type, /* Type of the drag event. */
        [@key "x"]
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        [@key "y"]
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@key "data"]
        data: Types.Input.DragData.t, /* No description provided */
        [@yojson.option] [@key "modifiers"]
        modifiers: option(float) /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */,
      };
      let make = (~type_, ~x, ~y, ~data, ~modifiers=?, ()) => {
        {type_, x, y, data, modifiers};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.dispatchDragEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Dispatches a key event to the page. */
  module DispatchKeyEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type dispatchkeyevent_type = [
        | `keyDown
        | `keyUp
        | `rawKeyDown
        | `char
      ];
      let dispatchkeyevent_type_of_yojson =
        fun
        | `String("keyDown") => `keyDown
        | `String("keyUp") => `keyUp
        | `String("rawKeyDown") => `rawKeyDown
        | `String("char") => `char
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_dispatchkeyevent_type =
        fun
        | `keyDown => `String("keyDown")
        | `keyUp => `String("keyUp")
        | `rawKeyDown => `String("rawKeyDown")
        | `char => `String("char");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: dispatchkeyevent_type, /* Type of the key event. */
        [@yojson.option] [@key "modifiers"]
        modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
        [@yojson.option] [@key "timestamp"]
        timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred. */
        [@yojson.option] [@key "text"]
        text: option(string), /* Text as generated by processing a virtual key code with a keyboard layout. Not needed for
for `keyUp` and `rawKeyDown` events (default: "") */
        [@yojson.option] [@key "unmodifiedText"]
        unmodifiedText: option(string), /* Text that would have been generated by the keyboard if no modifiers were pressed (except for
shift). Useful for shortcut (accelerator) key handling (default: ""). */
        [@yojson.option] [@key "keyIdentifier"]
        keyIdentifier: option(string), /* Unique key identifier (e.g., 'U+0041') (default: ""). */
        [@yojson.option] [@key "code"]
        code: option(string), /* Unique DOM defined string value for each physical key (e.g., 'KeyA') (default: ""). */
        [@yojson.option] [@key "key"]
        key: option(string), /* Unique DOM defined string value describing the meaning of the key in the context of active
modifiers, keyboard layout, etc (e.g., 'AltGr') (default: ""). */
        [@yojson.option] [@key "windowsVirtualKeyCode"]
        windowsVirtualKeyCode: option(float), /* Windows virtual key code (default: 0). */
        [@yojson.option] [@key "nativeVirtualKeyCode"]
        nativeVirtualKeyCode: option(float), /* Native virtual key code (default: 0). */
        [@yojson.option] [@key "autoRepeat"]
        autoRepeat: option(bool), /* Whether the event was generated from auto repeat (default: false). */
        [@yojson.option] [@key "isKeypad"]
        isKeypad: option(bool), /* Whether the event was generated from the keypad (default: false). */
        [@yojson.option] [@key "isSystemKey"]
        isSystemKey: option(bool), /* Whether the event was a system key event (default: false). */
        [@yojson.option] [@key "location"]
        location: option(float), /* Whether the event was from the left or right side of the keyboard. 1=Left, 2=Right (default:
0). */
        [@yojson.option] [@key "commands"]
        commands: option(list(string)) /* Editing commands to send with the key event (e.g., 'selectAll') (default: []).
These are related to but not equal the command names used in `document.execCommand` and NSStandardKeyBindingResponding.
See https://source.chromium.org/chromium/chromium/src/+/master:third_party/blink/renderer/core/editing/commands/editor_command_names.h for valid command names. */,
      };
      let make =
          (
            ~type_,
            ~modifiers=?,
            ~timestamp=?,
            ~text=?,
            ~unmodifiedText=?,
            ~keyIdentifier=?,
            ~code=?,
            ~key=?,
            ~windowsVirtualKeyCode=?,
            ~nativeVirtualKeyCode=?,
            ~autoRepeat=?,
            ~isKeypad=?,
            ~isSystemKey=?,
            ~location=?,
            ~commands=?,
            (),
          ) => {
        {
          type_,
          modifiers,
          timestamp,
          text,
          unmodifiedText,
          keyIdentifier,
          code,
          key,
          windowsVirtualKeyCode,
          nativeVirtualKeyCode,
          autoRepeat,
          isKeypad,
          isSystemKey,
          location,
          commands,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.dispatchKeyEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* This method emulates inserting text that doesn't come from a key press,
     for example an emoji keyboard or an IME. */
  module InsertText = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "text"]
        text: string /* The text to insert. */,
      };
      let make = (~text, ()) => {
        {text: text};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.insertText", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* This method sets the current candidate text for ime.
     Use imeCommitComposition to commit the final text.
     Use imeSetComposition with empty string as text to cancel composition. */
  module ImeSetComposition = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "text"]
        text: string, /* The text to insert */
        [@key "selectionStart"]
        selectionStart: float, /* selection start */
        [@key "selectionEnd"]
        selectionEnd: float, /* selection end */
        [@yojson.option] [@key "replacementStart"]
        replacementStart: option(float), /* replacement start */
        [@yojson.option] [@key "replacementEnd"]
        replacementEnd: option(float) /* replacement end */,
      };
      let make =
          (
            ~text,
            ~selectionStart,
            ~selectionEnd,
            ~replacementStart=?,
            ~replacementEnd=?,
            (),
          ) => {
        {
          text,
          selectionStart,
          selectionEnd,
          replacementStart,
          replacementEnd,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.imeSetComposition", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Dispatches a mouse event to the page. */
  module DispatchMouseEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type dispatchmouseevent_type = [
        | `mousePressed
        | `mouseReleased
        | `mouseMoved
        | `mouseWheel
      ];
      let dispatchmouseevent_type_of_yojson =
        fun
        | `String("mousePressed") => `mousePressed
        | `String("mouseReleased") => `mouseReleased
        | `String("mouseMoved") => `mouseMoved
        | `String("mouseWheel") => `mouseWheel
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_dispatchmouseevent_type =
        fun
        | `mousePressed => `String("mousePressed")
        | `mouseReleased => `String("mouseReleased")
        | `mouseMoved => `String("mouseMoved")
        | `mouseWheel => `String("mouseWheel");
      type dispatchmouseevent_pointertype = [ | `mouse | `pen];
      let dispatchmouseevent_pointertype_of_yojson =
        fun
        | `String("mouse") => `mouse
        | `String("pen") => `pen
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_dispatchmouseevent_pointertype =
        fun
        | `mouse => `String("mouse")
        | `pen => `String("pen");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: dispatchmouseevent_type, /* Type of the mouse event. */
        [@key "x"]
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        [@key "y"]
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@yojson.option] [@key "modifiers"]
        modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
        [@yojson.option] [@key "timestamp"]
        timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred. */
        [@yojson.option] [@key "button"]
        button: option(Types.Input.MouseButton.t), /* Mouse button (default: "none"). */
        [@yojson.option] [@key "buttons"]
        buttons: option(float), /* A number indicating which buttons are pressed on the mouse when a mouse event is triggered.
Left=1, Right=2, Middle=4, Back=8, Forward=16, None=0. */
        [@yojson.option] [@key "clickCount"]
        clickCount: option(float), /* Number of times the mouse button was clicked (default: 0). */
        [@yojson.option] [@key "force"]
        force: option(float), /* The normalized pressure, which has a range of [0,1] (default: 0). */
        [@yojson.option] [@key "tangentialPressure"]
        tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        [@yojson.option] [@key "tiltX"]
        tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0). */
        [@yojson.option] [@key "tiltY"]
        tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        [@yojson.option] [@key "twist"]
        twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        [@yojson.option] [@key "deltaX"]
        deltaX: option(float), /* X delta in CSS pixels for mouse wheel event (default: 0). */
        [@yojson.option] [@key "deltaY"]
        deltaY: option(float), /* Y delta in CSS pixels for mouse wheel event (default: 0). */
        [@yojson.option] [@key "pointerType"]
        pointerType: option(dispatchmouseevent_pointertype) /* Pointer type (default: "mouse"). */,
      };
      let make =
          (
            ~type_,
            ~x,
            ~y,
            ~modifiers=?,
            ~timestamp=?,
            ~button=?,
            ~buttons=?,
            ~clickCount=?,
            ~force=?,
            ~tangentialPressure=?,
            ~tiltX=?,
            ~tiltY=?,
            ~twist=?,
            ~deltaX=?,
            ~deltaY=?,
            ~pointerType=?,
            (),
          ) => {
        {
          type_,
          x,
          y,
          modifiers,
          timestamp,
          button,
          buttons,
          clickCount,
          force,
          tangentialPressure,
          tiltX,
          tiltY,
          twist,
          deltaX,
          deltaY,
          pointerType,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.dispatchMouseEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Dispatches a touch event to the page. */
  module DispatchTouchEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type dispatchtouchevent_type = [
        | `touchStart
        | `touchEnd
        | `touchMove
        | `touchCancel
      ];
      let dispatchtouchevent_type_of_yojson =
        fun
        | `String("touchStart") => `touchStart
        | `String("touchEnd") => `touchEnd
        | `String("touchMove") => `touchMove
        | `String("touchCancel") => `touchCancel
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_dispatchtouchevent_type =
        fun
        | `touchStart => `String("touchStart")
        | `touchEnd => `String("touchEnd")
        | `touchMove => `String("touchMove")
        | `touchCancel => `String("touchCancel");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: dispatchtouchevent_type, /* Type of the touch event. TouchEnd and TouchCancel must not contain any touch points, while
TouchStart and TouchMove must contains at least one. */
        [@key "touchPoints"]
        touchPoints: list(Types.Input.TouchPoint.t), /* Active touch points on the touch device. One event per any changed point (compared to
previous touch event in a sequence) is generated, emulating pressing/moving/releasing points
one by one. */
        [@yojson.option] [@key "modifiers"]
        modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
        [@yojson.option] [@key "timestamp"]
        timestamp: option(Types.Input.TimeSinceEpoch.t) /* Time at which the event occurred. */,
      };
      let make = (~type_, ~touchPoints, ~modifiers=?, ~timestamp=?, ()) => {
        {type_, touchPoints, modifiers, timestamp};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.dispatchTouchEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Emulates touch event from the mouse event parameters. */
  module EmulateTouchFromMouseEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type emulatetouchfrommouseevent_type = [
        | `mousePressed
        | `mouseReleased
        | `mouseMoved
        | `mouseWheel
      ];
      let emulatetouchfrommouseevent_type_of_yojson =
        fun
        | `String("mousePressed") => `mousePressed
        | `String("mouseReleased") => `mouseReleased
        | `String("mouseMoved") => `mouseMoved
        | `String("mouseWheel") => `mouseWheel
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_emulatetouchfrommouseevent_type =
        fun
        | `mousePressed => `String("mousePressed")
        | `mouseReleased => `String("mouseReleased")
        | `mouseMoved => `String("mouseMoved")
        | `mouseWheel => `String("mouseWheel");
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: emulatetouchfrommouseevent_type, /* Type of the mouse event. */
        [@key "x"]
        x: float, /* X coordinate of the mouse pointer in DIP. */
        [@key "y"]
        y: float, /* Y coordinate of the mouse pointer in DIP. */
        [@key "button"]
        button: Types.Input.MouseButton.t, /* Mouse button. Only "none", "left", "right" are supported. */
        [@yojson.option] [@key "timestamp"]
        timestamp: option(Types.Input.TimeSinceEpoch.t), /* Time at which the event occurred (default: current time). */
        [@yojson.option] [@key "deltaX"]
        deltaX: option(float), /* X delta in DIP for mouse wheel event (default: 0). */
        [@yojson.option] [@key "deltaY"]
        deltaY: option(float), /* Y delta in DIP for mouse wheel event (default: 0). */
        [@yojson.option] [@key "modifiers"]
        modifiers: option(float), /* Bit field representing pressed modifier keys. Alt=1, Ctrl=2, Meta/Command=4, Shift=8
(default: 0). */
        [@yojson.option] [@key "clickCount"]
        clickCount: option(float) /* Number of times the mouse button was clicked (default: 0). */,
      };
      let make =
          (
            ~type_,
            ~x,
            ~y,
            ~button,
            ~timestamp=?,
            ~deltaX=?,
            ~deltaY=?,
            ~modifiers=?,
            ~clickCount=?,
            (),
          ) => {
        {
          type_,
          x,
          y,
          button,
          timestamp,
          deltaX,
          deltaY,
          modifiers,
          clickCount,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.emulateTouchFromMouseEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Ignores input events (useful while auditing page). */
  module SetIgnoreInputEvents = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "ignore"]
        ignore: bool /* Ignores input events processing when set to true. */,
      };
      let make = (~ignore, ()) => {
        {ignore: ignore};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.setIgnoreInputEvents", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Prevents default drag and drop behavior and instead emits `Input.dragIntercepted` events.
     Drag and drop behavior can be directly controlled via `Input.dispatchDragEvent`. */
  module SetInterceptDrags = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* No description provided */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.setInterceptDrags", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Synthesizes a pinch gesture over a time period by issuing appropriate touch events. */
  module SynthesizePinchGesture = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "x"]
        x: float, /* X coordinate of the start of the gesture in CSS pixels. */
        [@key "y"]
        y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
        [@key "scaleFactor"]
        scaleFactor: float, /* Relative scale factor after zooming (>1.0 zooms in, <1.0 zooms out). */
        [@yojson.option] [@key "relativeSpeed"]
        relativeSpeed: option(float), /* Relative pointer speed in pixels per second (default: 800). */
        [@yojson.option] [@key "gestureSourceType"]
        gestureSourceType: option(Types.Input.GestureSourceType.t) /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */,
      };
      let make =
          (~x, ~y, ~scaleFactor, ~relativeSpeed=?, ~gestureSourceType=?, ()) => {
        {x, y, scaleFactor, relativeSpeed, gestureSourceType};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.synthesizePinchGesture", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Synthesizes a scroll gesture over a time period by issuing appropriate touch events. */
  module SynthesizeScrollGesture = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "x"]
        x: float, /* X coordinate of the start of the gesture in CSS pixels. */
        [@key "y"]
        y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
        [@yojson.option] [@key "xDistance"]
        xDistance: option(float), /* The distance to scroll along the X axis (positive to scroll left). */
        [@yojson.option] [@key "yDistance"]
        yDistance: option(float), /* The distance to scroll along the Y axis (positive to scroll up). */
        [@yojson.option] [@key "xOverscroll"]
        xOverscroll: option(float), /* The number of additional pixels to scroll back along the X axis, in addition to the given
distance. */
        [@yojson.option] [@key "yOverscroll"]
        yOverscroll: option(float), /* The number of additional pixels to scroll back along the Y axis, in addition to the given
distance. */
        [@yojson.option] [@key "preventFling"]
        preventFling: option(bool), /* Prevent fling (default: true). */
        [@yojson.option] [@key "speed"]
        speed: option(float), /* Swipe speed in pixels per second (default: 800). */
        [@yojson.option] [@key "gestureSourceType"]
        gestureSourceType: option(Types.Input.GestureSourceType.t), /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */
        [@yojson.option] [@key "repeatCount"]
        repeatCount: option(float), /* The number of times to repeat the gesture (default: 0). */
        [@yojson.option] [@key "repeatDelayMs"]
        repeatDelayMs: option(float), /* The number of milliseconds delay between each repeat. (default: 250). */
        [@yojson.option] [@key "interactionMarkerName"]
        interactionMarkerName: option(string) /* The name of the interaction markers to generate, if not empty (default: ""). */,
      };
      let make =
          (
            ~x,
            ~y,
            ~xDistance=?,
            ~yDistance=?,
            ~xOverscroll=?,
            ~yOverscroll=?,
            ~preventFling=?,
            ~speed=?,
            ~gestureSourceType=?,
            ~repeatCount=?,
            ~repeatDelayMs=?,
            ~interactionMarkerName=?,
            (),
          ) => {
        {
          x,
          y,
          xDistance,
          yDistance,
          xOverscroll,
          yOverscroll,
          preventFling,
          speed,
          gestureSourceType,
          repeatCount,
          repeatDelayMs,
          interactionMarkerName,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.synthesizeScrollGesture", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Synthesizes a tap gesture over a time period by issuing appropriate touch events. */
  module SynthesizeTapGesture = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "x"]
        x: float, /* X coordinate of the start of the gesture in CSS pixels. */
        [@key "y"]
        y: float, /* Y coordinate of the start of the gesture in CSS pixels. */
        [@yojson.option] [@key "duration"]
        duration: option(float), /* Duration between touchdown and touchup events in ms (default: 50). */
        [@yojson.option] [@key "tapCount"]
        tapCount: option(float), /* Number of times to perform the tap (e.g. 2 for double tap, default: 1). */
        [@yojson.option] [@key "gestureSourceType"]
        gestureSourceType: option(Types.Input.GestureSourceType.t) /* Which type of input events to be generated (default: 'default', which queries the platform
for the preferred input type). */,
      };
      let make = (~x, ~y, ~duration=?, ~tapCount=?, ~gestureSourceType=?, ()) => {
        {x, y, duration, tapCount, gestureSourceType};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Input.synthesizeTapGesture", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Inspector = {
  /* Disables inspector domain notifications. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Inspector.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables inspector domain notifications. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Inspector.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module LayerTree = {
  /* Provides the reasons why the given layer was composited. */
  module CompositingReasons = {
    module Response: {
      type result = {
        [@key "compositingReasons"]
        compositingReasons: list(string), /* A list of strings specifying reasons for the given layer to become composited. */
        [@key "compositingReasonIds"]
        compositingReasonIds: list(string) /* A list of strings specifying reason IDs for the given layer to become composited. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "compositingReasons"]
        compositingReasons: list(string), /* A list of strings specifying reasons for the given layer to become composited. */
        [@key "compositingReasonIds"]
        compositingReasonIds: list(string) /* A list of strings specifying reason IDs for the given layer to become composited. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "layerId"]
        layerId: Types.LayerTree.LayerId.t /* The id of the layer for which we want to get the reasons it was composited. */,
      };
      let make = (~layerId, ()) => {
        {layerId: layerId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.compositingReasons", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables compositing tree inspection. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "LayerTree.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables compositing tree inspection. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "LayerTree.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the snapshot identifier. */
  module LoadSnapshot = {
    module Response: {
      type result = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the snapshot. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the snapshot. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "tiles"]
        tiles: list(Types.LayerTree.PictureTile.t) /* An array of tiles composing the snapshot. */,
      };
      let make = (~tiles, ()) => {
        {tiles: tiles};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.loadSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the layer snapshot identifier. */
  module MakeSnapshot = {
    module Response: {
      type result = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "layerId"]
        layerId: Types.LayerTree.LayerId.t /* The id of the layer. */,
      };
      let make = (~layerId, ()) => {
        {layerId: layerId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.makeSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module ProfileSnapshot = {
    module Response: {
      type result = {
        [@key "timings"]
        timings: list(Types.LayerTree.PaintProfile.t) /* The array of paint profiles, one per run. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "timings"]
        timings: list(Types.LayerTree.PaintProfile.t) /* The array of paint profiles, one per run. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t, /* The id of the layer snapshot. */
        [@yojson.option] [@key "minRepeatCount"]
        minRepeatCount: option(float), /* The maximum number of times to replay the snapshot (1, if not specified). */
        [@yojson.option] [@key "minDuration"]
        minDuration: option(float), /* The minimum duration (in seconds) to replay the snapshot. */
        [@yojson.option] [@key "clipRect"]
        clipRect: option(Types.DOM.Rect.t) /* The clip rectangle to apply when replaying the snapshot. */,
      };
      let make =
          (~snapshotId, ~minRepeatCount=?, ~minDuration=?, ~clipRect=?, ()) => {
        {snapshotId, minRepeatCount, minDuration, clipRect};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.profileSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Releases layer snapshot captured by the back-end. */
  module ReleaseSnapshot = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
      };
      let make = (~snapshotId, ()) => {
        {snapshotId: snapshotId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.releaseSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Replays the layer snapshot and returns the resulting bitmap. */
  module ReplaySnapshot = {
    module Response: {
      type result = {
        [@key "dataURL"]
        dataURL: string /* A data: URL for resulting image. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "dataURL"]
        dataURL: string /* A data: URL for resulting image. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t, /* The id of the layer snapshot. */
        [@yojson.option] [@key "fromStep"]
        fromStep: option(float), /* The first step to replay from (replay from the very start if not specified). */
        [@yojson.option] [@key "toStep"]
        toStep: option(float), /* The last step to replay to (replay till the end if not specified). */
        [@yojson.option] [@key "scale"]
        scale: option(float) /* The scale to apply while replaying (defaults to 1). */,
      };
      let make = (~snapshotId, ~fromStep=?, ~toStep=?, ~scale=?, ()) => {
        {snapshotId, fromStep, toStep, scale};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.replaySnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Replays the layer snapshot and returns canvas log. */
  module SnapshotCommandLog = {
    module Response: {
      type result = {
        [@key "commandLog"]
        commandLog: list(Types.assoc) /* The array of canvas function calls. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "commandLog"]
        commandLog: list(Types.assoc) /* The array of canvas function calls. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "snapshotId"]
        snapshotId: Types.LayerTree.SnapshotId.t /* The id of the layer snapshot. */,
      };
      let make = (~snapshotId, ()) => {
        {snapshotId: snapshotId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "LayerTree.snapshotCommandLog", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Log = {
  /* Clears the log. */
  module Clear = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Log.clear", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables log domain, prevents further log entries from being reported to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Log.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables log domain, sends the entries collected so far to the client by means of the
     `entryAdded` notification. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Log.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* start violation reporting. */
  module StartViolationsReport = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "config"]
        config: list(Types.Log.ViolationSetting.t) /* Configuration for violations. */,
      };
      let make = (~config, ()) => {
        {config: config};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Log.startViolationsReport", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stop violation reporting. */
  module StopViolationsReport = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Log.stopViolationsReport", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Memory = {
  /* No description provided */
  module GetDOMCounters = {
    module Response: {
      type result = {
        [@key "documents"]
        documents: float, /* No description provided */
        [@key "nodes"]
        nodes: float, /* No description provided */
        [@key "jsEventListeners"]
        jsEventListeners: float /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "documents"]
        documents: float, /* No description provided */
        [@key "nodes"]
        nodes: float, /* No description provided */
        [@key "jsEventListeners"]
        jsEventListeners: float /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.getDOMCounters", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module PrepareForLeakDetection = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.prepareForLeakDetection", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Simulate OomIntervention by purging V8 memory. */
  module ForciblyPurgeJavaScriptMemory = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.forciblyPurgeJavaScriptMemory", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable/disable suppressing memory pressure notifications in all processes. */
  module SetPressureNotificationsSuppressed = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "suppressed"]
        suppressed: bool /* If true, memory pressure notifications will be suppressed. */,
      };
      let make = (~suppressed, ()) => {
        {suppressed: suppressed};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Memory.setPressureNotificationsSuppressed",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Simulate a memory pressure notification in all processes. */
  module SimulatePressureNotification = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "level"]
        level: Types.Memory.PressureLevel.t /* Memory pressure level of the notification. */,
      };
      let make = (~level, ()) => {
        {level: level};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Memory.simulatePressureNotification", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Start collecting native memory profile. */
  module StartSampling = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "samplingInterval"]
        samplingInterval: option(float), /* Average number of bytes between samples. */
        [@yojson.option] [@key "suppressRandomness"]
        suppressRandomness: option(bool) /* Do not randomize intervals between samples. */,
      };
      let make = (~samplingInterval=?, ~suppressRandomness=?, ()) => {
        {samplingInterval, suppressRandomness};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Memory.startSampling", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stop collecting native memory profile. */
  module StopSampling = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.stopSampling", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve native memory allocations profile
     collected since renderer process startup. */
  module GetAllTimeSamplingProfile = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.getAllTimeSamplingProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve native memory allocations profile
     collected since browser process startup. */
  module GetBrowserSamplingProfile = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.getBrowserSamplingProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve native memory allocations profile collected since last
     `startSampling` call. */
  module GetSamplingProfile = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.Memory.SamplingProfile.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Memory.getSamplingProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Network = {
  /* Sets a list of content encodings that will be accepted. Empty list means no encoding is accepted. */
  module SetAcceptedEncodings = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "encodings"]
        encodings: list(Types.Network.ContentEncoding.t) /* List of accepted content encodings. */,
      };
      let make = (~encodings, ()) => {
        {encodings: encodings};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setAcceptedEncodings", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears accepted encodings set by setAcceptedEncodings */
  module ClearAcceptedEncodingsOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.clearAcceptedEncodingsOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tells whether clearing browser cache is supported. */
  module CanClearBrowserCache = {
    module Response: {
      type result = {
        [@key "result"]
        result: bool /* True if browser cache can be cleared. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: bool /* True if browser cache can be cleared. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.canClearBrowserCache", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tells whether clearing browser cookies is supported. */
  module CanClearBrowserCookies = {
    module Response: {
      type result = {
        [@key "result"]
        result: bool /* True if browser cookies can be cleared. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: bool /* True if browser cookies can be cleared. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.canClearBrowserCookies", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tells whether emulation of network conditions is supported. */
  module CanEmulateNetworkConditions = {
    module Response: {
      type result = {
        [@key "result"]
        result: bool /* True if emulation of network conditions is supported. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: bool /* True if emulation of network conditions is supported. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.canEmulateNetworkConditions", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears browser cache. */
  module ClearBrowserCache = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.clearBrowserCache", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears browser cookies. */
  module ClearBrowserCookies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.clearBrowserCookies", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Response to Network.requestIntercepted which either modifies the request to continue with any
     modifications, or blocks it, or completes it with the provided response bytes. If a network
     fetch occurs as a result which encounters a redirect an additional Network.requestIntercepted
     event will be sent with the same InterceptionId.
     Deprecated, use Fetch.continueRequest, Fetch.fulfillRequest and Fetch.failRequest instead. */
  module ContinueInterceptedRequest = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "interceptionId"]
        interceptionId: Types.Network.InterceptionId.t, /* No description provided */
        [@yojson.option] [@key "errorReason"]
        errorReason: option(Types.Network.ErrorReason.t), /* If set this causes the request to fail with the given reason. Passing `Aborted` for requests
marked with `isNavigationRequest` also cancels the navigation. Must not be set in response
to an authChallenge. */
        [@yojson.option] [@key "rawResponse"]
        rawResponse: option(string), /* If set the requests completes using with the provided base64 encoded raw response, including
HTTP status line and headers etc... Must not be set in response to an authChallenge. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "url"]
        url: option(string), /* If set the request url will be modified in a way that's not observable by page. Must not be
set in response to an authChallenge. */
        [@yojson.option] [@key "method"]
        method: option(string), /* If set this allows the request method to be overridden. Must not be set in response to an
authChallenge. */
        [@yojson.option] [@key "postData"]
        postData: option(string), /* If set this allows postData to be set. Must not be set in response to an authChallenge. */
        [@yojson.option] [@key "headers"]
        headers: option(Types.Network.Headers.t), /* If set this allows the request headers to be changed. Must not be set in response to an
authChallenge. */
        [@yojson.option] [@key "authChallengeResponse"]
        authChallengeResponse: option(Types.Network.AuthChallengeResponse.t) /* Response to a requestIntercepted with an authChallenge. Must not be set otherwise. */,
      };
      let make =
          (
            ~interceptionId,
            ~errorReason=?,
            ~rawResponse=?,
            ~url=?,
            ~method=?,
            ~postData=?,
            ~headers=?,
            ~authChallengeResponse=?,
            (),
          ) => {
        {
          interceptionId,
          errorReason,
          rawResponse,
          url,
          method,
          postData,
          headers,
          authChallengeResponse,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.continueInterceptedRequest", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deletes browser cookies with matching name and url or domain/path pair. */
  module DeleteCookies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "name"]
        name: string, /* Name of the cookies to remove. */
        [@yojson.option] [@key "url"]
        url: option(string), /* If specified, deletes all the cookies with the given name where domain and path match
provided URL. */
        [@yojson.option] [@key "domain"]
        domain: option(string), /* If specified, deletes only cookies with the exact domain. */
        [@yojson.option] [@key "path"]
        path: option(string) /* If specified, deletes only cookies with the exact path. */,
      };
      let make = (~name, ~url=?, ~domain=?, ~path=?, ()) => {
        {name, url, domain, path};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.deleteCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables network tracking, prevents network events from being sent to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Activates emulation of network conditions. */
  module EmulateNetworkConditions = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "offline"]
        offline: bool, /* True to emulate internet disconnection. */
        [@key "latency"]
        latency: float, /* Minimum latency from request sent to response headers received (ms). */
        [@key "downloadThroughput"]
        downloadThroughput: float, /* Maximal aggregated download throughput (bytes/sec). -1 disables download throttling. */
        [@key "uploadThroughput"]
        uploadThroughput: float, /* Maximal aggregated upload throughput (bytes/sec).  -1 disables upload throttling. */
        [@yojson.option] [@key "connectionType"]
        connectionType: option(Types.Network.ConnectionType.t) /* Connection type if known. */,
      };
      let make =
          (
            ~offline,
            ~latency,
            ~downloadThroughput,
            ~uploadThroughput,
            ~connectionType=?,
            (),
          ) => {
        {
          offline,
          latency,
          downloadThroughput,
          uploadThroughput,
          connectionType,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.emulateNetworkConditions", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables network tracking, network events will now be delivered to the client. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "maxTotalBufferSize"]
        maxTotalBufferSize: option(float), /* Buffer size in bytes to use when preserving network payloads (XHRs, etc). */
        [@yojson.option] [@key "maxResourceBufferSize"]
        maxResourceBufferSize: option(float), /* Per-resource buffer size in bytes to use when preserving network payloads (XHRs, etc). */
        [@yojson.option] [@key "maxPostDataSize"]
        maxPostDataSize: option(float) /* Longest post body size (in bytes) that would be included in requestWillBeSent notification */,
      };
      let make =
          (
            ~maxTotalBufferSize=?,
            ~maxResourceBufferSize=?,
            ~maxPostDataSize=?,
            (),
          ) => {
        {maxTotalBufferSize, maxResourceBufferSize, maxPostDataSize};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all browser cookies. Depending on the backend support, will return detailed cookie
     information in the `cookies` field. */
  module GetAllCookies = {
    module Response: {
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Network.getAllCookies", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the DER-encoded certificate. */
  module GetCertificate = {
    module Response: {
      type result = {
        [@key "tableNames"]
        tableNames: list(string) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "tableNames"]
        tableNames: list(string) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Origin to get certificate for. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.getCertificate", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all browser cookies for the current URL. Depending on the backend support, will return
     detailed cookie information in the `cookies` field. */
  module GetCookies = {
    module Response: {
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "urls"]
        urls: option(list(string)) /* The list of URLs for which applicable cookies will be fetched.
If not specified, it's assumed to be set to the list containing
the URLs of the page and all of its subframes. */,
      };
      let make = (~urls=?, ()) => {
        {urls: urls};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.getCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns content served for the given request. */
  module GetResponseBody = {
    module Response: {
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Network.RequestId.t /* Identifier of the network request to get content for. */,
      };
      let make = (~requestId, ()) => {
        {requestId: requestId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.getResponseBody", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns post data sent with the request. Returns an error when no data was sent with the request. */
  module GetRequestPostData = {
    module Response: {
      type result = {
        [@key "postData"]
        postData: string /* Request body string, omitting files from multipart requests */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "postData"]
        postData: string /* Request body string, omitting files from multipart requests */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Network.RequestId.t /* Identifier of the network request to get content for. */,
      };
      let make = (~requestId, ()) => {
        {requestId: requestId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.getRequestPostData", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns content served for the given currently intercepted request. */
  module GetResponseBodyForInterception = {
    module Response: {
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "interceptionId"]
        interceptionId: Types.Network.InterceptionId.t /* Identifier for the intercepted request to get body for. */,
      };
      let make = (~interceptionId, ()) => {
        {interceptionId: interceptionId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Network.getResponseBodyForInterception",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns a handle to the stream representing the response body. Note that after this command,
     the intercepted request can't be continued as is -- you either need to cancel it or to provide
     the response body. The stream only supports sequential read, IO.read will fail if the position
     is specified. */
  module TakeResponseBodyForInterceptionAsStream = {
    module Response: {
      type result = {
        [@key "stream"]
        stream: Types.IO.StreamHandle.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "stream"]
        stream: Types.IO.StreamHandle.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "interceptionId"]
        interceptionId: Types.Network.InterceptionId.t /* No description provided */,
      };
      let make = (~interceptionId, ()) => {
        {interceptionId: interceptionId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Network.takeResponseBodyForInterceptionAsStream",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* This method sends a new XMLHttpRequest which is identical to the original one. The following
     parameters should be identical: method, url, async, request body, extra headers, withCredentials
     attribute, user, password. */
  module ReplayXHR = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Network.RequestId.t /* Identifier of XHR to replay. */,
      };
      let make = (~requestId, ()) => {
        {requestId: requestId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.replayXHR", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Searches for given string in response content. */
  module SearchInResponseBody = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Network.RequestId.t, /* Identifier of the network response to search. */
        [@key "query"]
        query: string, /* String to search for. */
        [@yojson.option] [@key "caseSensitive"]
        caseSensitive: option(bool), /* If true, search is case sensitive. */
        [@yojson.option] [@key "isRegex"]
        isRegex: option(bool) /* If true, treats string parameter as regex. */,
      };
      let make = (~requestId, ~query, ~caseSensitive=?, ~isRegex=?, ()) => {
        {requestId, query, caseSensitive, isRegex};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.searchInResponseBody", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Blocks URLs from loading. */
  module SetBlockedURLs = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "urls"]
        urls: list(string) /* URL patterns to block. Wildcards ('*') are allowed. */,
      };
      let make = (~urls, ()) => {
        {urls: urls};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setBlockedURLs", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Toggles ignoring of service worker for each request. */
  module SetBypassServiceWorker = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "bypass"]
        bypass: bool /* Bypass service worker and load from network. */,
      };
      let make = (~bypass, ()) => {
        {bypass: bypass};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setBypassServiceWorker", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Toggles ignoring cache for each request. If `true`, cache will not be used. */
  module SetCacheDisabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cacheDisabled"]
        cacheDisabled: bool /* Cache disabled state. */,
      };
      let make = (~cacheDisabled, ()) => {
        {cacheDisabled: cacheDisabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setCacheDisabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets a cookie with the given cookie data; may overwrite equivalent cookies if they exist. */
  module SetCookie = {
    module Response: {
      type result = {
        [@key "success"]
        success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "success"]
        success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "name"]
        name: string, /* Cookie name. */
        [@key "value"]
        value: string, /* Cookie value. */
        [@yojson.option] [@key "url"]
        url: option(string), /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
        [@yojson.option] [@key "domain"]
        domain: option(string), /* Cookie domain. */
        [@yojson.option] [@key "path"]
        path: option(string), /* Cookie path. */
        [@yojson.option] [@key "secure"]
        secure: option(bool), /* True if cookie is secure. */
        [@yojson.option] [@key "httpOnly"]
        httpOnly: option(bool), /* True if cookie is http-only. */
        [@yojson.option] [@key "sameSite"]
        sameSite: option(Types.Network.CookieSameSite.t), /* Cookie SameSite type. */
        [@yojson.option] [@key "expires"]
        expires: option(Types.Network.TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
        [@yojson.option] [@key "priority"]
        priority: option(Types.Network.CookiePriority.t), /* Cookie Priority type. */
        [@yojson.option] [@key "sameParty"]
        sameParty: option(bool), /* True if cookie is SameParty. */
        [@yojson.option] [@key "sourceScheme"]
        sourceScheme: option(Types.Network.CookieSourceScheme.t), /* Cookie source scheme type. */
        [@yojson.option] [@key "sourcePort"]
        sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
      let make =
          (
            ~name,
            ~value,
            ~url=?,
            ~domain=?,
            ~path=?,
            ~secure=?,
            ~httpOnly=?,
            ~sameSite=?,
            ~expires=?,
            ~priority=?,
            ~sameParty=?,
            ~sourceScheme=?,
            ~sourcePort=?,
            (),
          ) => {
        {
          name,
          value,
          url,
          domain,
          path,
          secure,
          httpOnly,
          sameSite,
          expires,
          priority,
          sameParty,
          sourceScheme,
          sourcePort,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setCookie", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets given cookies. */
  module SetCookies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cookies"]
        cookies: list(Types.Network.CookieParam.t) /* Cookies to be set. */,
      };
      let make = (~cookies, ()) => {
        {cookies: cookies};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Specifies whether to always send extra HTTP headers with the requests from this page. */
  module SetExtraHTTPHeaders = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "headers"]
        headers: Types.Network.Headers.t /* Map with extra HTTP headers. */,
      };
      let make = (~headers, ()) => {
        {headers: headers};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setExtraHTTPHeaders", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Specifies whether to attach a page script stack id in requests */
  module SetAttachDebugStack = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* Whether to attach a page script stack for debugging purpose. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setAttachDebugStack", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets the requests to intercept that match the provided patterns and optionally resource types.
     Deprecated, please use Fetch.enable instead. */
  module SetRequestInterception = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "patterns"]
        patterns: list(Types.Network.RequestPattern.t) /* Requests matching any of these patterns will be forwarded and wait for the corresponding
continueInterceptedRequest call. */,
      };
      let make = (~patterns, ()) => {
        {patterns: patterns};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setRequestInterception", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Allows overriding user agent with the given string. */
  module SetUserAgentOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "userAgent"]
        userAgent: string, /* User agent to use. */
        [@yojson.option] [@key "acceptLanguage"]
        acceptLanguage: option(string), /* Browser langugage to emulate. */
        [@yojson.option] [@key "platform"]
        platform: option(string), /* The platform navigator.platform should return. */
        [@yojson.option] [@key "userAgentMetadata"]
        userAgentMetadata: option(Types.Emulation.UserAgentMetadata.t) /* To be sent in Sec-CH-UA-* headers and returned in navigator.userAgentData */,
      };
      let make =
          (
            ~userAgent,
            ~acceptLanguage=?,
            ~platform=?,
            ~userAgentMetadata=?,
            (),
          ) => {
        {userAgent, acceptLanguage, platform, userAgentMetadata};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.setUserAgentOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns information about the COEP/COOP isolation status. */
  module GetSecurityIsolationStatus = {
    module Response: {
      type result = {
        [@key "status"]
        status: Types.Network.SecurityIsolationStatus.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "status"]
        status: Types.Network.SecurityIsolationStatus.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "frameId"]
        frameId: option(Types.Page.FrameId.t) /* If no frameId is provided, the status of the target is provided. */,
      };
      let make = (~frameId=?, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.getSecurityIsolationStatus", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetches the resource and returns the content. */
  module LoadNetworkResource = {
    module Response: {
      type result = {
        [@key "resource"]
        resource: Types.Network.LoadNetworkResourcePageResult.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "resource"]
        resource: Types.Network.LoadNetworkResourcePageResult.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id to get the resource for. */
        [@key "url"]
        url: string, /* URL of the resource to get content for. */
        [@key "options"]
        options: Types.Network.LoadNetworkResourceOptions.t /* Options for the request. */,
      };
      let make = (~frameId, ~url, ~options, ()) => {
        {frameId, url, options};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Network.loadNetworkResource", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Overlay = {
  /* Disables domain notifications. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Overlay.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables domain notifications. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Overlay.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* For testing. */
  module GetHighlightObjectForTest = {
    module Response: {
      type result = {
        [@key "highlight"]
        highlight: Types.assoc /* Highlight data for the node. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "highlight"]
        highlight: Types.assoc /* Highlight data for the node. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t, /* Id of the node to get highlight object for. */
        [@yojson.option] [@key "includeDistance"]
        includeDistance: option(bool), /* Whether to include distance info. */
        [@yojson.option] [@key "includeStyle"]
        includeStyle: option(bool), /* Whether to include style info. */
        [@yojson.option] [@key "colorFormat"]
        colorFormat: option(Types.Overlay.ColorFormat.t), /* The color format to get config with (default: hex). */
        [@yojson.option] [@key "showAccessibilityInfo"]
        showAccessibilityInfo: option(bool) /* Whether to show accessibility info (default: true). */,
      };
      let make =
          (
            ~nodeId,
            ~includeDistance=?,
            ~includeStyle=?,
            ~colorFormat=?,
            ~showAccessibilityInfo=?,
            (),
          ) => {
        {
          nodeId,
          includeDistance,
          includeStyle,
          colorFormat,
          showAccessibilityInfo,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.getHighlightObjectForTest", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* For Persistent Grid testing. */
  module GetGridHighlightObjectsForTest = {
    module Response: {
      type result = {
        [@key "highlights"]
        highlights: Types.assoc /* Grid Highlight data for the node ids provided. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "highlights"]
        highlights: Types.assoc /* Grid Highlight data for the node ids provided. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeIds"]
        nodeIds: list(Types.DOM.NodeId.t) /* Ids of the node to get highlight object for. */,
      };
      let make = (~nodeIds, ()) => {
        {nodeIds: nodeIds};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Overlay.getGridHighlightObjectsForTest",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* For Source Order Viewer testing. */
  module GetSourceOrderHighlightObjectForTest = {
    module Response: {
      type result = {
        [@key "highlight"]
        highlight: Types.assoc /* Source order highlight data for the node id provided. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "highlight"]
        highlight: Types.assoc /* Source order highlight data for the node id provided. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "nodeId"]
        nodeId: Types.DOM.NodeId.t /* Id of the node to highlight. */,
      };
      let make = (~nodeId, ()) => {
        {nodeId: nodeId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Overlay.getSourceOrderHighlightObjectForTest",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Hides any highlight. */
  module HideHighlight = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Overlay.hideHighlight", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights owner element of the frame with given id.
     Deprecated: Doesn't work reliablity and cannot be fixed due to process
     separatation (the owner node might be in a different process). Determine
     the owner node in the client and use highlightNode. */
  module HighlightFrame = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Identifier of the frame to highlight. */
        [@yojson.option] [@key "contentColor"]
        contentColor: option(Types.DOM.RGBA.t), /* The content box highlight fill color (default: transparent). */
        [@yojson.option] [@key "contentOutlineColor"]
        contentOutlineColor: option(Types.DOM.RGBA.t) /* The content box highlight outline color (default: transparent). */,
      };
      let make = (~frameId, ~contentColor=?, ~contentOutlineColor=?, ()) => {
        {frameId, contentColor, contentOutlineColor};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.highlightFrame", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights DOM node with given id or with the given JavaScript object wrapper. Either nodeId or
     objectId must be specified. */
  module HighlightNode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "highlightConfig"]
        highlightConfig: Types.Overlay.HighlightConfig.t, /* A descriptor for the highlight appearance. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to highlight. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to highlight. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* JavaScript object id of the node to be highlighted. */
        [@yojson.option] [@key "selector"]
        selector: option(string) /* Selectors to highlight relevant nodes. */,
      };
      let make =
          (
            ~highlightConfig,
            ~nodeId=?,
            ~backendNodeId=?,
            ~objectId=?,
            ~selector=?,
            (),
          ) => {
        {highlightConfig, nodeId, backendNodeId, objectId, selector};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.highlightNode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights given quad. Coordinates are absolute with respect to the main frame viewport. */
  module HighlightQuad = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "quad"]
        quad: Types.DOM.Quad.t, /* Quad to highlight */
        [@yojson.option] [@key "color"]
        color: option(Types.DOM.RGBA.t), /* The highlight fill color (default: transparent). */
        [@yojson.option] [@key "outlineColor"]
        outlineColor: option(Types.DOM.RGBA.t) /* The highlight outline color (default: transparent). */,
      };
      let make = (~quad, ~color=?, ~outlineColor=?, ()) => {
        {quad, color, outlineColor};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.highlightQuad", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights given rectangle. Coordinates are absolute with respect to the main frame viewport. */
  module HighlightRect = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "x"]
        x: float, /* X coordinate */
        [@key "y"]
        y: float, /* Y coordinate */
        [@key "width"]
        width: float, /* Rectangle width */
        [@key "height"]
        height: float, /* Rectangle height */
        [@yojson.option] [@key "color"]
        color: option(Types.DOM.RGBA.t), /* The highlight fill color (default: transparent). */
        [@yojson.option] [@key "outlineColor"]
        outlineColor: option(Types.DOM.RGBA.t) /* The highlight outline color (default: transparent). */,
      };
      let make = (~x, ~y, ~width, ~height, ~color=?, ~outlineColor=?, ()) => {
        {x, y, width, height, color, outlineColor};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.highlightRect", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights the source order of the children of the DOM node with given id or with the given
     JavaScript object wrapper. Either nodeId or objectId must be specified. */
  module HighlightSourceOrder = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "sourceOrderConfig"]
        sourceOrderConfig: Types.Overlay.SourceOrderConfig.t, /* A descriptor for the appearance of the overlay drawing. */
        [@yojson.option] [@key "nodeId"]
        nodeId: option(Types.DOM.NodeId.t), /* Identifier of the node to highlight. */
        [@yojson.option] [@key "backendNodeId"]
        backendNodeId: option(Types.DOM.BackendNodeId.t), /* Identifier of the backend node to highlight. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t) /* JavaScript object id of the node to be highlighted. */,
      };
      let make =
          (~sourceOrderConfig, ~nodeId=?, ~backendNodeId=?, ~objectId=?, ()) => {
        {sourceOrderConfig, nodeId, backendNodeId, objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.highlightSourceOrder", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enters the 'inspect' mode. In this mode, elements that user is hovering over are highlighted.
     Backend then generates 'inspectNodeRequested' event upon element selection. */
  module SetInspectMode = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "mode"]
        mode: Types.Overlay.InspectMode.t, /* Set an inspection mode. */
        [@yojson.option] [@key "highlightConfig"]
        highlightConfig: option(Types.Overlay.HighlightConfig.t) /* A descriptor for the highlight appearance of hovered-over nodes. May be omitted if `enabled
== false`. */,
      };
      let make = (~mode, ~highlightConfig=?, ()) => {
        {mode, highlightConfig};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setInspectMode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlights owner element of all frames detected to be ads. */
  module SetShowAdHighlights = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* True for showing ad highlights */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowAdHighlights", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetPausedInDebuggerMessage = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "message"]
        message: option(string) /* The message to display, also triggers resume and step over controls. */,
      };
      let make = (~message=?, ()) => {
        {message: message};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setPausedInDebuggerMessage", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows debug borders on layers */
  module SetShowDebugBorders = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* True for showing debug borders */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowDebugBorders", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows the FPS counter */
  module SetShowFPSCounter = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* True for showing the FPS counter */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowFPSCounter", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Highlight multiple elements with the CSS Grid overlay. */
  module SetShowGridOverlays = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "gridNodeHighlightConfigs"]
        gridNodeHighlightConfigs:
          list(Types.Overlay.GridNodeHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
      };
      let make = (~gridNodeHighlightConfigs, ()) => {
        {gridNodeHighlightConfigs: gridNodeHighlightConfigs};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowGridOverlays", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetShowFlexOverlays = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "flexNodeHighlightConfigs"]
        flexNodeHighlightConfigs:
          list(Types.Overlay.FlexNodeHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
      };
      let make = (~flexNodeHighlightConfigs, ()) => {
        {flexNodeHighlightConfigs: flexNodeHighlightConfigs};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowFlexOverlays", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetShowScrollSnapOverlays = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scrollSnapHighlightConfigs"]
        scrollSnapHighlightConfigs:
          list(Types.Overlay.ScrollSnapHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
      };
      let make = (~scrollSnapHighlightConfigs, ()) => {
        {scrollSnapHighlightConfigs: scrollSnapHighlightConfigs};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowScrollSnapOverlays", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetShowContainerQueryOverlays = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "containerQueryHighlightConfigs"]
        containerQueryHighlightConfigs:
          list(Types.Overlay.ContainerQueryHighlightConfig.t) /* An array of node identifiers and descriptors for the highlight appearance. */,
      };
      let make = (~containerQueryHighlightConfigs, ()) => {
        {containerQueryHighlightConfigs: containerQueryHighlightConfigs};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Overlay.setShowContainerQueryOverlays",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows paint rectangles */
  module SetShowPaintRects = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "result"]
        result: bool /* True for showing paint rectangles */,
      };
      let make = (~result, ()) => {
        {result: result};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowPaintRects", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows layout shift regions */
  module SetShowLayoutShiftRegions = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "result"]
        result: bool /* True for showing layout shift regions */,
      };
      let make = (~result, ()) => {
        {result: result};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowLayoutShiftRegions", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows scroll bottleneck rects */
  module SetShowScrollBottleneckRects = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* True for showing scroll bottleneck rects */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Overlay.setShowScrollBottleneckRects",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Requests that backend shows hit-test borders on layers */
  module SetShowHitTestBorders = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* True for showing hit-test borders */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowHitTestBorders", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Request that backend shows an overlay with web vital metrics. */
  module SetShowWebVitals = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* No description provided */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowWebVitals", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Paints viewport size upon main frame resize. */
  module SetShowViewportSizeOnResize = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "show"]
        show: bool /* Whether to paint size or not. */,
      };
      let make = (~show, ()) => {
        {show: show};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowViewportSizeOnResize", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Add a dual screen device hinge */
  module SetShowHinge = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "hingeConfig"]
        hingeConfig: option(Types.Overlay.HingeConfig.t) /* hinge data, null means hideHinge */,
      };
      let make = (~hingeConfig=?, ()) => {
        {hingeConfig: hingeConfig};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Overlay.setShowHinge", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Page = {
  /* Deprecated, please use addScriptToEvaluateOnNewDocument instead. */
  module AddScriptToEvaluateOnLoad = {
    module Response: {
      type result = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptSource"]
        scriptSource: string /* No description provided */,
      };
      let make = (~scriptSource, ()) => {
        {scriptSource: scriptSource};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.addScriptToEvaluateOnLoad", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Evaluates given script in every frame upon creation (before loading frame's scripts). */
  module AddScriptToEvaluateOnNewDocument = {
    module Response: {
      type result = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* Identifier of the added script. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "source"]
        source: string, /* No description provided */
        [@yojson.option] [@key "worldName"]
        worldName: option(string), /* If specified, creates an isolated world with the given name and evaluates given script in it.
This world name will be used as the ExecutionContextDescription::name when the corresponding
event is emitted. */
        [@yojson.option] [@key "includeCommandLineAPI"]
        includeCommandLineAPI: option(bool) /* Specifies whether command line API should be available to the script, defaults
to false. */,
      };
      let make = (~source, ~worldName=?, ~includeCommandLineAPI=?, ()) => {
        {source, worldName, includeCommandLineAPI};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Page.addScriptToEvaluateOnNewDocument",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Brings page to front (activates tab). */
  module BringToFront = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.bringToFront", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Capture page screenshot. */
  module CaptureScreenshot = {
    module Response: {
      type result = {
        [@key "data"]
        data: string /* Base64-encoded image data. (Encoded as a base64 string when passed over JSON) */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "data"]
        data: string /* Base64-encoded image data. (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type capturescreenshot_format = [ | `jpeg | `png | `webp];
      let capturescreenshot_format_of_yojson =
        fun
        | `String("jpeg") => `jpeg
        | `String("png") => `png
        | `String("webp") => `webp
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_capturescreenshot_format =
        fun
        | `jpeg => `String("jpeg")
        | `png => `String("png")
        | `webp => `String("webp");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "format"]
        format: option(capturescreenshot_format), /* Image compression format (defaults to png). */
        [@yojson.option] [@key "quality"]
        quality: option(float), /* Compression quality from range [0..100] (jpeg only). */
        [@yojson.option] [@key "clip"]
        clip: option(Types.Page.Viewport.t), /* Capture the screenshot of a given region only. */
        [@yojson.option] [@key "fromSurface"]
        fromSurface: option(bool), /* Capture the screenshot from the surface, rather than the view. Defaults to true. */
        [@yojson.option] [@key "captureBeyondViewport"]
        captureBeyondViewport: option(bool) /* Capture the screenshot beyond the viewport. Defaults to false. */,
      };
      let make =
          (
            ~format=?,
            ~quality=?,
            ~clip=?,
            ~fromSurface=?,
            ~captureBeyondViewport=?,
            (),
          ) => {
        {format, quality, clip, fromSurface, captureBeyondViewport};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.captureScreenshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns a snapshot of the page as a string. For MHTML format, the serialization includes
     iframes, shadow DOM, external resources, and element-inline styles. */
  module CaptureSnapshot = {
    module Response: {
      type result = {
        [@key "data"]
        data: string /* Serialized page data. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "data"]
        data: string /* Serialized page data. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type capturesnapshot_format = [ | `mhtml];
      let capturesnapshot_format_of_yojson =
        fun
        | `String("mhtml") => `mhtml
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_capturesnapshot_format =
        fun
        | `mhtml => `String("mhtml");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "format"]
        format: option(capturesnapshot_format) /* Format (defaults to mhtml). */,
      };
      let make = (~format=?, ()) => {
        {format: format};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.captureSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears the overridden device metrics. */
  module ClearDeviceMetricsOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.clearDeviceMetricsOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears the overridden Device Orientation. */
  module ClearDeviceOrientationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.clearDeviceOrientationOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears the overridden Geolocation Position and Error. */
  module ClearGeolocationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.clearGeolocationOverride", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates an isolated world for the given frame. */
  module CreateIsolatedWorld = {
    module Response: {
      type result = {
        [@key "executionContextId"]
        executionContextId: Types.Runtime.ExecutionContextId.t /* Execution context of the isolated world. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "executionContextId"]
        executionContextId: Types.Runtime.ExecutionContextId.t /* Execution context of the isolated world. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Id of the frame in which the isolated world should be created. */
        [@yojson.option] [@key "worldName"]
        worldName: option(string), /* An optional name which is reported in the Execution Context. */
        [@yojson.option] [@key "grantUniveralAccess"]
        grantUniveralAccess: option(bool) /* Whether or not universal access should be granted to the isolated world. This is a powerful
option, use with caution. */,
      };
      let make = (~frameId, ~worldName=?, ~grantUniveralAccess=?, ()) => {
        {frameId, worldName, grantUniveralAccess};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.createIsolatedWorld", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deletes browser cookie with given name, domain and path. */
  module DeleteCookie = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cookieName"]
        cookieName: string, /* Name of the cookie to remove. */
        [@key "url"]
        url: string /* URL to match cooke domain and path. */,
      };
      let make = (~cookieName, ~url, ()) => {
        {cookieName, url};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.deleteCookie", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables page domain notifications. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables page domain notifications. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetAppManifest = {
    module Response: {
      type result = {
        [@key "url"]
        url: string, /* Manifest location. */
        [@key "errors"]
        errors: list(Types.Page.AppManifestError.t), /* No description provided */
        [@yojson.option] [@key "data"]
        data: option(string), /* Manifest content. */
        [@yojson.option] [@key "parsed"]
        parsed: option(Types.Page.AppManifestParsedProperties.t) /* Parsed manifest properties */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "url"]
        url: string, /* Manifest location. */
        [@key "errors"]
        errors: list(Types.Page.AppManifestError.t), /* No description provided */
        [@yojson.option] [@key "data"]
        data: option(string), /* Manifest content. */
        [@yojson.option] [@key "parsed"]
        parsed: option(Types.Page.AppManifestParsedProperties.t) /* Parsed manifest properties */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getAppManifest", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetInstallabilityErrors = {
    module Response: {
      type result = {
        [@key "installabilityErrors"]
        installabilityErrors: list(Types.Page.InstallabilityError.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "installabilityErrors"]
        installabilityErrors: list(Types.Page.InstallabilityError.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getInstallabilityErrors", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetManifestIcons = {
    module Response: {
      type result = {
        [@yojson.option] [@key "primaryIcon"]
        primaryIcon: option(string) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "primaryIcon"]
        primaryIcon: option(string) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getManifestIcons", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all browser cookies. Depending on the backend support, will return detailed cookie
     information in the `cookies` field. */
  module GetCookies = {
    module Response: {
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getCookies", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns present frame tree structure. */
  module GetFrameTree = {
    module Response: {
      type result = {
        [@key "frameTree"]
        frameTree: Types.Page.FrameTree.t /* Present frame tree structure. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "frameTree"]
        frameTree: Types.Page.FrameTree.t /* Present frame tree structure. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getFrameTree", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns metrics relating to the layouting of the page, such as viewport bounds/scale. */
  module GetLayoutMetrics = {
    module Response: {
      type result = {
        [@key "layoutViewport"]
        layoutViewport: Types.Page.LayoutViewport.t, /* Deprecated metrics relating to the layout viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssLayoutViewport` instead. */
        [@key "visualViewport"]
        visualViewport: Types.Page.VisualViewport.t, /* Deprecated metrics relating to the visual viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssVisualViewport` instead. */
        [@key "contentSize"]
        contentSize: Types.DOM.Rect.t, /* Deprecated size of scrollable area. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssContentSize` instead. */
        [@key "cssLayoutViewport"]
        cssLayoutViewport: Types.Page.LayoutViewport.t, /* Metrics relating to the layout viewport in CSS pixels. */
        [@key "cssVisualViewport"]
        cssVisualViewport: Types.Page.VisualViewport.t, /* Metrics relating to the visual viewport in CSS pixels. */
        [@key "cssContentSize"]
        cssContentSize: Types.DOM.Rect.t /* Size of scrollable area in CSS pixels. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "layoutViewport"]
        layoutViewport: Types.Page.LayoutViewport.t, /* Deprecated metrics relating to the layout viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssLayoutViewport` instead. */
        [@key "visualViewport"]
        visualViewport: Types.Page.VisualViewport.t, /* Deprecated metrics relating to the visual viewport. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssVisualViewport` instead. */
        [@key "contentSize"]
        contentSize: Types.DOM.Rect.t, /* Deprecated size of scrollable area. Can be in DP or in CSS pixels depending on the `enable-use-zoom-for-dsf` flag. Use `cssContentSize` instead. */
        [@key "cssLayoutViewport"]
        cssLayoutViewport: Types.Page.LayoutViewport.t, /* Metrics relating to the layout viewport in CSS pixels. */
        [@key "cssVisualViewport"]
        cssVisualViewport: Types.Page.VisualViewport.t, /* Metrics relating to the visual viewport in CSS pixels. */
        [@key "cssContentSize"]
        cssContentSize: Types.DOM.Rect.t /* Size of scrollable area in CSS pixels. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getLayoutMetrics", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns navigation history for the current page. */
  module GetNavigationHistory = {
    module Response: {
      type result = {
        [@key "currentIndex"]
        currentIndex: float, /* Index of the current navigation history entry. */
        [@key "entries"]
        entries: list(Types.Page.NavigationEntry.t) /* Array of navigation history entries. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "currentIndex"]
        currentIndex: float, /* Index of the current navigation history entry. */
        [@key "entries"]
        entries: list(Types.Page.NavigationEntry.t) /* Array of navigation history entries. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getNavigationHistory", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Resets navigation history for the current page. */
  module ResetNavigationHistory = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.resetNavigationHistory", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns content of the given resource. */
  module GetResourceContent = {
    module Response: {
      type result = {
        [@key "content"]
        content: string, /* Resource content. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was served as base64. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "content"]
        content: string, /* Resource content. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was served as base64. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id to get resource for. */
        [@key "url"]
        url: string /* URL of the resource to get content for. */,
      };
      let make = (~frameId, ~url, ()) => {
        {frameId, url};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.getResourceContent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns present frame / resource tree structure. */
  module GetResourceTree = {
    module Response: {
      type result = {
        [@key "frameTree"]
        frameTree: Types.Page.FrameResourceTree.t /* Present frame / resource tree structure. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "frameTree"]
        frameTree: Types.Page.FrameResourceTree.t /* Present frame / resource tree structure. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.getResourceTree", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Accepts or dismisses a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload). */
  module HandleJavaScriptDialog = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "accept"]
        accept: bool, /* Whether to accept or dismiss the dialog. */
        [@yojson.option] [@key "promptText"]
        promptText: option(string) /* The text to enter into the dialog prompt before accepting. Used only if this is a prompt
dialog. */,
      };
      let make = (~accept, ~promptText=?, ()) => {
        {accept, promptText};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.handleJavaScriptDialog", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Navigates current page to the given URL. */
  module Navigate = {
    module Response: {
      type result = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id that has navigated (or failed to navigate) */
        [@yojson.option] [@key "loaderId"]
        loaderId: option(Types.Network.LoaderId.t), /* Loader identifier. */
        [@yojson.option] [@key "errorText"]
        errorText: option(string) /* User friendly error message, present if and only if navigation has failed. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id that has navigated (or failed to navigate) */
        [@yojson.option] [@key "loaderId"]
        loaderId: option(Types.Network.LoaderId.t), /* Loader identifier. */
        [@yojson.option] [@key "errorText"]
        errorText: option(string) /* User friendly error message, present if and only if navigation has failed. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "url"]
        url: string, /* URL to navigate the page to. */
        [@yojson.option] [@key "referrer"]
        referrer: option(string), /* Referrer URL. */
        [@yojson.option] [@key "transitionType"]
        transitionType: option(Types.Page.TransitionType.t), /* Intended transition type. */
        [@yojson.option] [@key "frameId"]
        frameId: option(Types.Page.FrameId.t), /* Frame id to navigate, if not specified navigates the top frame. */
        [@yojson.option] [@key "referrerPolicy"]
        referrerPolicy: option(Types.Page.ReferrerPolicy.t) /* Referrer-policy used for the navigation. */,
      };
      let make =
          (
            ~url,
            ~referrer=?,
            ~transitionType=?,
            ~frameId=?,
            ~referrerPolicy=?,
            (),
          ) => {
        {url, referrer, transitionType, frameId, referrerPolicy};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.navigate", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Navigates current page to the given history entry. */
  module NavigateToHistoryEntry = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "entryId"]
        entryId: float /* Unique id of the entry to navigate to. */,
      };
      let make = (~entryId, ()) => {
        {entryId: entryId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.navigateToHistoryEntry", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Print page as PDF. */
  module PrintToPDF = {
    module Response: {
      type result = {
        [@key "data"]
        data: string, /* Base64-encoded pdf data. Empty if |returnAsStream| is specified. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "stream"]
        stream: option(Types.IO.StreamHandle.t) /* A handle of the stream that holds resulting PDF data. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "data"]
        data: string, /* Base64-encoded pdf data. Empty if |returnAsStream| is specified. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "stream"]
        stream: option(Types.IO.StreamHandle.t) /* A handle of the stream that holds resulting PDF data. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type printtopdf_transfermode = [ | `ReturnAsBase64 | `ReturnAsStream];
      let printtopdf_transfermode_of_yojson =
        fun
        | `String("ReturnAsBase64") => `ReturnAsBase64
        | `String("ReturnAsStream") => `ReturnAsStream
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_printtopdf_transfermode =
        fun
        | `ReturnAsBase64 => `String("ReturnAsBase64")
        | `ReturnAsStream => `String("ReturnAsStream");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "landscape"]
        landscape: option(bool), /* Paper orientation. Defaults to false. */
        [@yojson.option] [@key "displayHeaderFooter"]
        displayHeaderFooter: option(bool), /* Display header and footer. Defaults to false. */
        [@yojson.option] [@key "printBackground"]
        printBackground: option(bool), /* Print background graphics. Defaults to false. */
        [@yojson.option] [@key "scale"]
        scale: option(float), /* Scale of the webpage rendering. Defaults to 1. */
        [@yojson.option] [@key "paperWidth"]
        paperWidth: option(float), /* Paper width in inches. Defaults to 8.5 inches. */
        [@yojson.option] [@key "paperHeight"]
        paperHeight: option(float), /* Paper height in inches. Defaults to 11 inches. */
        [@yojson.option] [@key "marginTop"]
        marginTop: option(float), /* Top margin in inches. Defaults to 1cm (~0.4 inches). */
        [@yojson.option] [@key "marginBottom"]
        marginBottom: option(float), /* Bottom margin in inches. Defaults to 1cm (~0.4 inches). */
        [@yojson.option] [@key "marginLeft"]
        marginLeft: option(float), /* Left margin in inches. Defaults to 1cm (~0.4 inches). */
        [@yojson.option] [@key "marginRight"]
        marginRight: option(float), /* Right margin in inches. Defaults to 1cm (~0.4 inches). */
        [@yojson.option] [@key "pageRanges"]
        pageRanges: option(string), /* Paper ranges to print, e.g., '1-5, 8, 11-13'. Defaults to the empty string, which means
print all pages. */
        [@yojson.option] [@key "ignoreInvalidPageRanges"]
        ignoreInvalidPageRanges: option(bool), /* Whether to silently ignore invalid but successfully parsed page ranges, such as '3-2'.
Defaults to false. */
        [@yojson.option] [@key "headerTemplate"]
        headerTemplate: option(string), /* HTML template for the print header. Should be valid HTML markup with following
classes used to inject printing values into them:
- `date`: formatted print date
- `title`: document title
- `url`: document location
- `pageNumber`: current page number
- `totalPages`: total pages in the document

For example, `<span class=title></span>` would generate span containing the title. */
        [@yojson.option] [@key "footerTemplate"]
        footerTemplate: option(string), /* HTML template for the print footer. Should use the same format as the `headerTemplate`. */
        [@yojson.option] [@key "preferCSSPageSize"]
        preferCSSPageSize: option(bool), /* Whether or not to prefer page size as defined by css. Defaults to false,
in which case the content will be scaled to fit the paper size. */
        [@yojson.option] [@key "transferMode"]
        transferMode: option(printtopdf_transfermode) /* return as stream */,
      };
      let make =
          (
            ~landscape=?,
            ~displayHeaderFooter=?,
            ~printBackground=?,
            ~scale=?,
            ~paperWidth=?,
            ~paperHeight=?,
            ~marginTop=?,
            ~marginBottom=?,
            ~marginLeft=?,
            ~marginRight=?,
            ~pageRanges=?,
            ~ignoreInvalidPageRanges=?,
            ~headerTemplate=?,
            ~footerTemplate=?,
            ~preferCSSPageSize=?,
            ~transferMode=?,
            (),
          ) => {
        {
          landscape,
          displayHeaderFooter,
          printBackground,
          scale,
          paperWidth,
          paperHeight,
          marginTop,
          marginBottom,
          marginLeft,
          marginRight,
          pageRanges,
          ignoreInvalidPageRanges,
          headerTemplate,
          footerTemplate,
          preferCSSPageSize,
          transferMode,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.printToPDF", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Reloads given page optionally ignoring the cache. */
  module Reload = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "ignoreCache"]
        ignoreCache: option(bool), /* If true, browser cache is ignored (as if the user pressed Shift+refresh). */
        [@yojson.option] [@key "scriptToEvaluateOnLoad"]
        scriptToEvaluateOnLoad: option(string) /* If set, the script will be injected into all frames of the inspected page after reload.
Argument will be ignored if reloading dataURL origin. */,
      };
      let make = (~ignoreCache=?, ~scriptToEvaluateOnLoad=?, ()) => {
        {ignoreCache, scriptToEvaluateOnLoad};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.reload", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deprecated, please use removeScriptToEvaluateOnNewDocument instead. */
  module RemoveScriptToEvaluateOnLoad = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* No description provided */,
      };
      let make = (~identifier, ()) => {
        {identifier: identifier};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.removeScriptToEvaluateOnLoad", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes given script from the list. */
  module RemoveScriptToEvaluateOnNewDocument = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "identifier"]
        identifier: Types.Page.ScriptIdentifier.t /* No description provided */,
      };
      let make = (~identifier, ()) => {
        {identifier: identifier};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Page.removeScriptToEvaluateOnNewDocument",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Acknowledges that a screencast frame has been received by the frontend. */
  module ScreencastFrameAck = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "sessionId"]
        sessionId: float /* Frame number. */,
      };
      let make = (~sessionId, ()) => {
        {sessionId: sessionId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.screencastFrameAck", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Searches for given string in resource content. */
  module SearchInResource = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id for resource to search in. */
        [@key "url"]
        url: string, /* URL of the resource to search in. */
        [@key "query"]
        query: string, /* String to search for. */
        [@yojson.option] [@key "caseSensitive"]
        caseSensitive: option(bool), /* If true, search is case sensitive. */
        [@yojson.option] [@key "isRegex"]
        isRegex: option(bool) /* If true, treats string parameter as regex. */,
      };
      let make = (~frameId, ~url, ~query, ~caseSensitive=?, ~isRegex=?, ()) => {
        {frameId, url, query, caseSensitive, isRegex};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.searchInResource", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable Chrome's experimental ad filter on all sites. */
  module SetAdBlockingEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* Whether to block ads. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setAdBlockingEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable page Content Security Policy by-passing. */
  module SetBypassCSP = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* Whether to bypass page CSP. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setBypassCSP", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Get Permissions Policy state on given frame. */
  module GetPermissionsPolicyState = {
    module Response: {
      type result = {
        [@key "states"]
        states: list(Types.Page.PermissionsPolicyFeatureState.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "states"]
        states: list(Types.Page.PermissionsPolicyFeatureState.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t /* No description provided */,
      };
      let make = (~frameId, ()) => {
        {frameId: frameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.getPermissionsPolicyState", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the values of device screen dimensions (window.screen.width, window.screen.height,
     window.innerWidth, window.innerHeight, and "device-width"/"device-height"-related CSS media
     query results). */
  module SetDeviceMetricsOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "width"]
        width: float, /* Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
        [@key "height"]
        height: float, /* Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override. */
        [@key "deviceScaleFactor"]
        deviceScaleFactor: float, /* Overriding device scale factor value. 0 disables the override. */
        [@key "mobile"]
        mobile: bool, /* Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
autosizing and more. */
        [@yojson.option] [@key "scale"]
        scale: option(float), /* Scale to apply to resulting view image. */
        [@yojson.option] [@key "screenWidth"]
        screenWidth: option(float), /* Overriding screen width value in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "screenHeight"]
        screenHeight: option(float), /* Overriding screen height value in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "positionX"]
        positionX: option(float), /* Overriding view X position on screen in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "positionY"]
        positionY: option(float), /* Overriding view Y position on screen in pixels (minimum 0, maximum 10000000). */
        [@yojson.option] [@key "dontSetVisibleSize"]
        dontSetVisibleSize: option(bool), /* Do not set visible view size, rely upon explicit setVisibleSize call. */
        [@yojson.option] [@key "screenOrientation"]
        screenOrientation: option(Types.Emulation.ScreenOrientation.t), /* Screen orientation override. */
        [@yojson.option] [@key "viewport"]
        viewport: option(Types.Page.Viewport.t) /* The viewport dimensions and scale. If not set, the override is cleared. */,
      };
      let make =
          (
            ~width,
            ~height,
            ~deviceScaleFactor,
            ~mobile,
            ~scale=?,
            ~screenWidth=?,
            ~screenHeight=?,
            ~positionX=?,
            ~positionY=?,
            ~dontSetVisibleSize=?,
            ~screenOrientation=?,
            ~viewport=?,
            (),
          ) => {
        {
          width,
          height,
          deviceScaleFactor,
          mobile,
          scale,
          screenWidth,
          screenHeight,
          positionX,
          positionY,
          dontSetVisibleSize,
          screenOrientation,
          viewport,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setDeviceMetricsOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the Device Orientation. */
  module SetDeviceOrientationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "alpha"]
        alpha: float, /* Mock alpha */
        [@key "beta"]
        beta: float, /* Mock beta */
        [@key "gamma"]
        gamma: float /* Mock gamma */,
      };
      let make = (~alpha, ~beta, ~gamma, ()) => {
        {alpha, beta, gamma};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setDeviceOrientationOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set generic font families. */
  module SetFontFamilies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "fontFamilies"]
        fontFamilies: Types.Page.FontFamilies.t /* Specifies font families to set. If a font family is not specified, it won't be changed. */,
      };
      let make = (~fontFamilies, ()) => {
        {fontFamilies: fontFamilies};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setFontFamilies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set default font sizes. */
  module SetFontSizes = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "fontSizes"]
        fontSizes: Types.Page.FontSizes.t /* Specifies font sizes to set. If a font size is not specified, it won't be changed. */,
      };
      let make = (~fontSizes, ()) => {
        {fontSizes: fontSizes};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setFontSizes", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets given markup as the document's HTML. */
  module SetDocumentContent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "frameId"]
        frameId: Types.Page.FrameId.t, /* Frame id to set HTML for. */
        [@key "html"]
        html: string /* HTML content to set. */,
      };
      let make = (~frameId, ~html, ()) => {
        {frameId, html};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setDocumentContent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Set the behavior when downloading a file. */
  module SetDownloadBehavior = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setdownloadbehavior_behavior = [ | `deny | `allow | `default];
      let setdownloadbehavior_behavior_of_yojson =
        fun
        | `String("deny") => `deny
        | `String("allow") => `allow
        | `String("default") => `default
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setdownloadbehavior_behavior =
        fun
        | `deny => `String("deny")
        | `allow => `String("allow")
        | `default => `String("default");
      [@deriving yojson]
      type t = {
        [@key "behavior"]
        behavior: setdownloadbehavior_behavior, /* Whether to allow all or deny all download requests, or use default Chrome behavior if
available (otherwise deny). */
        [@yojson.option] [@key "downloadPath"]
        downloadPath: option(string) /* The default path to save downloaded files to. This is required if behavior is set to 'allow' */,
      };
      let make = (~behavior, ~downloadPath=?, ()) => {
        {behavior, downloadPath};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setDownloadBehavior", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Overrides the Geolocation Position or Error. Omitting any of the parameters emulates position
     unavailable. */
  module SetGeolocationOverride = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "latitude"]
        latitude: option(float), /* Mock latitude */
        [@yojson.option] [@key "longitude"]
        longitude: option(float), /* Mock longitude */
        [@yojson.option] [@key "accuracy"]
        accuracy: option(float) /* Mock accuracy */,
      };
      let make = (~latitude=?, ~longitude=?, ~accuracy=?, ()) => {
        {latitude, longitude, accuracy};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setGeolocationOverride", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Controls whether page will emit lifecycle events. */
  module SetLifecycleEventsEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* If true, starts emitting lifecycle events. */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setLifecycleEventsEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Toggles mouse event-based touch event emulation. */
  module SetTouchEmulationEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type settouchemulationenabled_configuration = [ | `mobile | `desktop];
      let settouchemulationenabled_configuration_of_yojson =
        fun
        | `String("mobile") => `mobile
        | `String("desktop") => `desktop
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_settouchemulationenabled_configuration =
        fun
        | `mobile => `String("mobile")
        | `desktop => `String("desktop");
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool, /* Whether the touch event emulation should be enabled. */
        [@yojson.option] [@key "configuration"]
        configuration: option(settouchemulationenabled_configuration) /* Touch/gesture events configuration. Default: current platform. */,
      };
      let make = (~enabled, ~configuration=?, ()) => {
        {enabled, configuration};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setTouchEmulationEnabled", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Starts sending each frame using the `screencastFrame` event. */
  module StartScreencast = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type startscreencast_format = [ | `jpeg | `png];
      let startscreencast_format_of_yojson =
        fun
        | `String("jpeg") => `jpeg
        | `String("png") => `png
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_startscreencast_format =
        fun
        | `jpeg => `String("jpeg")
        | `png => `String("png");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "format"]
        format: option(startscreencast_format), /* Image compression format. */
        [@yojson.option] [@key "quality"]
        quality: option(float), /* Compression quality from range [0..100]. */
        [@yojson.option] [@key "maxWidth"]
        maxWidth: option(float), /* Maximum screenshot width. */
        [@yojson.option] [@key "maxHeight"]
        maxHeight: option(float), /* Maximum screenshot height. */
        [@yojson.option] [@key "everyNthFrame"]
        everyNthFrame: option(float) /* Send every n-th frame. */,
      };
      let make =
          (
            ~format=?,
            ~quality=?,
            ~maxWidth=?,
            ~maxHeight=?,
            ~everyNthFrame=?,
            (),
          ) => {
        {format, quality, maxWidth, maxHeight, everyNthFrame};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.startScreencast", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Force the page stop all navigations and pending resource fetches. */
  module StopLoading = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.stopLoading", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Crashes renderer on the IO thread, generates minidumps. */
  module Crash = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.crash", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tries to close page, running its beforeunload hooks, if any. */
  module Close = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.close", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tries to update the web lifecycle state of the page.
     It will transition the page to the given state according to:
     https://github.com/WICG/web-lifecycle/ */
  module SetWebLifecycleState = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setweblifecyclestate_state = [ | `frozen | `active];
      let setweblifecyclestate_state_of_yojson =
        fun
        | `String("frozen") => `frozen
        | `String("active") => `active
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setweblifecyclestate_state =
        fun
        | `frozen => `String("frozen")
        | `active => `String("active");
      [@deriving yojson]
      type t = {
        [@key "state"]
        state: setweblifecyclestate_state /* Target lifecycle state */,
      };
      let make = (~state, ()) => {
        {state: state};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setWebLifecycleState", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stops sending each frame in the `screencastFrame`. */
  module StopScreencast = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.stopScreencast", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Forces compilation cache to be generated for every subresource script.
     See also: `Page.produceCompilationCache`. */
  module SetProduceCompilationCache = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* No description provided */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setProduceCompilationCache", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
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
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scripts"]
        scripts: list(Types.Page.CompilationCacheParams.t) /* No description provided */,
      };
      let make = (~scripts, ()) => {
        {scripts: scripts};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.produceCompilationCache", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Seeds compilation cache for given url. Compilation cache does not survive
     cross-process navigation. */
  module AddCompilationCache = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "url"]
        url: string, /* No description provided */
        [@key "data"]
        data: string /* Base64-encoded data (Encoded as a base64 string when passed over JSON) */,
      };
      let make = (~url, ~data, ()) => {
        {url, data};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.addCompilationCache", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears seeded compilation cache. */
  module ClearCompilationCache = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.clearCompilationCache", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Generates a report for testing. */
  module GenerateTestReport = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "message"]
        message: string, /* Message to be displayed in the report. */
        [@yojson.option] [@key "group"]
        group: option(string) /* Specifies the endpoint group to deliver the report to. */,
      };
      let make = (~message, ~group=?, ()) => {
        {message, group};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.generateTestReport", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Pauses page execution. Can be resumed using generic Runtime.runIfWaitingForDebugger. */
  module WaitForDebugger = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Page.waitForDebugger", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Intercept file chooser requests and transfer control to protocol clients.
     When file chooser interception is enabled, native file chooser dialog is not shown.
     Instead, a protocol event `Page.fileChooserOpened` is emitted. */
  module SetInterceptFileChooserDialog = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* No description provided */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Page.setInterceptFileChooserDialog", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Performance = {
  /* Disable collecting and reporting metrics. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Performance.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable collecting and reporting metrics. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type enable_timedomain = [ | `timeTicks | `threadTicks];
      let enable_timedomain_of_yojson =
        fun
        | `String("timeTicks") => `timeTicks
        | `String("threadTicks") => `threadTicks
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_enable_timedomain =
        fun
        | `timeTicks => `String("timeTicks")
        | `threadTicks => `String("threadTicks");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "timeDomain"]
        timeDomain: option(enable_timedomain) /* Time domain to use for collecting and reporting duration metrics. */,
      };
      let make = (~timeDomain=?, ()) => {
        {timeDomain: timeDomain};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Performance.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets time domain to use for collecting and reporting duration metrics.
     Note that this must be called before enabling metrics collection. Calling
     this method while metrics collection is enabled returns an error. */
  module SetTimeDomain = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type settimedomain_timedomain = [ | `timeTicks | `threadTicks];
      let settimedomain_timedomain_of_yojson =
        fun
        | `String("timeTicks") => `timeTicks
        | `String("threadTicks") => `threadTicks
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_settimedomain_timedomain =
        fun
        | `timeTicks => `String("timeTicks")
        | `threadTicks => `String("threadTicks");
      [@deriving yojson]
      type t = {
        [@key "timeDomain"]
        timeDomain: settimedomain_timedomain /* Time domain */,
      };
      let make = (~timeDomain, ()) => {
        {timeDomain: timeDomain};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Performance.setTimeDomain", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve current values of run-time metrics. */
  module GetMetrics = {
    module Response: {
      type result = {
        [@key "metrics"]
        metrics: list(Types.Performance.Metric.t) /* Current values for run-time metrics. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "metrics"]
        metrics: list(Types.Performance.Metric.t) /* Current values for run-time metrics. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Performance.getMetrics", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module PerformanceTimeline = {
  /* Previously buffered events would be reported before method returns.
     See also: timelineEventAdded */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventTypes"]
        eventTypes: list(string) /* The types of event to report, as specified in
https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
The specified filter overrides any previous filters, passing empty
filter disables recording.
Note that not all types exposed to the web platform are currently supported. */,
      };
      let make = (~eventTypes, ()) => {
        {eventTypes: eventTypes};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "PerformanceTimeline.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Security = {
  /* Disables tracking security state changes. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Security.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables tracking security state changes. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Security.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable/disable whether all certificate errors should be ignored. */
  module SetIgnoreCertificateErrors = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "ignore"]
        ignore: bool /* If true, all certificate errors will be ignored. */,
      };
      let make = (~ignore, ()) => {
        {ignore: ignore};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Security.setIgnoreCertificateErrors", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Handles a certificate error that fired a certificateError event. */
  module HandleCertificateError = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "eventId"]
        eventId: float, /* The ID of the event. */
        [@key "action"]
        action: Types.Security.CertificateErrorAction.t /* The action to take on the certificate error. */,
      };
      let make = (~eventId, ~action, ()) => {
        {eventId, action};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Security.handleCertificateError", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable/disable overriding certificate errors. If enabled, all certificate error events need to
     be handled by the DevTools client and should be answered with `handleCertificateError` commands. */
  module SetOverrideCertificateErrors = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "override"]
        override: bool /* If true, certificate errors will be overridden. */,
      };
      let make = (~override, ()) => {
        {override: override};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Security.setOverrideCertificateErrors",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module ServiceWorker = {
  /* No description provided */
  module DeliverPushMessage = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string, /* No description provided */
        [@key "registrationId"]
        registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
        [@key "data"]
        data: string /* No description provided */,
      };
      let make = (~origin, ~registrationId, ~data, ()) => {
        {origin, registrationId, data};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.deliverPushMessage", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "ServiceWorker.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module DispatchSyncEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string, /* No description provided */
        [@key "registrationId"]
        registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
        [@key "tag"]
        tag: string, /* No description provided */
        [@key "lastChance"]
        lastChance: bool /* No description provided */,
      };
      let make = (~origin, ~registrationId, ~tag, ~lastChance, ()) => {
        {origin, registrationId, tag, lastChance};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.dispatchSyncEvent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module DispatchPeriodicSyncEvent = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string, /* No description provided */
        [@key "registrationId"]
        registrationId: Types.ServiceWorker.RegistrationID.t, /* No description provided */
        [@key "tag"]
        tag: string /* No description provided */,
      };
      let make = (~origin, ~registrationId, ~tag, ()) => {
        {origin, registrationId, tag};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "ServiceWorker.dispatchPeriodicSyncEvent",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "ServiceWorker.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module InspectWorker = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "versionId"]
        versionId: string /* No description provided */,
      };
      let make = (~versionId, ()) => {
        {versionId: versionId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.inspectWorker", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetForceUpdateOnPageLoad = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "forceUpdateOnPageLoad"]
        forceUpdateOnPageLoad: bool /* No description provided */,
      };
      let make = (~forceUpdateOnPageLoad, ()) => {
        {forceUpdateOnPageLoad: forceUpdateOnPageLoad};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "ServiceWorker.setForceUpdateOnPageLoad",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SkipWaiting = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scopeURL"]
        scopeURL: string /* No description provided */,
      };
      let make = (~scopeURL, ()) => {
        {scopeURL: scopeURL};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.skipWaiting", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StartWorker = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scopeURL"]
        scopeURL: string /* No description provided */,
      };
      let make = (~scopeURL, ()) => {
        {scopeURL: scopeURL};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.startWorker", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StopAllWorkers = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "ServiceWorker.stopAllWorkers", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StopWorker = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "versionId"]
        versionId: string /* No description provided */,
      };
      let make = (~versionId, ()) => {
        {versionId: versionId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.stopWorker", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Unregister = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scopeURL"]
        scopeURL: string /* No description provided */,
      };
      let make = (~scopeURL, ()) => {
        {scopeURL: scopeURL};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.unregister", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module UpdateRegistration = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scopeURL"]
        scopeURL: string /* No description provided */,
      };
      let make = (~scopeURL, ()) => {
        {scopeURL: scopeURL};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "ServiceWorker.updateRegistration", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Storage = {
  /* Clears storage for origin. */
  module ClearDataForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string, /* Security origin. */
        [@key "storageTypes"]
        storageTypes: string /* Comma separated list of StorageType to clear. */,
      };
      let make = (~origin, ~storageTypes, ()) => {
        {origin, storageTypes};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.clearDataForOrigin", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all browser cookies. */
  module GetCookies = {
    module Response: {
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "cookies"]
        cookies: list(Types.Network.Cookie.t) /* Array of cookie objects. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
      };
      let make = (~browserContextId=?, ()) => {
        {browserContextId: browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.getCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets given cookies. */
  module SetCookies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "cookies"]
        cookies: list(Types.Network.CookieParam.t), /* Cookies to be set. */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
      };
      let make = (~cookies, ~browserContextId=?, ()) => {
        {cookies, browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.setCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears cookies. */
  module ClearCookies = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t) /* Browser context to use when called on the browser endpoint. */,
      };
      let make = (~browserContextId=?, ()) => {
        {browserContextId: browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.clearCookies", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns usage and quota in bytes. */
  module GetUsageAndQuota = {
    module Response: {
      type result = {
        [@key "usage"]
        usage: float, /* Storage usage (bytes). */
        [@key "quota"]
        quota: float, /* Storage quota (bytes). */
        [@key "overrideActive"]
        overrideActive: bool, /* Whether or not the origin has an active storage quota override */
        [@key "usageBreakdown"]
        usageBreakdown: list(Types.Storage.UsageForType.t) /* Storage usage per type (bytes). */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "usage"]
        usage: float, /* Storage usage (bytes). */
        [@key "quota"]
        quota: float, /* Storage quota (bytes). */
        [@key "overrideActive"]
        overrideActive: bool, /* Whether or not the origin has an active storage quota override */
        [@key "usageBreakdown"]
        usageBreakdown: list(Types.Storage.UsageForType.t) /* Storage usage per type (bytes). */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Security origin. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.getUsageAndQuota", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Override quota for the specified origin */
  module OverrideQuotaForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string, /* Security origin. */
        [@yojson.option] [@key "quotaSize"]
        quotaSize: option(float) /* The quota size (in bytes) to override the original quota with.
If this is called multiple times, the overridden quota will be equal to
the quotaSize provided in the final call. If this is called without
specifying a quotaSize, the quota will be reset to the default value for
the specified origin. If this is called multiple times with different
origins, the override will be maintained for each origin until it is
disabled (called without a quotaSize). */,
      };
      let make = (~origin, ~quotaSize=?, ()) => {
        {origin, quotaSize};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.overrideQuotaForOrigin", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Registers origin to be notified when an update occurs to its cache storage list. */
  module TrackCacheStorageForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Security origin. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.trackCacheStorageForOrigin", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Registers origin to be notified when an update occurs to its IndexedDB. */
  module TrackIndexedDBForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Security origin. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.trackIndexedDBForOrigin", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Unregisters origin from receiving notifications for cache storage. */
  module UntrackCacheStorageForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Security origin. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Storage.untrackCacheStorageForOrigin",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Unregisters origin from receiving notifications for IndexedDB. */
  module UntrackIndexedDBForOrigin = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "origin"]
        origin: string /* Security origin. */,
      };
      let make = (~origin, ()) => {
        {origin: origin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.untrackIndexedDBForOrigin", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the number of stored Trust Tokens per issuer for the
     current browsing context. */
  module GetTrustTokens = {
    module Response: {
      type result = {
        [@key "tokens"]
        tokens: list(Types.Storage.TrustTokens.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "tokens"]
        tokens: list(Types.Storage.TrustTokens.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Storage.getTrustTokens", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes all Trust Tokens issued by the provided issuerOrigin.
     Leaves other stored data, including the issuer's Redemption Records, intact. */
  module ClearTrustTokens = {
    module Response: {
      type result = {
        [@key "didDeleteTokens"]
        didDeleteTokens: bool /* True if any tokens were deleted, false otherwise. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "didDeleteTokens"]
        didDeleteTokens: bool /* True if any tokens were deleted, false otherwise. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "issuerOrigin"]
        issuerOrigin: string /* No description provided */,
      };
      let make = (~issuerOrigin, ()) => {
        {issuerOrigin: issuerOrigin};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Storage.clearTrustTokens", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module SystemInfo = {
  /* Returns information about the system. */
  module GetInfo = {
    module Response: {
      type result = {
        [@key "gpu"]
        gpu: Types.SystemInfo.GPUInfo.t, /* Information about the GPUs on the system. */
        [@key "modelName"]
        modelName: string, /* A platform-dependent description of the model of the machine. On Mac OS, this is, for
example, 'MacBookPro'. Will be the empty string if not supported. */
        [@key "modelVersion"]
        modelVersion: string, /* A platform-dependent description of the version of the machine. On Mac OS, this is, for
example, '10.1'. Will be the empty string if not supported. */
        [@key "commandLine"]
        commandLine: string /* The command line string used to launch the browser. Will be the empty string if not
supported. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "gpu"]
        gpu: Types.SystemInfo.GPUInfo.t, /* Information about the GPUs on the system. */
        [@key "modelName"]
        modelName: string, /* A platform-dependent description of the model of the machine. On Mac OS, this is, for
example, 'MacBookPro'. Will be the empty string if not supported. */
        [@key "modelVersion"]
        modelVersion: string, /* A platform-dependent description of the version of the machine. On Mac OS, this is, for
example, '10.1'. Will be the empty string if not supported. */
        [@key "commandLine"]
        commandLine: string /* The command line string used to launch the browser. Will be the empty string if not
supported. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "SystemInfo.getInfo", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns information about all running processes. */
  module GetProcessInfo = {
    module Response: {
      type result = {
        [@key "processInfo"]
        processInfo: list(Types.SystemInfo.ProcessInfo.t) /* An array of process info blocks. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "processInfo"]
        processInfo: list(Types.SystemInfo.ProcessInfo.t) /* An array of process info blocks. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "SystemInfo.getProcessInfo", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Target = {
  /* Activates (focuses) the target. */
  module ActivateTarget = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t /* No description provided */,
      };
      let make = (~targetId, ()) => {
        {targetId: targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.activateTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Attaches to the target with given id. */
  module AttachToTarget = {
    module Response: {
      type result = {
        [@key "sessionId"]
        sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "sessionId"]
        sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t, /* No description provided */
        [@yojson.option] [@key "flatten"]
        flatten: option(bool) /* Enables "flat" access to the session via specifying sessionId attribute in the commands.
We plan to make this the default, deprecate non-flattened mode,
and eventually retire it. See crbug.com/991325. */,
      };
      let make = (~targetId, ~flatten=?, ()) => {
        {targetId, flatten};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.attachToTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Attaches to the browser target, only uses flat sessionId mode. */
  module AttachToBrowserTarget = {
    module Response: {
      type result = {
        [@key "sessionId"]
        sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "sessionId"]
        sessionId: Types.Target.SessionID.t /* Id assigned to the session. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Target.attachToBrowserTarget", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Closes the target. If the target is a page that gets closed too. */
  module CloseTarget = {
    module Response: {
      type result = {
        [@key "success"]
        success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "success"]
        success: bool /* Always set to true. If an error occurs, the response indicates protocol error. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t /* No description provided */,
      };
      let make = (~targetId, ()) => {
        {targetId: targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.closeTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Inject object to the target's main frame that provides a communication
     channel with browser target.

     Injected object will be available as `window[bindingName]`.

     The object has the follwing API:
     - `binding.send(json)` - a method to send messages over the remote debugging protocol
     - `binding.onmessage = json => handleMessage(json)` - a callback that will be called for the protocol notifications and command responses. */
  module ExposeDevToolsProtocol = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t, /* No description provided */
        [@yojson.option] [@key "bindingName"]
        bindingName: option(string) /* Binding name, 'cdp' if not specified. */,
      };
      let make = (~targetId, ~bindingName=?, ()) => {
        {targetId, bindingName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.exposeDevToolsProtocol", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates a new empty BrowserContext. Similar to an incognito profile but you can have more than
     one. */
  module CreateBrowserContext = {
    module Response: {
      type result = {
        [@key "browserContextId"]
        browserContextId: Types.Browser.BrowserContextID.t /* The id of the context created. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "browserContextId"]
        browserContextId: Types.Browser.BrowserContextID.t /* The id of the context created. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "disposeOnDetach"]
        disposeOnDetach: option(bool), /* If specified, disposes this context when debugging session disconnects. */
        [@yojson.option] [@key "proxyServer"]
        proxyServer: option(string), /* Proxy server, similar to the one passed to --proxy-server */
        [@yojson.option] [@key "proxyBypassList"]
        proxyBypassList: option(string) /* Proxy bypass list, similar to the one passed to --proxy-bypass-list */,
      };
      let make = (~disposeOnDetach=?, ~proxyServer=?, ~proxyBypassList=?, ()) => {
        {disposeOnDetach, proxyServer, proxyBypassList};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.createBrowserContext", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all browser contexts created with `Target.createBrowserContext` method. */
  module GetBrowserContexts = {
    module Response: {
      type result = {
        [@key "browserContextIds"]
        browserContextIds: list(Types.Browser.BrowserContextID.t) /* An array of browser context ids. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "browserContextIds"]
        browserContextIds: list(Types.Browser.BrowserContextID.t) /* An array of browser context ids. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Target.getBrowserContexts", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates a new page. */
  module CreateTarget = {
    module Response: {
      type result = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t /* The id of the page opened. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "targetId"]
        targetId: Types.Target.TargetID.t /* The id of the page opened. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "url"]
        url: string, /* The initial URL the page will be navigated to. An empty string indicates about:blank. */
        [@yojson.option] [@key "width"]
        width: option(float), /* Frame width in DIP (headless chrome only). */
        [@yojson.option] [@key "height"]
        height: option(float), /* Frame height in DIP (headless chrome only). */
        [@yojson.option] [@key "browserContextId"]
        browserContextId: option(Types.Browser.BrowserContextID.t), /* The browser context to create the page in. */
        [@yojson.option] [@key "enableBeginFrameControl"]
        enableBeginFrameControl: option(bool), /* Whether BeginFrames for this target will be controlled via DevTools (headless chrome only,
not supported on MacOS yet, false by default). */
        [@yojson.option] [@key "newWindow"]
        newWindow: option(bool), /* Whether to create a new Window or Tab (chrome-only, false by default). */
        [@yojson.option] [@key "background"]
        background: option(bool) /* Whether to create the target in background or foreground (chrome-only,
false by default). */,
      };
      let make =
          (
            ~url,
            ~width=?,
            ~height=?,
            ~browserContextId=?,
            ~enableBeginFrameControl=?,
            ~newWindow=?,
            ~background=?,
            (),
          ) => {
        {
          url,
          width,
          height,
          browserContextId,
          enableBeginFrameControl,
          newWindow,
          background,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.createTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Detaches session with given id. */
  module DetachFromTarget = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "sessionId"]
        sessionId: option(Types.Target.SessionID.t), /* Session to detach. */
        [@yojson.option] [@key "targetId"]
        targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
      };
      let make = (~sessionId=?, ~targetId=?, ()) => {
        {sessionId, targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.detachFromTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Deletes a BrowserContext. All the belonging pages will be closed without calling their
     beforeunload hooks. */
  module DisposeBrowserContext = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "browserContextId"]
        browserContextId: Types.Browser.BrowserContextID.t /* No description provided */,
      };
      let make = (~browserContextId, ()) => {
        {browserContextId: browserContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.disposeBrowserContext", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns information about a target. */
  module GetTargetInfo = {
    module Response: {
      type result = {
        [@key "targetInfo"]
        targetInfo: Types.Target.TargetInfo.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "targetInfo"]
        targetInfo: Types.Target.TargetInfo.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "targetId"]
        targetId: option(Types.Target.TargetID.t) /* No description provided */,
      };
      let make = (~targetId=?, ()) => {
        {targetId: targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.getTargetInfo", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieves a list of available targets. */
  module GetTargets = {
    module Response: {
      type result = {
        [@key "targetInfos"]
        targetInfos: list(Types.Target.TargetInfo.t) /* The list of targets. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "targetInfos"]
        targetInfos: list(Types.Target.TargetInfo.t) /* The list of targets. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Target.getTargets", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sends protocol message over session with given id.
     Consider using flat mode instead; see commands attachToTarget, setAutoAttach,
     and crbug.com/991325. */
  module SendMessageToTarget = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "message"]
        message: string, /* No description provided */
        [@yojson.option] [@key "sessionId"]
        sessionId: option(Types.Target.SessionID.t), /* Identifier of the session. */
        [@yojson.option] [@key "targetId"]
        targetId: option(Types.Target.TargetID.t) /* Deprecated. */,
      };
      let make = (~message, ~sessionId=?, ~targetId=?, ()) => {
        {message, sessionId, targetId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.sendMessageToTarget", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Controls whether to automatically attach to new targets which are considered to be related to
     this one. When turned on, attaches to all existing related targets as well. When turned off,
     automatically detaches from all currently attached targets. */
  module SetAutoAttach = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "autoAttach"]
        autoAttach: bool, /* Whether to auto-attach to related targets. */
        [@key "waitForDebuggerOnStart"]
        waitForDebuggerOnStart: bool, /* Whether to pause new targets when attaching to them. Use `Runtime.runIfWaitingForDebugger`
to run paused targets. */
        [@yojson.option] [@key "flatten"]
        flatten: option(bool) /* Enables "flat" access to the session via specifying sessionId attribute in the commands.
We plan to make this the default, deprecate non-flattened mode,
and eventually retire it. See crbug.com/991325. */,
      };
      let make = (~autoAttach, ~waitForDebuggerOnStart, ~flatten=?, ()) => {
        {autoAttach, waitForDebuggerOnStart, flatten};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.setAutoAttach", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Controls whether to discover available targets and notify via
     `targetCreated/targetInfoChanged/targetDestroyed` events. */
  module SetDiscoverTargets = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "discover"]
        discover: bool /* Whether to discover available targets. */,
      };
      let make = (~discover, ()) => {
        {discover: discover};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.setDiscoverTargets", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables target discovery for the specified locations, when `setDiscoverTargets` was set to
     `true`. */
  module SetRemoteLocations = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "locations"]
        locations: list(Types.Target.RemoteLocation.t) /* List of remote locations. */,
      };
      let make = (~locations, ()) => {
        {locations: locations};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Target.setRemoteLocations", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Tethering = {
  /* Request browser port binding. */
  module Bind = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "port"]
        port: float /* Port number to bind. */,
      };
      let make = (~port, ()) => {
        {port: port};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Tethering.bind", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Request browser port unbinding. */
  module Unbind = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "port"]
        port: float /* Port number to unbind. */,
      };
      let make = (~port, ()) => {
        {port: port};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Tethering.unbind", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Tracing = {
  /* Stop trace events collection. */
  module End = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Tracing.end", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Gets supported tracing categories. */
  module GetCategories = {
    module Response: {
      type result = {
        [@key "categories"]
        categories: list(string) /* A list of supported tracing categories. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "categories"]
        categories: list(string) /* A list of supported tracing categories. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Tracing.getCategories", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Record a clock sync marker in the trace. */
  module RecordClockSyncMarker = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "syncId"]
        syncId: string /* The ID of this clock sync marker */,
      };
      let make = (~syncId, ()) => {
        {syncId: syncId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Tracing.recordClockSyncMarker", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Request a global memory dump. */
  module RequestMemoryDump = {
    module Response: {
      type result = {
        [@key "dumpGuid"]
        dumpGuid: string, /* GUID of the resulting global memory dump. */
        [@key "success"]
        success: bool /* True iff the global memory dump succeeded. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "dumpGuid"]
        dumpGuid: string, /* GUID of the resulting global memory dump. */
        [@key "success"]
        success: bool /* True iff the global memory dump succeeded. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "deterministic"]
        deterministic: option(bool), /* Enables more deterministic results by forcing garbage collection */
        [@yojson.option] [@key "levelOfDetail"]
        levelOfDetail: option(Types.Tracing.MemoryDumpLevelOfDetail.t) /* Specifies level of details in memory dump. Defaults to "detailed". */,
      };
      let make = (~deterministic=?, ~levelOfDetail=?, ()) => {
        {deterministic, levelOfDetail};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Tracing.requestMemoryDump", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Start trace events collection. */
  module Start = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type start_transfermode = [ | `ReportEvents | `ReturnAsStream];
      let start_transfermode_of_yojson =
        fun
        | `String("ReportEvents") => `ReportEvents
        | `String("ReturnAsStream") => `ReturnAsStream
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_start_transfermode =
        fun
        | `ReportEvents => `String("ReportEvents")
        | `ReturnAsStream => `String("ReturnAsStream");
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "categories"]
        categories: option(string), /* Category/tag filter */
        [@yojson.option] [@key "options"]
        options: option(string), /* Tracing options */
        [@yojson.option] [@key "bufferUsageReportingInterval"]
        bufferUsageReportingInterval: option(float), /* If set, the agent will issue bufferUsage events at this interval, specified in milliseconds */
        [@yojson.option] [@key "transferMode"]
        transferMode: option(start_transfermode), /* Whether to report trace events as series of dataCollected events or to save trace to a
stream (defaults to `ReportEvents`). */
        [@yojson.option] [@key "streamFormat"]
        streamFormat: option(Types.Tracing.StreamFormat.t), /* Trace data format to use. This only applies when using `ReturnAsStream`
transfer mode (defaults to `json`). */
        [@yojson.option] [@key "streamCompression"]
        streamCompression: option(Types.Tracing.StreamCompression.t), /* Compression format to use. This only applies when using `ReturnAsStream`
transfer mode (defaults to `none`) */
        [@yojson.option] [@key "traceConfig"]
        traceConfig: option(Types.Tracing.TraceConfig.t), /* No description provided */
        [@yojson.option] [@key "perfettoConfig"]
        perfettoConfig: option(string), /* Base64-encoded serialized perfetto.protos.TraceConfig protobuf message
When specified, the parameters `categories`, `options`, `traceConfig`
are ignored. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "tracingBackend"]
        tracingBackend: option(Types.Tracing.TracingBackend.t) /* Backend type (defaults to `auto`) */,
      };
      let make =
          (
            ~categories=?,
            ~options=?,
            ~bufferUsageReportingInterval=?,
            ~transferMode=?,
            ~streamFormat=?,
            ~streamCompression=?,
            ~traceConfig=?,
            ~perfettoConfig=?,
            ~tracingBackend=?,
            (),
          ) => {
        {
          categories,
          options,
          bufferUsageReportingInterval,
          transferMode,
          streamFormat,
          streamCompression,
          traceConfig,
          perfettoConfig,
          tracingBackend,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Tracing.start", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Fetch = {
  /* Disables the fetch domain. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Fetch.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables issuing of requestPaused events. A request will be paused until client
     calls one of failRequest, fulfillRequest or continueRequest/continueWithAuth. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "patterns"]
        patterns: option(list(Types.Fetch.RequestPattern.t)), /* If specified, only requests matching any of these patterns will produce
fetchRequested event and will be paused until clients response. If not set,
all requests will be affected. */
        [@yojson.option] [@key "handleAuthRequests"]
        handleAuthRequests: option(bool) /* If true, authRequired events will be issued and requests will be paused
expecting a call to continueWithAuth. */,
      };
      let make = (~patterns=?, ~handleAuthRequests=?, ()) => {
        {patterns, handleAuthRequests};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Causes the request to fail with specified reason. */
  module FailRequest = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
        [@key "errorReason"]
        errorReason: Types.Network.ErrorReason.t /* Causes the request to fail with the given reason. */,
      };
      let make = (~requestId, ~errorReason, ()) => {
        {requestId, errorReason};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.failRequest", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Provides response to the request. */
  module FulfillRequest = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
        [@key "responseCode"]
        responseCode: float, /* An HTTP response code. */
        [@yojson.option] [@key "responseHeaders"]
        responseHeaders: option(list(Types.Fetch.HeaderEntry.t)), /* Response headers. */
        [@yojson.option] [@key "binaryResponseHeaders"]
        binaryResponseHeaders: option(string), /* Alternative way of specifying response headers as a \0-separated
series of name: value pairs. Prefer the above method unless you
need to represent some non-UTF8 values that can't be transmitted
over the protocol as text. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "body"]
        body: option(string), /* A response body. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "responsePhrase"]
        responsePhrase: option(string) /* A textual representation of responseCode.
If absent, a standard phrase matching responseCode is used. */,
      };
      let make =
          (
            ~requestId,
            ~responseCode,
            ~responseHeaders=?,
            ~binaryResponseHeaders=?,
            ~body=?,
            ~responsePhrase=?,
            (),
          ) => {
        {
          requestId,
          responseCode,
          responseHeaders,
          binaryResponseHeaders,
          body,
          responsePhrase,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.fulfillRequest", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Continues the request, optionally modifying some of its parameters. */
  module ContinueRequest = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t, /* An id the client received in requestPaused event. */
        [@yojson.option] [@key "url"]
        url: option(string), /* If set, the request url will be modified in a way that's not observable by page. */
        [@yojson.option] [@key "method"]
        method: option(string), /* If set, the request method is overridden. */
        [@yojson.option] [@key "postData"]
        postData: option(string), /* If set, overrides the post data in the request. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option] [@key "headers"]
        headers: option(list(Types.Fetch.HeaderEntry.t)), /* If set, overrides the request headers. */
        [@yojson.option] [@key "interceptResponse"]
        interceptResponse: option(bool) /* If set, overrides response interception behavior for this request. */,
      };
      let make =
          (
            ~requestId,
            ~url=?,
            ~method=?,
            ~postData=?,
            ~headers=?,
            ~interceptResponse=?,
            (),
          ) => {
        {requestId, url, method, postData, headers, interceptResponse};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.continueRequest", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Continues a request supplying authChallengeResponse following authRequired event. */
  module ContinueWithAuth = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t, /* An id the client received in authRequired event. */
        [@key "authChallengeResponse"]
        authChallengeResponse: Types.Fetch.AuthChallengeResponse.t /* Response to  with an authChallenge. */,
      };
      let make = (~requestId, ~authChallengeResponse, ()) => {
        {requestId, authChallengeResponse};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.continueWithAuth", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Causes the body of the response to be received from the server and
     returned as a single string. May only be issued for a request that
     is paused in the Response stage and is mutually exclusive with
     takeResponseBodyForInterceptionAsStream. Calling other methods that
     affect the request or disabling fetch domain before body is received
     results in an undefined behavior. */
  module GetResponseBody = {
    module Response: {
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "body"]
        body: string, /* Response body. */
        [@key "base64Encoded"]
        base64Encoded: bool /* True, if content was sent as base64. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t /* Identifier for the intercepted request to get body for. */,
      };
      let make = (~requestId, ()) => {
        {requestId: requestId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.getResponseBody", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
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
    module Response: {
      type result = {
        [@key "stream"]
        stream: Types.IO.StreamHandle.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "stream"]
        stream: Types.IO.StreamHandle.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "requestId"]
        requestId: Types.Fetch.RequestId.t /* No description provided */,
      };
      let make = (~requestId, ()) => {
        {requestId: requestId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Fetch.takeResponseBodyAsStream", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module WebAudio = {
  /* Enables the WebAudio domain and starts sending context lifetime events. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "WebAudio.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables the WebAudio domain. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "WebAudio.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Fetch the realtime data from the registered contexts. */
  module GetRealtimeData = {
    module Response: {
      type result = {
        [@key "realtimeData"]
        realtimeData: Types.WebAudio.ContextRealtimeData.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "realtimeData"]
        realtimeData: Types.WebAudio.ContextRealtimeData.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "contextId"]
        contextId: Types.WebAudio.GraphObjectId.t /* No description provided */,
      };
      let make = (~contextId, ()) => {
        {contextId: contextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAudio.getRealtimeData", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module WebAuthn = {
  /* Enable the WebAuthn domain and start intercepting credential storage and
     retrieval with a virtual authenticator. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "WebAuthn.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disable the WebAuthn domain. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "WebAuthn.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Creates and adds a virtual authenticator. */
  module AddVirtualAuthenticator = {
    module Response: {
      type result = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "options"]
        options: Types.WebAuthn.VirtualAuthenticatorOptions.t /* No description provided */,
      };
      let make = (~options, ()) => {
        {options: options};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.addVirtualAuthenticator", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes the given authenticator. */
  module RemoveVirtualAuthenticator = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
      };
      let make = (~authenticatorId, ()) => {
        {authenticatorId: authenticatorId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.removeVirtualAuthenticator", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Adds the credential to the specified authenticator. */
  module AddCredential = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
        [@key "credential"]
        credential: Types.WebAuthn.Credential.t /* No description provided */,
      };
      let make = (~authenticatorId, ~credential, ()) => {
        {authenticatorId, credential};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.addCredential", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns a single credential stored in the given virtual authenticator that
     matches the credential ID. */
  module GetCredential = {
    module Response: {
      type result = {
        [@key "credential"]
        credential: Types.WebAuthn.Credential.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "credential"]
        credential: Types.WebAuthn.Credential.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
        [@key "credentialId"]
        credentialId: string /* No description provided */,
      };
      let make = (~authenticatorId, ~credentialId, ()) => {
        {authenticatorId, credentialId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.getCredential", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all the credentials stored in the given virtual authenticator. */
  module GetCredentials = {
    module Response: {
      type result = {
        [@key "credentials"]
        credentials: list(Types.WebAuthn.Credential.t) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "credentials"]
        credentials: list(Types.WebAuthn.Credential.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
      };
      let make = (~authenticatorId, ()) => {
        {authenticatorId: authenticatorId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.getCredentials", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes a credential from the authenticator. */
  module RemoveCredential = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
        [@key "credentialId"]
        credentialId: string /* No description provided */,
      };
      let make = (~authenticatorId, ~credentialId, ()) => {
        {authenticatorId, credentialId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.removeCredential", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Clears all the credentials from the specified device. */
  module ClearCredentials = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t /* No description provided */,
      };
      let make = (~authenticatorId, ()) => {
        {authenticatorId: authenticatorId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.clearCredentials", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets whether User Verification succeeds or fails for an authenticator.
     The default is true. */
  module SetUserVerified = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
        [@key "isUserVerified"]
        isUserVerified: bool /* No description provided */,
      };
      let make = (~authenticatorId, ~isUserVerified, ()) => {
        {authenticatorId, isUserVerified};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "WebAuthn.setUserVerified", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets whether tests of user presence will succeed immediately (if true) or fail to resolve (if false) for an authenticator.
     The default is true. */
  module SetAutomaticPresenceSimulation = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "authenticatorId"]
        authenticatorId: Types.WebAuthn.AuthenticatorId.t, /* No description provided */
        [@key "enabled"]
        enabled: bool /* No description provided */,
      };
      let make = (~authenticatorId, ~enabled, ()) => {
        {authenticatorId, enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "WebAuthn.setAutomaticPresenceSimulation",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Media = {
  /* Enables the Media domain */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Media.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables the Media domain. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Media.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Console = {
  /* Does nothing. */
  module ClearMessages = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Console.clearMessages", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables console domain, prevents further console messages from being reported to the client. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Console.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables console domain, sends the messages collected so far to the client by means of the
     `messageAdded` notification. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Console.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Debugger = {
  /* Continues execution until specific location is reached. */
  module ContinueToLocation = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type continuetolocation_targetcallframes = [ | `any | `current];
      let continuetolocation_targetcallframes_of_yojson =
        fun
        | `String("any") => `any
        | `String("current") => `current
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_continuetolocation_targetcallframes =
        fun
        | `any => `String("any")
        | `current => `String("current");
      [@deriving yojson]
      type t = {
        [@key "location"]
        location: Types.Debugger.Location.t, /* Location to continue to. */
        [@yojson.option] [@key "targetCallFrames"]
        targetCallFrames: option(continuetolocation_targetcallframes) /* No description provided */,
      };
      let make = (~location, ~targetCallFrames=?, ()) => {
        {location, targetCallFrames};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.continueToLocation", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables debugger for given page. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Debugger.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables debugger for the given page. Clients should not assume that the debugging has been
     enabled until the result for this command is received. */
  module Enable = {
    module Response: {
      type result = {
        [@key "debuggerId"]
        debuggerId: Types.Runtime.UniqueDebuggerId.t /* Unique identifier of the debugger. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "debuggerId"]
        debuggerId: Types.Runtime.UniqueDebuggerId.t /* Unique identifier of the debugger. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "maxScriptsCacheSize"]
        maxScriptsCacheSize: option(float) /* The maximum size in bytes of collected scripts (not referenced by other heap objects)
the debugger can hold. Puts no limit if paramter is omitted. */,
      };
      let make = (~maxScriptsCacheSize=?, ()) => {
        {maxScriptsCacheSize: maxScriptsCacheSize};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.enable", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Evaluates expression on a given call frame. */
  module EvaluateOnCallFrame = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Object wrapper for the evaluation result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Object wrapper for the evaluation result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "callFrameId"]
        callFrameId: Types.Debugger.CallFrameId.t, /* Call frame identifier to evaluate on. */
        [@key "expression"]
        expression: string, /* Expression to evaluate. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string), /* String object group name to put result into (allows rapid releasing resulting object handles
using `releaseObjectGroup`). */
        [@yojson.option] [@key "includeCommandLineAPI"]
        includeCommandLineAPI: option(bool), /* Specifies whether command line API should be available to the evaluated expression, defaults
to false. */
        [@yojson.option] [@key "silent"]
        silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
        [@yojson.option] [@key "returnByValue"]
        returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool), /* Whether preview should be generated for the result. */
        [@yojson.option] [@key "throwOnSideEffect"]
        throwOnSideEffect: option(bool), /* Whether to throw an exception if side effect cannot be ruled out during evaluation. */
        [@yojson.option] [@key "timeout"]
        timeout: option(Types.Runtime.TimeDelta.t) /* Terminate execution after timing out (number of milliseconds). */,
      };
      let make =
          (
            ~callFrameId,
            ~expression,
            ~objectGroup=?,
            ~includeCommandLineAPI=?,
            ~silent=?,
            ~returnByValue=?,
            ~generatePreview=?,
            ~throwOnSideEffect=?,
            ~timeout=?,
            (),
          ) => {
        {
          callFrameId,
          expression,
          objectGroup,
          includeCommandLineAPI,
          silent,
          returnByValue,
          generatePreview,
          throwOnSideEffect,
          timeout,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.evaluateOnCallFrame", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns possible locations for breakpoint. scriptId in start and end range locations should be
     the same. */
  module GetPossibleBreakpoints = {
    module Response: {
      type result = {
        [@key "locations"]
        locations: list(Types.Debugger.BreakLocation.t) /* List of the possible breakpoint locations. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "locations"]
        locations: list(Types.Debugger.BreakLocation.t) /* List of the possible breakpoint locations. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "start"]
        start: Types.Debugger.Location.t, /* Start of range to search possible breakpoint locations in. */
        [@yojson.option] [@key "end"]
        end_: option(Types.Debugger.Location.t), /* End of range to search possible breakpoint locations in (excluding). When not specified, end
of scripts is used as end of range. */
        [@yojson.option] [@key "restrictToFunction"]
        restrictToFunction: option(bool) /* Only consider locations which are in the same (non-nested) function as start. */,
      };
      let make = (~start, ~end_=?, ~restrictToFunction=?, ()) => {
        {start, end_, restrictToFunction};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.getPossibleBreakpoints", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns source for the script with given id. */
  module GetScriptSource = {
    module Response: {
      type result = {
        [@key "scriptSource"]
        scriptSource: string, /* Script source (empty in case of Wasm bytecode). */
        [@yojson.option] [@key "bytecode"]
        bytecode: option(string) /* Wasm bytecode. (Encoded as a base64 string when passed over JSON) */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "scriptSource"]
        scriptSource: string, /* Script source (empty in case of Wasm bytecode). */
        [@yojson.option] [@key "bytecode"]
        bytecode: option(string) /* Wasm bytecode. (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t /* Id of the script to get source for. */,
      };
      let make = (~scriptId, ()) => {
        {scriptId: scriptId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.getScriptSource", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* This command is deprecated. Use getScriptSource instead. */
  module GetWasmBytecode = {
    module Response: {
      type result = {
        [@key "bytecode"]
        bytecode: string /* Script source. (Encoded as a base64 string when passed over JSON) */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "bytecode"]
        bytecode: string /* Script source. (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t /* Id of the Wasm script to get source for. */,
      };
      let make = (~scriptId, ()) => {
        {scriptId: scriptId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.getWasmBytecode", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns stack trace with given `stackTraceId`. */
  module GetStackTrace = {
    module Response: {
      type result = {
        [@key "stackTrace"]
        stackTrace: Types.Runtime.StackTrace.t /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "stackTrace"]
        stackTrace: Types.Runtime.StackTrace.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "stackTraceId"]
        stackTraceId: Types.Runtime.StackTraceId.t /* No description provided */,
      };
      let make = (~stackTraceId, ()) => {
        {stackTraceId: stackTraceId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.getStackTrace", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Stops on the next JavaScript statement. */
  module Pause = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Debugger.pause", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module PauseOnAsyncCall = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "parentStackTraceId"]
        parentStackTraceId: Types.Runtime.StackTraceId.t /* Debugger will pause when async call with given stack trace is started. */,
      };
      let make = (~parentStackTraceId, ()) => {
        {parentStackTraceId: parentStackTraceId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.pauseOnAsyncCall", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Removes JavaScript breakpoint. */
  module RemoveBreakpoint = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t /* No description provided */,
      };
      let make = (~breakpointId, ()) => {
        {breakpointId: breakpointId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.removeBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Restarts particular call frame from the beginning. */
  module RestartFrame = {
    module Response: {
      type result = {
        [@key "callFrames"]
        callFrames: list(Types.Debugger.CallFrame.t), /* New stack trace. */
        [@yojson.option] [@key "asyncStackTrace"]
        asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "asyncStackTraceId"]
        asyncStackTraceId: option(Types.Runtime.StackTraceId.t) /* Async stack trace, if any. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "callFrames"]
        callFrames: list(Types.Debugger.CallFrame.t), /* New stack trace. */
        [@yojson.option] [@key "asyncStackTrace"]
        asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "asyncStackTraceId"]
        asyncStackTraceId: option(Types.Runtime.StackTraceId.t) /* Async stack trace, if any. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "callFrameId"]
        callFrameId: Types.Debugger.CallFrameId.t /* Call frame identifier to evaluate on. */,
      };
      let make = (~callFrameId, ()) => {
        {callFrameId: callFrameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.restartFrame", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Resumes JavaScript execution. */
  module Resume = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "terminateOnResume"]
        terminateOnResume: option(bool) /* Set to true to terminate execution upon resuming execution. In contrast
to Runtime.terminateExecution, this will allows to execute further
JavaScript (i.e. via evaluation) until execution of the paused code
is actually resumed, at which point termination is triggered.
If execution is currently not paused, this parameter has no effect. */,
      };
      let make = (~terminateOnResume=?, ()) => {
        {terminateOnResume: terminateOnResume};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.resume", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Searches for given string in script content. */
  module SearchInContent = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Debugger.SearchMatch.t) /* List of search matches. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t, /* Id of the script to search in. */
        [@key "query"]
        query: string, /* String to search for. */
        [@yojson.option] [@key "caseSensitive"]
        caseSensitive: option(bool), /* If true, search is case sensitive. */
        [@yojson.option] [@key "isRegex"]
        isRegex: option(bool) /* If true, treats string parameter as regex. */,
      };
      let make = (~scriptId, ~query, ~caseSensitive=?, ~isRegex=?, ()) => {
        {scriptId, query, caseSensitive, isRegex};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.searchInContent", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables or disables async call stacks tracking. */
  module SetAsyncCallStackDepth = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "maxDepth"]
        maxDepth: float /* Maximum depth of async call stacks. Setting to `0` will effectively disable collecting async
call stacks (default). */,
      };
      let make = (~maxDepth, ()) => {
        {maxDepth: maxDepth};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setAsyncCallStackDepth", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Replace previous blackbox patterns with passed ones. Forces backend to skip stepping/pausing in
     scripts with url matching one of the patterns. VM will try to leave blackboxed script by
     performing 'step in' several times, finally resorting to 'step out' if unsuccessful. */
  module SetBlackboxPatterns = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "patterns"]
        patterns: list(string) /* Array of regexps that will be used to check script url for blackbox state. */,
      };
      let make = (~patterns, ()) => {
        {patterns: patterns};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setBlackboxPatterns", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Makes backend skip steps in the script in blackboxed ranges. VM will try leave blacklisted
     scripts by performing 'step in' several times, finally resorting to 'step out' if unsuccessful.
     Positions array contains positions where blackbox state is changed. First interval isn't
     blackboxed. Array should be sorted. */
  module SetBlackboxedRanges = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t, /* Id of the script. */
        [@key "positions"]
        positions: list(Types.Debugger.ScriptPosition.t) /* No description provided */,
      };
      let make = (~scriptId, ~positions, ()) => {
        {scriptId, positions};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setBlackboxedRanges", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets JavaScript breakpoint at a given location. */
  module SetBreakpoint = {
    module Response: {
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
        [@key "actualLocation"]
        actualLocation: Types.Debugger.Location.t /* Location this breakpoint resolved into. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
        [@key "actualLocation"]
        actualLocation: Types.Debugger.Location.t /* Location this breakpoint resolved into. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "location"]
        location: Types.Debugger.Location.t, /* Location to set breakpoint in. */
        [@yojson.option] [@key "condition"]
        condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will only stop on the
breakpoint if this expression evaluates to true. */,
      };
      let make = (~location, ~condition=?, ()) => {
        {location, condition};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setBreakpoint", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets instrumentation breakpoint. */
  module SetInstrumentationBreakpoint = {
    module Response: {
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setinstrumentationbreakpoint_instrumentation = [
        | `beforeScriptExecution
        | `beforeScriptWithSourceMapExecution
      ];
      let setinstrumentationbreakpoint_instrumentation_of_yojson =
        fun
        | `String("beforeScriptExecution") => `beforeScriptExecution
        | `String("beforeScriptWithSourceMapExecution") => `beforeScriptWithSourceMapExecution
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setinstrumentationbreakpoint_instrumentation =
        fun
        | `beforeScriptExecution => `String("beforeScriptExecution")
        | `beforeScriptWithSourceMapExecution =>
          `String("beforeScriptWithSourceMapExecution");
      [@deriving yojson]
      type t = {
        [@key "instrumentation"]
        instrumentation: setinstrumentationbreakpoint_instrumentation /* Instrumentation name. */,
      };
      let make = (~instrumentation, ()) => {
        {instrumentation: instrumentation};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Debugger.setInstrumentationBreakpoint",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets JavaScript breakpoint at given location specified either by URL or URL regex. Once this
     command is issued, all existing parsed scripts will have breakpoints resolved and returned in
     `locations` property. Further matching script parsing will result in subsequent
     `breakpointResolved` events issued. This logical breakpoint will survive page reloads. */
  module SetBreakpointByUrl = {
    module Response: {
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
        [@key "locations"]
        locations: list(Types.Debugger.Location.t) /* List of the locations this breakpoint resolved into upon addition. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t, /* Id of the created breakpoint for further reference. */
        [@key "locations"]
        locations: list(Types.Debugger.Location.t) /* List of the locations this breakpoint resolved into upon addition. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "lineNumber"]
        lineNumber: float, /* Line number to set breakpoint at. */
        [@yojson.option] [@key "url"]
        url: option(string), /* URL of the resources to set breakpoint on. */
        [@yojson.option] [@key "urlRegex"]
        urlRegex: option(string), /* Regex pattern for the URLs of the resources to set breakpoints on. Either `url` or
`urlRegex` must be specified. */
        [@yojson.option] [@key "scriptHash"]
        scriptHash: option(string), /* Script hash of the resources to set breakpoint on. */
        [@yojson.option] [@key "columnNumber"]
        columnNumber: option(float), /* Offset in the line to set breakpoint at. */
        [@yojson.option] [@key "condition"]
        condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will only stop on the
breakpoint if this expression evaluates to true. */,
      };
      let make =
          (
            ~lineNumber,
            ~url=?,
            ~urlRegex=?,
            ~scriptHash=?,
            ~columnNumber=?,
            ~condition=?,
            (),
          ) => {
        {lineNumber, url, urlRegex, scriptHash, columnNumber, condition};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setBreakpointByUrl", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Sets JavaScript breakpoint before each call to the given function.
     If another function was created from the same source as a given one,
     calling it will also trigger the breakpoint. */
  module SetBreakpointOnFunctionCall = {
    module Response: {
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "breakpointId"]
        breakpointId: Types.Debugger.BreakpointId.t /* Id of the created breakpoint for further reference. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t, /* Function object id. */
        [@yojson.option] [@key "condition"]
        condition: option(string) /* Expression to use as a breakpoint condition. When specified, debugger will
stop on the breakpoint if this expression evaluates to true. */,
      };
      let make = (~objectId, ~condition=?, ()) => {
        {objectId, condition};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Debugger.setBreakpointOnFunctionCall",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Activates / deactivates all breakpoints on the page. */
  module SetBreakpointsActive = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "active"]
        active: bool /* New value for breakpoints active state. */,
      };
      let make = (~active, ()) => {
        {active: active};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setBreakpointsActive", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Defines pause on exceptions state. Can be set to stop on all exceptions, uncaught exceptions or
     no exceptions. Initial pause on exceptions state is `none`. */
  module SetPauseOnExceptions = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      type setpauseonexceptions_state = [ | `none | `uncaught | `all];
      let setpauseonexceptions_state_of_yojson =
        fun
        | `String("none") => `none
        | `String("uncaught") => `uncaught
        | `String("all") => `all
        | `String(s) => failwith("unknown enum: " ++ s)
        | _ => failwith("unknown enum type");
      let yojson_of_setpauseonexceptions_state =
        fun
        | `none => `String("none")
        | `uncaught => `String("uncaught")
        | `all => `String("all");
      [@deriving yojson]
      type t = {
        [@key "state"]
        state: setpauseonexceptions_state /* Pause on exceptions mode. */,
      };
      let make = (~state, ()) => {
        {state: state};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setPauseOnExceptions", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Changes return value in top frame. Available only at return break position. */
  module SetReturnValue = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "newValue"]
        newValue: Types.Runtime.CallArgument.t /* New return value. */,
      };
      let make = (~newValue, ()) => {
        {newValue: newValue};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setReturnValue", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Edits JavaScript source live. */
  module SetScriptSource = {
    module Response: {
      type result = {
        [@yojson.option] [@key "callFrames"]
        callFrames: option(list(Types.Debugger.CallFrame.t)), /* New stack trace in case editing has happened while VM was stopped. */
        [@yojson.option] [@key "stackChanged"]
        stackChanged: option(bool), /* Whether current call stack  was modified after applying the changes. */
        [@yojson.option] [@key "asyncStackTrace"]
        asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "asyncStackTraceId"]
        asyncStackTraceId: option(Types.Runtime.StackTraceId.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if any. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "callFrames"]
        callFrames: option(list(Types.Debugger.CallFrame.t)), /* New stack trace in case editing has happened while VM was stopped. */
        [@yojson.option] [@key "stackChanged"]
        stackChanged: option(bool), /* Whether current call stack  was modified after applying the changes. */
        [@yojson.option] [@key "asyncStackTrace"]
        asyncStackTrace: option(Types.Runtime.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "asyncStackTraceId"]
        asyncStackTraceId: option(Types.Runtime.StackTraceId.t), /* Async stack trace, if any. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if any. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t, /* Id of the script to edit. */
        [@key "scriptSource"]
        scriptSource: string, /* New content of the script. */
        [@yojson.option] [@key "dryRun"]
        dryRun: option(bool) /* If true the change will not actually be applied. Dry run may be used to get result
description without actually modifying the code. */,
      };
      let make = (~scriptId, ~scriptSource, ~dryRun=?, ()) => {
        {scriptId, scriptSource, dryRun};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setScriptSource", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Makes page not interrupt on any pauses (breakpoint, exception, dom exception etc). */
  module SetSkipAllPauses = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "skip"]
        skip: bool /* New value for skip pauses state. */,
      };
      let make = (~skip, ()) => {
        {skip: skip};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setSkipAllPauses", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Changes value of variable in a callframe. Object-based scopes are not supported and must be
     mutated manually. */
  module SetVariableValue = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scopeNumber"]
        scopeNumber: float, /* 0-based number of scope as was listed in scope chain. Only 'local', 'closure' and 'catch'
scope types are allowed. Other scopes could be manipulated manually. */
        [@key "variableName"]
        variableName: string, /* Variable name. */
        [@key "newValue"]
        newValue: Types.Runtime.CallArgument.t, /* New variable value. */
        [@key "callFrameId"]
        callFrameId: Types.Debugger.CallFrameId.t /* Id of callframe that holds variable. */,
      };
      let make = (~scopeNumber, ~variableName, ~newValue, ~callFrameId, ()) => {
        {scopeNumber, variableName, newValue, callFrameId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.setVariableValue", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Steps into the function call. */
  module StepInto = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "breakOnAsyncCall"]
        breakOnAsyncCall: option(bool), /* Debugger will pause on the execution of the first async task which was scheduled
before next pause. */
        [@yojson.option] [@key "skipList"]
        skipList: option(list(Types.Debugger.LocationRange.t)) /* The skipList specifies location ranges that should be skipped on step into. */,
      };
      let make = (~breakOnAsyncCall=?, ~skipList=?, ()) => {
        {breakOnAsyncCall, skipList};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.stepInto", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Steps out of the function call. */
  module StepOut = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Debugger.stepOut", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Steps over the statement. */
  module StepOver = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "skipList"]
        skipList: option(list(Types.Debugger.LocationRange.t)) /* The skipList specifies location ranges that should be skipped on step over. */,
      };
      let make = (~skipList=?, ()) => {
        {skipList: skipList};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Debugger.stepOver", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module HeapProfiler = {
  /* Enables console to refer to the node with given id via $x (see Command Line API for more details
     $x functions). */
  module AddInspectedHeapObject = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "heapObjectId"]
        heapObjectId: Types.HeapProfiler.HeapSnapshotObjectId.t /* Heap snapshot object id to be accessible by means of $x command line API. */,
      };
      let make = (~heapObjectId, ()) => {
        {heapObjectId: heapObjectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "HeapProfiler.addInspectedHeapObject", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module CollectGarbage = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeapProfiler.collectGarbage", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeapProfiler.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeapProfiler.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetHeapObjectId = {
    module Response: {
      type result = {
        [@key "heapSnapshotObjectId"]
        heapSnapshotObjectId: Types.HeapProfiler.HeapSnapshotObjectId.t /* Id of the heap snapshot object corresponding to the passed remote object id. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "heapSnapshotObjectId"]
        heapSnapshotObjectId: Types.HeapProfiler.HeapSnapshotObjectId.t /* Id of the heap snapshot object corresponding to the passed remote object id. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t /* Identifier of the object to get heap object id for. */,
      };
      let make = (~objectId, ()) => {
        {objectId: objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "HeapProfiler.getHeapObjectId", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetObjectByHeapObjectId = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t /* Evaluation result. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t /* Evaluation result. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.HeapProfiler.HeapSnapshotObjectId.t, /* No description provided */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string) /* Symbolic group name that can be used to release multiple objects. */,
      };
      let make = (~objectId, ~objectGroup=?, ()) => {
        {objectId, objectGroup};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "HeapProfiler.getObjectByHeapObjectId",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module GetSamplingProfile = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.HeapProfiler.SamplingHeapProfile.t /* Return the sampling profile being collected. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.HeapProfiler.SamplingHeapProfile.t /* Return the sampling profile being collected. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeapProfiler.getSamplingProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StartSampling = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "samplingInterval"]
        samplingInterval: option(float) /* Average sample interval in bytes. Poisson distribution is used for the intervals. The
default value is 32768 bytes. */,
      };
      let make = (~samplingInterval=?, ()) => {
        {samplingInterval: samplingInterval};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "HeapProfiler.startSampling", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StartTrackingHeapObjects = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "trackAllocations"]
        trackAllocations: option(bool) /* No description provided */,
      };
      let make = (~trackAllocations=?, ()) => {
        {trackAllocations: trackAllocations};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "HeapProfiler.startTrackingHeapObjects",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StopSampling = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.HeapProfiler.SamplingHeapProfile.t /* Recorded sampling heap profile. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.HeapProfiler.SamplingHeapProfile.t /* Recorded sampling heap profile. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "HeapProfiler.stopSampling", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module StopTrackingHeapObjects = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "reportProgress"]
        reportProgress: option(bool), /* If true 'reportHeapSnapshotProgress' events will be generated while snapshot is being taken
when the tracking is stopped. */
        [@yojson.option] [@key "treatGlobalObjectsAsRoots"]
        treatGlobalObjectsAsRoots: option(bool) /* No description provided */,
      };
      let make = (~reportProgress=?, ~treatGlobalObjectsAsRoots=?, ()) => {
        {reportProgress, treatGlobalObjectsAsRoots};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "HeapProfiler.stopTrackingHeapObjects",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module TakeHeapSnapshot = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "reportProgress"]
        reportProgress: option(bool), /* If true 'reportHeapSnapshotProgress' events will be generated while snapshot is being taken. */
        [@yojson.option] [@key "treatGlobalObjectsAsRoots"]
        treatGlobalObjectsAsRoots: option(bool) /* If true, a raw snapshot without artifical roots will be generated */,
      };
      let make = (~reportProgress=?, ~treatGlobalObjectsAsRoots=?, ()) => {
        {reportProgress, treatGlobalObjectsAsRoots};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "HeapProfiler.takeHeapSnapshot", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Profiler = {
  /* No description provided */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Collect coverage data for the current isolate. The coverage data may be incomplete due to
     garbage collection. */
  module GetBestEffortCoverage = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptCoverage.t) /* Coverage data for the current isolate. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptCoverage.t) /* Coverage data for the current isolate. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.getBestEffortCoverage", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Changes CPU profiler sampling interval. Must be called before CPU profiles recording started. */
  module SetSamplingInterval = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "interval"]
        interval: float /* New sampling interval in microseconds. */,
      };
      let make = (~interval, ()) => {
        {interval: interval};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Profiler.setSamplingInterval", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Start = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.start", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable precise code coverage. Coverage data for JavaScript executed before enabling precise code
     coverage may be incomplete. Enabling prevents running optimized code and resets execution
     counters. */
  module StartPreciseCoverage = {
    module Response: {
      type result = {
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "callCount"]
        callCount: option(bool), /* Collect accurate call counts beyond simple 'covered' or 'not covered'. */
        [@yojson.option] [@key "detailed"]
        detailed: option(bool), /* Collect block-based coverage. */
        [@yojson.option] [@key "allowTriggeredUpdates"]
        allowTriggeredUpdates: option(bool) /* Allow the backend to send updates on its own initiative */,
      };
      let make = (~callCount=?, ~detailed=?, ~allowTriggeredUpdates=?, ()) => {
        {callCount, detailed, allowTriggeredUpdates};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Profiler.startPreciseCoverage", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable type profile. */
  module StartTypeProfile = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.startTypeProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module Stop = {
    module Response: {
      type result = {
        [@key "profile"]
        profile: Types.Profiler.Profile.t /* Recorded profile. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "profile"]
        profile: Types.Profiler.Profile.t /* Recorded profile. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.stop", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disable precise code coverage. Disabling releases unnecessary execution count records and allows
     executing optimized code. */
  module StopPreciseCoverage = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.stopPreciseCoverage", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disable type profile. Disabling releases type profile data collected so far. */
  module StopTypeProfile = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.stopTypeProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Collect coverage data for the current isolate, and resets execution counters. Precise code
     coverage needs to have started. */
  module TakePreciseCoverage = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptCoverage.t), /* Coverage data for the current isolate. */
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptCoverage.t), /* Coverage data for the current isolate. */
        [@key "timestamp"]
        timestamp: float /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.takePreciseCoverage", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Collect type profile. */
  module TakeTypeProfile = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptTypeProfile.t) /* Type profile for all scripts since startTypeProfile() was turned on. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Profiler.ScriptTypeProfile.t) /* Type profile for all scripts since startTypeProfile() was turned on. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.takeTypeProfile", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable counters collection. */
  module EnableCounters = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.enableCounters", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disable counters collection. */
  module DisableCounters = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.disableCounters", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve counters. */
  module GetCounters = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Profiler.CounterInfo.t) /* Collected counters information. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Profiler.CounterInfo.t) /* Collected counters information. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.getCounters", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enable run time call stats collection. */
  module EnableRuntimeCallStats = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.enableRuntimeCallStats", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disable run time call stats collection. */
  module DisableRuntimeCallStats = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.disableRuntimeCallStats", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Retrieve run time call stats. */
  module GetRuntimeCallStats = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Profiler.RuntimeCallCounterInfo.t) /* Collected runtime call counter information. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Profiler.RuntimeCallCounterInfo.t) /* Collected runtime call counter information. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Profiler.getRuntimeCallStats", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Runtime = {
  /* Add handler to promise with given promise object id. */
  module AwaitPromise = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Promise result. Will contain rejected value if promise was rejected. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if stack strace is available. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Promise result. Will contain rejected value if promise was rejected. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details if stack strace is available. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "promiseObjectId"]
        promiseObjectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the promise. */
        [@yojson.option] [@key "returnByValue"]
        returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool) /* Whether preview should be generated for the result. */,
      };
      let make = (~promiseObjectId, ~returnByValue=?, ~generatePreview=?, ()) => {
        {promiseObjectId, returnByValue, generatePreview};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.awaitPromise", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Calls function with given declaration on the given object. Object group of the result is
     inherited from the target object. */
  module CallFunctionOn = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Call result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Call result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "functionDeclaration"]
        functionDeclaration: string, /* Declaration of the function to call. */
        [@yojson.option] [@key "objectId"]
        objectId: option(Types.Runtime.RemoteObjectId.t), /* Identifier of the object to call function on. Either objectId or executionContextId should
be specified. */
        [@yojson.option] [@key "arguments"]
        arguments: option(list(Types.Runtime.CallArgument.t)), /* Call arguments. All call arguments must belong to the same JavaScript world as the target
object. */
        [@yojson.option] [@key "silent"]
        silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
        [@yojson.option] [@key "returnByValue"]
        returnByValue: option(bool), /* Whether the result is expected to be a JSON object which should be sent by value. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool), /* Whether preview should be generated for the result. */
        [@yojson.option] [@key "userGesture"]
        userGesture: option(bool), /* Whether execution should be treated as initiated by user in the UI. */
        [@yojson.option] [@key "awaitPromise"]
        awaitPromise: option(bool), /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies execution context which global object will be used to call function on. Either
executionContextId or objectId should be specified. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string) /* Symbolic group name that can be used to release multiple objects. If objectGroup is not
specified and objectId is, objectGroup will be inherited from object. */,
      };
      let make =
          (
            ~functionDeclaration,
            ~objectId=?,
            ~arguments=?,
            ~silent=?,
            ~returnByValue=?,
            ~generatePreview=?,
            ~userGesture=?,
            ~awaitPromise=?,
            ~executionContextId=?,
            ~objectGroup=?,
            (),
          ) => {
        {
          functionDeclaration,
          objectId,
          arguments,
          silent,
          returnByValue,
          generatePreview,
          userGesture,
          awaitPromise,
          executionContextId,
          objectGroup,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.callFunctionOn", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Compiles expression. */
  module CompileScript = {
    module Response: {
      type result = {
        [@yojson.option] [@key "scriptId"]
        scriptId: option(Types.Runtime.ScriptId.t), /* Id of the script. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@yojson.option] [@key "scriptId"]
        scriptId: option(Types.Runtime.ScriptId.t), /* Id of the script. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "expression"]
        expression: string, /* Expression to compile. */
        [@key "sourceURL"]
        sourceURL: string, /* Source url to be set for the script. */
        [@key "persistScript"]
        persistScript: bool, /* Specifies whether the compiled script should be persisted. */
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Specifies in which execution context to perform script run. If the parameter is omitted the
evaluation will be performed in the context of the inspected page. */,
      };
      let make =
          (~expression, ~sourceURL, ~persistScript, ~executionContextId=?, ()) => {
        {expression, sourceURL, persistScript, executionContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.compileScript", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Disables reporting of execution contexts creation. */
  module Disable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.disable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Discards collected exceptions and console API calls. */
  module DiscardConsoleEntries = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.discardConsoleEntries", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables reporting of execution contexts creation by means of `executionContextCreated` event.
     When the reporting gets enabled the event will be sent immediately for each existing execution
     context. */
  module Enable = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.enable", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Evaluates expression on global object. */
  module Evaluate = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Evaluation result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Evaluation result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "expression"]
        expression: string, /* Expression to evaluate. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
        [@yojson.option] [@key "includeCommandLineAPI"]
        includeCommandLineAPI: option(bool), /* Determines whether Command Line API should be available during the evaluation. */
        [@yojson.option] [@key "silent"]
        silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
        [@yojson.option] [@key "contextId"]
        contextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies in which execution context to perform evaluation. If the parameter is omitted the
evaluation will be performed in the context of the inspected page.
This is mutually exclusive with `uniqueContextId`, which offers an
alternative way to identify the execution context that is more reliable
in a multi-process environment. */
        [@yojson.option] [@key "returnByValue"]
        returnByValue: option(bool), /* Whether the result is expected to be a JSON object that should be sent by value. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool), /* Whether preview should be generated for the result. */
        [@yojson.option] [@key "userGesture"]
        userGesture: option(bool), /* Whether execution should be treated as initiated by user in the UI. */
        [@yojson.option] [@key "awaitPromise"]
        awaitPromise: option(bool), /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */
        [@yojson.option] [@key "throwOnSideEffect"]
        throwOnSideEffect: option(bool), /* Whether to throw an exception if side effect cannot be ruled out during evaluation.
This implies `disableBreaks` below. */
        [@yojson.option] [@key "timeout"]
        timeout: option(Types.Runtime.TimeDelta.t), /* Terminate execution after timing out (number of milliseconds). */
        [@yojson.option] [@key "disableBreaks"]
        disableBreaks: option(bool), /* Disable breakpoints during execution. */
        [@yojson.option] [@key "replMode"]
        replMode: option(bool), /* Setting this flag to true enables `let` re-declaration and top-level `await`.
Note that `let` variables can only be re-declared if they originate from
`replMode` themselves. */
        [@yojson.option] [@key "allowUnsafeEvalBlockedByCSP"]
        allowUnsafeEvalBlockedByCSP: option(bool), /* The Content Security Policy (CSP) for the target might block 'unsafe-eval'
which includes eval(), Function(), setTimeout() and setInterval()
when called with non-callable arguments. This flag bypasses CSP for this
evaluation and allows unsafe-eval. Defaults to true. */
        [@yojson.option] [@key "uniqueContextId"]
        uniqueContextId: option(string) /* An alternative way to specify the execution context to evaluate in.
Compared to contextId that may be reused accross processes, this is guaranteed to be
system-unique, so it can be used to prevent accidental evaluation of the expression
in context different than intended (e.g. as a result of navigation accross process
boundaries).
This is mutually exclusive with `contextId`. */,
      };
      let make =
          (
            ~expression,
            ~objectGroup=?,
            ~includeCommandLineAPI=?,
            ~silent=?,
            ~contextId=?,
            ~returnByValue=?,
            ~generatePreview=?,
            ~userGesture=?,
            ~awaitPromise=?,
            ~throwOnSideEffect=?,
            ~timeout=?,
            ~disableBreaks=?,
            ~replMode=?,
            ~allowUnsafeEvalBlockedByCSP=?,
            ~uniqueContextId=?,
            (),
          ) => {
        {
          expression,
          objectGroup,
          includeCommandLineAPI,
          silent,
          contextId,
          returnByValue,
          generatePreview,
          userGesture,
          awaitPromise,
          throwOnSideEffect,
          timeout,
          disableBreaks,
          replMode,
          allowUnsafeEvalBlockedByCSP,
          uniqueContextId,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.evaluate", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the isolate id. */
  module GetIsolateId = {
    module Response: {
      type result = {
        [@key "id"]
        id: string /* The isolate id. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "id"]
        id: string /* The isolate id. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.getIsolateId", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns the JavaScript heap usage.
     It is the total usage of the corresponding isolate not scoped to a particular Runtime. */
  module GetHeapUsage = {
    module Response: {
      type result = {
        [@key "usedSize"]
        usedSize: float, /* Used heap size in bytes. */
        [@key "totalSize"]
        totalSize: float /* Allocated heap size in bytes. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "usedSize"]
        usedSize: float, /* Used heap size in bytes. */
        [@key "totalSize"]
        totalSize: float /* Allocated heap size in bytes. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.getHeapUsage", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns properties of a given object. Object group of the result is inherited from the target
     object. */
  module GetProperties = {
    module Response: {
      type result = {
        [@key "result"]
        result: list(Types.Runtime.PropertyDescriptor.t), /* Object properties. */
        [@yojson.option] [@key "internalProperties"]
        internalProperties:
          option(list(Types.Runtime.InternalPropertyDescriptor.t)), /* Internal object properties (only of the element itself). */
        [@yojson.option] [@key "privateProperties"]
        privateProperties:
          option(list(Types.Runtime.PrivatePropertyDescriptor.t)), /* Object private properties. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: list(Types.Runtime.PropertyDescriptor.t), /* Object properties. */
        [@yojson.option] [@key "internalProperties"]
        internalProperties:
          option(list(Types.Runtime.InternalPropertyDescriptor.t)), /* Internal object properties (only of the element itself). */
        [@yojson.option] [@key "privateProperties"]
        privateProperties:
          option(list(Types.Runtime.PrivatePropertyDescriptor.t)), /* Object private properties. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the object to return properties for. */
        [@yojson.option] [@key "ownProperties"]
        ownProperties: option(bool), /* If true, returns properties belonging only to the element itself, not to its prototype
chain. */
        [@yojson.option] [@key "accessorPropertiesOnly"]
        accessorPropertiesOnly: option(bool), /* If true, returns accessor properties (with getter/setter) only; internal properties are not
returned either. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool) /* Whether preview should be generated for the results. */,
      };
      let make =
          (
            ~objectId,
            ~ownProperties=?,
            ~accessorPropertiesOnly=?,
            ~generatePreview=?,
            (),
          ) => {
        {objectId, ownProperties, accessorPropertiesOnly, generatePreview};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.getProperties", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Returns all let, const and class variables from global scope. */
  module GlobalLexicalScopeNames = {
    module Response: {
      type result = {
        [@key "names"]
        names: list(string) /* No description provided */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "names"]
        names: list(string) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t) /* Specifies in which execution context to lookup global scope variables. */,
      };
      let make = (~executionContextId=?, ()) => {
        {executionContextId: executionContextId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.globalLexicalScopeNames", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module QueryObjects = {
    module Response: {
      type result = {
        [@key "objects"]
        objects: Types.Runtime.RemoteObject.t /* Array with objects. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "objects"]
        objects: Types.Runtime.RemoteObject.t /* Array with objects. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "prototypeObjectId"]
        prototypeObjectId: Types.Runtime.RemoteObjectId.t, /* Identifier of the prototype to return objects for. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string) /* Symbolic group name that can be used to release the results. */,
      };
      let make = (~prototypeObjectId, ~objectGroup=?, ()) => {
        {prototypeObjectId, objectGroup};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.queryObjects", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Releases remote object with given id. */
  module ReleaseObject = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectId"]
        objectId: Types.Runtime.RemoteObjectId.t /* Identifier of the object to release. */,
      };
      let make = (~objectId, ()) => {
        {objectId: objectId};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.releaseObject", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Releases all remote objects that belong to a given group. */
  module ReleaseObjectGroup = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "objectGroup"]
        objectGroup: string /* Symbolic object group name. */,
      };
      let make = (~objectGroup, ()) => {
        {objectGroup: objectGroup};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.releaseObjectGroup", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Tells inspected instance to run if it was waiting for debugger to attach. */
  module RunIfWaitingForDebugger = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.runIfWaitingForDebugger", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Runs script with given id in a given context. */
  module RunScript = {
    module Response: {
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Run result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "result"]
        result: Types.Runtime.RemoteObject.t, /* Run result. */
        [@yojson.option] [@key "exceptionDetails"]
        exceptionDetails: option(Types.Runtime.ExceptionDetails.t) /* Exception details. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "scriptId"]
        scriptId: Types.Runtime.ScriptId.t, /* Id of the script to run. */
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t), /* Specifies in which execution context to perform script run. If the parameter is omitted the
evaluation will be performed in the context of the inspected page. */
        [@yojson.option] [@key "objectGroup"]
        objectGroup: option(string), /* Symbolic group name that can be used to release multiple objects. */
        [@yojson.option] [@key "silent"]
        silent: option(bool), /* In silent mode exceptions thrown during evaluation are not reported and do not pause
execution. Overrides `setPauseOnException` state. */
        [@yojson.option] [@key "includeCommandLineAPI"]
        includeCommandLineAPI: option(bool), /* Determines whether Command Line API should be available during the evaluation. */
        [@yojson.option] [@key "returnByValue"]
        returnByValue: option(bool), /* Whether the result is expected to be a JSON object which should be sent by value. */
        [@yojson.option] [@key "generatePreview"]
        generatePreview: option(bool), /* Whether preview should be generated for the result. */
        [@yojson.option] [@key "awaitPromise"]
        awaitPromise: option(bool) /* Whether execution should `await` for resulting value and return once awaited promise is
resolved. */,
      };
      let make =
          (
            ~scriptId,
            ~executionContextId=?,
            ~objectGroup=?,
            ~silent=?,
            ~includeCommandLineAPI=?,
            ~returnByValue=?,
            ~generatePreview=?,
            ~awaitPromise=?,
            (),
          ) => {
        {
          scriptId,
          executionContextId,
          objectGroup,
          silent,
          includeCommandLineAPI,
          returnByValue,
          generatePreview,
          awaitPromise,
        };
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.runScript", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Enables or disables async call stacks tracking. */
  module SetAsyncCallStackDepth = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "maxDepth"]
        maxDepth: float /* Maximum depth of async call stacks. Setting to `0` will effectively disable collecting async
call stacks (default). */,
      };
      let make = (~maxDepth, ()) => {
        {maxDepth: maxDepth};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.setAsyncCallStackDepth", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetCustomObjectFormatterEnabled = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "enabled"]
        enabled: bool /* No description provided */,
      };
      let make = (~enabled, ()) => {
        {enabled: enabled};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Runtime.setCustomObjectFormatterEnabled",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* No description provided */
  module SetMaxCallStackSizeToCapture = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "size"]
        size: float /* No description provided */,
      };
      let make = (~size, ()) => {
        {size: size};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {
          id,
          method: "Runtime.setMaxCallStackSizeToCapture",
          sessionId,
          params,
        }
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* Terminate current or next JavaScript execution.
     Will cancel the termination when the outer-most script execution ends. */
  module TerminateExecution = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Runtime.terminateExecution", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* If executionContextId is empty, adds binding with the given name on the
     global objects of all inspected contexts, including those created later,
     bindings survive reloads.
     Binding function takes exactly one argument, this argument should be string,
     in case of any other input, function throws an exception.
     Each binding function call produces Runtime.bindingCalled notification. */
  module AddBinding = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "name"]
        name: string, /* No description provided */
        [@yojson.option] [@key "executionContextId"]
        executionContextId: option(Types.Runtime.ExecutionContextId.t), /* If specified, the binding would only be exposed to the specified
execution context. If omitted and `executionContextName` is not set,
the binding is exposed to all execution contexts of the target.
This parameter is mutually exclusive with `executionContextName`. */
        [@yojson.option] [@key "executionContextName"]
        executionContextName: option(string) /* If specified, the binding is exposed to the executionContext with
matching name, even for contexts created after the binding is added.
See also `ExecutionContext.name` and `worldName` parameter to
`Page.addScriptToEvaluateOnNewDocument`.
This parameter is mutually exclusive with `executionContextId`. */,
      };
      let make = (~name, ~executionContextId=?, ~executionContextName=?, ()) => {
        {name, executionContextId, executionContextName};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.addBinding", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
  /* This method does not remove binding function from global object but
     unsubscribes current runtime agent from Runtime.bindingCalled notifications. */
  module RemoveBinding = {
    module Response: {
      type result = Types.assoc;

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = Types.assoc;

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Params = {
      [@deriving yojson]
      type t = {
        [@key "name"]
        name: string /* No description provided */,
      };
      let make = (~name, ()) => {
        {name: name};
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
        params: Params.t,
      };

      let make = (~sessionId=?, ~params, id) => {
        {id, method: "Runtime.removeBinding", sessionId, params}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
module Schema = {
  /* Returns supported domains. */
  module GetDomains = {
    module Response: {
      type result = {
        [@key "domains"]
        domains: list(Types.Schema.Domain.t) /* List of supported domains. */,
      };

      type t = {
        id: int,
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse: string => t;
    } = {
      [@deriving yojson]
      type result = {
        [@key "domains"]
        domains: list(Types.Schema.Domain.t) /* List of supported domains. */,
      };

      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        result,
      };

      let parse = response => {
        response |> Yojson.Safe.from_string |> t_of_yojson;
      };
    };

    module Request = {
      [@deriving yojson]
      type t = {
        id: int,
        [@yojson.option]
        sessionId: option(Types.Target.SessionID.t),
        method: string,
      };

      let make = (~sessionId=?, id) => {
        {id, method: "Schema.getDomains", sessionId}
        |> yojson_of_t
        |> Yojson.Safe.to_string;
      };
    };
  };
};
