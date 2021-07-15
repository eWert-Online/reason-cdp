[@deriving yojson]
type empty;

type assoc = list((string, string));
let assoc_of_yojson =
  fun
  | `Assoc(l) => {
      l |> List.map(((key, value)) => (key, string_of_yojson(value)));
    }
  | _ => [];

let yojson_of_assoc = assoc => {
  `Assoc(
    assoc |> List.map(((key, value)) => (key, yojson_of_string(value))),
  );
};

module rec Accessibility: {
  module Types: {
    module rec AXNodeId: {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueType: {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSourceType: {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueNativeSourceType: {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSource: {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueSourceType.t, /* What type of source this is. */
        [@yojson.option]
        value: option(AXValue.t), /* The value of this property source. */
        [@yojson.option]
        attribute: option(string), /* The name of the relevant attribute, if any. */
        [@yojson.option]
        attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
        [@yojson.option]
        superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
        [@yojson.option]
        nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
        [@yojson.option]
        nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
        [@yojson.option]
        invalid: option(bool), /* Whether the value for this property is invalid. */
        [@yojson.option]
        invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
      };
    }
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        [@yojson.option]
        idref: option(string), /* The IDRef value provided, if any. */
        [@yojson.option]
        text: option(string) /* The text alternative of this node in the current context. */,
      };
    }
    and AXProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: AXPropertyName.t, /* The name of this property. */
        value: AXValue.t /* The value of this property. */,
      };
    }
    and AXValue: {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueType.t, /* The type of this value. */
        [@yojson.option]
        value: option(string), /* The computed value of this property. */
        [@yojson.option]
        relatedNodes: option(array(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
        [@yojson.option]
        sources: option(array(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
      };
    }
    and AXPropertyName: {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    }
    and AXNode: {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {
        nodeId: AXNodeId.t, /* Unique identifier for this node. */
        ignored: bool, /* Whether this node is ignored for accessibility */
        [@yojson.option]
        ignoredReasons: option(array(AXProperty.t)), /* Collection of reasons why this node is hidden. */
        [@yojson.option]
        role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
        [@yojson.option]
        name: option(AXValue.t), /* The accessible name for this `Node`. */
        [@yojson.option]
        description: option(AXValue.t), /* The accessible description for this `Node`. */
        [@yojson.option]
        value: option(AXValue.t), /* The value for this `Node`. */
        [@yojson.option]
        properties: option(array(AXProperty.t)), /* All other properties */
        [@yojson.option]
        childIds: option(array(AXNodeId.t)), /* IDs for each of this node's child nodes. */
        [@yojson.option]
        backendDOMNodeId: option(DOM.Types.BackendNodeId.t) /* The backend ID for the associated DOM node, if any. */,
      };
    };
  };
} = {
  module Types: {
    module rec AXNodeId: {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueType: {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSourceType: {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueNativeSourceType: {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSource: {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueSourceType.t, /* What type of source this is. */
        [@yojson.option]
        value: option(AXValue.t), /* The value of this property source. */
        [@yojson.option]
        attribute: option(string), /* The name of the relevant attribute, if any. */
        [@yojson.option]
        attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
        [@yojson.option]
        superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
        [@yojson.option]
        nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
        [@yojson.option]
        nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
        [@yojson.option]
        invalid: option(bool), /* Whether the value for this property is invalid. */
        [@yojson.option]
        invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
      };
    }
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        [@yojson.option]
        idref: option(string), /* The IDRef value provided, if any. */
        [@yojson.option]
        text: option(string) /* The text alternative of this node in the current context. */,
      };
    }
    and AXProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: AXPropertyName.t, /* The name of this property. */
        value: AXValue.t /* The value of this property. */,
      };
    }
    and AXValue: {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueType.t, /* The type of this value. */
        [@yojson.option]
        value: option(string), /* The computed value of this property. */
        [@yojson.option]
        relatedNodes: option(array(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
        [@yojson.option]
        sources: option(array(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
      };
    }
    and AXPropertyName: {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    }
    and AXNode: {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {
        nodeId: AXNodeId.t, /* Unique identifier for this node. */
        ignored: bool, /* Whether this node is ignored for accessibility */
        [@yojson.option]
        ignoredReasons: option(array(AXProperty.t)), /* Collection of reasons why this node is hidden. */
        [@yojson.option]
        role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
        [@yojson.option]
        name: option(AXValue.t), /* The accessible name for this `Node`. */
        [@yojson.option]
        description: option(AXValue.t), /* The accessible description for this `Node`. */
        [@yojson.option]
        value: option(AXValue.t), /* The value for this `Node`. */
        [@yojson.option]
        properties: option(array(AXProperty.t)), /* All other properties */
        [@yojson.option]
        childIds: option(array(AXNodeId.t)), /* IDs for each of this node's child nodes. */
        [@yojson.option]
        backendDOMNodeId: option(DOM.Types.BackendNodeId.t) /* The backend ID for the associated DOM node, if any. */,
      };
    };
  } = {
    module rec AXNodeId: {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueType: {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSourceType: {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueNativeSourceType: {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSource: {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueSourceType.t, /* What type of source this is. */
        [@yojson.option]
        value: option(AXValue.t), /* The value of this property source. */
        [@yojson.option]
        attribute: option(string), /* The name of the relevant attribute, if any. */
        [@yojson.option]
        attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
        [@yojson.option]
        superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
        [@yojson.option]
        nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
        [@yojson.option]
        nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
        [@yojson.option]
        invalid: option(bool), /* Whether the value for this property is invalid. */
        [@yojson.option]
        invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
      };
    } = {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueSourceType.t, /* What type of source this is. */
        [@yojson.option]
        value: option(AXValue.t), /* The value of this property source. */
        [@yojson.option]
        attribute: option(string), /* The name of the relevant attribute, if any. */
        [@yojson.option]
        attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
        [@yojson.option]
        superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
        [@yojson.option]
        nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
        [@yojson.option]
        nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
        [@yojson.option]
        invalid: option(bool), /* Whether the value for this property is invalid. */
        [@yojson.option]
        invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
      };
    }
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        [@yojson.option]
        idref: option(string), /* The IDRef value provided, if any. */
        [@yojson.option]
        text: option(string) /* The text alternative of this node in the current context. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        [@yojson.option]
        idref: option(string), /* The IDRef value provided, if any. */
        [@yojson.option]
        text: option(string) /* The text alternative of this node in the current context. */,
      };
    }
    and AXProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: AXPropertyName.t, /* The name of this property. */
        value: AXValue.t /* The value of this property. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: AXPropertyName.t, /* The name of this property. */
        value: AXValue.t /* The value of this property. */,
      };
    }
    and AXValue: {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueType.t, /* The type of this value. */
        [@yojson.option]
        value: option(string), /* The computed value of this property. */
        [@yojson.option]
        relatedNodes: option(array(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
        [@yojson.option]
        sources: option(array(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
      };
    } = {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: AXValueType.t, /* The type of this value. */
        [@yojson.option]
        value: option(string), /* The computed value of this property. */
        [@yojson.option]
        relatedNodes: option(array(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
        [@yojson.option]
        sources: option(array(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
      };
    }
    and AXPropertyName: {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    }
    and AXNode: {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {
        nodeId: AXNodeId.t, /* Unique identifier for this node. */
        ignored: bool, /* Whether this node is ignored for accessibility */
        [@yojson.option]
        ignoredReasons: option(array(AXProperty.t)), /* Collection of reasons why this node is hidden. */
        [@yojson.option]
        role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
        [@yojson.option]
        name: option(AXValue.t), /* The accessible name for this `Node`. */
        [@yojson.option]
        description: option(AXValue.t), /* The accessible description for this `Node`. */
        [@yojson.option]
        value: option(AXValue.t), /* The value for this `Node`. */
        [@yojson.option]
        properties: option(array(AXProperty.t)), /* All other properties */
        [@yojson.option]
        childIds: option(array(AXNodeId.t)), /* IDs for each of this node's child nodes. */
        [@yojson.option]
        backendDOMNodeId: option(DOM.Types.BackendNodeId.t) /* The backend ID for the associated DOM node, if any. */,
      };
    } = {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {
        nodeId: AXNodeId.t, /* Unique identifier for this node. */
        ignored: bool, /* Whether this node is ignored for accessibility */
        [@yojson.option]
        ignoredReasons: option(array(AXProperty.t)), /* Collection of reasons why this node is hidden. */
        [@yojson.option]
        role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
        [@yojson.option]
        name: option(AXValue.t), /* The accessible name for this `Node`. */
        [@yojson.option]
        description: option(AXValue.t), /* The accessible description for this `Node`. */
        [@yojson.option]
        value: option(AXValue.t), /* The value for this `Node`. */
        [@yojson.option]
        properties: option(array(AXProperty.t)), /* All other properties */
        [@yojson.option]
        childIds: option(array(AXNodeId.t)), /* IDs for each of this node's child nodes. */
        [@yojson.option]
        backendDOMNodeId: option(DOM.Types.BackendNodeId.t) /* The backend ID for the associated DOM node, if any. */,
      };
    };
  };
}
and Animation: {
  module Types: {
    module rec Animation: {
      /* Animation instance. */
      [@deriving yojson]
      type t = {
        id: string, /* `Animation`'s id. */
        name: string, /* `Animation`'s name. */
        pausedState: bool, /* `Animation`'s internal paused state. */
        playState: string, /* `Animation`'s play state. */
        playbackRate: float, /* `Animation`'s playback rate. */
        startTime: float, /* `Animation`'s start time. */
        currentTime: float, /* `Animation`'s current time. */
        [@key "type"]
        type_: string, /* Animation type of `Animation`. */
        [@yojson.option]
        source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
        [@yojson.option]
        cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
      };
    }
    and AnimationEffect: {
      /* AnimationEffect instance */
      [@deriving yojson]
      type t = {
        delay: float, /* `AnimationEffect`'s delay. */
        endDelay: float, /* `AnimationEffect`'s end delay. */
        iterationStart: float, /* `AnimationEffect`'s iteration start. */
        iterations: float, /* `AnimationEffect`'s iterations. */
        duration: float, /* `AnimationEffect`'s iteration duration. */
        direction: string, /* `AnimationEffect`'s playback direction. */
        fill: string, /* `AnimationEffect`'s fill mode. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* `AnimationEffect`'s target node. */
        [@yojson.option]
        keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    }
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        name: option(string), /* CSS keyframed animation's name. */
        keyframes: array(KeyframeStyle.t) /* List of animation keyframes. */,
      };
    }
    and KeyframeStyle: {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {
        offset: string, /* Keyframe's time offset. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    };
  };

  module Events: {
    /* Event for when an animation has been cancelled. */
    module AnimationCanceled: {
      [@deriving yojson]
      type result = {
        id: string /* Id of the animation that was cancelled. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Event for each animation that has been created. */
    module AnimationCreated: {
      [@deriving yojson]
      type result = {id: string /* Id of the animation that was created. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Event for animation that has been started. */
    module AnimationStarted: {
      [@deriving yojson]
      type result = {
        animation: Types.Animation.t /* Animation that was started. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec Animation: {
      /* Animation instance. */
      [@deriving yojson]
      type t = {
        id: string, /* `Animation`'s id. */
        name: string, /* `Animation`'s name. */
        pausedState: bool, /* `Animation`'s internal paused state. */
        playState: string, /* `Animation`'s play state. */
        playbackRate: float, /* `Animation`'s playback rate. */
        startTime: float, /* `Animation`'s start time. */
        currentTime: float, /* `Animation`'s current time. */
        [@key "type"]
        type_: string, /* Animation type of `Animation`. */
        [@yojson.option]
        source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
        [@yojson.option]
        cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
      };
    }
    and AnimationEffect: {
      /* AnimationEffect instance */
      [@deriving yojson]
      type t = {
        delay: float, /* `AnimationEffect`'s delay. */
        endDelay: float, /* `AnimationEffect`'s end delay. */
        iterationStart: float, /* `AnimationEffect`'s iteration start. */
        iterations: float, /* `AnimationEffect`'s iterations. */
        duration: float, /* `AnimationEffect`'s iteration duration. */
        direction: string, /* `AnimationEffect`'s playback direction. */
        fill: string, /* `AnimationEffect`'s fill mode. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* `AnimationEffect`'s target node. */
        [@yojson.option]
        keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    }
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        name: option(string), /* CSS keyframed animation's name. */
        keyframes: array(KeyframeStyle.t) /* List of animation keyframes. */,
      };
    }
    and KeyframeStyle: {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {
        offset: string, /* Keyframe's time offset. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    };
  } = {
    module rec Animation: {
      /* Animation instance. */
      [@deriving yojson]
      type t = {
        id: string, /* `Animation`'s id. */
        name: string, /* `Animation`'s name. */
        pausedState: bool, /* `Animation`'s internal paused state. */
        playState: string, /* `Animation`'s play state. */
        playbackRate: float, /* `Animation`'s playback rate. */
        startTime: float, /* `Animation`'s start time. */
        currentTime: float, /* `Animation`'s current time. */
        [@key "type"]
        type_: string, /* Animation type of `Animation`. */
        [@yojson.option]
        source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
        [@yojson.option]
        cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
      };
    } = {
      /* Animation instance. */
      [@deriving yojson]
      type t = {
        id: string, /* `Animation`'s id. */
        name: string, /* `Animation`'s name. */
        pausedState: bool, /* `Animation`'s internal paused state. */
        playState: string, /* `Animation`'s play state. */
        playbackRate: float, /* `Animation`'s playback rate. */
        startTime: float, /* `Animation`'s start time. */
        currentTime: float, /* `Animation`'s current time. */
        [@key "type"]
        type_: string, /* Animation type of `Animation`. */
        [@yojson.option]
        source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
        [@yojson.option]
        cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
      };
    }
    and AnimationEffect: {
      /* AnimationEffect instance */
      [@deriving yojson]
      type t = {
        delay: float, /* `AnimationEffect`'s delay. */
        endDelay: float, /* `AnimationEffect`'s end delay. */
        iterationStart: float, /* `AnimationEffect`'s iteration start. */
        iterations: float, /* `AnimationEffect`'s iterations. */
        duration: float, /* `AnimationEffect`'s iteration duration. */
        direction: string, /* `AnimationEffect`'s playback direction. */
        fill: string, /* `AnimationEffect`'s fill mode. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* `AnimationEffect`'s target node. */
        [@yojson.option]
        keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    } = {
      /* AnimationEffect instance */
      [@deriving yojson]
      type t = {
        delay: float, /* `AnimationEffect`'s delay. */
        endDelay: float, /* `AnimationEffect`'s end delay. */
        iterationStart: float, /* `AnimationEffect`'s iteration start. */
        iterations: float, /* `AnimationEffect`'s iterations. */
        duration: float, /* `AnimationEffect`'s iteration duration. */
        direction: string, /* `AnimationEffect`'s playback direction. */
        fill: string, /* `AnimationEffect`'s fill mode. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* `AnimationEffect`'s target node. */
        [@yojson.option]
        keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    }
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        name: option(string), /* CSS keyframed animation's name. */
        keyframes: array(KeyframeStyle.t) /* List of animation keyframes. */,
      };
    } = {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        name: option(string), /* CSS keyframed animation's name. */
        keyframes: array(KeyframeStyle.t) /* List of animation keyframes. */,
      };
    }
    and KeyframeStyle: {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {
        offset: string, /* Keyframe's time offset. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    } = {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {
        offset: string, /* Keyframe's time offset. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    };
  };

  module Events = {
    /* Event for when an animation has been cancelled. */
    module AnimationCanceled = {
      [@deriving yojson]
      type result = {
        id: string /* Id of the animation that was cancelled. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Event for each animation that has been created. */
    module AnimationCreated = {
      [@deriving yojson]
      type result = {id: string /* Id of the animation that was created. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Event for animation that has been started. */
    module AnimationStarted = {
      [@deriving yojson]
      type result = {
        animation: Types.Animation.t /* Animation that was started. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and ApplicationCache: {
  module Types: {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: float, /* Resource size. */
        [@key "type"]
        type_: string /* Resource type. */,
      };
    }
    and ApplicationCache: {
      /* Detailed application cache information. */
      [@deriving yojson]
      type t = {
        manifestURL: string, /* Manifest URL. */
        size: float, /* Application cache size. */
        creationTime: float, /* Application cache creation time. */
        updateTime: float, /* Application cache update time. */
        resources: array(ApplicationCacheResource.t) /* Application cache resources. */,
      };
    }
    and FrameWithManifest: {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Frame identifier. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Application cache status. */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module ApplicationCacheStatusUpdated: {
      [@deriving yojson]
      type result = {
        frameId: Page.Types.FrameId.t, /* Identifier of the frame containing document whose application cache updated status. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Updated application cache status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module NetworkStateUpdated: {
      [@deriving yojson]
      type result = {isNowOnline: bool /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: float, /* Resource size. */
        [@key "type"]
        type_: string /* Resource type. */,
      };
    }
    and ApplicationCache: {
      /* Detailed application cache information. */
      [@deriving yojson]
      type t = {
        manifestURL: string, /* Manifest URL. */
        size: float, /* Application cache size. */
        creationTime: float, /* Application cache creation time. */
        updateTime: float, /* Application cache update time. */
        resources: array(ApplicationCacheResource.t) /* Application cache resources. */,
      };
    }
    and FrameWithManifest: {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Frame identifier. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Application cache status. */,
      };
    };
  } = {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: float, /* Resource size. */
        [@key "type"]
        type_: string /* Resource type. */,
      };
    } = {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: float, /* Resource size. */
        [@key "type"]
        type_: string /* Resource type. */,
      };
    }
    and ApplicationCache: {
      /* Detailed application cache information. */
      [@deriving yojson]
      type t = {
        manifestURL: string, /* Manifest URL. */
        size: float, /* Application cache size. */
        creationTime: float, /* Application cache creation time. */
        updateTime: float, /* Application cache update time. */
        resources: array(ApplicationCacheResource.t) /* Application cache resources. */,
      };
    } = {
      /* Detailed application cache information. */
      [@deriving yojson]
      type t = {
        manifestURL: string, /* Manifest URL. */
        size: float, /* Application cache size. */
        creationTime: float, /* Application cache creation time. */
        updateTime: float, /* Application cache update time. */
        resources: array(ApplicationCacheResource.t) /* Application cache resources. */,
      };
    }
    and FrameWithManifest: {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Frame identifier. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Application cache status. */,
      };
    } = {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Frame identifier. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Application cache status. */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module ApplicationCacheStatusUpdated = {
      [@deriving yojson]
      type result = {
        frameId: Page.Types.FrameId.t, /* Identifier of the frame containing document whose application cache updated status. */
        manifestURL: string, /* Manifest URL. */
        status: float /* Updated application cache status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module NetworkStateUpdated = {
      [@deriving yojson]
      type result = {isNowOnline: bool /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Audits: {
  module Types: {
    module rec AffectedCookie: {
      /* Information about a cookie that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        name: string, /* The following three properties uniquely identify a cookie */
        path: string, /* No description provided */
        domain: string /* No description provided */,
      };
    }
    and AffectedRequest: {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        requestId: Network.Types.RequestId.t, /* The unique request id. */
        [@yojson.option]
        url: option(string) /* No description provided */,
      };
    }
    and AffectedFrame: {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {frameId: Page.Types.FrameId.t /* No description provided */};
    }
    and SameSiteCookieExclusionReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieWarningReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieOperation: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieIssueDetails: {
      /* This information is currently necessary, as the front-end has a difficult
         time finding a specific cookie. With this, we can convey specific error
         information without the cookie. */
      [@deriving yojson]
      type t = {
        cookie: AffectedCookie.t, /* No description provided */
        cookieWarningReasons: array(SameSiteCookieWarningReason.t), /* No description provided */
        cookieExclusionReasons: array(SameSiteCookieExclusionReason.t), /* No description provided */
        operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
        [@yojson.option]
        siteForCookies: option(string), /* No description provided */
        [@yojson.option]
        cookieUrl: option(string), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t) /* No description provided */,
      };
    }
    and MixedContentResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentResourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        [@yojson.option]
        request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        [@yojson.option]
        frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
      };
    }
    and BlockedByResponseReason: {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedByResponseIssueDetails: {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        parentFrame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        blockedFrame: option(AffectedFrame.t), /* No description provided */
        reason: BlockedByResponseReason.t /* No description provided */,
      };
    }
    and HeavyAdResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
        reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
        frame: AffectedFrame.t /* The frame that was blocked. */,
      };
    }
    and ContentSecurityPolicyViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SourceCodeLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        scriptId: option(Runtime.Types.ScriptId.t), /* No description provided */
        url: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        blockedURL: option(string), /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        [@yojson.option]
        frameAncestor: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and SharedArrayBufferIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SharedArrayBufferIssueDetails: {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        isWarning: bool, /* No description provided */
        [@key "type"]
        type_: SharedArrayBufferIssueType.t /* No description provided */,
      };
    }
    and TwaQualityEnforcementViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TrustedWebActivityIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        url: string, /* The url that triggers the violation. */
        violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        [@yojson.option]
        signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
      };
    }
    and LowTextContrastIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        violatingNodeSelector: string, /* No description provided */
        contrastRatio: float, /* No description provided */
        thresholdAA: float, /* No description provided */
        thresholdAAA: float, /* No description provided */
        fontSize: string, /* No description provided */
        fontWeight: string /* No description provided */,
      };
    }
    and CorsIssueDetails: {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {
        corsErrorStatus: Network.Types.CorsErrorStatus.t, /* No description provided */
        isWarning: bool, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        location: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        initiatorOrigin: option(string), /* No description provided */
        [@yojson.option]
        resourceIPAddressSpace: option(Network.Types.IPAddressSpace.t), /* No description provided */
        [@yojson.option]
        clientSecurityState: option(Network.Types.ClientSecurityState.t) /* No description provided */,
      };
    }
    and AttributionReportingIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AttributionReportingIssueDetails: {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {
        violationType: AttributionReportingIssueType.t, /* No description provided */
        [@yojson.option]
        frame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t), /* No description provided */
        [@yojson.option]
        invalidParameter: option(string) /* No description provided */,
      };
    }
    and QuirksModeIssueDetails: {
      /* Details for issues about documents in Quirks Mode
         or Limited Quirks Mode that affects page layouting. */
      [@deriving yojson]
      type t = {
        isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
        documentNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        url: string, /* No description provided */
        frameId: Page.Types.FrameId.t, /* No description provided */
        loaderId: Network.Types.LoaderId.t /* No description provided */,
      };
    }
    and InspectorIssueCode: {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    }
    and InspectorIssueDetails: {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
        [@yojson.option]
        mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
        [@yojson.option]
        blockedByResponseIssueDetails:
          option(BlockedByResponseIssueDetails.t), /* No description provided */
        [@yojson.option]
        heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
        [@yojson.option]
        contentSecurityPolicyIssueDetails:
          option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
        [@yojson.option]
        sharedArrayBufferIssueDetails:
          option(SharedArrayBufferIssueDetails.t), /* No description provided */
        [@yojson.option]
        twaQualityEnforcementDetails:
          option(TrustedWebActivityIssueDetails.t), /* No description provided */
        [@yojson.option]
        lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
        [@yojson.option]
        corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
        [@yojson.option]
        attributionReportingIssueDetails:
          option(AttributionReportingIssueDetails.t), /* No description provided */
        [@yojson.option]
        quirksModeIssueDetails: option(QuirksModeIssueDetails.t) /* No description provided */,
      };
    }
    and InspectorIssue: {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {
        code: InspectorIssueCode.t, /* No description provided */
        details: InspectorIssueDetails.t /* No description provided */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module IssueAdded: {
      [@deriving yojson]
      type result = {
        issue: Types.InspectorIssue.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec AffectedCookie: {
      /* Information about a cookie that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        name: string, /* The following three properties uniquely identify a cookie */
        path: string, /* No description provided */
        domain: string /* No description provided */,
      };
    }
    and AffectedRequest: {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        requestId: Network.Types.RequestId.t, /* The unique request id. */
        [@yojson.option]
        url: option(string) /* No description provided */,
      };
    }
    and AffectedFrame: {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {frameId: Page.Types.FrameId.t /* No description provided */};
    }
    and SameSiteCookieExclusionReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieWarningReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieOperation: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieIssueDetails: {
      /* This information is currently necessary, as the front-end has a difficult
         time finding a specific cookie. With this, we can convey specific error
         information without the cookie. */
      [@deriving yojson]
      type t = {
        cookie: AffectedCookie.t, /* No description provided */
        cookieWarningReasons: array(SameSiteCookieWarningReason.t), /* No description provided */
        cookieExclusionReasons: array(SameSiteCookieExclusionReason.t), /* No description provided */
        operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
        [@yojson.option]
        siteForCookies: option(string), /* No description provided */
        [@yojson.option]
        cookieUrl: option(string), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t) /* No description provided */,
      };
    }
    and MixedContentResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentResourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        [@yojson.option]
        request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        [@yojson.option]
        frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
      };
    }
    and BlockedByResponseReason: {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedByResponseIssueDetails: {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        parentFrame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        blockedFrame: option(AffectedFrame.t), /* No description provided */
        reason: BlockedByResponseReason.t /* No description provided */,
      };
    }
    and HeavyAdResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
        reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
        frame: AffectedFrame.t /* The frame that was blocked. */,
      };
    }
    and ContentSecurityPolicyViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SourceCodeLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        scriptId: option(Runtime.Types.ScriptId.t), /* No description provided */
        url: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        blockedURL: option(string), /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        [@yojson.option]
        frameAncestor: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and SharedArrayBufferIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SharedArrayBufferIssueDetails: {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        isWarning: bool, /* No description provided */
        [@key "type"]
        type_: SharedArrayBufferIssueType.t /* No description provided */,
      };
    }
    and TwaQualityEnforcementViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TrustedWebActivityIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        url: string, /* The url that triggers the violation. */
        violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        [@yojson.option]
        signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
      };
    }
    and LowTextContrastIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        violatingNodeSelector: string, /* No description provided */
        contrastRatio: float, /* No description provided */
        thresholdAA: float, /* No description provided */
        thresholdAAA: float, /* No description provided */
        fontSize: string, /* No description provided */
        fontWeight: string /* No description provided */,
      };
    }
    and CorsIssueDetails: {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {
        corsErrorStatus: Network.Types.CorsErrorStatus.t, /* No description provided */
        isWarning: bool, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        location: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        initiatorOrigin: option(string), /* No description provided */
        [@yojson.option]
        resourceIPAddressSpace: option(Network.Types.IPAddressSpace.t), /* No description provided */
        [@yojson.option]
        clientSecurityState: option(Network.Types.ClientSecurityState.t) /* No description provided */,
      };
    }
    and AttributionReportingIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AttributionReportingIssueDetails: {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {
        violationType: AttributionReportingIssueType.t, /* No description provided */
        [@yojson.option]
        frame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t), /* No description provided */
        [@yojson.option]
        invalidParameter: option(string) /* No description provided */,
      };
    }
    and QuirksModeIssueDetails: {
      /* Details for issues about documents in Quirks Mode
         or Limited Quirks Mode that affects page layouting. */
      [@deriving yojson]
      type t = {
        isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
        documentNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        url: string, /* No description provided */
        frameId: Page.Types.FrameId.t, /* No description provided */
        loaderId: Network.Types.LoaderId.t /* No description provided */,
      };
    }
    and InspectorIssueCode: {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    }
    and InspectorIssueDetails: {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
        [@yojson.option]
        mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
        [@yojson.option]
        blockedByResponseIssueDetails:
          option(BlockedByResponseIssueDetails.t), /* No description provided */
        [@yojson.option]
        heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
        [@yojson.option]
        contentSecurityPolicyIssueDetails:
          option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
        [@yojson.option]
        sharedArrayBufferIssueDetails:
          option(SharedArrayBufferIssueDetails.t), /* No description provided */
        [@yojson.option]
        twaQualityEnforcementDetails:
          option(TrustedWebActivityIssueDetails.t), /* No description provided */
        [@yojson.option]
        lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
        [@yojson.option]
        corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
        [@yojson.option]
        attributionReportingIssueDetails:
          option(AttributionReportingIssueDetails.t), /* No description provided */
        [@yojson.option]
        quirksModeIssueDetails: option(QuirksModeIssueDetails.t) /* No description provided */,
      };
    }
    and InspectorIssue: {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {
        code: InspectorIssueCode.t, /* No description provided */
        details: InspectorIssueDetails.t /* No description provided */,
      };
    };
  } = {
    module rec AffectedCookie: {
      /* Information about a cookie that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        name: string, /* The following three properties uniquely identify a cookie */
        path: string, /* No description provided */
        domain: string /* No description provided */,
      };
    } = {
      /* Information about a cookie that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        name: string, /* The following three properties uniquely identify a cookie */
        path: string, /* No description provided */
        domain: string /* No description provided */,
      };
    }
    and AffectedRequest: {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        requestId: Network.Types.RequestId.t, /* The unique request id. */
        [@yojson.option]
        url: option(string) /* No description provided */,
      };
    } = {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        requestId: Network.Types.RequestId.t, /* The unique request id. */
        [@yojson.option]
        url: option(string) /* No description provided */,
      };
    }
    and AffectedFrame: {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {frameId: Page.Types.FrameId.t /* No description provided */};
    } = {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {frameId: Page.Types.FrameId.t /* No description provided */};
    }
    and SameSiteCookieExclusionReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieWarningReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieOperation: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieIssueDetails: {
      /* This information is currently necessary, as the front-end has a difficult
         time finding a specific cookie. With this, we can convey specific error
         information without the cookie. */
      [@deriving yojson]
      type t = {
        cookie: AffectedCookie.t, /* No description provided */
        cookieWarningReasons: array(SameSiteCookieWarningReason.t), /* No description provided */
        cookieExclusionReasons: array(SameSiteCookieExclusionReason.t), /* No description provided */
        operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
        [@yojson.option]
        siteForCookies: option(string), /* No description provided */
        [@yojson.option]
        cookieUrl: option(string), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t) /* No description provided */,
      };
    } = {
      /* This information is currently necessary, as the front-end has a difficult
         time finding a specific cookie. With this, we can convey specific error
         information without the cookie. */
      [@deriving yojson]
      type t = {
        cookie: AffectedCookie.t, /* No description provided */
        cookieWarningReasons: array(SameSiteCookieWarningReason.t), /* No description provided */
        cookieExclusionReasons: array(SameSiteCookieExclusionReason.t), /* No description provided */
        operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
        [@yojson.option]
        siteForCookies: option(string), /* No description provided */
        [@yojson.option]
        cookieUrl: option(string), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t) /* No description provided */,
      };
    }
    and MixedContentResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentResourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        [@yojson.option]
        request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        [@yojson.option]
        frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        [@yojson.option]
        request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        [@yojson.option]
        frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
      };
    }
    and BlockedByResponseReason: {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedByResponseIssueDetails: {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        parentFrame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        blockedFrame: option(AffectedFrame.t), /* No description provided */
        reason: BlockedByResponseReason.t /* No description provided */,
      };
    } = {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        parentFrame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        blockedFrame: option(AffectedFrame.t), /* No description provided */
        reason: BlockedByResponseReason.t /* No description provided */,
      };
    }
    and HeavyAdResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
        reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
        frame: AffectedFrame.t /* The frame that was blocked. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
        reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
        frame: AffectedFrame.t /* The frame that was blocked. */,
      };
    }
    and ContentSecurityPolicyViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SourceCodeLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        scriptId: option(Runtime.Types.ScriptId.t), /* No description provided */
        url: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        scriptId: option(Runtime.Types.ScriptId.t), /* No description provided */
        url: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        blockedURL: option(string), /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        [@yojson.option]
        frameAncestor: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        blockedURL: option(string), /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        [@yojson.option]
        frameAncestor: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and SharedArrayBufferIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SharedArrayBufferIssueDetails: {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        isWarning: bool, /* No description provided */
        [@key "type"]
        type_: SharedArrayBufferIssueType.t /* No description provided */,
      };
    } = {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        isWarning: bool, /* No description provided */
        [@key "type"]
        type_: SharedArrayBufferIssueType.t /* No description provided */,
      };
    }
    and TwaQualityEnforcementViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TrustedWebActivityIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        url: string, /* The url that triggers the violation. */
        violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        [@yojson.option]
        signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        url: string, /* The url that triggers the violation. */
        violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        [@yojson.option]
        signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
      };
    }
    and LowTextContrastIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        violatingNodeSelector: string, /* No description provided */
        contrastRatio: float, /* No description provided */
        thresholdAA: float, /* No description provided */
        thresholdAAA: float, /* No description provided */
        fontSize: string, /* No description provided */
        fontWeight: string /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        violatingNodeSelector: string, /* No description provided */
        contrastRatio: float, /* No description provided */
        thresholdAA: float, /* No description provided */
        thresholdAAA: float, /* No description provided */
        fontSize: string, /* No description provided */
        fontWeight: string /* No description provided */,
      };
    }
    and CorsIssueDetails: {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {
        corsErrorStatus: Network.Types.CorsErrorStatus.t, /* No description provided */
        isWarning: bool, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        location: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        initiatorOrigin: option(string), /* No description provided */
        [@yojson.option]
        resourceIPAddressSpace: option(Network.Types.IPAddressSpace.t), /* No description provided */
        [@yojson.option]
        clientSecurityState: option(Network.Types.ClientSecurityState.t) /* No description provided */,
      };
    } = {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {
        corsErrorStatus: Network.Types.CorsErrorStatus.t, /* No description provided */
        isWarning: bool, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        [@yojson.option]
        location: option(SourceCodeLocation.t), /* No description provided */
        [@yojson.option]
        initiatorOrigin: option(string), /* No description provided */
        [@yojson.option]
        resourceIPAddressSpace: option(Network.Types.IPAddressSpace.t), /* No description provided */
        [@yojson.option]
        clientSecurityState: option(Network.Types.ClientSecurityState.t) /* No description provided */,
      };
    }
    and AttributionReportingIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AttributionReportingIssueDetails: {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {
        violationType: AttributionReportingIssueType.t, /* No description provided */
        [@yojson.option]
        frame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t), /* No description provided */
        [@yojson.option]
        invalidParameter: option(string) /* No description provided */,
      };
    } = {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {
        violationType: AttributionReportingIssueType.t, /* No description provided */
        [@yojson.option]
        frame: option(AffectedFrame.t), /* No description provided */
        [@yojson.option]
        request: option(AffectedRequest.t), /* No description provided */
        [@yojson.option]
        violatingNodeId: option(DOM.Types.BackendNodeId.t), /* No description provided */
        [@yojson.option]
        invalidParameter: option(string) /* No description provided */,
      };
    }
    and QuirksModeIssueDetails: {
      /* Details for issues about documents in Quirks Mode
         or Limited Quirks Mode that affects page layouting. */
      [@deriving yojson]
      type t = {
        isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
        documentNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        url: string, /* No description provided */
        frameId: Page.Types.FrameId.t, /* No description provided */
        loaderId: Network.Types.LoaderId.t /* No description provided */,
      };
    } = {
      /* Details for issues about documents in Quirks Mode
         or Limited Quirks Mode that affects page layouting. */
      [@deriving yojson]
      type t = {
        isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
        documentNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        url: string, /* No description provided */
        frameId: Page.Types.FrameId.t, /* No description provided */
        loaderId: Network.Types.LoaderId.t /* No description provided */,
      };
    }
    and InspectorIssueCode: {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    } = {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    }
    and InspectorIssueDetails: {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
        [@yojson.option]
        mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
        [@yojson.option]
        blockedByResponseIssueDetails:
          option(BlockedByResponseIssueDetails.t), /* No description provided */
        [@yojson.option]
        heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
        [@yojson.option]
        contentSecurityPolicyIssueDetails:
          option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
        [@yojson.option]
        sharedArrayBufferIssueDetails:
          option(SharedArrayBufferIssueDetails.t), /* No description provided */
        [@yojson.option]
        twaQualityEnforcementDetails:
          option(TrustedWebActivityIssueDetails.t), /* No description provided */
        [@yojson.option]
        lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
        [@yojson.option]
        corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
        [@yojson.option]
        attributionReportingIssueDetails:
          option(AttributionReportingIssueDetails.t), /* No description provided */
        [@yojson.option]
        quirksModeIssueDetails: option(QuirksModeIssueDetails.t) /* No description provided */,
      };
    } = {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
        [@yojson.option]
        mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
        [@yojson.option]
        blockedByResponseIssueDetails:
          option(BlockedByResponseIssueDetails.t), /* No description provided */
        [@yojson.option]
        heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
        [@yojson.option]
        contentSecurityPolicyIssueDetails:
          option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
        [@yojson.option]
        sharedArrayBufferIssueDetails:
          option(SharedArrayBufferIssueDetails.t), /* No description provided */
        [@yojson.option]
        twaQualityEnforcementDetails:
          option(TrustedWebActivityIssueDetails.t), /* No description provided */
        [@yojson.option]
        lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
        [@yojson.option]
        corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
        [@yojson.option]
        attributionReportingIssueDetails:
          option(AttributionReportingIssueDetails.t), /* No description provided */
        [@yojson.option]
        quirksModeIssueDetails: option(QuirksModeIssueDetails.t) /* No description provided */,
      };
    }
    and InspectorIssue: {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {
        code: InspectorIssueCode.t, /* No description provided */
        details: InspectorIssueDetails.t /* No description provided */,
      };
    } = {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {
        code: InspectorIssueCode.t, /* No description provided */
        details: InspectorIssueDetails.t /* No description provided */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module IssueAdded = {
      [@deriving yojson]
      type result = {
        issue: Types.InspectorIssue.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and BackgroundService: {
  module Types: {
    module rec ServiceName: {
      /* The Background Service that will be associated with the commands/events.
         Every Background Service operates independently, but they share the same
         API. */
      [@deriving yojson]
      type t = string;
    }
    and EventMetadata: {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {
        key: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and BackgroundServiceEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        timestamp: Network.Types.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
        origin: string, /* The origin this event belongs to. */
        serviceWorkerRegistrationId: ServiceWorker.Types.RegistrationID.t, /* The Service Worker ID that initiated the event. */
        service: ServiceName.t, /* The Background Service this event belongs to. */
        eventName: string, /* A description of the event. */
        instanceId: string, /* An identifier that groups related events together. */
        eventMetadata: array(EventMetadata.t) /* A list of event-specific information. */,
      };
    };
  };

  module Events: {
    /* Called when the recording state for the service has been updated. */
    module RecordingStateChanged: {
      [@deriving yojson]
      type result = {
        isRecording: bool, /* No description provided */
        service: Types.ServiceName.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called with all existing backgroundServiceEvents when enabled, and all new
       events afterwards if enabled and recording. */
    module BackgroundServiceEventReceived: {
      [@deriving yojson]
      type result = {
        backgroundServiceEvent: Types.BackgroundServiceEvent.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ServiceName: {
      /* The Background Service that will be associated with the commands/events.
         Every Background Service operates independently, but they share the same
         API. */
      [@deriving yojson]
      type t = string;
    }
    and EventMetadata: {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {
        key: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and BackgroundServiceEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        timestamp: Network.Types.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
        origin: string, /* The origin this event belongs to. */
        serviceWorkerRegistrationId: ServiceWorker.Types.RegistrationID.t, /* The Service Worker ID that initiated the event. */
        service: ServiceName.t, /* The Background Service this event belongs to. */
        eventName: string, /* A description of the event. */
        instanceId: string, /* An identifier that groups related events together. */
        eventMetadata: array(EventMetadata.t) /* A list of event-specific information. */,
      };
    };
  } = {
    module rec ServiceName: {
      /* The Background Service that will be associated with the commands/events.
         Every Background Service operates independently, but they share the same
         API. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The Background Service that will be associated with the commands/events.
         Every Background Service operates independently, but they share the same
         API. */
      [@deriving yojson]
      type t = string;
    }
    and EventMetadata: {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {
        key: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {
        key: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and BackgroundServiceEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        timestamp: Network.Types.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
        origin: string, /* The origin this event belongs to. */
        serviceWorkerRegistrationId: ServiceWorker.Types.RegistrationID.t, /* The Service Worker ID that initiated the event. */
        service: ServiceName.t, /* The Background Service this event belongs to. */
        eventName: string, /* A description of the event. */
        instanceId: string, /* An identifier that groups related events together. */
        eventMetadata: array(EventMetadata.t) /* A list of event-specific information. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        timestamp: Network.Types.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
        origin: string, /* The origin this event belongs to. */
        serviceWorkerRegistrationId: ServiceWorker.Types.RegistrationID.t, /* The Service Worker ID that initiated the event. */
        service: ServiceName.t, /* The Background Service this event belongs to. */
        eventName: string, /* A description of the event. */
        instanceId: string, /* An identifier that groups related events together. */
        eventMetadata: array(EventMetadata.t) /* A list of event-specific information. */,
      };
    };
  };

  module Events = {
    /* Called when the recording state for the service has been updated. */
    module RecordingStateChanged = {
      [@deriving yojson]
      type result = {
        isRecording: bool, /* No description provided */
        service: Types.ServiceName.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called with all existing backgroundServiceEvents when enabled, and all new
       events afterwards if enabled and recording. */
    module BackgroundServiceEventReceived = {
      [@deriving yojson]
      type result = {
        backgroundServiceEvent: Types.BackgroundServiceEvent.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Browser: {
  module Types: {
    module rec BrowserContextID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and WindowID: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and WindowState: {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    }
    and Bounds: {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
        [@yojson.option]
        top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
        [@yojson.option]
        width: option(float), /* The window width in pixels. */
        [@yojson.option]
        height: option(float), /* The window height in pixels. */
        [@yojson.option]
        windowState: option(WindowState.t) /* The window state. Default to normal. */,
      };
    }
    and PermissionType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionSetting: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionDescriptor: {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
        [@yojson.option]
        sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
        [@yojson.option]
        userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        [@yojson.option]
        allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
        [@yojson.option]
        panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
      };
    }
    and BrowserCommandId: {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    }
    and Bucket: {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {
        low: float, /* Minimum value (inclusive). */
        high: float, /* Maximum value (exclusive). */
        count: float /* Number of samples. */,
      };
    }
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: float, /* Sum of sample values. */
        count: float, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    };
  };

  module Events: {
    /* Fired when page is about to start a download. */
    module DownloadWillBegin: {
      [@deriving yojson]
      type result = {
        frameId: Page.Types.FrameId.t, /* Id of the frame that caused the download to begin. */
        guid: string, /* Global unique identifier of the download. */
        url: string, /* URL of the resource being downloaded. */
        suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when download makes progress. Last call has |done| == true. */
    module DownloadProgress: {
      [@deriving yojson]
      type result = {
        guid: string, /* Global unique identifier of the download. */
        totalBytes: float, /* Total expected bytes to download. */
        receivedBytes: float, /* Total bytes received. */
        state: string /* Download status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec BrowserContextID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and WindowID: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and WindowState: {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    }
    and Bounds: {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
        [@yojson.option]
        top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
        [@yojson.option]
        width: option(float), /* The window width in pixels. */
        [@yojson.option]
        height: option(float), /* The window height in pixels. */
        [@yojson.option]
        windowState: option(WindowState.t) /* The window state. Default to normal. */,
      };
    }
    and PermissionType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionSetting: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionDescriptor: {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
        [@yojson.option]
        sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
        [@yojson.option]
        userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        [@yojson.option]
        allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
        [@yojson.option]
        panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
      };
    }
    and BrowserCommandId: {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    }
    and Bucket: {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {
        low: float, /* Minimum value (inclusive). */
        high: float, /* Maximum value (exclusive). */
        count: float /* Number of samples. */,
      };
    }
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: float, /* Sum of sample values. */
        count: float, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    };
  } = {
    module rec BrowserContextID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and WindowID: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and WindowState: {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    }
    and Bounds: {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
        [@yojson.option]
        top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
        [@yojson.option]
        width: option(float), /* The window width in pixels. */
        [@yojson.option]
        height: option(float), /* The window height in pixels. */
        [@yojson.option]
        windowState: option(WindowState.t) /* The window state. Default to normal. */,
      };
    } = {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
        [@yojson.option]
        top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
        [@yojson.option]
        width: option(float), /* The window width in pixels. */
        [@yojson.option]
        height: option(float), /* The window height in pixels. */
        [@yojson.option]
        windowState: option(WindowState.t) /* The window state. Default to normal. */,
      };
    }
    and PermissionType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionSetting: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionDescriptor: {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
        [@yojson.option]
        sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
        [@yojson.option]
        userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        [@yojson.option]
        allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
        [@yojson.option]
        panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
      };
    } = {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
        [@yojson.option]
        sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
        [@yojson.option]
        userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        [@yojson.option]
        allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
        [@yojson.option]
        panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
      };
    }
    and BrowserCommandId: {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    }
    and Bucket: {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {
        low: float, /* Minimum value (inclusive). */
        high: float, /* Maximum value (exclusive). */
        count: float /* Number of samples. */,
      };
    } = {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {
        low: float, /* Minimum value (inclusive). */
        high: float, /* Maximum value (exclusive). */
        count: float /* Number of samples. */,
      };
    }
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: float, /* Sum of sample values. */
        count: float, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    } = {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: float, /* Sum of sample values. */
        count: float, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    };
  };

  module Events = {
    /* Fired when page is about to start a download. */
    module DownloadWillBegin = {
      [@deriving yojson]
      type result = {
        frameId: Page.Types.FrameId.t, /* Id of the frame that caused the download to begin. */
        guid: string, /* Global unique identifier of the download. */
        url: string, /* URL of the resource being downloaded. */
        suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when download makes progress. Last call has |done| == true. */
    module DownloadProgress = {
      [@deriving yojson]
      type result = {
        guid: string, /* Global unique identifier of the download. */
        totalBytes: float, /* Total expected bytes to download. */
        receivedBytes: float, /* Total bytes received. */
        state: string /* Download status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and CSS: {
  module Types: {
    module rec StyleSheetId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and StyleSheetOrigin: {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    }
    and PseudoElementMatches: {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {
        pseudoType: DOM.Types.PseudoType.t, /* Pseudo element type. */
        matches: array(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
      };
    }
    and InheritedStyleEntry: {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    }
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    }
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        [@yojson.option]
        range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
      };
    }
    and SelectorList: {
      /* Selector list data. */
      [@deriving yojson]
      type t = {
        selectors: array(Value.t), /* Selectors in the list. */
        text: string /* Rule selector text. */,
      };
    }
    and CSSStyleSheetHeader: {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
        frameId: Page.Types.FrameId.t, /* Owner frame identifier. */
        sourceURL: string, /* Stylesheet resource URL. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        [@yojson.option]
        ownerNode: option(DOM.Types.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        [@yojson.option]
        hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
        isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
        isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
        isConstructed: bool, /* Whether this stylesheet is a constructed stylesheet (created using new CSSStyleSheet()). */
        startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
        startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
        length: float, /* Size of the content (in characters). */
        endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
        endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
      };
    }
    and CSSRule: {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        [@yojson.option]
        media: option(array(CSSMedia.t)) /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */,
      };
    }
    and RuleUsage: {
      /* CSS coverage information. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
        endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
        used: bool /* Indicates whether the rule was actually used by some element in the page. */,
      };
    }
    and SourceRange: {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {
        startLine: float, /* Start line of range. */
        startColumn: float, /* Start column of range (inclusive). */
        endLine: float, /* End line of range */
        endColumn: float /* End column of range (exclusive). */,
      };
    }
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        [@yojson.option]
        important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    }
    and CSSStyle: {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        [@yojson.option]
        cssText: option(string), /* Style declaration text (if available). */
        [@yojson.option]
        range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    }
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        [@yojson.option]
        important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
        [@yojson.option]
        implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
        [@yojson.option]
        text: option(string), /* The full property text as specified in the style. */
        [@yojson.option]
        parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
        [@yojson.option]
        disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
        [@yojson.option]
        range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
      };
    }
    and CSSMedia: {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {
        text: string, /* Media query text. */
        source: string, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
        [@yojson.option]
        sourceURL: option(string), /* URL of the document containing the media query description. */
        [@yojson.option]
        range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
        [@yojson.option]
        mediaList: option(array(MediaQuery.t)) /* Array of media queries. */,
      };
    }
    and MediaQuery: {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {
        expressions: array(MediaQueryExpression.t), /* Array of media query expressions. */
        active: bool /* Whether the media query condition is satisfied. */,
      };
    }
    and MediaQueryExpression: {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {
        value: float, /* Media query expression value. */
        unit: string, /* Media query expression units. */
        feature: string, /* Media query expression feature. */
        [@yojson.option]
        valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
        [@yojson.option]
        computedLength: option(float) /* Computed length of media query expression (if applicable). */,
      };
    }
    and PlatformFontUsage: {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {
        familyName: string, /* Font's family name reported by platform. */
        isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
        glyphCount: float /* Amount of glyphs that were rendered with this font. */,
      };
    }
    and FontVariationAxis: {
      /* Information about font variation axes for variable fonts */
      [@deriving yojson]
      type t = {
        tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
        name: string, /* Human-readable variation name in the default language (normally, "en"). */
        minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
        maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
        defaultValue: float /* The default value. */,
      };
    }
    and FontFace: {
      /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
         and additional information such as platformFontFamily and fontVariationAxes. */
      [@deriving yojson]
      type t = {
        fontFamily: string, /* The font-family. */
        fontStyle: string, /* The font-style. */
        fontVariant: string, /* The font-variant. */
        fontWeight: string, /* The font-weight. */
        fontStretch: string, /* The font-stretch. */
        unicodeRange: string, /* The unicode-range. */
        src: string, /* The src. */
        platformFontFamily: string, /* The resolved platform font family */
        [@yojson.option]
        fontVariationAxes: option(array(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
      };
    }
    and CSSKeyframesRule: {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {
        animationName: Value.t, /* Animation name. */
        keyframes: array(CSSKeyframeRule.t) /* List of keyframes. */,
      };
    }
    and CSSKeyframeRule: {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        keyText: Value.t, /* Associated key text. */
        style: CSSStyle.t /* Associated style declaration. */,
      };
    }
    and StyleDeclarationEdit: {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
        range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
        text: string /* New style text. */,
      };
    };
  };

  module Events: {
    /* Fires whenever a web font is updated.  A non-empty font parameter indicates a successfully loaded
       web font */
    module FontsUpdated: {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        font: option(Types.FontFace.t) /* The web font that has loaded. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fires whenever a MediaQuery result changes (for example, after a browser window has been
       resized.) The current implementation considers only viewport-dependent media features. */
    module MediaQueryResultChanged: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired whenever an active document stylesheet is added. */
    module StyleSheetAdded: {
      [@deriving yojson]
      type result = {
        header: Types.CSSStyleSheetHeader.t /* Added stylesheet metainfo. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired whenever a stylesheet is changed as a result of the client operation. */
    module StyleSheetChanged: {
      [@deriving yojson]
      type result = {
        styleSheetId: Types.StyleSheetId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired whenever an active document stylesheet is removed. */
    module StyleSheetRemoved: {
      [@deriving yojson]
      type result = {
        styleSheetId: Types.StyleSheetId.t /* Identifier of the removed stylesheet. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec StyleSheetId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and StyleSheetOrigin: {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    }
    and PseudoElementMatches: {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {
        pseudoType: DOM.Types.PseudoType.t, /* Pseudo element type. */
        matches: array(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
      };
    }
    and InheritedStyleEntry: {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    }
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    }
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        [@yojson.option]
        range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
      };
    }
    and SelectorList: {
      /* Selector list data. */
      [@deriving yojson]
      type t = {
        selectors: array(Value.t), /* Selectors in the list. */
        text: string /* Rule selector text. */,
      };
    }
    and CSSStyleSheetHeader: {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
        frameId: Page.Types.FrameId.t, /* Owner frame identifier. */
        sourceURL: string, /* Stylesheet resource URL. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        [@yojson.option]
        ownerNode: option(DOM.Types.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        [@yojson.option]
        hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
        isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
        isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
        isConstructed: bool, /* Whether this stylesheet is a constructed stylesheet (created using new CSSStyleSheet()). */
        startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
        startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
        length: float, /* Size of the content (in characters). */
        endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
        endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
      };
    }
    and CSSRule: {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        [@yojson.option]
        media: option(array(CSSMedia.t)) /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */,
      };
    }
    and RuleUsage: {
      /* CSS coverage information. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
        endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
        used: bool /* Indicates whether the rule was actually used by some element in the page. */,
      };
    }
    and SourceRange: {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {
        startLine: float, /* Start line of range. */
        startColumn: float, /* Start column of range (inclusive). */
        endLine: float, /* End line of range */
        endColumn: float /* End column of range (exclusive). */,
      };
    }
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        [@yojson.option]
        important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    }
    and CSSStyle: {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        [@yojson.option]
        cssText: option(string), /* Style declaration text (if available). */
        [@yojson.option]
        range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    }
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        [@yojson.option]
        important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
        [@yojson.option]
        implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
        [@yojson.option]
        text: option(string), /* The full property text as specified in the style. */
        [@yojson.option]
        parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
        [@yojson.option]
        disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
        [@yojson.option]
        range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
      };
    }
    and CSSMedia: {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {
        text: string, /* Media query text. */
        source: string, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
        [@yojson.option]
        sourceURL: option(string), /* URL of the document containing the media query description. */
        [@yojson.option]
        range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
        [@yojson.option]
        mediaList: option(array(MediaQuery.t)) /* Array of media queries. */,
      };
    }
    and MediaQuery: {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {
        expressions: array(MediaQueryExpression.t), /* Array of media query expressions. */
        active: bool /* Whether the media query condition is satisfied. */,
      };
    }
    and MediaQueryExpression: {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {
        value: float, /* Media query expression value. */
        unit: string, /* Media query expression units. */
        feature: string, /* Media query expression feature. */
        [@yojson.option]
        valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
        [@yojson.option]
        computedLength: option(float) /* Computed length of media query expression (if applicable). */,
      };
    }
    and PlatformFontUsage: {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {
        familyName: string, /* Font's family name reported by platform. */
        isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
        glyphCount: float /* Amount of glyphs that were rendered with this font. */,
      };
    }
    and FontVariationAxis: {
      /* Information about font variation axes for variable fonts */
      [@deriving yojson]
      type t = {
        tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
        name: string, /* Human-readable variation name in the default language (normally, "en"). */
        minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
        maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
        defaultValue: float /* The default value. */,
      };
    }
    and FontFace: {
      /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
         and additional information such as platformFontFamily and fontVariationAxes. */
      [@deriving yojson]
      type t = {
        fontFamily: string, /* The font-family. */
        fontStyle: string, /* The font-style. */
        fontVariant: string, /* The font-variant. */
        fontWeight: string, /* The font-weight. */
        fontStretch: string, /* The font-stretch. */
        unicodeRange: string, /* The unicode-range. */
        src: string, /* The src. */
        platformFontFamily: string, /* The resolved platform font family */
        [@yojson.option]
        fontVariationAxes: option(array(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
      };
    }
    and CSSKeyframesRule: {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {
        animationName: Value.t, /* Animation name. */
        keyframes: array(CSSKeyframeRule.t) /* List of keyframes. */,
      };
    }
    and CSSKeyframeRule: {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        keyText: Value.t, /* Associated key text. */
        style: CSSStyle.t /* Associated style declaration. */,
      };
    }
    and StyleDeclarationEdit: {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
        range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
        text: string /* New style text. */,
      };
    };
  } = {
    module rec StyleSheetId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and StyleSheetOrigin: {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    }
    and PseudoElementMatches: {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {
        pseudoType: DOM.Types.PseudoType.t, /* Pseudo element type. */
        matches: array(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
      };
    } = {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {
        pseudoType: DOM.Types.PseudoType.t, /* Pseudo element type. */
        matches: array(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
      };
    }
    and InheritedStyleEntry: {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    } = {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    }
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    } = {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    }
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        [@yojson.option]
        range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
      };
    } = {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        [@yojson.option]
        range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
      };
    }
    and SelectorList: {
      /* Selector list data. */
      [@deriving yojson]
      type t = {
        selectors: array(Value.t), /* Selectors in the list. */
        text: string /* Rule selector text. */,
      };
    } = {
      /* Selector list data. */
      [@deriving yojson]
      type t = {
        selectors: array(Value.t), /* Selectors in the list. */
        text: string /* Rule selector text. */,
      };
    }
    and CSSStyleSheetHeader: {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
        frameId: Page.Types.FrameId.t, /* Owner frame identifier. */
        sourceURL: string, /* Stylesheet resource URL. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        [@yojson.option]
        ownerNode: option(DOM.Types.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        [@yojson.option]
        hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
        isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
        isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
        isConstructed: bool, /* Whether this stylesheet is a constructed stylesheet (created using new CSSStyleSheet()). */
        startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
        startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
        length: float, /* Size of the content (in characters). */
        endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
        endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
      };
    } = {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
        frameId: Page.Types.FrameId.t, /* Owner frame identifier. */
        sourceURL: string, /* Stylesheet resource URL. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        [@yojson.option]
        ownerNode: option(DOM.Types.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        [@yojson.option]
        hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
        isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
        isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
        isConstructed: bool, /* Whether this stylesheet is a constructed stylesheet (created using new CSSStyleSheet()). */
        startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
        startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
        length: float, /* Size of the content (in characters). */
        endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
        endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
      };
    }
    and CSSRule: {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        [@yojson.option]
        media: option(array(CSSMedia.t)) /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */,
      };
    } = {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        [@yojson.option]
        media: option(array(CSSMedia.t)) /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */,
      };
    }
    and RuleUsage: {
      /* CSS coverage information. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
        endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
        used: bool /* Indicates whether the rule was actually used by some element in the page. */,
      };
    } = {
      /* CSS coverage information. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
        endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
        used: bool /* Indicates whether the rule was actually used by some element in the page. */,
      };
    }
    and SourceRange: {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {
        startLine: float, /* Start line of range. */
        startColumn: float, /* Start column of range (inclusive). */
        endLine: float, /* End line of range */
        endColumn: float /* End column of range (exclusive). */,
      };
    } = {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {
        startLine: float, /* Start line of range. */
        startColumn: float, /* Start column of range (inclusive). */
        endLine: float, /* End line of range */
        endColumn: float /* End column of range (exclusive). */,
      };
    }
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        [@yojson.option]
        important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        [@yojson.option]
        important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    }
    and CSSStyle: {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        [@yojson.option]
        cssText: option(string), /* Style declaration text (if available). */
        [@yojson.option]
        range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    } = {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        [@yojson.option]
        cssText: option(string), /* Style declaration text (if available). */
        [@yojson.option]
        range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    }
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        [@yojson.option]
        important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
        [@yojson.option]
        implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
        [@yojson.option]
        text: option(string), /* The full property text as specified in the style. */
        [@yojson.option]
        parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
        [@yojson.option]
        disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
        [@yojson.option]
        range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
      };
    } = {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        [@yojson.option]
        important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
        [@yojson.option]
        implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
        [@yojson.option]
        text: option(string), /* The full property text as specified in the style. */
        [@yojson.option]
        parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
        [@yojson.option]
        disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
        [@yojson.option]
        range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
      };
    }
    and CSSMedia: {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {
        text: string, /* Media query text. */
        source: string, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
        [@yojson.option]
        sourceURL: option(string), /* URL of the document containing the media query description. */
        [@yojson.option]
        range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
        [@yojson.option]
        mediaList: option(array(MediaQuery.t)) /* Array of media queries. */,
      };
    } = {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {
        text: string, /* Media query text. */
        source: string, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
        [@yojson.option]
        sourceURL: option(string), /* URL of the document containing the media query description. */
        [@yojson.option]
        range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
        [@yojson.option]
        mediaList: option(array(MediaQuery.t)) /* Array of media queries. */,
      };
    }
    and MediaQuery: {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {
        expressions: array(MediaQueryExpression.t), /* Array of media query expressions. */
        active: bool /* Whether the media query condition is satisfied. */,
      };
    } = {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {
        expressions: array(MediaQueryExpression.t), /* Array of media query expressions. */
        active: bool /* Whether the media query condition is satisfied. */,
      };
    }
    and MediaQueryExpression: {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {
        value: float, /* Media query expression value. */
        unit: string, /* Media query expression units. */
        feature: string, /* Media query expression feature. */
        [@yojson.option]
        valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
        [@yojson.option]
        computedLength: option(float) /* Computed length of media query expression (if applicable). */,
      };
    } = {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {
        value: float, /* Media query expression value. */
        unit: string, /* Media query expression units. */
        feature: string, /* Media query expression feature. */
        [@yojson.option]
        valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
        [@yojson.option]
        computedLength: option(float) /* Computed length of media query expression (if applicable). */,
      };
    }
    and PlatformFontUsage: {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {
        familyName: string, /* Font's family name reported by platform. */
        isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
        glyphCount: float /* Amount of glyphs that were rendered with this font. */,
      };
    } = {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {
        familyName: string, /* Font's family name reported by platform. */
        isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
        glyphCount: float /* Amount of glyphs that were rendered with this font. */,
      };
    }
    and FontVariationAxis: {
      /* Information about font variation axes for variable fonts */
      [@deriving yojson]
      type t = {
        tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
        name: string, /* Human-readable variation name in the default language (normally, "en"). */
        minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
        maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
        defaultValue: float /* The default value. */,
      };
    } = {
      /* Information about font variation axes for variable fonts */
      [@deriving yojson]
      type t = {
        tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
        name: string, /* Human-readable variation name in the default language (normally, "en"). */
        minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
        maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
        defaultValue: float /* The default value. */,
      };
    }
    and FontFace: {
      /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
         and additional information such as platformFontFamily and fontVariationAxes. */
      [@deriving yojson]
      type t = {
        fontFamily: string, /* The font-family. */
        fontStyle: string, /* The font-style. */
        fontVariant: string, /* The font-variant. */
        fontWeight: string, /* The font-weight. */
        fontStretch: string, /* The font-stretch. */
        unicodeRange: string, /* The unicode-range. */
        src: string, /* The src. */
        platformFontFamily: string, /* The resolved platform font family */
        [@yojson.option]
        fontVariationAxes: option(array(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
      };
    } = {
      /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
         and additional information such as platformFontFamily and fontVariationAxes. */
      [@deriving yojson]
      type t = {
        fontFamily: string, /* The font-family. */
        fontStyle: string, /* The font-style. */
        fontVariant: string, /* The font-variant. */
        fontWeight: string, /* The font-weight. */
        fontStretch: string, /* The font-stretch. */
        unicodeRange: string, /* The unicode-range. */
        src: string, /* The src. */
        platformFontFamily: string, /* The resolved platform font family */
        [@yojson.option]
        fontVariationAxes: option(array(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
      };
    }
    and CSSKeyframesRule: {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {
        animationName: Value.t, /* Animation name. */
        keyframes: array(CSSKeyframeRule.t) /* List of keyframes. */,
      };
    } = {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {
        animationName: Value.t, /* Animation name. */
        keyframes: array(CSSKeyframeRule.t) /* List of keyframes. */,
      };
    }
    and CSSKeyframeRule: {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        keyText: Value.t, /* Associated key text. */
        style: CSSStyle.t /* Associated style declaration. */,
      };
    } = {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        keyText: Value.t, /* Associated key text. */
        style: CSSStyle.t /* Associated style declaration. */,
      };
    }
    and StyleDeclarationEdit: {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
        range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
        text: string /* New style text. */,
      };
    } = {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
        range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
        text: string /* New style text. */,
      };
    };
  };

  module Events = {
    /* Fires whenever a web font is updated.  A non-empty font parameter indicates a successfully loaded
       web font */
    module FontsUpdated = {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        font: option(Types.FontFace.t) /* The web font that has loaded. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fires whenever a MediaQuery result changes (for example, after a browser window has been
       resized.) The current implementation considers only viewport-dependent media features. */
    module MediaQueryResultChanged = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired whenever an active document stylesheet is added. */
    module StyleSheetAdded = {
      [@deriving yojson]
      type result = {
        header: Types.CSSStyleSheetHeader.t /* Added stylesheet metainfo. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired whenever a stylesheet is changed as a result of the client operation. */
    module StyleSheetChanged = {
      [@deriving yojson]
      type result = {
        styleSheetId: Types.StyleSheetId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired whenever an active document stylesheet is removed. */
    module StyleSheetRemoved = {
      [@deriving yojson]
      type result = {
        styleSheetId: Types.StyleSheetId.t /* Identifier of the removed stylesheet. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and CacheStorage: {
  module Types: {
    module rec CacheId: {
      /* Unique identifier of the Cache object. */
      [@deriving yojson]
      type t = string;
    }
    and CachedResponseType: {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        requestURL: string, /* Request URL. */
        requestMethod: string, /* Request method. */
        requestHeaders: array(Header.t), /* Request headers */
        responseTime: float, /* Number of seconds since epoch. */
        responseStatus: float, /* HTTP response status code. */
        responseStatusText: string, /* HTTP response status text. */
        responseType: CachedResponseType.t, /* HTTP response type */
        responseHeaders: array(Header.t) /* Response headers */,
      };
    }
    and Cache: {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {
        cacheId: CacheId.t, /* An opaque unique id of the cache. */
        securityOrigin: string, /* Security origin of the cache. */
        cacheName: string /* The name of the cache. */,
      };
    }
    and Header: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and CachedResponse: {
      /* Cached response */
      [@deriving yojson]
      type t = {
        body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
      };
    };
  };
} = {
  module Types: {
    module rec CacheId: {
      /* Unique identifier of the Cache object. */
      [@deriving yojson]
      type t = string;
    }
    and CachedResponseType: {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        requestURL: string, /* Request URL. */
        requestMethod: string, /* Request method. */
        requestHeaders: array(Header.t), /* Request headers */
        responseTime: float, /* Number of seconds since epoch. */
        responseStatus: float, /* HTTP response status code. */
        responseStatusText: string, /* HTTP response status text. */
        responseType: CachedResponseType.t, /* HTTP response type */
        responseHeaders: array(Header.t) /* Response headers */,
      };
    }
    and Cache: {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {
        cacheId: CacheId.t, /* An opaque unique id of the cache. */
        securityOrigin: string, /* Security origin of the cache. */
        cacheName: string /* The name of the cache. */,
      };
    }
    and Header: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and CachedResponse: {
      /* Cached response */
      [@deriving yojson]
      type t = {
        body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
      };
    };
  } = {
    module rec CacheId: {
      /* Unique identifier of the Cache object. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique identifier of the Cache object. */
      [@deriving yojson]
      type t = string;
    }
    and CachedResponseType: {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    } = {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        requestURL: string, /* Request URL. */
        requestMethod: string, /* Request method. */
        requestHeaders: array(Header.t), /* Request headers */
        responseTime: float, /* Number of seconds since epoch. */
        responseStatus: float, /* HTTP response status code. */
        responseStatusText: string, /* HTTP response status text. */
        responseType: CachedResponseType.t, /* HTTP response type */
        responseHeaders: array(Header.t) /* Response headers */,
      };
    } = {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        requestURL: string, /* Request URL. */
        requestMethod: string, /* Request method. */
        requestHeaders: array(Header.t), /* Request headers */
        responseTime: float, /* Number of seconds since epoch. */
        responseStatus: float, /* HTTP response status code. */
        responseStatusText: string, /* HTTP response status text. */
        responseType: CachedResponseType.t, /* HTTP response type */
        responseHeaders: array(Header.t) /* Response headers */,
      };
    }
    and Cache: {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {
        cacheId: CacheId.t, /* An opaque unique id of the cache. */
        securityOrigin: string, /* Security origin of the cache. */
        cacheName: string /* The name of the cache. */,
      };
    } = {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {
        cacheId: CacheId.t, /* An opaque unique id of the cache. */
        securityOrigin: string, /* Security origin of the cache. */
        cacheName: string /* The name of the cache. */,
      };
    }
    and Header: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and CachedResponse: {
      /* Cached response */
      [@deriving yojson]
      type t = {
        body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
      };
    } = {
      /* Cached response */
      [@deriving yojson]
      type t = {
        body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
      };
    };
  };
}
and Cast: {
  module Types: {
    module rec Sink: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        id: string, /* No description provided */
        [@yojson.option]
        session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
    };
  };

  module Events: {
    /* This is fired whenever the list of available sinks changes. A sink is a
       device or a software surface that you can cast to. */
    module SinksUpdated: {
      [@deriving yojson]
      type result = {
        sinks: array(Types.Sink.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* This is fired whenever the outstanding issue/error message changes.
       |issueMessage| is empty if there is no issue. */
    module IssueUpdated: {
      [@deriving yojson]
      type result = {issueMessage: string /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec Sink: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        id: string, /* No description provided */
        [@yojson.option]
        session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
    };
  } = {
    module rec Sink: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        id: string, /* No description provided */
        [@yojson.option]
        session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        id: string, /* No description provided */
        [@yojson.option]
        session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
    };
  };

  module Events = {
    /* This is fired whenever the list of available sinks changes. A sink is a
       device or a software surface that you can cast to. */
    module SinksUpdated = {
      [@deriving yojson]
      type result = {
        sinks: array(Types.Sink.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* This is fired whenever the outstanding issue/error message changes.
       |issueMessage| is empty if there is no issue. */
    module IssueUpdated = {
      [@deriving yojson]
      type result = {issueMessage: string /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Console: {
  module Types: {
    module rec ConsoleMessage: {
      /* Console message. */
      [@deriving yojson]
      type t = {
        source: string, /* Message source. */
        level: string, /* Message severity. */
        text: string, /* Message text. */
        [@yojson.option]
        url: option(string), /* URL of the message origin. */
        [@yojson.option]
        line: option(float), /* Line number in the resource that generated this message (1-based). */
        [@yojson.option]
        column: option(float) /* Column number in the resource that generated this message (1-based). */,
      };
    };
  };

  module Events: {
    /* Issued when new console message is added. */
    module MessageAdded: {
      [@deriving yojson]
      type result = {
        message: Types.ConsoleMessage.t /* Console message that has been added. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ConsoleMessage: {
      /* Console message. */
      [@deriving yojson]
      type t = {
        source: string, /* Message source. */
        level: string, /* Message severity. */
        text: string, /* Message text. */
        [@yojson.option]
        url: option(string), /* URL of the message origin. */
        [@yojson.option]
        line: option(float), /* Line number in the resource that generated this message (1-based). */
        [@yojson.option]
        column: option(float) /* Column number in the resource that generated this message (1-based). */,
      };
    };
  } = {
    module rec ConsoleMessage: {
      /* Console message. */
      [@deriving yojson]
      type t = {
        source: string, /* Message source. */
        level: string, /* Message severity. */
        text: string, /* Message text. */
        [@yojson.option]
        url: option(string), /* URL of the message origin. */
        [@yojson.option]
        line: option(float), /* Line number in the resource that generated this message (1-based). */
        [@yojson.option]
        column: option(float) /* Column number in the resource that generated this message (1-based). */,
      };
    } = {
      /* Console message. */
      [@deriving yojson]
      type t = {
        source: string, /* Message source. */
        level: string, /* Message severity. */
        text: string, /* Message text. */
        [@yojson.option]
        url: option(string), /* URL of the message origin. */
        [@yojson.option]
        line: option(float), /* Line number in the resource that generated this message (1-based). */
        [@yojson.option]
        column: option(float) /* Column number in the resource that generated this message (1-based). */,
      };
    };
  };

  module Events = {
    /* Issued when new console message is added. */
    module MessageAdded = {
      [@deriving yojson]
      type result = {
        message: Types.ConsoleMessage.t /* Console message that has been added. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Debugger: {
  module Types: {
    module rec BreakpointId: {
      /* Breakpoint identifier. */
      [@deriving yojson]
      type t = string;
    }
    and CallFrameId: {
      /* Call frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and Location: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float) /* Column number in the script (0-based). */,
      };
    }
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        [@key "end"]
        end_: ScriptPosition.t /* No description provided */,
      };
    }
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        [@yojson.option]
        functionLocation: option(Location.t), /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        [@yojson.option]
        returnValue: option(Runtime.Types.RemoteObject.t) /* The value being returned, if the function is at return point. */,
      };
    }
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Scope type. */
        [@key "object"]
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        [@yojson.option]
        name: option(string), /* No description provided */
        [@yojson.option]
        startLocation: option(Location.t), /* Location in the source code where scope starts */
        [@yojson.option]
        endLocation: option(Location.t) /* Location in the source code where scope ends */,
      };
    }
    and SearchMatch: {
      /* Search match for resource. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* Line number in resource content. */
        lineContent: string /* Line with match content. */,
      };
    }
    and BreakLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Column number in the script (0-based). */
        [@yojson.option] [@key "type"]
        type_: option(string) /* No description provided */,
      };
    }
    and ScriptLanguage: {
      /* Enum of possible script languages. */
      [@deriving yojson]
      type t = string;
    }
    and DebugSymbols: {
      /* Debug symbols available for a wasm script. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of the debug symbols. */
        [@yojson.option]
        externalURL: option(string) /* URL of the external symbol source. */,
      };
    };
  };

  module Events: {
    /* Fired when breakpoint is resolved to an actual script and location. */
    module BreakpointResolved: {
      [@deriving yojson]
      type result = {
        breakpointId: Types.BreakpointId.t, /* Breakpoint unique identifier. */
        location: Types.Location.t /* Actual breakpoint location. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria. */
    module Paused: {
      [@deriving yojson]
      type result = {
        callFrames: array(Types.CallFrame.t), /* Call stack the virtual machine stopped on. */
        reason: string, /* Pause reason. */
        [@yojson.option]
        data: option(assoc), /* Object containing break-specific auxiliary properties. */
        [@yojson.option]
        hitBreakpoints: option(array(string)), /* Hit breakpoints IDs */
        [@yojson.option]
        asyncStackTrace: option(Runtime.Types.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option]
        asyncStackTraceId: option(Runtime.Types.StackTraceId.t), /* Async stack trace, if any. */
        [@yojson.option]
        asyncCallStackTraceId: option(Runtime.Types.StackTraceId.t) /* Never present, will be removed. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when the virtual machine resumed execution. */
    module Resumed: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when virtual machine fails to parse the script. */
    module ScriptFailedToParse: {
      [@deriving yojson]
      type result = {
        scriptId: Runtime.Types.ScriptId.t, /* Identifier of the script parsed. */
        url: string, /* URL or name of the script parsed (if any). */
        startLine: float, /* Line offset of the script within the resource with given URL (for script tags). */
        startColumn: float, /* Column offset of the script within the resource with given URL. */
        endLine: float, /* Last line of the script. */
        endColumn: float, /* Length of the last line of the script. */
        executionContextId: Runtime.Types.ExecutionContextId.t, /* Specifies script creation context. */
        hash: string, /* Content hash of the script. */
        [@yojson.option]
        executionContextAuxData: option(assoc), /* Embedder-specific auxiliary data. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with script (if any). */
        [@yojson.option]
        hasSourceURL: option(bool), /* True, if this script has sourceURL. */
        [@yojson.option]
        isModule: option(bool), /* True, if this script is ES6 module. */
        [@yojson.option]
        length: option(float), /* This script length. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
        [@yojson.option]
        codeOffset: option(float), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
        [@yojson.option]
        scriptLanguage: option(Debugger.Types.ScriptLanguage.t), /* The language of the script. */
        [@yojson.option]
        embedderName: option(string) /* The name the embedder supplied for this script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when virtual machine parses script. This event is also fired for all known and uncollected
       scripts upon enabling debugger. */
    module ScriptParsed: {
      [@deriving yojson]
      type result = {
        scriptId: Runtime.Types.ScriptId.t, /* Identifier of the script parsed. */
        url: string, /* URL or name of the script parsed (if any). */
        startLine: float, /* Line offset of the script within the resource with given URL (for script tags). */
        startColumn: float, /* Column offset of the script within the resource with given URL. */
        endLine: float, /* Last line of the script. */
        endColumn: float, /* Length of the last line of the script. */
        executionContextId: Runtime.Types.ExecutionContextId.t, /* Specifies script creation context. */
        hash: string, /* Content hash of the script. */
        [@yojson.option]
        executionContextAuxData: option(assoc), /* Embedder-specific auxiliary data. */
        [@yojson.option]
        isLiveEdit: option(bool), /* True, if this script is generated as a result of the live edit operation. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with script (if any). */
        [@yojson.option]
        hasSourceURL: option(bool), /* True, if this script has sourceURL. */
        [@yojson.option]
        isModule: option(bool), /* True, if this script is ES6 module. */
        [@yojson.option]
        length: option(float), /* This script length. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
        [@yojson.option]
        codeOffset: option(float), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
        [@yojson.option]
        scriptLanguage: option(Debugger.Types.ScriptLanguage.t), /* The language of the script. */
        [@yojson.option]
        debugSymbols: option(Debugger.Types.DebugSymbols.t), /* If the scriptLanguage is WebASsembly, the source of debug symbols for the module. */
        [@yojson.option]
        embedderName: option(string) /* The name the embedder supplied for this script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec BreakpointId: {
      /* Breakpoint identifier. */
      [@deriving yojson]
      type t = string;
    }
    and CallFrameId: {
      /* Call frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and Location: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float) /* Column number in the script (0-based). */,
      };
    }
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        [@key "end"]
        end_: ScriptPosition.t /* No description provided */,
      };
    }
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        [@yojson.option]
        functionLocation: option(Location.t), /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        [@yojson.option]
        returnValue: option(Runtime.Types.RemoteObject.t) /* The value being returned, if the function is at return point. */,
      };
    }
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Scope type. */
        [@key "object"]
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        [@yojson.option]
        name: option(string), /* No description provided */
        [@yojson.option]
        startLocation: option(Location.t), /* Location in the source code where scope starts */
        [@yojson.option]
        endLocation: option(Location.t) /* Location in the source code where scope ends */,
      };
    }
    and SearchMatch: {
      /* Search match for resource. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* Line number in resource content. */
        lineContent: string /* Line with match content. */,
      };
    }
    and BreakLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Column number in the script (0-based). */
        [@yojson.option] [@key "type"]
        type_: option(string) /* No description provided */,
      };
    }
    and ScriptLanguage: {
      /* Enum of possible script languages. */
      [@deriving yojson]
      type t = string;
    }
    and DebugSymbols: {
      /* Debug symbols available for a wasm script. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of the debug symbols. */
        [@yojson.option]
        externalURL: option(string) /* URL of the external symbol source. */,
      };
    };
  } = {
    module rec BreakpointId: {
      /* Breakpoint identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Breakpoint identifier. */
      [@deriving yojson]
      type t = string;
    }
    and CallFrameId: {
      /* Call frame identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Call frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and Location: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float) /* Column number in the script (0-based). */,
      };
    } = {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float) /* Column number in the script (0-based). */,
      };
    }
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    } = {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    }
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        [@key "end"]
        end_: ScriptPosition.t /* No description provided */,
      };
    } = {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        [@key "end"]
        end_: ScriptPosition.t /* No description provided */,
      };
    }
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        [@yojson.option]
        functionLocation: option(Location.t), /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        [@yojson.option]
        returnValue: option(Runtime.Types.RemoteObject.t) /* The value being returned, if the function is at return point. */,
      };
    } = {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        [@yojson.option]
        functionLocation: option(Location.t), /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        [@yojson.option]
        returnValue: option(Runtime.Types.RemoteObject.t) /* The value being returned, if the function is at return point. */,
      };
    }
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Scope type. */
        [@key "object"]
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        [@yojson.option]
        name: option(string), /* No description provided */
        [@yojson.option]
        startLocation: option(Location.t), /* Location in the source code where scope starts */
        [@yojson.option]
        endLocation: option(Location.t) /* Location in the source code where scope ends */,
      };
    } = {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Scope type. */
        [@key "object"]
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        [@yojson.option]
        name: option(string), /* No description provided */
        [@yojson.option]
        startLocation: option(Location.t), /* Location in the source code where scope starts */
        [@yojson.option]
        endLocation: option(Location.t) /* Location in the source code where scope ends */,
      };
    }
    and SearchMatch: {
      /* Search match for resource. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* Line number in resource content. */
        lineContent: string /* Line with match content. */,
      };
    } = {
      /* Search match for resource. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* Line number in resource content. */
        lineContent: string /* Line with match content. */,
      };
    }
    and BreakLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Column number in the script (0-based). */
        [@yojson.option] [@key "type"]
        type_: option(string) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: float, /* Line number in the script (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Column number in the script (0-based). */
        [@yojson.option] [@key "type"]
        type_: option(string) /* No description provided */,
      };
    }
    and ScriptLanguage: {
      /* Enum of possible script languages. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of possible script languages. */
      [@deriving yojson]
      type t = string;
    }
    and DebugSymbols: {
      /* Debug symbols available for a wasm script. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of the debug symbols. */
        [@yojson.option]
        externalURL: option(string) /* URL of the external symbol source. */,
      };
    } = {
      /* Debug symbols available for a wasm script. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of the debug symbols. */
        [@yojson.option]
        externalURL: option(string) /* URL of the external symbol source. */,
      };
    };
  };

  module Events = {
    /* Fired when breakpoint is resolved to an actual script and location. */
    module BreakpointResolved = {
      [@deriving yojson]
      type result = {
        breakpointId: Types.BreakpointId.t, /* Breakpoint unique identifier. */
        location: Types.Location.t /* Actual breakpoint location. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when the virtual machine stopped on breakpoint or exception or any other stop criteria. */
    module Paused = {
      [@deriving yojson]
      type result = {
        callFrames: array(Types.CallFrame.t), /* Call stack the virtual machine stopped on. */
        reason: string, /* Pause reason. */
        [@yojson.option]
        data: option(assoc), /* Object containing break-specific auxiliary properties. */
        [@yojson.option]
        hitBreakpoints: option(array(string)), /* Hit breakpoints IDs */
        [@yojson.option]
        asyncStackTrace: option(Runtime.Types.StackTrace.t), /* Async stack trace, if any. */
        [@yojson.option]
        asyncStackTraceId: option(Runtime.Types.StackTraceId.t), /* Async stack trace, if any. */
        [@yojson.option]
        asyncCallStackTraceId: option(Runtime.Types.StackTraceId.t) /* Never present, will be removed. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when the virtual machine resumed execution. */
    module Resumed = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when virtual machine fails to parse the script. */
    module ScriptFailedToParse = {
      [@deriving yojson]
      type result = {
        scriptId: Runtime.Types.ScriptId.t, /* Identifier of the script parsed. */
        url: string, /* URL or name of the script parsed (if any). */
        startLine: float, /* Line offset of the script within the resource with given URL (for script tags). */
        startColumn: float, /* Column offset of the script within the resource with given URL. */
        endLine: float, /* Last line of the script. */
        endColumn: float, /* Length of the last line of the script. */
        executionContextId: Runtime.Types.ExecutionContextId.t, /* Specifies script creation context. */
        hash: string, /* Content hash of the script. */
        [@yojson.option]
        executionContextAuxData: option(assoc), /* Embedder-specific auxiliary data. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with script (if any). */
        [@yojson.option]
        hasSourceURL: option(bool), /* True, if this script has sourceURL. */
        [@yojson.option]
        isModule: option(bool), /* True, if this script is ES6 module. */
        [@yojson.option]
        length: option(float), /* This script length. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
        [@yojson.option]
        codeOffset: option(float), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
        [@yojson.option]
        scriptLanguage: option(Debugger.Types.ScriptLanguage.t), /* The language of the script. */
        [@yojson.option]
        embedderName: option(string) /* The name the embedder supplied for this script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when virtual machine parses script. This event is also fired for all known and uncollected
       scripts upon enabling debugger. */
    module ScriptParsed = {
      [@deriving yojson]
      type result = {
        scriptId: Runtime.Types.ScriptId.t, /* Identifier of the script parsed. */
        url: string, /* URL or name of the script parsed (if any). */
        startLine: float, /* Line offset of the script within the resource with given URL (for script tags). */
        startColumn: float, /* Column offset of the script within the resource with given URL. */
        endLine: float, /* Last line of the script. */
        endColumn: float, /* Length of the last line of the script. */
        executionContextId: Runtime.Types.ExecutionContextId.t, /* Specifies script creation context. */
        hash: string, /* Content hash of the script. */
        [@yojson.option]
        executionContextAuxData: option(assoc), /* Embedder-specific auxiliary data. */
        [@yojson.option]
        isLiveEdit: option(bool), /* True, if this script is generated as a result of the live edit operation. */
        [@yojson.option]
        sourceMapURL: option(string), /* URL of source map associated with script (if any). */
        [@yojson.option]
        hasSourceURL: option(bool), /* True, if this script has sourceURL. */
        [@yojson.option]
        isModule: option(bool), /* True, if this script is ES6 module. */
        [@yojson.option]
        length: option(float), /* This script length. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript top stack frame of where the script parsed event was triggered if available. */
        [@yojson.option]
        codeOffset: option(float), /* If the scriptLanguage is WebAssembly, the code section offset in the module. */
        [@yojson.option]
        scriptLanguage: option(Debugger.Types.ScriptLanguage.t), /* The language of the script. */
        [@yojson.option]
        debugSymbols: option(Debugger.Types.DebugSymbols.t), /* If the scriptLanguage is WebASsembly, the source of debug symbols for the module. */
        [@yojson.option]
        embedderName: option(string) /* The name the embedder supplied for this script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and DOM: {
  module Types: {
    module rec NodeId: {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        backendNodeId: BackendNodeId.t /* No description provided */,
      };
    }
    and PseudoType: {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    }
    and ShadowRootType: {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    }
    and CompatibilityMode: {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    }
    and Node: {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {
        nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
        [@yojson.option]
        parentId: option(NodeId.t), /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        childNodeCount: option(float), /* Child count for `Container` nodes. */
        [@yojson.option]
        children: option(array(Node.t)), /* Child nodes of this node when requested with children. */
        [@yojson.option]
        attributes: option(array(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType`'s publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType`'s systemId. */
        [@yojson.option]
        internalSubset: option(string), /* `DocumentType`'s internalSubset. */
        [@yojson.option]
        xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
        [@yojson.option]
        name: option(string), /* `Attr`'s name. */
        [@yojson.option]
        value: option(string), /* `Attr`'s value. */
        [@yojson.option]
        pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
        [@yojson.option]
        shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements. */
        [@yojson.option]
        contentDocument: option(Node.t), /* Content document for frame owner elements. */
        [@yojson.option]
        shadowRoots: option(array(Node.t)), /* Shadow root list for given element host. */
        [@yojson.option]
        templateContent: option(Node.t), /* Content document fragment for template elements. */
        [@yojson.option]
        pseudoElements: option(array(Node.t)), /* Pseudo elements associated with this node. */
        [@yojson.option]
        importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        [@yojson.option]
        distributedNodes: option(array(BackendNode.t)), /* Distributed nodes for given insertion point. */
        [@yojson.option]
        isSVG: option(bool), /* Whether the node is SVG. */
        [@yojson.option]
        compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
      };
    }
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: float, /* The red component, in the [0-255] range. */
        g: float, /* The green component, in the [0-255] range. */
        b: float, /* The blue component, in the [0-255] range. */
        [@yojson.option]
        a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
      };
    }
    and Quad: {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(float);
    }
    and BoxModel: {
      /* Box model. */
      [@deriving yojson]
      type t = {
        content: Quad.t, /* Content box */
        padding: Quad.t, /* Padding box */
        border: Quad.t, /* Border box */
        margin: Quad.t, /* Margin box */
        width: float, /* Node width */
        height: float, /* Node height */
        [@yojson.option]
        shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
      };
    }
    and ShapeOutsideInfo: {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {
        bounds: Quad.t, /* Shape bounds */
        shape: array(string), /* Shape coordinate details */
        marginShape: array(string) /* Margin shape bounds */,
      };
    }
    and Rect: {
      /* Rectangle. */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate */
        y: float, /* Y coordinate */
        width: float, /* Rectangle width */
        height: float /* Rectangle height */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    };
  };

  module Events: {
    /* Fired when `Element`'s attribute is modified. */
    module AttributeModified: {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        name: string, /* Attribute name. */
        value: string /* Attribute value. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when `Element`'s attribute is removed. */
    module AttributeRemoved: {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        name: string /* A ttribute name. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Mirrors `DOMCharacterDataModified` event. */
    module CharacterDataModified: {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        characterData: string /* New text value. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when `Container`'s child node count has changed. */
    module ChildNodeCountUpdated: {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        childNodeCount: float /* New node count. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Mirrors `DOMNodeInserted` event. */
    module ChildNodeInserted: {
      [@deriving yojson]
      type result = {
        parentNodeId: Types.NodeId.t, /* Id of the node that has changed. */
        previousNodeId: Types.NodeId.t, /* If of the previous siblint. */
        node: Types.Node.t /* Inserted node data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Mirrors `DOMNodeRemoved` event. */
    module ChildNodeRemoved: {
      [@deriving yojson]
      type result = {
        parentNodeId: Types.NodeId.t, /* Parent id. */
        nodeId: Types.NodeId.t /* Id of the node that has been removed. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called when distribution is changed. */
    module DistributedNodesUpdated: {
      [@deriving yojson]
      type result = {
        insertionPointId: Types.NodeId.t, /* Insertion point where distributed nodes were updated. */
        distributedNodes: array(Types.BackendNode.t) /* Distributed nodes for given insertion point. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when `Document` has been totally updated. Node ids are no longer valid. */
    module DocumentUpdated: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when `Element`'s inline style is modified via a CSS property modification. */
    module InlineStyleInvalidated: {
      [@deriving yojson]
      type result = {
        nodeIds: array(Types.NodeId.t) /* Ids of the nodes for which the inline styles have been invalidated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called when a pseudo element is added to an element. */
    module PseudoElementAdded: {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Pseudo element's parent element id. */
        pseudoElement: Types.Node.t /* The added pseudo element. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called when a pseudo element is removed from an element. */
    module PseudoElementRemoved: {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Pseudo element's parent element id. */
        pseudoElementId: Types.NodeId.t /* The removed pseudo element id. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when backend wants to provide client with the missing DOM structure. This happens upon
       most of the calls requesting node ids. */
    module SetChildNodes: {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Parent node id to populate with children. */
        nodes: array(Types.Node.t) /* Child nodes array. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called when shadow root is popped from the element. */
    module ShadowRootPopped: {
      [@deriving yojson]
      type result = {
        hostId: Types.NodeId.t, /* Host element id. */
        rootId: Types.NodeId.t /* Shadow root id. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called when shadow root is pushed into the element. */
    module ShadowRootPushed: {
      [@deriving yojson]
      type result = {
        hostId: Types.NodeId.t, /* Host element id. */
        root: Types.Node.t /* Shadow root. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec NodeId: {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        backendNodeId: BackendNodeId.t /* No description provided */,
      };
    }
    and PseudoType: {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    }
    and ShadowRootType: {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    }
    and CompatibilityMode: {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    }
    and Node: {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {
        nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
        [@yojson.option]
        parentId: option(NodeId.t), /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        childNodeCount: option(float), /* Child count for `Container` nodes. */
        [@yojson.option]
        children: option(array(Node.t)), /* Child nodes of this node when requested with children. */
        [@yojson.option]
        attributes: option(array(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType`'s publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType`'s systemId. */
        [@yojson.option]
        internalSubset: option(string), /* `DocumentType`'s internalSubset. */
        [@yojson.option]
        xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
        [@yojson.option]
        name: option(string), /* `Attr`'s name. */
        [@yojson.option]
        value: option(string), /* `Attr`'s value. */
        [@yojson.option]
        pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
        [@yojson.option]
        shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements. */
        [@yojson.option]
        contentDocument: option(Node.t), /* Content document for frame owner elements. */
        [@yojson.option]
        shadowRoots: option(array(Node.t)), /* Shadow root list for given element host. */
        [@yojson.option]
        templateContent: option(Node.t), /* Content document fragment for template elements. */
        [@yojson.option]
        pseudoElements: option(array(Node.t)), /* Pseudo elements associated with this node. */
        [@yojson.option]
        importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        [@yojson.option]
        distributedNodes: option(array(BackendNode.t)), /* Distributed nodes for given insertion point. */
        [@yojson.option]
        isSVG: option(bool), /* Whether the node is SVG. */
        [@yojson.option]
        compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
      };
    }
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: float, /* The red component, in the [0-255] range. */
        g: float, /* The green component, in the [0-255] range. */
        b: float, /* The blue component, in the [0-255] range. */
        [@yojson.option]
        a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
      };
    }
    and Quad: {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(float);
    }
    and BoxModel: {
      /* Box model. */
      [@deriving yojson]
      type t = {
        content: Quad.t, /* Content box */
        padding: Quad.t, /* Padding box */
        border: Quad.t, /* Border box */
        margin: Quad.t, /* Margin box */
        width: float, /* Node width */
        height: float, /* Node height */
        [@yojson.option]
        shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
      };
    }
    and ShapeOutsideInfo: {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {
        bounds: Quad.t, /* Shape bounds */
        shape: array(string), /* Shape coordinate details */
        marginShape: array(string) /* Margin shape bounds */,
      };
    }
    and Rect: {
      /* Rectangle. */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate */
        y: float, /* Y coordinate */
        width: float, /* Rectangle width */
        height: float /* Rectangle height */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    };
  } = {
    module rec NodeId: {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = float;
    }
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        backendNodeId: BackendNodeId.t /* No description provided */,
      };
    } = {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        backendNodeId: BackendNodeId.t /* No description provided */,
      };
    }
    and PseudoType: {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    }
    and ShadowRootType: {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    }
    and CompatibilityMode: {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    }
    and Node: {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {
        nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
        [@yojson.option]
        parentId: option(NodeId.t), /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        childNodeCount: option(float), /* Child count for `Container` nodes. */
        [@yojson.option]
        children: option(array(Node.t)), /* Child nodes of this node when requested with children. */
        [@yojson.option]
        attributes: option(array(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType`'s publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType`'s systemId. */
        [@yojson.option]
        internalSubset: option(string), /* `DocumentType`'s internalSubset. */
        [@yojson.option]
        xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
        [@yojson.option]
        name: option(string), /* `Attr`'s name. */
        [@yojson.option]
        value: option(string), /* `Attr`'s value. */
        [@yojson.option]
        pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
        [@yojson.option]
        shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements. */
        [@yojson.option]
        contentDocument: option(Node.t), /* Content document for frame owner elements. */
        [@yojson.option]
        shadowRoots: option(array(Node.t)), /* Shadow root list for given element host. */
        [@yojson.option]
        templateContent: option(Node.t), /* Content document fragment for template elements. */
        [@yojson.option]
        pseudoElements: option(array(Node.t)), /* Pseudo elements associated with this node. */
        [@yojson.option]
        importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        [@yojson.option]
        distributedNodes: option(array(BackendNode.t)), /* Distributed nodes for given insertion point. */
        [@yojson.option]
        isSVG: option(bool), /* Whether the node is SVG. */
        [@yojson.option]
        compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
      };
    } = {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {
        nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
        [@yojson.option]
        parentId: option(NodeId.t), /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        childNodeCount: option(float), /* Child count for `Container` nodes. */
        [@yojson.option]
        children: option(array(Node.t)), /* Child nodes of this node when requested with children. */
        [@yojson.option]
        attributes: option(array(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType`'s publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType`'s systemId. */
        [@yojson.option]
        internalSubset: option(string), /* `DocumentType`'s internalSubset. */
        [@yojson.option]
        xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
        [@yojson.option]
        name: option(string), /* `Attr`'s name. */
        [@yojson.option]
        value: option(string), /* `Attr`'s value. */
        [@yojson.option]
        pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
        [@yojson.option]
        shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements. */
        [@yojson.option]
        contentDocument: option(Node.t), /* Content document for frame owner elements. */
        [@yojson.option]
        shadowRoots: option(array(Node.t)), /* Shadow root list for given element host. */
        [@yojson.option]
        templateContent: option(Node.t), /* Content document fragment for template elements. */
        [@yojson.option]
        pseudoElements: option(array(Node.t)), /* Pseudo elements associated with this node. */
        [@yojson.option]
        importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        [@yojson.option]
        distributedNodes: option(array(BackendNode.t)), /* Distributed nodes for given insertion point. */
        [@yojson.option]
        isSVG: option(bool), /* Whether the node is SVG. */
        [@yojson.option]
        compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
      };
    }
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: float, /* The red component, in the [0-255] range. */
        g: float, /* The green component, in the [0-255] range. */
        b: float, /* The blue component, in the [0-255] range. */
        [@yojson.option]
        a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
      };
    } = {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: float, /* The red component, in the [0-255] range. */
        g: float, /* The green component, in the [0-255] range. */
        b: float, /* The blue component, in the [0-255] range. */
        [@yojson.option]
        a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
      };
    }
    and Quad: {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(float);
    } = {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(float);
    }
    and BoxModel: {
      /* Box model. */
      [@deriving yojson]
      type t = {
        content: Quad.t, /* Content box */
        padding: Quad.t, /* Padding box */
        border: Quad.t, /* Border box */
        margin: Quad.t, /* Margin box */
        width: float, /* Node width */
        height: float, /* Node height */
        [@yojson.option]
        shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
      };
    } = {
      /* Box model. */
      [@deriving yojson]
      type t = {
        content: Quad.t, /* Content box */
        padding: Quad.t, /* Padding box */
        border: Quad.t, /* Border box */
        margin: Quad.t, /* Margin box */
        width: float, /* Node width */
        height: float, /* Node height */
        [@yojson.option]
        shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
      };
    }
    and ShapeOutsideInfo: {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {
        bounds: Quad.t, /* Shape bounds */
        shape: array(string), /* Shape coordinate details */
        marginShape: array(string) /* Margin shape bounds */,
      };
    } = {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {
        bounds: Quad.t, /* Shape bounds */
        shape: array(string), /* Shape coordinate details */
        marginShape: array(string) /* Margin shape bounds */,
      };
    }
    and Rect: {
      /* Rectangle. */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate */
        y: float, /* Y coordinate */
        width: float, /* Rectangle width */
        height: float /* Rectangle height */,
      };
    } = {
      /* Rectangle. */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate */
        y: float, /* Y coordinate */
        width: float, /* Rectangle width */
        height: float /* Rectangle height */,
      };
    }
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    };
  };

  module Events = {
    /* Fired when `Element`'s attribute is modified. */
    module AttributeModified = {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        name: string, /* Attribute name. */
        value: string /* Attribute value. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when `Element`'s attribute is removed. */
    module AttributeRemoved = {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        name: string /* A ttribute name. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Mirrors `DOMCharacterDataModified` event. */
    module CharacterDataModified = {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        characterData: string /* New text value. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when `Container`'s child node count has changed. */
    module ChildNodeCountUpdated = {
      [@deriving yojson]
      type result = {
        nodeId: Types.NodeId.t, /* Id of the node that has changed. */
        childNodeCount: float /* New node count. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Mirrors `DOMNodeInserted` event. */
    module ChildNodeInserted = {
      [@deriving yojson]
      type result = {
        parentNodeId: Types.NodeId.t, /* Id of the node that has changed. */
        previousNodeId: Types.NodeId.t, /* If of the previous siblint. */
        node: Types.Node.t /* Inserted node data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Mirrors `DOMNodeRemoved` event. */
    module ChildNodeRemoved = {
      [@deriving yojson]
      type result = {
        parentNodeId: Types.NodeId.t, /* Parent id. */
        nodeId: Types.NodeId.t /* Id of the node that has been removed. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called when distribution is changed. */
    module DistributedNodesUpdated = {
      [@deriving yojson]
      type result = {
        insertionPointId: Types.NodeId.t, /* Insertion point where distributed nodes were updated. */
        distributedNodes: array(Types.BackendNode.t) /* Distributed nodes for given insertion point. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when `Document` has been totally updated. Node ids are no longer valid. */
    module DocumentUpdated = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when `Element`'s inline style is modified via a CSS property modification. */
    module InlineStyleInvalidated = {
      [@deriving yojson]
      type result = {
        nodeIds: array(Types.NodeId.t) /* Ids of the nodes for which the inline styles have been invalidated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called when a pseudo element is added to an element. */
    module PseudoElementAdded = {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Pseudo element's parent element id. */
        pseudoElement: Types.Node.t /* The added pseudo element. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called when a pseudo element is removed from an element. */
    module PseudoElementRemoved = {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Pseudo element's parent element id. */
        pseudoElementId: Types.NodeId.t /* The removed pseudo element id. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when backend wants to provide client with the missing DOM structure. This happens upon
       most of the calls requesting node ids. */
    module SetChildNodes = {
      [@deriving yojson]
      type result = {
        parentId: Types.NodeId.t, /* Parent node id to populate with children. */
        nodes: array(Types.Node.t) /* Child nodes array. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called when shadow root is popped from the element. */
    module ShadowRootPopped = {
      [@deriving yojson]
      type result = {
        hostId: Types.NodeId.t, /* Host element id. */
        rootId: Types.NodeId.t /* Shadow root id. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called when shadow root is pushed into the element. */
    module ShadowRootPushed = {
      [@deriving yojson]
      type result = {
        hostId: Types.NodeId.t, /* Host element id. */
        root: Types.Node.t /* Shadow root. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and DOMDebugger: {
  module Types: {
    module rec DOMBreakpointType: {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    }
    and CSPViolationType: {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    }
    and EventListener: {
      /* Object event listener. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: float, /* Line number in the script (0-based). */
        columnNumber: float, /* Column number in the script (0-based). */
        [@yojson.option]
        handler: option(Runtime.Types.RemoteObject.t), /* Event handler function value. */
        [@yojson.option]
        originalHandler: option(Runtime.Types.RemoteObject.t), /* Event original handler function value. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t) /* Node the listener is added to (if any). */,
      };
    };
  };
} = {
  module Types: {
    module rec DOMBreakpointType: {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    }
    and CSPViolationType: {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    }
    and EventListener: {
      /* Object event listener. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: float, /* Line number in the script (0-based). */
        columnNumber: float, /* Column number in the script (0-based). */
        [@yojson.option]
        handler: option(Runtime.Types.RemoteObject.t), /* Event handler function value. */
        [@yojson.option]
        originalHandler: option(Runtime.Types.RemoteObject.t), /* Event original handler function value. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t) /* Node the listener is added to (if any). */,
      };
    };
  } = {
    module rec DOMBreakpointType: {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    }
    and CSPViolationType: {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    }
    and EventListener: {
      /* Object event listener. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: float, /* Line number in the script (0-based). */
        columnNumber: float, /* Column number in the script (0-based). */
        [@yojson.option]
        handler: option(Runtime.Types.RemoteObject.t), /* Event handler function value. */
        [@yojson.option]
        originalHandler: option(Runtime.Types.RemoteObject.t), /* Event original handler function value. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t) /* Node the listener is added to (if any). */,
      };
    } = {
      /* Object event listener. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: float, /* Line number in the script (0-based). */
        columnNumber: float, /* Column number in the script (0-based). */
        [@yojson.option]
        handler: option(Runtime.Types.RemoteObject.t), /* Event handler function value. */
        [@yojson.option]
        originalHandler: option(Runtime.Types.RemoteObject.t), /* Event original handler function value. */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t) /* Node the listener is added to (if any). */,
      };
    };
  };
}
and DOMSnapshot: {
  module Types: {
    module rec DOMNode: {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        textValue: option(string), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        childNodeIndexes: option(array(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        [@yojson.option]
        attributes: option(array(NameValue.t)), /* Attributes of an `Element` node. */
        [@yojson.option]
        pseudoElementIndexes: option(array(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
        [@yojson.option]
        documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType` node's publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType` node's systemId. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
        [@yojson.option]
        contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        pseudoType: option(DOM.Types.PseudoType.t), /* Type of a pseudo element node. */
        [@yojson.option]
        shadowRootType: option(DOM.Types.ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        eventListeners: option(array(DOMDebugger.Types.EventListener.t)), /* Details of the node's event listeners, if any. */
        [@yojson.option]
        currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(string), /* The url of the script (if any) that generates this node. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
        [@yojson.option]
        scrollOffsetY: option(float) /* No description provided */,
      };
    }
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    }
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        [@yojson.option]
        layoutText: option(string), /* Contents of the LayoutText, if any. */
        [@yojson.option]
        inlineTextNodes: option(array(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
        [@yojson.option]
        styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
        [@yojson.option]
        paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        [@yojson.option]
        isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
      };
    }
    and ComputedStyle: {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {
        properties: array(NameValue.t) /* Name/value pairs of computed style properties. */,
      };
    }
    and NameValue: {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {
        name: string, /* Attribute/property name. */
        value: string /* Attribute/property value. */,
      };
    }
    and StringIndex: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = float;
    }
    and ArrayOfStrings: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(StringIndex.t);
    }
    and RareStringData: {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    }
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(float) /* No description provided */};
    }
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(float) /* No description provided */,
      };
    }
    and Rectangle: {
      /* No description provided */
      [@deriving yojson]
      type t = array(float);
    }
    and DocumentSnapshot: {
      /* Document snapshot. */
      [@deriving yojson]
      type t = {
        documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
        title: StringIndex.t, /* Document title. */
        baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: StringIndex.t, /* Contains the document's content language. */
        encodingName: StringIndex.t, /* Contains the document's character set encoding. */
        publicId: StringIndex.t, /* `DocumentType` node's publicId. */
        systemId: StringIndex.t, /* `DocumentType` node's systemId. */
        frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
        nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
        layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
        textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Horizontal scroll offset. */
        [@yojson.option]
        scrollOffsetY: option(float), /* Vertical scroll offset. */
        [@yojson.option]
        contentWidth: option(float), /* Document content width. */
        [@yojson.option]
        contentHeight: option(float) /* Document content height. */,
      };
    }
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        parentIndex: option(array(float)), /* Parent node index. */
        [@yojson.option]
        nodeType: option(array(float)), /* `Node`'s nodeType. */
        [@yojson.option]
        nodeName: option(array(StringIndex.t)), /* `Node`'s nodeName. */
        [@yojson.option]
        nodeValue: option(array(StringIndex.t)), /* `Node`'s nodeValue. */
        [@yojson.option]
        backendNodeId: option(array(DOM.Types.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        attributes: option(array(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
        [@yojson.option]
        textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
        [@yojson.option]
        contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
        [@yojson.option]
        pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
        [@yojson.option]
        isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
      };
    }
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        [@yojson.option]
        paintOrders: option(array(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        [@yojson.option]
        offsetRects: option(array(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        scrollRects: option(array(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        clientRects: option(array(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        blendedBackgroundColors: option(array(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
        [@yojson.option]
        textColorOpacities: option(array(float)) /* The list of computed text opacities. */,
      };
    }
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(float), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    };
  };
} = {
  module Types: {
    module rec DOMNode: {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        textValue: option(string), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        childNodeIndexes: option(array(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        [@yojson.option]
        attributes: option(array(NameValue.t)), /* Attributes of an `Element` node. */
        [@yojson.option]
        pseudoElementIndexes: option(array(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
        [@yojson.option]
        documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType` node's publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType` node's systemId. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
        [@yojson.option]
        contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        pseudoType: option(DOM.Types.PseudoType.t), /* Type of a pseudo element node. */
        [@yojson.option]
        shadowRootType: option(DOM.Types.ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        eventListeners: option(array(DOMDebugger.Types.EventListener.t)), /* Details of the node's event listeners, if any. */
        [@yojson.option]
        currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(string), /* The url of the script (if any) that generates this node. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
        [@yojson.option]
        scrollOffsetY: option(float) /* No description provided */,
      };
    }
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    }
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        [@yojson.option]
        layoutText: option(string), /* Contents of the LayoutText, if any. */
        [@yojson.option]
        inlineTextNodes: option(array(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
        [@yojson.option]
        styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
        [@yojson.option]
        paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        [@yojson.option]
        isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
      };
    }
    and ComputedStyle: {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {
        properties: array(NameValue.t) /* Name/value pairs of computed style properties. */,
      };
    }
    and NameValue: {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {
        name: string, /* Attribute/property name. */
        value: string /* Attribute/property value. */,
      };
    }
    and StringIndex: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = float;
    }
    and ArrayOfStrings: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(StringIndex.t);
    }
    and RareStringData: {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    }
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(float) /* No description provided */};
    }
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(float) /* No description provided */,
      };
    }
    and Rectangle: {
      /* No description provided */
      [@deriving yojson]
      type t = array(float);
    }
    and DocumentSnapshot: {
      /* Document snapshot. */
      [@deriving yojson]
      type t = {
        documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
        title: StringIndex.t, /* Document title. */
        baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: StringIndex.t, /* Contains the document's content language. */
        encodingName: StringIndex.t, /* Contains the document's character set encoding. */
        publicId: StringIndex.t, /* `DocumentType` node's publicId. */
        systemId: StringIndex.t, /* `DocumentType` node's systemId. */
        frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
        nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
        layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
        textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Horizontal scroll offset. */
        [@yojson.option]
        scrollOffsetY: option(float), /* Vertical scroll offset. */
        [@yojson.option]
        contentWidth: option(float), /* Document content width. */
        [@yojson.option]
        contentHeight: option(float) /* Document content height. */,
      };
    }
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        parentIndex: option(array(float)), /* Parent node index. */
        [@yojson.option]
        nodeType: option(array(float)), /* `Node`'s nodeType. */
        [@yojson.option]
        nodeName: option(array(StringIndex.t)), /* `Node`'s nodeName. */
        [@yojson.option]
        nodeValue: option(array(StringIndex.t)), /* `Node`'s nodeValue. */
        [@yojson.option]
        backendNodeId: option(array(DOM.Types.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        attributes: option(array(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
        [@yojson.option]
        textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
        [@yojson.option]
        contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
        [@yojson.option]
        pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
        [@yojson.option]
        isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
      };
    }
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        [@yojson.option]
        paintOrders: option(array(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        [@yojson.option]
        offsetRects: option(array(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        scrollRects: option(array(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        clientRects: option(array(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        blendedBackgroundColors: option(array(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
        [@yojson.option]
        textColorOpacities: option(array(float)) /* The list of computed text opacities. */,
      };
    }
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(float), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    };
  } = {
    module rec DOMNode: {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        textValue: option(string), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        childNodeIndexes: option(array(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        [@yojson.option]
        attributes: option(array(NameValue.t)), /* Attributes of an `Element` node. */
        [@yojson.option]
        pseudoElementIndexes: option(array(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
        [@yojson.option]
        documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType` node's publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType` node's systemId. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
        [@yojson.option]
        contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        pseudoType: option(DOM.Types.PseudoType.t), /* Type of a pseudo element node. */
        [@yojson.option]
        shadowRootType: option(DOM.Types.ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        eventListeners: option(array(DOMDebugger.Types.EventListener.t)), /* Details of the node's event listeners, if any. */
        [@yojson.option]
        currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(string), /* The url of the script (if any) that generates this node. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
        [@yojson.option]
        scrollOffsetY: option(float) /* No description provided */,
      };
    } = {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: float, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        [@yojson.option]
        textValue: option(string), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        childNodeIndexes: option(array(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        [@yojson.option]
        attributes: option(array(NameValue.t)), /* Attributes of an `Element` node. */
        [@yojson.option]
        pseudoElementIndexes: option(array(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
        [@yojson.option]
        baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        [@yojson.option]
        contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
        [@yojson.option]
        documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
        [@yojson.option]
        publicId: option(string), /* `DocumentType` node's publicId. */
        [@yojson.option]
        systemId: option(string), /* `DocumentType` node's systemId. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
        [@yojson.option]
        contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        [@yojson.option]
        pseudoType: option(DOM.Types.PseudoType.t), /* Type of a pseudo element node. */
        [@yojson.option]
        shadowRootType: option(DOM.Types.ShadowRootType.t), /* Shadow root type. */
        [@yojson.option]
        isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        eventListeners: option(array(DOMDebugger.Types.EventListener.t)), /* Details of the node's event listeners, if any. */
        [@yojson.option]
        currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(string), /* The url of the script (if any) that generates this node. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
        [@yojson.option]
        scrollOffsetY: option(float) /* No description provided */,
      };
    }
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    } = {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    }
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        [@yojson.option]
        layoutText: option(string), /* Contents of the LayoutText, if any. */
        [@yojson.option]
        inlineTextNodes: option(array(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
        [@yojson.option]
        styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
        [@yojson.option]
        paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        [@yojson.option]
        isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
      };
    } = {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        [@yojson.option]
        layoutText: option(string), /* Contents of the LayoutText, if any. */
        [@yojson.option]
        inlineTextNodes: option(array(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
        [@yojson.option]
        styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
        [@yojson.option]
        paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        [@yojson.option]
        isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
      };
    }
    and ComputedStyle: {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {
        properties: array(NameValue.t) /* Name/value pairs of computed style properties. */,
      };
    } = {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {
        properties: array(NameValue.t) /* Name/value pairs of computed style properties. */,
      };
    }
    and NameValue: {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {
        name: string, /* Attribute/property name. */
        value: string /* Attribute/property value. */,
      };
    } = {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {
        name: string, /* Attribute/property name. */
        value: string /* Attribute/property value. */,
      };
    }
    and StringIndex: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = float;
    }
    and ArrayOfStrings: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(StringIndex.t);
    } = {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(StringIndex.t);
    }
    and RareStringData: {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    } = {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    }
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(float) /* No description provided */};
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(float) /* No description provided */};
    }
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(float) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(float), /* No description provided */
        value: array(float) /* No description provided */,
      };
    }
    and Rectangle: {
      /* No description provided */
      [@deriving yojson]
      type t = array(float);
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = array(float);
    }
    and DocumentSnapshot: {
      /* Document snapshot. */
      [@deriving yojson]
      type t = {
        documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
        title: StringIndex.t, /* Document title. */
        baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: StringIndex.t, /* Contains the document's content language. */
        encodingName: StringIndex.t, /* Contains the document's character set encoding. */
        publicId: StringIndex.t, /* `DocumentType` node's publicId. */
        systemId: StringIndex.t, /* `DocumentType` node's systemId. */
        frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
        nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
        layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
        textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Horizontal scroll offset. */
        [@yojson.option]
        scrollOffsetY: option(float), /* Vertical scroll offset. */
        [@yojson.option]
        contentWidth: option(float), /* Document content width. */
        [@yojson.option]
        contentHeight: option(float) /* Document content height. */,
      };
    } = {
      /* Document snapshot. */
      [@deriving yojson]
      type t = {
        documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
        title: StringIndex.t, /* Document title. */
        baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: StringIndex.t, /* Contains the document's content language. */
        encodingName: StringIndex.t, /* Contains the document's character set encoding. */
        publicId: StringIndex.t, /* `DocumentType` node's publicId. */
        systemId: StringIndex.t, /* `DocumentType` node's systemId. */
        frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
        nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
        layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
        textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
        [@yojson.option]
        scrollOffsetX: option(float), /* Horizontal scroll offset. */
        [@yojson.option]
        scrollOffsetY: option(float), /* Vertical scroll offset. */
        [@yojson.option]
        contentWidth: option(float), /* Document content width. */
        [@yojson.option]
        contentHeight: option(float) /* Document content height. */,
      };
    }
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        parentIndex: option(array(float)), /* Parent node index. */
        [@yojson.option]
        nodeType: option(array(float)), /* `Node`'s nodeType. */
        [@yojson.option]
        nodeName: option(array(StringIndex.t)), /* `Node`'s nodeName. */
        [@yojson.option]
        nodeValue: option(array(StringIndex.t)), /* `Node`'s nodeValue. */
        [@yojson.option]
        backendNodeId: option(array(DOM.Types.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        attributes: option(array(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
        [@yojson.option]
        textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
        [@yojson.option]
        contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
        [@yojson.option]
        pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
        [@yojson.option]
        isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
      };
    } = {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        parentIndex: option(array(float)), /* Parent node index. */
        [@yojson.option]
        nodeType: option(array(float)), /* `Node`'s nodeType. */
        [@yojson.option]
        nodeName: option(array(StringIndex.t)), /* `Node`'s nodeName. */
        [@yojson.option]
        nodeValue: option(array(StringIndex.t)), /* `Node`'s nodeValue. */
        [@yojson.option]
        backendNodeId: option(array(DOM.Types.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        [@yojson.option]
        attributes: option(array(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
        [@yojson.option]
        textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
        [@yojson.option]
        inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
        [@yojson.option]
        inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        [@yojson.option]
        optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
        [@yojson.option]
        contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
        [@yojson.option]
        pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
        [@yojson.option]
        isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        [@yojson.option]
        currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
        [@yojson.option]
        originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
      };
    }
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        [@yojson.option]
        paintOrders: option(array(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        [@yojson.option]
        offsetRects: option(array(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        scrollRects: option(array(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        clientRects: option(array(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        blendedBackgroundColors: option(array(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
        [@yojson.option]
        textColorOpacities: option(array(float)) /* The list of computed text opacities. */,
      };
    } = {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        [@yojson.option]
        paintOrders: option(array(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        [@yojson.option]
        offsetRects: option(array(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        scrollRects: option(array(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        clientRects: option(array(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        [@yojson.option]
        blendedBackgroundColors: option(array(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
        [@yojson.option]
        textColorOpacities: option(array(float)) /* The list of computed text opacities. */,
      };
    }
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(float), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    } = {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(float), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    };
  };
}
and DOMStorage: {
  module Types: {
    module rec StorageId: {
      /* DOM Storage identifier. */
      [@deriving yojson]
      type t = {
        securityOrigin: string, /* Security origin for the storage. */
        isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
      };
    }
    and Item: {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(string);
    };
  };

  module Events: {
    /* No description provided */
    module DomStorageItemAdded: {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string, /* No description provided */
        newValue: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module DomStorageItemRemoved: {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module DomStorageItemUpdated: {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string, /* No description provided */
        oldValue: string, /* No description provided */
        newValue: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module DomStorageItemsCleared: {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec StorageId: {
      /* DOM Storage identifier. */
      [@deriving yojson]
      type t = {
        securityOrigin: string, /* Security origin for the storage. */
        isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
      };
    }
    and Item: {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(string);
    };
  } = {
    module rec StorageId: {
      /* DOM Storage identifier. */
      [@deriving yojson]
      type t = {
        securityOrigin: string, /* Security origin for the storage. */
        isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
      };
    } = {
      /* DOM Storage identifier. */
      [@deriving yojson]
      type t = {
        securityOrigin: string, /* Security origin for the storage. */
        isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
      };
    }
    and Item: {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(string);
    } = {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(string);
    };
  };

  module Events = {
    /* No description provided */
    module DomStorageItemAdded = {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string, /* No description provided */
        newValue: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module DomStorageItemRemoved = {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module DomStorageItemUpdated = {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t, /* No description provided */
        key: string, /* No description provided */
        oldValue: string, /* No description provided */
        newValue: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module DomStorageItemsCleared = {
      [@deriving yojson]
      type result = {
        storageId: Types.StorageId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Database: {
  module Types: {
    module rec DatabaseId: {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    }
    and Database: {
      /* Database object. */
      [@deriving yojson]
      type t = {
        id: DatabaseId.t, /* Database ID. */
        domain: string, /* Database domain. */
        name: string, /* Database name. */
        version: string /* Database version. */,
      };
    }
    and Error: {
      /* Database error. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        code: float /* Error code. */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module AddDatabase: {
      [@deriving yojson]
      type result = {
        database: Types.Database.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec DatabaseId: {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    }
    and Database: {
      /* Database object. */
      [@deriving yojson]
      type t = {
        id: DatabaseId.t, /* Database ID. */
        domain: string, /* Database domain. */
        name: string, /* Database name. */
        version: string /* Database version. */,
      };
    }
    and Error: {
      /* Database error. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        code: float /* Error code. */,
      };
    };
  } = {
    module rec DatabaseId: {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    }
    and Database: {
      /* Database object. */
      [@deriving yojson]
      type t = {
        id: DatabaseId.t, /* Database ID. */
        domain: string, /* Database domain. */
        name: string, /* Database name. */
        version: string /* Database version. */,
      };
    } = {
      /* Database object. */
      [@deriving yojson]
      type t = {
        id: DatabaseId.t, /* Database ID. */
        domain: string, /* Database domain. */
        name: string, /* Database name. */
        version: string /* Database version. */,
      };
    }
    and Error: {
      /* Database error. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        code: float /* Error code. */,
      };
    } = {
      /* Database error. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        code: float /* Error code. */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module AddDatabase = {
      [@deriving yojson]
      type result = {
        database: Types.Database.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and DeviceOrientation: {} = {}
and Emulation: {
  module Types: {
    module rec ScreenOrientation: {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Orientation type. */
        angle: float /* Orientation angle. */,
      };
    }
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
      };
    }
    and MediaFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and VirtualTimePolicy: {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    }
    and UserAgentBrandVersion: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {
        brand: string, /* No description provided */
        version: string /* No description provided */,
      };
    }
    and UserAgentMetadata: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        brands: option(array(UserAgentBrandVersion.t)), /* No description provided */
        [@yojson.option]
        fullVersion: option(string), /* No description provided */
        platform: string, /* No description provided */
        platformVersion: string, /* No description provided */
        architecture: string, /* No description provided */
        model: string, /* No description provided */
        mobile: bool /* No description provided */,
      };
    }
    and DisabledImageType: {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events: {
    /* Notification sent after the virtual time budget for the current VirtualTimePolicy has run out. */
    module VirtualTimeBudgetExpired: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ScreenOrientation: {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Orientation type. */
        angle: float /* Orientation angle. */,
      };
    }
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
      };
    }
    and MediaFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and VirtualTimePolicy: {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    }
    and UserAgentBrandVersion: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {
        brand: string, /* No description provided */
        version: string /* No description provided */,
      };
    }
    and UserAgentMetadata: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        brands: option(array(UserAgentBrandVersion.t)), /* No description provided */
        [@yojson.option]
        fullVersion: option(string), /* No description provided */
        platform: string, /* No description provided */
        platformVersion: string, /* No description provided */
        architecture: string, /* No description provided */
        model: string, /* No description provided */
        mobile: bool /* No description provided */,
      };
    }
    and DisabledImageType: {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec ScreenOrientation: {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Orientation type. */
        angle: float /* Orientation angle. */,
      };
    } = {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Orientation type. */
        angle: float /* Orientation angle. */,
      };
    }
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
      };
    }
    and MediaFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and VirtualTimePolicy: {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    } = {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    }
    and UserAgentBrandVersion: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {
        brand: string, /* No description provided */
        version: string /* No description provided */,
      };
    } = {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {
        brand: string, /* No description provided */
        version: string /* No description provided */,
      };
    }
    and UserAgentMetadata: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        brands: option(array(UserAgentBrandVersion.t)), /* No description provided */
        [@yojson.option]
        fullVersion: option(string), /* No description provided */
        platform: string, /* No description provided */
        platformVersion: string, /* No description provided */
        architecture: string, /* No description provided */
        model: string, /* No description provided */
        mobile: bool /* No description provided */,
      };
    } = {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        brands: option(array(UserAgentBrandVersion.t)), /* No description provided */
        [@yojson.option]
        fullVersion: option(string), /* No description provided */
        platform: string, /* No description provided */
        platformVersion: string, /* No description provided */
        architecture: string, /* No description provided */
        model: string, /* No description provided */
        mobile: bool /* No description provided */,
      };
    }
    and DisabledImageType: {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events = {
    /* Notification sent after the virtual time budget for the current VirtualTimePolicy has run out. */
    module VirtualTimeBudgetExpired = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and HeadlessExperimental: {
  module Types: {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        format: option(string), /* Image compression format (defaults to png). */
        [@yojson.option]
        quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
      };
    };
  };

  module Events: {
    /* Issued when the target starts or stops needing BeginFrames.
       Deprecated. Issue beginFrame unconditionally instead and use result from
       beginFrame to detect whether the frames were suppressed. */
    module NeedsBeginFramesChanged: {
      [@deriving yojson]
      type result = {
        needsBeginFrames: bool /* True if BeginFrames are needed, false otherwise. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        format: option(string), /* Image compression format (defaults to png). */
        [@yojson.option]
        quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
      };
    };
  } = {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        format: option(string), /* Image compression format (defaults to png). */
        [@yojson.option]
        quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
      };
    } = {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        format: option(string), /* Image compression format (defaults to png). */
        [@yojson.option]
        quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
      };
    };
  };

  module Events = {
    /* Issued when the target starts or stops needing BeginFrames.
       Deprecated. Issue beginFrame unconditionally instead and use result from
       beginFrame to detect whether the frames were suppressed. */
    module NeedsBeginFramesChanged = {
      [@deriving yojson]
      type result = {
        needsBeginFrames: bool /* True if BeginFrames are needed, false otherwise. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and HeapProfiler: {
  module Types: {
    module rec HeapSnapshotObjectId: {
      /* Heap snapshot object id. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingHeapProfileNode: {
      /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
      [@deriving yojson]
      type t = {
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        selfSize: float, /* Allocations size in bytes for the node excluding children. */
        id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    }
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: float, /* Id of the corresponding profile tree node. */
        ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
      };
    }
    and SamplingHeapProfile: {
      /* Sampling profile. */
      [@deriving yojson]
      type t = {
        head: SamplingHeapProfileNode.t, /* No description provided */
        samples: array(SamplingHeapProfileSample.t) /* No description provided */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module AddHeapSnapshotChunk: {
      [@deriving yojson]
      type result = {chunk: string /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* If heap objects tracking has been started then backend may send update for one or more fragments */
    module HeapStatsUpdate: {
      [@deriving yojson]
      type result = {
        statsUpdate: array(float) /* An array of triplets. Each triplet describes a fragment. The first integer is the fragment
index, the second integer is a total count of objects for the fragment, the third integer is
a total size of the objects for the fragment. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* If heap objects tracking has been started then backend regularly sends a current value for last
       seen object id and corresponding timestamp. If the were changes in the heap since last event
       then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event. */
    module LastSeenObjectId: {
      [@deriving yojson]
      type result = {
        lastSeenObjectId: float, /* No description provided */
        timestamp: float /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module ReportHeapSnapshotProgress: {
      [@deriving yojson]
      type result = {
        [@key "done"]
        done_: float, /* No description provided */
        total: float, /* No description provided */
        [@yojson.option]
        finished: option(bool) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module ResetProfiles: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec HeapSnapshotObjectId: {
      /* Heap snapshot object id. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingHeapProfileNode: {
      /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
      [@deriving yojson]
      type t = {
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        selfSize: float, /* Allocations size in bytes for the node excluding children. */
        id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    }
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: float, /* Id of the corresponding profile tree node. */
        ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
      };
    }
    and SamplingHeapProfile: {
      /* Sampling profile. */
      [@deriving yojson]
      type t = {
        head: SamplingHeapProfileNode.t, /* No description provided */
        samples: array(SamplingHeapProfileSample.t) /* No description provided */,
      };
    };
  } = {
    module rec HeapSnapshotObjectId: {
      /* Heap snapshot object id. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Heap snapshot object id. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingHeapProfileNode: {
      /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
      [@deriving yojson]
      type t = {
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        selfSize: float, /* Allocations size in bytes for the node excluding children. */
        id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    } = {
      /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
      [@deriving yojson]
      type t = {
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        selfSize: float, /* Allocations size in bytes for the node excluding children. */
        id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    }
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: float, /* Id of the corresponding profile tree node. */
        ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
      };
    } = {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: float, /* Id of the corresponding profile tree node. */
        ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
      };
    }
    and SamplingHeapProfile: {
      /* Sampling profile. */
      [@deriving yojson]
      type t = {
        head: SamplingHeapProfileNode.t, /* No description provided */
        samples: array(SamplingHeapProfileSample.t) /* No description provided */,
      };
    } = {
      /* Sampling profile. */
      [@deriving yojson]
      type t = {
        head: SamplingHeapProfileNode.t, /* No description provided */
        samples: array(SamplingHeapProfileSample.t) /* No description provided */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module AddHeapSnapshotChunk = {
      [@deriving yojson]
      type result = {chunk: string /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* If heap objects tracking has been started then backend may send update for one or more fragments */
    module HeapStatsUpdate = {
      [@deriving yojson]
      type result = {
        statsUpdate: array(float) /* An array of triplets. Each triplet describes a fragment. The first integer is the fragment
index, the second integer is a total count of objects for the fragment, the third integer is
a total size of the objects for the fragment. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* If heap objects tracking has been started then backend regularly sends a current value for last
       seen object id and corresponding timestamp. If the were changes in the heap since last event
       then one or more heapStatsUpdate events will be sent before a new lastSeenObjectId event. */
    module LastSeenObjectId = {
      [@deriving yojson]
      type result = {
        lastSeenObjectId: float, /* No description provided */
        timestamp: float /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module ReportHeapSnapshotProgress = {
      [@deriving yojson]
      type result = {
        [@key "done"]
        done_: float, /* No description provided */
        total: float, /* No description provided */
        [@yojson.option]
        finished: option(bool) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module ResetProfiles = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and IO: {
  module Types: {
    module rec StreamHandle: {
      /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
         `&lt;uuid&gt` is an UUID of a Blob. */
      [@deriving yojson]
      type t = string;
    };
  };
} = {
  module Types: {
    module rec StreamHandle: {
      /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
         `&lt;uuid&gt` is an UUID of a Blob. */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec StreamHandle: {
      /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
         `&lt;uuid&gt` is an UUID of a Blob. */
      [@deriving yojson]
      type t = string;
    } = {
      /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
         `&lt;uuid&gt` is an UUID of a Blob. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and IndexedDB: {
  module Types: {
    module rec DatabaseWithObjectStores: {
      /* Database with an array of object stores. */
      [@deriving yojson]
      type t = {
        name: string, /* Database name. */
        version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
        objectStores: array(ObjectStore.t) /* Object stores in this database. */,
      };
    }
    and ObjectStore: {
      /* Object store. */
      [@deriving yojson]
      type t = {
        name: string, /* Object store name. */
        keyPath: KeyPath.t, /* Object store key path. */
        autoIncrement: bool, /* If true, object store has auto increment flag set. */
        indexes: array(ObjectStoreIndex.t) /* Indexes in this object store. */,
      };
    }
    and ObjectStoreIndex: {
      /* Object store index. */
      [@deriving yojson]
      type t = {
        name: string, /* Index name. */
        keyPath: KeyPath.t, /* Index key path. */
        unique: bool, /* If true, index is unique. */
        multiEntry: bool /* If true, index allows multiple entries for a key. */,
      };
    }
    and Key: {
      /* Key. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key type. */
        [@yojson.option]
        number: option(float), /* Number value. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        date: option(float), /* Date value. */
        [@yojson.option]
        array: option(array(Key.t)) /* Array value. */,
      };
    }
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        lower: option(Key.t), /* Lower bound. */
        [@yojson.option]
        upper: option(Key.t), /* Upper bound. */
        lowerOpen: bool, /* If true lower bound is open. */
        upperOpen: bool /* If true upper bound is open. */,
      };
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        key: Runtime.Types.RemoteObject.t, /* Key object. */
        primaryKey: Runtime.Types.RemoteObject.t, /* Primary key object. */
        value: Runtime.Types.RemoteObject.t /* Value object. */,
      };
    }
    and KeyPath: {
      /* Key path. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key path type. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        array: option(array(string)) /* Array value. */,
      };
    };
  };
} = {
  module Types: {
    module rec DatabaseWithObjectStores: {
      /* Database with an array of object stores. */
      [@deriving yojson]
      type t = {
        name: string, /* Database name. */
        version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
        objectStores: array(ObjectStore.t) /* Object stores in this database. */,
      };
    }
    and ObjectStore: {
      /* Object store. */
      [@deriving yojson]
      type t = {
        name: string, /* Object store name. */
        keyPath: KeyPath.t, /* Object store key path. */
        autoIncrement: bool, /* If true, object store has auto increment flag set. */
        indexes: array(ObjectStoreIndex.t) /* Indexes in this object store. */,
      };
    }
    and ObjectStoreIndex: {
      /* Object store index. */
      [@deriving yojson]
      type t = {
        name: string, /* Index name. */
        keyPath: KeyPath.t, /* Index key path. */
        unique: bool, /* If true, index is unique. */
        multiEntry: bool /* If true, index allows multiple entries for a key. */,
      };
    }
    and Key: {
      /* Key. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key type. */
        [@yojson.option]
        number: option(float), /* Number value. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        date: option(float), /* Date value. */
        [@yojson.option]
        array: option(array(Key.t)) /* Array value. */,
      };
    }
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        lower: option(Key.t), /* Lower bound. */
        [@yojson.option]
        upper: option(Key.t), /* Upper bound. */
        lowerOpen: bool, /* If true lower bound is open. */
        upperOpen: bool /* If true upper bound is open. */,
      };
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        key: Runtime.Types.RemoteObject.t, /* Key object. */
        primaryKey: Runtime.Types.RemoteObject.t, /* Primary key object. */
        value: Runtime.Types.RemoteObject.t /* Value object. */,
      };
    }
    and KeyPath: {
      /* Key path. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key path type. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        array: option(array(string)) /* Array value. */,
      };
    };
  } = {
    module rec DatabaseWithObjectStores: {
      /* Database with an array of object stores. */
      [@deriving yojson]
      type t = {
        name: string, /* Database name. */
        version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
        objectStores: array(ObjectStore.t) /* Object stores in this database. */,
      };
    } = {
      /* Database with an array of object stores. */
      [@deriving yojson]
      type t = {
        name: string, /* Database name. */
        version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
        objectStores: array(ObjectStore.t) /* Object stores in this database. */,
      };
    }
    and ObjectStore: {
      /* Object store. */
      [@deriving yojson]
      type t = {
        name: string, /* Object store name. */
        keyPath: KeyPath.t, /* Object store key path. */
        autoIncrement: bool, /* If true, object store has auto increment flag set. */
        indexes: array(ObjectStoreIndex.t) /* Indexes in this object store. */,
      };
    } = {
      /* Object store. */
      [@deriving yojson]
      type t = {
        name: string, /* Object store name. */
        keyPath: KeyPath.t, /* Object store key path. */
        autoIncrement: bool, /* If true, object store has auto increment flag set. */
        indexes: array(ObjectStoreIndex.t) /* Indexes in this object store. */,
      };
    }
    and ObjectStoreIndex: {
      /* Object store index. */
      [@deriving yojson]
      type t = {
        name: string, /* Index name. */
        keyPath: KeyPath.t, /* Index key path. */
        unique: bool, /* If true, index is unique. */
        multiEntry: bool /* If true, index allows multiple entries for a key. */,
      };
    } = {
      /* Object store index. */
      [@deriving yojson]
      type t = {
        name: string, /* Index name. */
        keyPath: KeyPath.t, /* Index key path. */
        unique: bool, /* If true, index is unique. */
        multiEntry: bool /* If true, index allows multiple entries for a key. */,
      };
    }
    and Key: {
      /* Key. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key type. */
        [@yojson.option]
        number: option(float), /* Number value. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        date: option(float), /* Date value. */
        [@yojson.option]
        array: option(array(Key.t)) /* Array value. */,
      };
    } = {
      /* Key. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key type. */
        [@yojson.option]
        number: option(float), /* Number value. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        date: option(float), /* Date value. */
        [@yojson.option]
        array: option(array(Key.t)) /* Array value. */,
      };
    }
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        lower: option(Key.t), /* Lower bound. */
        [@yojson.option]
        upper: option(Key.t), /* Upper bound. */
        lowerOpen: bool, /* If true lower bound is open. */
        upperOpen: bool /* If true upper bound is open. */,
      };
    } = {
      /* Key range. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        lower: option(Key.t), /* Lower bound. */
        [@yojson.option]
        upper: option(Key.t), /* Upper bound. */
        lowerOpen: bool, /* If true lower bound is open. */
        upperOpen: bool /* If true upper bound is open. */,
      };
    }
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        key: Runtime.Types.RemoteObject.t, /* Key object. */
        primaryKey: Runtime.Types.RemoteObject.t, /* Primary key object. */
        value: Runtime.Types.RemoteObject.t /* Value object. */,
      };
    } = {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        key: Runtime.Types.RemoteObject.t, /* Key object. */
        primaryKey: Runtime.Types.RemoteObject.t, /* Primary key object. */
        value: Runtime.Types.RemoteObject.t /* Value object. */,
      };
    }
    and KeyPath: {
      /* Key path. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key path type. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        array: option(array(string)) /* Array value. */,
      };
    } = {
      /* Key path. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Key path type. */
        [@yojson.option]
        string: option(string), /* String value. */
        [@yojson.option]
        array: option(array(string)) /* Array value. */,
      };
    };
  };
}
and Input: {
  module Types: {
    module rec TouchPoint: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@yojson.option]
        radiusX: option(float), /* X radius of the touch area (default: 1.0). */
        [@yojson.option]
        radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
        [@yojson.option]
        rotationAngle: option(float), /* Rotation angle (default: 0.0). */
        [@yojson.option]
        force: option(float), /* Force (default: 1.0). */
        [@yojson.option]
        tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        [@yojson.option]
        tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        [@yojson.option]
        tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        [@yojson.option]
        twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        [@yojson.option]
        id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
      };
    }
    and GestureSourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MouseButton: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and DragDataItem: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        mimeType: string, /* Mime type of the dragged data. */
        data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
        [@yojson.option]
        title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        [@yojson.option]
        baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    }
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
    };
  };

  module Events: {
    /* Emitted only when `Input.setInterceptDrags` is enabled. Use this data with `Input.dispatchDragEvent` to
       restore normal drag and drop behavior. */
    module DragIntercepted: {
      [@deriving yojson]
      type result = {data: Types.DragData.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec TouchPoint: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@yojson.option]
        radiusX: option(float), /* X radius of the touch area (default: 1.0). */
        [@yojson.option]
        radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
        [@yojson.option]
        rotationAngle: option(float), /* Rotation angle (default: 0.0). */
        [@yojson.option]
        force: option(float), /* Force (default: 1.0). */
        [@yojson.option]
        tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        [@yojson.option]
        tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        [@yojson.option]
        tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        [@yojson.option]
        twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        [@yojson.option]
        id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
      };
    }
    and GestureSourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MouseButton: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and DragDataItem: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        mimeType: string, /* Mime type of the dragged data. */
        data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
        [@yojson.option]
        title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        [@yojson.option]
        baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    }
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
    };
  } = {
    module rec TouchPoint: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@yojson.option]
        radiusX: option(float), /* X radius of the touch area (default: 1.0). */
        [@yojson.option]
        radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
        [@yojson.option]
        rotationAngle: option(float), /* Rotation angle (default: 0.0). */
        [@yojson.option]
        force: option(float), /* Force (default: 1.0). */
        [@yojson.option]
        tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        [@yojson.option]
        tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        [@yojson.option]
        tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        [@yojson.option]
        twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        [@yojson.option]
        id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
        y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
        [@yojson.option]
        radiusX: option(float), /* X radius of the touch area (default: 1.0). */
        [@yojson.option]
        radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
        [@yojson.option]
        rotationAngle: option(float), /* Rotation angle (default: 0.0). */
        [@yojson.option]
        force: option(float), /* Force (default: 1.0). */
        [@yojson.option]
        tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        [@yojson.option]
        tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        [@yojson.option]
        tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        [@yojson.option]
        twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        [@yojson.option]
        id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
      };
    }
    and GestureSourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MouseButton: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    } = {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and DragDataItem: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        mimeType: string, /* Mime type of the dragged data. */
        data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
        [@yojson.option]
        title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        [@yojson.option]
        baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        mimeType: string, /* Mime type of the dragged data. */
        data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
        [@yojson.option]
        title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        [@yojson.option]
        baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    }
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
    };
  };

  module Events = {
    /* Emitted only when `Input.setInterceptDrags` is enabled. Use this data with `Input.dispatchDragEvent` to
       restore normal drag and drop behavior. */
    module DragIntercepted = {
      [@deriving yojson]
      type result = {data: Types.DragData.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Inspector: {
  module Events: {
    /* Fired when remote debugging connection is about to be terminated. Contains detach reason. */
    module Detached: {
      [@deriving yojson]
      type result = {
        reason: string /* The reason why connection has been terminated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when debugging target has crashed */
    module TargetCrashed: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when debugging target has reloaded after crash */
    module TargetReloadedAfterCrash: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Events = {
    /* Fired when remote debugging connection is about to be terminated. Contains detach reason. */
    module Detached = {
      [@deriving yojson]
      type result = {
        reason: string /* The reason why connection has been terminated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when debugging target has crashed */
    module TargetCrashed = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when debugging target has reloaded after crash */
    module TargetReloadedAfterCrash = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and LayerTree: {
  module Types: {
    module rec LayerId: {
      /* Unique Layer identifier. */
      [@deriving yojson]
      type t = string;
    }
    and SnapshotId: {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ScrollRect: {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* Rectangle itself. */
        [@key "type"]
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    }
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        [@yojson.option]
        nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
        [@yojson.option]
        nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
      };
    }
    and PictureTile: {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {
        x: float, /* Offset from owning layer left boundary */
        y: float, /* Offset from owning layer top boundary */
        picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
      };
    }
    and Layer: {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {
        layerId: LayerId.t, /* The unique id for this layer. */
        [@yojson.option]
        parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        [@yojson.option]
        transform: option(array(float)), /* Transformation matrix for layer, default is identity matrix */
        [@yojson.option]
        anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
        [@yojson.option]
        anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
        [@yojson.option]
        anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
        paintCount: float, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        [@yojson.option]
        invisible: option(bool), /* Set if layer is not visible. */
        [@yojson.option]
        scrollRects: option(array(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
        [@yojson.option]
        stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
      };
    }
    and PaintProfile: {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
    };
  };

  module Events: {
    /* No description provided */
    module LayerPainted: {
      [@deriving yojson]
      type result = {
        layerId: Types.LayerId.t, /* The id of the painted layer. */
        clip: DOM.Types.Rect.t /* Clip rectangle. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module LayerTreeDidChange: {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        layers: option(array(Types.Layer.t)) /* Layer tree, absent if not in the comspositing mode. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec LayerId: {
      /* Unique Layer identifier. */
      [@deriving yojson]
      type t = string;
    }
    and SnapshotId: {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ScrollRect: {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* Rectangle itself. */
        [@key "type"]
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    }
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        [@yojson.option]
        nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
        [@yojson.option]
        nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
      };
    }
    and PictureTile: {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {
        x: float, /* Offset from owning layer left boundary */
        y: float, /* Offset from owning layer top boundary */
        picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
      };
    }
    and Layer: {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {
        layerId: LayerId.t, /* The unique id for this layer. */
        [@yojson.option]
        parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        [@yojson.option]
        transform: option(array(float)), /* Transformation matrix for layer, default is identity matrix */
        [@yojson.option]
        anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
        [@yojson.option]
        anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
        [@yojson.option]
        anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
        paintCount: float, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        [@yojson.option]
        invisible: option(bool), /* Set if layer is not visible. */
        [@yojson.option]
        scrollRects: option(array(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
        [@yojson.option]
        stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
      };
    }
    and PaintProfile: {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
    };
  } = {
    module rec LayerId: {
      /* Unique Layer identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique Layer identifier. */
      [@deriving yojson]
      type t = string;
    }
    and SnapshotId: {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ScrollRect: {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* Rectangle itself. */
        [@key "type"]
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    } = {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* Rectangle itself. */
        [@key "type"]
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    }
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        [@yojson.option]
        nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
        [@yojson.option]
        nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
      };
    } = {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        [@yojson.option]
        nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
        [@yojson.option]
        nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
      };
    }
    and PictureTile: {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {
        x: float, /* Offset from owning layer left boundary */
        y: float, /* Offset from owning layer top boundary */
        picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
      };
    } = {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {
        x: float, /* Offset from owning layer left boundary */
        y: float, /* Offset from owning layer top boundary */
        picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
      };
    }
    and Layer: {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {
        layerId: LayerId.t, /* The unique id for this layer. */
        [@yojson.option]
        parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        [@yojson.option]
        transform: option(array(float)), /* Transformation matrix for layer, default is identity matrix */
        [@yojson.option]
        anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
        [@yojson.option]
        anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
        [@yojson.option]
        anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
        paintCount: float, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        [@yojson.option]
        invisible: option(bool), /* Set if layer is not visible. */
        [@yojson.option]
        scrollRects: option(array(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
        [@yojson.option]
        stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
      };
    } = {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {
        layerId: LayerId.t, /* The unique id for this layer. */
        [@yojson.option]
        parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
        [@yojson.option]
        backendNodeId: option(DOM.Types.BackendNodeId.t), /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        [@yojson.option]
        transform: option(array(float)), /* Transformation matrix for layer, default is identity matrix */
        [@yojson.option]
        anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
        [@yojson.option]
        anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
        [@yojson.option]
        anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
        paintCount: float, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        [@yojson.option]
        invisible: option(bool), /* Set if layer is not visible. */
        [@yojson.option]
        scrollRects: option(array(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
        [@yojson.option]
        stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
      };
    }
    and PaintProfile: {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
    } = {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
    };
  };

  module Events = {
    /* No description provided */
    module LayerPainted = {
      [@deriving yojson]
      type result = {
        layerId: Types.LayerId.t, /* The id of the painted layer. */
        clip: DOM.Types.Rect.t /* Clip rectangle. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module LayerTreeDidChange = {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        layers: option(array(Types.Layer.t)) /* Layer tree, absent if not in the comspositing mode. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Log: {
  module Types: {
    module rec LogEntry: {
      /* Log entry. */
      [@deriving yojson]
      type t = {
        source: string, /* Log entry source. */
        level: string, /* Log entry severity. */
        text: string, /* Logged text. */
        timestamp: Runtime.Types.Timestamp.t, /* Timestamp when this entry was added. */
        [@yojson.option]
        url: option(string), /* URL of the resource if known. */
        [@yojson.option]
        lineNumber: option(float), /* Line number in the resource. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript stack trace. */
        [@yojson.option]
        networkRequestId: option(Network.Types.RequestId.t), /* Identifier of the network request associated with this entry. */
        [@yojson.option]
        workerId: option(string), /* Identifier of the worker associated with this entry. */
        [@yojson.option]
        args: option(array(Runtime.Types.RemoteObject.t)) /* Call arguments. */,
      };
    }
    and ViolationSetting: {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {
        name: string, /* Violation type. */
        threshold: float /* Time threshold to trigger upon. */,
      };
    };
  };

  module Events: {
    /* Issued when new message was logged. */
    module EntryAdded: {
      [@deriving yojson]
      type result = {entry: Types.LogEntry.t /* The entry. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec LogEntry: {
      /* Log entry. */
      [@deriving yojson]
      type t = {
        source: string, /* Log entry source. */
        level: string, /* Log entry severity. */
        text: string, /* Logged text. */
        timestamp: Runtime.Types.Timestamp.t, /* Timestamp when this entry was added. */
        [@yojson.option]
        url: option(string), /* URL of the resource if known. */
        [@yojson.option]
        lineNumber: option(float), /* Line number in the resource. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript stack trace. */
        [@yojson.option]
        networkRequestId: option(Network.Types.RequestId.t), /* Identifier of the network request associated with this entry. */
        [@yojson.option]
        workerId: option(string), /* Identifier of the worker associated with this entry. */
        [@yojson.option]
        args: option(array(Runtime.Types.RemoteObject.t)) /* Call arguments. */,
      };
    }
    and ViolationSetting: {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {
        name: string, /* Violation type. */
        threshold: float /* Time threshold to trigger upon. */,
      };
    };
  } = {
    module rec LogEntry: {
      /* Log entry. */
      [@deriving yojson]
      type t = {
        source: string, /* Log entry source. */
        level: string, /* Log entry severity. */
        text: string, /* Logged text. */
        timestamp: Runtime.Types.Timestamp.t, /* Timestamp when this entry was added. */
        [@yojson.option]
        url: option(string), /* URL of the resource if known. */
        [@yojson.option]
        lineNumber: option(float), /* Line number in the resource. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript stack trace. */
        [@yojson.option]
        networkRequestId: option(Network.Types.RequestId.t), /* Identifier of the network request associated with this entry. */
        [@yojson.option]
        workerId: option(string), /* Identifier of the worker associated with this entry. */
        [@yojson.option]
        args: option(array(Runtime.Types.RemoteObject.t)) /* Call arguments. */,
      };
    } = {
      /* Log entry. */
      [@deriving yojson]
      type t = {
        source: string, /* Log entry source. */
        level: string, /* Log entry severity. */
        text: string, /* Logged text. */
        timestamp: Runtime.Types.Timestamp.t, /* Timestamp when this entry was added. */
        [@yojson.option]
        url: option(string), /* URL of the resource if known. */
        [@yojson.option]
        lineNumber: option(float), /* Line number in the resource. */
        [@yojson.option]
        stackTrace: option(Runtime.Types.StackTrace.t), /* JavaScript stack trace. */
        [@yojson.option]
        networkRequestId: option(Network.Types.RequestId.t), /* Identifier of the network request associated with this entry. */
        [@yojson.option]
        workerId: option(string), /* Identifier of the worker associated with this entry. */
        [@yojson.option]
        args: option(array(Runtime.Types.RemoteObject.t)) /* Call arguments. */,
      };
    }
    and ViolationSetting: {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {
        name: string, /* Violation type. */
        threshold: float /* Time threshold to trigger upon. */,
      };
    } = {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {
        name: string, /* Violation type. */
        threshold: float /* Time threshold to trigger upon. */,
      };
    };
  };

  module Events = {
    /* Issued when new message was logged. */
    module EntryAdded = {
      [@deriving yojson]
      type result = {entry: Types.LogEntry.t /* The entry. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Memory: {
  module Types: {
    module rec PressureLevel: {
      /* Memory pressure level. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingProfileNode: {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {
        size: float, /* Size of the sampled allocation. */
        total: float, /* Total bytes attributed to this sample. */
        stack: array(string) /* Execution stack at the point of allocation. */,
      };
    }
    and SamplingProfile: {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {
        samples: array(SamplingProfileNode.t), /* No description provided */
        modules: array(Module.t) /* No description provided */,
      };
    }
    and Module: {
      /* Executable module information */
      [@deriving yojson]
      type t = {
        name: string, /* Name of the module. */
        uuid: string, /* UUID of the module. */
        baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
        size: float /* Size of the module in bytes. */,
      };
    };
  };
} = {
  module Types: {
    module rec PressureLevel: {
      /* Memory pressure level. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingProfileNode: {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {
        size: float, /* Size of the sampled allocation. */
        total: float, /* Total bytes attributed to this sample. */
        stack: array(string) /* Execution stack at the point of allocation. */,
      };
    }
    and SamplingProfile: {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {
        samples: array(SamplingProfileNode.t), /* No description provided */
        modules: array(Module.t) /* No description provided */,
      };
    }
    and Module: {
      /* Executable module information */
      [@deriving yojson]
      type t = {
        name: string, /* Name of the module. */
        uuid: string, /* UUID of the module. */
        baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
        size: float /* Size of the module in bytes. */,
      };
    };
  } = {
    module rec PressureLevel: {
      /* Memory pressure level. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Memory pressure level. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingProfileNode: {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {
        size: float, /* Size of the sampled allocation. */
        total: float, /* Total bytes attributed to this sample. */
        stack: array(string) /* Execution stack at the point of allocation. */,
      };
    } = {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {
        size: float, /* Size of the sampled allocation. */
        total: float, /* Total bytes attributed to this sample. */
        stack: array(string) /* Execution stack at the point of allocation. */,
      };
    }
    and SamplingProfile: {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {
        samples: array(SamplingProfileNode.t), /* No description provided */
        modules: array(Module.t) /* No description provided */,
      };
    } = {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {
        samples: array(SamplingProfileNode.t), /* No description provided */
        modules: array(Module.t) /* No description provided */,
      };
    }
    and Module: {
      /* Executable module information */
      [@deriving yojson]
      type t = {
        name: string, /* Name of the module. */
        uuid: string, /* UUID of the module. */
        baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
        size: float /* Size of the module in bytes. */,
      };
    } = {
      /* Executable module information */
      [@deriving yojson]
      type t = {
        name: string, /* Name of the module. */
        uuid: string, /* UUID of the module. */
        baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
        size: float /* Size of the module in bytes. */,
      };
    };
  };
}
and Network: {
  module Types: {
    module rec ResourceType: {
      /* Resource type as it was perceived by the rendering engine. */
      [@deriving yojson]
      type t = string;
    }
    and LoaderId: {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and InterceptionId: {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ErrorReason: {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and MonotonicTime: {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    }
    and Headers: {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = assoc;
    }
    and ConnectionType: {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    }
    and CookieSameSite: {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    }
    and CookiePriority: {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    }
    and CookieSourceScheme: {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    }
    and ResourceTiming: {
      /* Timing information for the request. */
      [@deriving yojson]
      type t = {
        requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
        proxyStart: float, /* Started resolving proxy. */
        proxyEnd: float, /* Finished resolving proxy. */
        dnsStart: float, /* Started DNS address resolve. */
        dnsEnd: float, /* Finished DNS address resolve. */
        connectStart: float, /* Started connecting to the remote host. */
        connectEnd: float, /* Connected to the remote host. */
        sslStart: float, /* Started SSL handshake. */
        sslEnd: float, /* Finished SSL handshake. */
        workerStart: float, /* Started running ServiceWorker. */
        workerReady: float, /* Finished Starting ServiceWorker. */
        workerFetchStart: float, /* Started fetch event. */
        workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
        sendStart: float, /* Started sending request. */
        sendEnd: float, /* Finished sending request. */
        pushStart: float, /* Time the server started pushing request. */
        pushEnd: float, /* Time the server finished pushing request. */
        receiveHeadersEnd: float /* Finished receiving response headers. */,
      };
    }
    and ResourcePriority: {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    }
    and PostDataEntry: {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        bytes: option(string) /* No description provided */,
      };
    }
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        [@yojson.option]
        urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        [@yojson.option]
        postData: option(string), /* HTTP POST request data. */
        [@yojson.option]
        hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        [@yojson.option]
        postDataEntries: option(array(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
        [@yojson.option]
        mixedContentType: option(Security.Types.MixedContentType.t), /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        [@yojson.option]
        isLinkPreload: option(bool), /* Whether is loaded via link preload. */
        [@yojson.option]
        trustTokenParams: option(TrustTokenParams.t) /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */,
      };
    }
    and SignedCertificateTimestamp: {
      /* Details of a signed certificate timestamp (SCT). */
      [@deriving yojson]
      type t = {
        status: string, /* Validation status. */
        origin: string, /* Origin. */
        logDescription: string, /* Log name / description. */
        logId: string, /* Log ID. */
        timestamp: TimeSinceEpoch.t, /* Issuance date. */
        hashAlgorithm: string, /* Hash algorithm. */
        signatureAlgorithm: string, /* Signature algorithm. */
        signatureData: string /* Signature data. */,
      };
    }
    and SecurityDetails: {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificateId: Security.Types.CertificateId.t, /* Certificate ID value. */
        subjectName: string, /* Certificate subject name. */
        sanList: array(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        signedCertificateTimestampList: array(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
        certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
      };
    }
    and CertificateTransparencyCompliance: {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedReason: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsError: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsErrorStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        corsError: CorsError.t, /* No description provided */
        failedParameter: string /* No description provided */,
      };
    }
    and ServiceWorkerResponseSource: {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    }
    and TrustTokenParams: {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        [@yojson.option]
        issuers: option(array(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
      };
    }
    and TrustTokenOperationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Response: {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {
        url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
        [@yojson.option]
        requestHeadersText: option(string), /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        [@yojson.option]
        remoteIPAddress: option(string), /* Remote IP address. */
        [@yojson.option]
        remotePort: option(float), /* Remote port. */
        [@yojson.option]
        fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
        [@yojson.option]
        fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
        [@yojson.option]
        fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        [@yojson.option]
        timing: option(ResourceTiming.t), /* Timing information for the given request. */
        [@yojson.option]
        serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
        [@yojson.option]
        responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
        [@yojson.option]
        cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
        [@yojson.option]
        protocol: option(string), /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
      };
    }
    and WebSocketRequest: {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {headers: Headers.t /* HTTP request headers. */};
    }
    and WebSocketResponse: {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* HTTP request headers. */
        [@yojson.option]
        requestHeadersText: option(string) /* HTTP request headers text. */,
      };
    }
    and WebSocketFrame: {
      /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
      [@deriving yojson]
      type t = {
        opcode: float, /* WebSocket message opcode. */
        mask: bool, /* WebSocket message mask. */
        payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
      };
    }
    and CachedResource: {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. This is the url of the original network request. */
        [@key "type"]
        type_: ResourceType.t, /* Type of this resource. */
        [@yojson.option]
        response: option(Response.t), /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    }
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of this initiator. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
        [@yojson.option]
        url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        [@yojson.option]
        lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
      };
    }
    and Cookie: {
      /* Cookie object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
        size: float, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        [@yojson.option]
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: float /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and SetCookieBlockedReason: {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    }
    and CookieBlockedReason: {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedSetCookieWithReason: {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
        cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
        [@yojson.option]
        cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
      };
    }
    and BlockedCookieWithReason: {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
        cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
      };
    }
    and CookieParam: {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {
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
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        [@yojson.option]
        expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
        [@yojson.option]
        priority: option(CookiePriority.t), /* Cookie Priority. */
        [@yojson.option]
        sameParty: option(bool), /* True if cookie is SameParty. */
        [@yojson.option]
        sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
        [@yojson.option]
        sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    }
    and InterceptionStage: {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and SignedExchangeSignature: {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {
        label: string, /* Signed exchange signature label. */
        signature: string, /* The hex string of signed exchange signature. */
        integrity: string, /* Signed exchange signature integrity. */
        [@yojson.option]
        certUrl: option(string), /* Signed exchange signature cert Url. */
        [@yojson.option]
        certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: float, /* Signed exchange signature date. */
        expires: float, /* Signed exchange signature expires. */
        [@yojson.option]
        certificates: option(array(string)) /* The encoded certificates. */,
      };
    }
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: float, /* Signed exchange response code. */
        responseHeaders: Headers.t, /* Signed exchange response headers. */
        signatures: array(SignedExchangeSignature.t), /* Signed exchange response signature. */
        headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
      };
    }
    and SignedExchangeErrorField: {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    }
    and SignedExchangeError: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        [@yojson.option]
        signatureIndex: option(float), /* The index of the signature which caused the error. */
        [@yojson.option]
        errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
      };
    }
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        [@yojson.option]
        header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
        [@yojson.option]
        errors: option(array(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
      };
    }
    and ContentEncoding: {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    }
    and PrivateNetworkRequestPolicy: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and IPAddressSpace: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientSecurityState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        initiatorIsSecureContext: bool, /* No description provided */
        initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
        privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
      };
    }
    and CrossOriginOpenerPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginOpenerPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and CrossOriginEmbedderPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginEmbedderPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
        [@yojson.option]
        coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
      };
    }
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        [@yojson.option]
        netError: option(float), /* Optional values used for error reporting. */
        [@yojson.option]
        netErrorName: option(string), /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
        [@yojson.option]
        headers: option(Network.Types.Headers.t) /* Response headers. */,
      };
    }
    and LoadNetworkResourceOptions: {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {
        disableCache: bool, /* No description provided */
        includeCredentials: bool /* No description provided */,
      };
    };
  };

  module Events: {
    /* Fired when data chunk was received over the network. */
    module DataReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        dataLength: float, /* Data chunk length. */
        encodedDataLength: float /* Actual bytes received (might be less than dataLength for compressed encodings). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when EventSource message is received. */
    module EventSourceMessageReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        eventName: string, /* Message type. */
        eventId: string, /* Message identifier. */
        data: string /* Message content. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when HTTP request has failed to load. */
    module LoadingFailed: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@key "type"]
        type_: Types.ResourceType.t, /* Resource type. */
        errorText: string, /* User friendly error message. */
        [@yojson.option]
        canceled: option(bool), /* True if loading was canceled. */
        [@yojson.option]
        blockedReason: option(Types.BlockedReason.t), /* The reason why loading was blocked, if any. */
        [@yojson.option]
        corsErrorStatus: option(Types.CorsErrorStatus.t) /* The reason why loading was blocked by CORS, if any. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when HTTP request has finished loading. */
    module LoadingFinished: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        encodedDataLength: float, /* Total number of bytes received for this request. */
        [@yojson.option]
        shouldReportCorbBlocking: option(bool) /* Set when 1) response was blocked by Cross-Origin Read Blocking and also
2) this needs to be reported to the DevTools console. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
       mocked.
       Deprecated, use Fetch.requestPaused instead. */
    module RequestIntercepted: {
      [@deriving yojson]
      type result = {
        interceptionId: Types.InterceptionId.t, /* Each request the page makes will have a unique id, however if any redirects are encountered
while processing that fetch, they will be reported with the same id as the original fetch.
Likewise if HTTP authentication is needed then the same fetch id will be used. */
        request: Types.Request.t, /* No description provided */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Types.ResourceType.t, /* How the requested resource will be used. */
        isNavigationRequest: bool, /* Whether this is a navigation request, which can abort the navigation completely. */
        [@yojson.option]
        isDownload: option(bool), /* Set if the request is a navigation that will result in a download.
Only present after response is received from the server (i.e. HeadersReceived stage). */
        [@yojson.option]
        redirectUrl: option(string), /* Redirect location, only sent if a redirect was intercepted. */
        [@yojson.option]
        authChallenge: option(Types.AuthChallenge.t), /* Details of the Authorization Challenge encountered. If this is set then
continueInterceptedRequest must contain an authChallengeResponse. */
        [@yojson.option]
        responseErrorReason: option(Types.ErrorReason.t), /* Response error if intercepted at response stage or if redirect occurred while intercepting
request. */
        [@yojson.option]
        responseStatusCode: option(float), /* Response code if intercepted at response stage or if redirect occurred while intercepting
request or auth retry occurred. */
        [@yojson.option]
        responseHeaders: option(Types.Headers.t), /* Response headers if intercepted at the response stage or if redirect occurred while
intercepting request or auth retry occurred. */
        [@yojson.option]
        requestId: option(Types.RequestId.t) /* If the intercepted request had a corresponding requestWillBeSent event fired for it, then
this requestId will be the same as the requestId present in the requestWillBeSent event. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired if request ended up loading from cache. */
    module RequestServedFromCache: {
      [@deriving yojson]
      type result = {requestId: Types.RequestId.t /* Request identifier. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when page is about to send HTTP request. */
    module RequestWillBeSent: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        loaderId: Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        documentURL: string, /* URL of the document this request is loaded for. */
        request: Types.Request.t, /* Request data. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        wallTime: Types.TimeSinceEpoch.t, /* Timestamp. */
        initiator: Types.Initiator.t, /* Request initiator. */
        [@yojson.option]
        redirectResponse: option(Types.Response.t), /* Redirect response data. */
        [@yojson.option] [@key "type"]
        type_: option(Types.ResourceType.t), /* Type of this resource. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame identifier. */
        [@yojson.option]
        hasUserGesture: option(bool) /* Whether the request is initiated by a user gesture. Defaults to false. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when resource loading priority is changed */
    module ResourceChangedPriority: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        newPriority: Types.ResourcePriority.t, /* New priority */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when a signed exchange was received over the network */
    module SignedExchangeReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        info: Types.SignedExchangeInfo.t /* Information about the signed exchange response. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when HTTP response is available. */
    module ResponseReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        loaderId: Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@key "type"]
        type_: Types.ResourceType.t, /* Resource type. */
        response: Types.Response.t, /* Response data. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t) /* Frame identifier. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket is closed. */
    module WebSocketClosed: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired upon WebSocket creation. */
    module WebSocketCreated: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        url: string, /* WebSocket request URL. */
        [@yojson.option]
        initiator: option(Types.Initiator.t) /* Request initiator. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket message error occurs. */
    module WebSocketFrameError: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        errorMessage: string /* WebSocket error message. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket message is received. */
    module WebSocketFrameReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketFrame.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket message is sent. */
    module WebSocketFrameSent: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketFrame.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket handshake response becomes available. */
    module WebSocketHandshakeResponseReceived: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketResponse.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebSocket is about to initiate handshake. */
    module WebSocketWillSendHandshakeRequest: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        wallTime: Types.TimeSinceEpoch.t, /* UTC Timestamp. */
        request: Types.WebSocketRequest.t /* WebSocket request data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired upon WebTransport creation. */
    module WebTransportCreated: {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        url: string, /* WebTransport request URL. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@yojson.option]
        initiator: option(Types.Initiator.t) /* Request initiator. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebTransport handshake is finished. */
    module WebTransportConnectionEstablished: {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when WebTransport is disposed. */
    module WebTransportClosed: {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when additional information about a requestWillBeSent event is available from the
       network stack. Not every requestWillBeSent event will have an additional
       requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
       or requestWillBeSentExtraInfo will be fired first for the same request. */
    module RequestWillBeSentExtraInfo: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. Used to match this information to an existing requestWillBeSent event. */
        associatedCookies: array(Types.BlockedCookieWithReason.t), /* A list of cookies potentially associated to the requested URL. This includes both cookies sent with
the request and the ones not sent; the latter are distinguished by having blockedReason field set. */
        headers: Types.Headers.t, /* Raw request headers as they will be sent over the wire. */
        [@yojson.option]
        clientSecurityState: option(Types.ClientSecurityState.t) /* The client security state set for the request. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when additional information about a responseReceived event is available from the network
       stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
       it, and responseReceivedExtraInfo may be fired before or after responseReceived. */
    module ResponseReceivedExtraInfo: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. Used to match this information to another responseReceived event. */
        blockedCookies: array(Types.BlockedSetCookieWithReason.t), /* A list of cookies which were not stored from the response along with the corresponding
reasons for blocking. The cookies here may not be valid due to syntax errors, which
are represented by the invalid cookie line string instead of a proper cookie. */
        headers: Types.Headers.t, /* Raw response headers as they were received over the wire. */
        resourceIPAddressSpace: Types.IPAddressSpace.t, /* The IP address space of the resource. The address space can only be determined once the transport
established the connection, so we can't send it in `requestWillBeSentExtraInfo`. */
        [@yojson.option]
        headersText: option(string) /* Raw response header text as it was received over the wire. The raw text may not always be
available, such as in the case of HTTP/2 or QUIC. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired exactly once for each Trust Token operation. Depending on
       the type of the operation and whether the operation succeeded or
       failed, the event is fired before the corresponding request was sent
       or after the response was received. */
    module TrustTokenOperationDone: {
      [@deriving yojson]
      type result = {
        status: string, /* Detailed success or error status of the operation.
'AlreadyExists' also signifies a successful operation, as the result
of the operation already exists und thus, the operation was abort
preemptively (e.g. a cache hit). */
        [@key "type"]
        type_: Types.TrustTokenOperationType.t, /* No description provided */
        requestId: Types.RequestId.t, /* No description provided */
        [@yojson.option]
        topLevelOrigin: option(string), /* Top level origin. The context in which the operation was attempted. */
        [@yojson.option]
        issuerOrigin: option(string), /* Origin of the issuer in case of a "Issuance" or "Redemption" operation. */
        [@yojson.option]
        issuedTokenCount: option(float) /* The number of obtained Trust Tokens on a successful "Issuance" operation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ResourceType: {
      /* Resource type as it was perceived by the rendering engine. */
      [@deriving yojson]
      type t = string;
    }
    and LoaderId: {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and InterceptionId: {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ErrorReason: {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and MonotonicTime: {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    }
    and Headers: {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = assoc;
    }
    and ConnectionType: {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    }
    and CookieSameSite: {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    }
    and CookiePriority: {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    }
    and CookieSourceScheme: {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    }
    and ResourceTiming: {
      /* Timing information for the request. */
      [@deriving yojson]
      type t = {
        requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
        proxyStart: float, /* Started resolving proxy. */
        proxyEnd: float, /* Finished resolving proxy. */
        dnsStart: float, /* Started DNS address resolve. */
        dnsEnd: float, /* Finished DNS address resolve. */
        connectStart: float, /* Started connecting to the remote host. */
        connectEnd: float, /* Connected to the remote host. */
        sslStart: float, /* Started SSL handshake. */
        sslEnd: float, /* Finished SSL handshake. */
        workerStart: float, /* Started running ServiceWorker. */
        workerReady: float, /* Finished Starting ServiceWorker. */
        workerFetchStart: float, /* Started fetch event. */
        workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
        sendStart: float, /* Started sending request. */
        sendEnd: float, /* Finished sending request. */
        pushStart: float, /* Time the server started pushing request. */
        pushEnd: float, /* Time the server finished pushing request. */
        receiveHeadersEnd: float /* Finished receiving response headers. */,
      };
    }
    and ResourcePriority: {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    }
    and PostDataEntry: {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        bytes: option(string) /* No description provided */,
      };
    }
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        [@yojson.option]
        urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        [@yojson.option]
        postData: option(string), /* HTTP POST request data. */
        [@yojson.option]
        hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        [@yojson.option]
        postDataEntries: option(array(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
        [@yojson.option]
        mixedContentType: option(Security.Types.MixedContentType.t), /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        [@yojson.option]
        isLinkPreload: option(bool), /* Whether is loaded via link preload. */
        [@yojson.option]
        trustTokenParams: option(TrustTokenParams.t) /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */,
      };
    }
    and SignedCertificateTimestamp: {
      /* Details of a signed certificate timestamp (SCT). */
      [@deriving yojson]
      type t = {
        status: string, /* Validation status. */
        origin: string, /* Origin. */
        logDescription: string, /* Log name / description. */
        logId: string, /* Log ID. */
        timestamp: TimeSinceEpoch.t, /* Issuance date. */
        hashAlgorithm: string, /* Hash algorithm. */
        signatureAlgorithm: string, /* Signature algorithm. */
        signatureData: string /* Signature data. */,
      };
    }
    and SecurityDetails: {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificateId: Security.Types.CertificateId.t, /* Certificate ID value. */
        subjectName: string, /* Certificate subject name. */
        sanList: array(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        signedCertificateTimestampList: array(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
        certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
      };
    }
    and CertificateTransparencyCompliance: {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedReason: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsError: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsErrorStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        corsError: CorsError.t, /* No description provided */
        failedParameter: string /* No description provided */,
      };
    }
    and ServiceWorkerResponseSource: {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    }
    and TrustTokenParams: {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        [@yojson.option]
        issuers: option(array(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
      };
    }
    and TrustTokenOperationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Response: {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {
        url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
        [@yojson.option]
        requestHeadersText: option(string), /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        [@yojson.option]
        remoteIPAddress: option(string), /* Remote IP address. */
        [@yojson.option]
        remotePort: option(float), /* Remote port. */
        [@yojson.option]
        fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
        [@yojson.option]
        fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
        [@yojson.option]
        fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        [@yojson.option]
        timing: option(ResourceTiming.t), /* Timing information for the given request. */
        [@yojson.option]
        serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
        [@yojson.option]
        responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
        [@yojson.option]
        cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
        [@yojson.option]
        protocol: option(string), /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
      };
    }
    and WebSocketRequest: {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {headers: Headers.t /* HTTP request headers. */};
    }
    and WebSocketResponse: {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* HTTP request headers. */
        [@yojson.option]
        requestHeadersText: option(string) /* HTTP request headers text. */,
      };
    }
    and WebSocketFrame: {
      /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
      [@deriving yojson]
      type t = {
        opcode: float, /* WebSocket message opcode. */
        mask: bool, /* WebSocket message mask. */
        payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
      };
    }
    and CachedResource: {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. This is the url of the original network request. */
        [@key "type"]
        type_: ResourceType.t, /* Type of this resource. */
        [@yojson.option]
        response: option(Response.t), /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    }
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of this initiator. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
        [@yojson.option]
        url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        [@yojson.option]
        lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
      };
    }
    and Cookie: {
      /* Cookie object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
        size: float, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        [@yojson.option]
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: float /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and SetCookieBlockedReason: {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    }
    and CookieBlockedReason: {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedSetCookieWithReason: {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
        cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
        [@yojson.option]
        cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
      };
    }
    and BlockedCookieWithReason: {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
        cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
      };
    }
    and CookieParam: {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {
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
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        [@yojson.option]
        expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
        [@yojson.option]
        priority: option(CookiePriority.t), /* Cookie Priority. */
        [@yojson.option]
        sameParty: option(bool), /* True if cookie is SameParty. */
        [@yojson.option]
        sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
        [@yojson.option]
        sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    }
    and InterceptionStage: {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and SignedExchangeSignature: {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {
        label: string, /* Signed exchange signature label. */
        signature: string, /* The hex string of signed exchange signature. */
        integrity: string, /* Signed exchange signature integrity. */
        [@yojson.option]
        certUrl: option(string), /* Signed exchange signature cert Url. */
        [@yojson.option]
        certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: float, /* Signed exchange signature date. */
        expires: float, /* Signed exchange signature expires. */
        [@yojson.option]
        certificates: option(array(string)) /* The encoded certificates. */,
      };
    }
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: float, /* Signed exchange response code. */
        responseHeaders: Headers.t, /* Signed exchange response headers. */
        signatures: array(SignedExchangeSignature.t), /* Signed exchange response signature. */
        headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
      };
    }
    and SignedExchangeErrorField: {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    }
    and SignedExchangeError: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        [@yojson.option]
        signatureIndex: option(float), /* The index of the signature which caused the error. */
        [@yojson.option]
        errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
      };
    }
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        [@yojson.option]
        header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
        [@yojson.option]
        errors: option(array(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
      };
    }
    and ContentEncoding: {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    }
    and PrivateNetworkRequestPolicy: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and IPAddressSpace: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientSecurityState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        initiatorIsSecureContext: bool, /* No description provided */
        initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
        privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
      };
    }
    and CrossOriginOpenerPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginOpenerPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and CrossOriginEmbedderPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginEmbedderPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
        [@yojson.option]
        coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
      };
    }
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        [@yojson.option]
        netError: option(float), /* Optional values used for error reporting. */
        [@yojson.option]
        netErrorName: option(string), /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
        [@yojson.option]
        headers: option(Network.Types.Headers.t) /* Response headers. */,
      };
    }
    and LoadNetworkResourceOptions: {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {
        disableCache: bool, /* No description provided */
        includeCredentials: bool /* No description provided */,
      };
    };
  } = {
    module rec ResourceType: {
      /* Resource type as it was perceived by the rendering engine. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Resource type as it was perceived by the rendering engine. */
      [@deriving yojson]
      type t = string;
    }
    and LoaderId: {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and InterceptionId: {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ErrorReason: {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    } = {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and MonotonicTime: {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    }
    and Headers: {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = assoc;
    } = {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = assoc;
    }
    and ConnectionType: {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    }
    and CookieSameSite: {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    } = {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    }
    and CookiePriority: {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    } = {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    }
    and CookieSourceScheme: {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    }
    and ResourceTiming: {
      /* Timing information for the request. */
      [@deriving yojson]
      type t = {
        requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
        proxyStart: float, /* Started resolving proxy. */
        proxyEnd: float, /* Finished resolving proxy. */
        dnsStart: float, /* Started DNS address resolve. */
        dnsEnd: float, /* Finished DNS address resolve. */
        connectStart: float, /* Started connecting to the remote host. */
        connectEnd: float, /* Connected to the remote host. */
        sslStart: float, /* Started SSL handshake. */
        sslEnd: float, /* Finished SSL handshake. */
        workerStart: float, /* Started running ServiceWorker. */
        workerReady: float, /* Finished Starting ServiceWorker. */
        workerFetchStart: float, /* Started fetch event. */
        workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
        sendStart: float, /* Started sending request. */
        sendEnd: float, /* Finished sending request. */
        pushStart: float, /* Time the server started pushing request. */
        pushEnd: float, /* Time the server finished pushing request. */
        receiveHeadersEnd: float /* Finished receiving response headers. */,
      };
    } = {
      /* Timing information for the request. */
      [@deriving yojson]
      type t = {
        requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
        proxyStart: float, /* Started resolving proxy. */
        proxyEnd: float, /* Finished resolving proxy. */
        dnsStart: float, /* Started DNS address resolve. */
        dnsEnd: float, /* Finished DNS address resolve. */
        connectStart: float, /* Started connecting to the remote host. */
        connectEnd: float, /* Connected to the remote host. */
        sslStart: float, /* Started SSL handshake. */
        sslEnd: float, /* Finished SSL handshake. */
        workerStart: float, /* Started running ServiceWorker. */
        workerReady: float, /* Finished Starting ServiceWorker. */
        workerFetchStart: float, /* Started fetch event. */
        workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
        sendStart: float, /* Started sending request. */
        sendEnd: float, /* Finished sending request. */
        pushStart: float, /* Time the server started pushing request. */
        pushEnd: float, /* Time the server finished pushing request. */
        receiveHeadersEnd: float /* Finished receiving response headers. */,
      };
    }
    and ResourcePriority: {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    }
    and PostDataEntry: {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        bytes: option(string) /* No description provided */,
      };
    } = {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        bytes: option(string) /* No description provided */,
      };
    }
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        [@yojson.option]
        urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        [@yojson.option]
        postData: option(string), /* HTTP POST request data. */
        [@yojson.option]
        hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        [@yojson.option]
        postDataEntries: option(array(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
        [@yojson.option]
        mixedContentType: option(Security.Types.MixedContentType.t), /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        [@yojson.option]
        isLinkPreload: option(bool), /* Whether is loaded via link preload. */
        [@yojson.option]
        trustTokenParams: option(TrustTokenParams.t) /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */,
      };
    } = {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        [@yojson.option]
        urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        [@yojson.option]
        postData: option(string), /* HTTP POST request data. */
        [@yojson.option]
        hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        [@yojson.option]
        postDataEntries: option(array(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
        [@yojson.option]
        mixedContentType: option(Security.Types.MixedContentType.t), /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        [@yojson.option]
        isLinkPreload: option(bool), /* Whether is loaded via link preload. */
        [@yojson.option]
        trustTokenParams: option(TrustTokenParams.t) /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */,
      };
    }
    and SignedCertificateTimestamp: {
      /* Details of a signed certificate timestamp (SCT). */
      [@deriving yojson]
      type t = {
        status: string, /* Validation status. */
        origin: string, /* Origin. */
        logDescription: string, /* Log name / description. */
        logId: string, /* Log ID. */
        timestamp: TimeSinceEpoch.t, /* Issuance date. */
        hashAlgorithm: string, /* Hash algorithm. */
        signatureAlgorithm: string, /* Signature algorithm. */
        signatureData: string /* Signature data. */,
      };
    } = {
      /* Details of a signed certificate timestamp (SCT). */
      [@deriving yojson]
      type t = {
        status: string, /* Validation status. */
        origin: string, /* Origin. */
        logDescription: string, /* Log name / description. */
        logId: string, /* Log ID. */
        timestamp: TimeSinceEpoch.t, /* Issuance date. */
        hashAlgorithm: string, /* Hash algorithm. */
        signatureAlgorithm: string, /* Signature algorithm. */
        signatureData: string /* Signature data. */,
      };
    }
    and SecurityDetails: {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificateId: Security.Types.CertificateId.t, /* Certificate ID value. */
        subjectName: string, /* Certificate subject name. */
        sanList: array(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        signedCertificateTimestampList: array(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
        certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
      };
    } = {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificateId: Security.Types.CertificateId.t, /* Certificate ID value. */
        subjectName: string, /* Certificate subject name. */
        sanList: array(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        signedCertificateTimestampList: array(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
        certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
      };
    }
    and CertificateTransparencyCompliance: {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedReason: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsError: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsErrorStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        corsError: CorsError.t, /* No description provided */
        failedParameter: string /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        corsError: CorsError.t, /* No description provided */
        failedParameter: string /* No description provided */,
      };
    }
    and ServiceWorkerResponseSource: {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    }
    and TrustTokenParams: {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        [@yojson.option]
        issuers: option(array(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
      };
    } = {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        [@yojson.option]
        issuers: option(array(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
      };
    }
    and TrustTokenOperationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Response: {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {
        url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
        [@yojson.option]
        requestHeadersText: option(string), /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        [@yojson.option]
        remoteIPAddress: option(string), /* Remote IP address. */
        [@yojson.option]
        remotePort: option(float), /* Remote port. */
        [@yojson.option]
        fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
        [@yojson.option]
        fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
        [@yojson.option]
        fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        [@yojson.option]
        timing: option(ResourceTiming.t), /* Timing information for the given request. */
        [@yojson.option]
        serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
        [@yojson.option]
        responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
        [@yojson.option]
        cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
        [@yojson.option]
        protocol: option(string), /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
      };
    } = {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {
        url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
        [@yojson.option]
        requestHeadersText: option(string), /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        [@yojson.option]
        remoteIPAddress: option(string), /* Remote IP address. */
        [@yojson.option]
        remotePort: option(float), /* Remote port. */
        [@yojson.option]
        fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
        [@yojson.option]
        fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
        [@yojson.option]
        fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        [@yojson.option]
        timing: option(ResourceTiming.t), /* Timing information for the given request. */
        [@yojson.option]
        serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
        [@yojson.option]
        responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
        [@yojson.option]
        cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
        [@yojson.option]
        protocol: option(string), /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
      };
    }
    and WebSocketRequest: {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {headers: Headers.t /* HTTP request headers. */};
    } = {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {headers: Headers.t /* HTTP request headers. */};
    }
    and WebSocketResponse: {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* HTTP request headers. */
        [@yojson.option]
        requestHeadersText: option(string) /* HTTP request headers text. */,
      };
    } = {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {
        status: float, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        [@yojson.option]
        headersText: option(string), /* HTTP response headers text. */
        [@yojson.option]
        requestHeaders: option(Headers.t), /* HTTP request headers. */
        [@yojson.option]
        requestHeadersText: option(string) /* HTTP request headers text. */,
      };
    }
    and WebSocketFrame: {
      /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
      [@deriving yojson]
      type t = {
        opcode: float, /* WebSocket message opcode. */
        mask: bool, /* WebSocket message mask. */
        payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
      };
    } = {
      /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
      [@deriving yojson]
      type t = {
        opcode: float, /* WebSocket message opcode. */
        mask: bool, /* WebSocket message mask. */
        payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
      };
    }
    and CachedResource: {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. This is the url of the original network request. */
        [@key "type"]
        type_: ResourceType.t, /* Type of this resource. */
        [@yojson.option]
        response: option(Response.t), /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    } = {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. This is the url of the original network request. */
        [@key "type"]
        type_: ResourceType.t, /* Type of this resource. */
        [@yojson.option]
        response: option(Response.t), /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    }
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of this initiator. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
        [@yojson.option]
        url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        [@yojson.option]
        lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
      };
    } = {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Type of this initiator. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
        [@yojson.option]
        url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        [@yojson.option]
        lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        [@yojson.option]
        requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
      };
    }
    and Cookie: {
      /* Cookie object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
        size: float, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        [@yojson.option]
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: float /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    } = {
      /* Cookie object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
        size: float, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        [@yojson.option]
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: float /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and SetCookieBlockedReason: {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    }
    and CookieBlockedReason: {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedSetCookieWithReason: {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
        cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
        [@yojson.option]
        cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
      };
    } = {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
        cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
        [@yojson.option]
        cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
      };
    }
    and BlockedCookieWithReason: {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
        cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
      };
    } = {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
        cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
      };
    }
    and CookieParam: {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {
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
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        [@yojson.option]
        expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
        [@yojson.option]
        priority: option(CookiePriority.t), /* Cookie Priority. */
        [@yojson.option]
        sameParty: option(bool), /* True if cookie is SameParty. */
        [@yojson.option]
        sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
        [@yojson.option]
        sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    } = {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {
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
        sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
        [@yojson.option]
        expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
        [@yojson.option]
        priority: option(CookiePriority.t), /* Cookie Priority. */
        [@yojson.option]
        sameParty: option(bool), /* True if cookie is SameParty. */
        [@yojson.option]
        sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
        [@yojson.option]
        sourcePort: option(float) /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    } = {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    } = {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    }
    and InterceptionStage: {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    } = {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and SignedExchangeSignature: {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {
        label: string, /* Signed exchange signature label. */
        signature: string, /* The hex string of signed exchange signature. */
        integrity: string, /* Signed exchange signature integrity. */
        [@yojson.option]
        certUrl: option(string), /* Signed exchange signature cert Url. */
        [@yojson.option]
        certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: float, /* Signed exchange signature date. */
        expires: float, /* Signed exchange signature expires. */
        [@yojson.option]
        certificates: option(array(string)) /* The encoded certificates. */,
      };
    } = {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {
        label: string, /* Signed exchange signature label. */
        signature: string, /* The hex string of signed exchange signature. */
        integrity: string, /* Signed exchange signature integrity. */
        [@yojson.option]
        certUrl: option(string), /* Signed exchange signature cert Url. */
        [@yojson.option]
        certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: float, /* Signed exchange signature date. */
        expires: float, /* Signed exchange signature expires. */
        [@yojson.option]
        certificates: option(array(string)) /* The encoded certificates. */,
      };
    }
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: float, /* Signed exchange response code. */
        responseHeaders: Headers.t, /* Signed exchange response headers. */
        signatures: array(SignedExchangeSignature.t), /* Signed exchange response signature. */
        headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
      };
    } = {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: float, /* Signed exchange response code. */
        responseHeaders: Headers.t, /* Signed exchange response headers. */
        signatures: array(SignedExchangeSignature.t), /* Signed exchange response signature. */
        headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
      };
    }
    and SignedExchangeErrorField: {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    }
    and SignedExchangeError: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        [@yojson.option]
        signatureIndex: option(float), /* The index of the signature which caused the error. */
        [@yojson.option]
        errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
      };
    } = {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        [@yojson.option]
        signatureIndex: option(float), /* The index of the signature which caused the error. */
        [@yojson.option]
        errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
      };
    }
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        [@yojson.option]
        header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
        [@yojson.option]
        errors: option(array(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
      };
    } = {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        [@yojson.option]
        header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
        [@yojson.option]
        securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
        [@yojson.option]
        errors: option(array(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
      };
    }
    and ContentEncoding: {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    } = {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    }
    and PrivateNetworkRequestPolicy: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and IPAddressSpace: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientSecurityState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        initiatorIsSecureContext: bool, /* No description provided */
        initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
        privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        initiatorIsSecureContext: bool, /* No description provided */
        initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
        privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
      };
    }
    and CrossOriginOpenerPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginOpenerPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and CrossOriginEmbedderPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginEmbedderPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        [@yojson.option]
        reportingEndpoint: option(string), /* No description provided */
        [@yojson.option]
        reportOnlyReportingEndpoint: option(string) /* No description provided */,
      };
    }
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
        [@yojson.option]
        coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
        [@yojson.option]
        coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
      };
    }
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        [@yojson.option]
        netError: option(float), /* Optional values used for error reporting. */
        [@yojson.option]
        netErrorName: option(string), /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
        [@yojson.option]
        headers: option(Network.Types.Headers.t) /* Response headers. */,
      };
    } = {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        [@yojson.option]
        netError: option(float), /* Optional values used for error reporting. */
        [@yojson.option]
        netErrorName: option(string), /* No description provided */
        [@yojson.option]
        httpStatusCode: option(float), /* No description provided */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
        [@yojson.option]
        headers: option(Network.Types.Headers.t) /* Response headers. */,
      };
    }
    and LoadNetworkResourceOptions: {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {
        disableCache: bool, /* No description provided */
        includeCredentials: bool /* No description provided */,
      };
    } = {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {
        disableCache: bool, /* No description provided */
        includeCredentials: bool /* No description provided */,
      };
    };
  };

  module Events = {
    /* Fired when data chunk was received over the network. */
    module DataReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        dataLength: float, /* Data chunk length. */
        encodedDataLength: float /* Actual bytes received (might be less than dataLength for compressed encodings). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when EventSource message is received. */
    module EventSourceMessageReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        eventName: string, /* Message type. */
        eventId: string, /* Message identifier. */
        data: string /* Message content. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when HTTP request has failed to load. */
    module LoadingFailed = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@key "type"]
        type_: Types.ResourceType.t, /* Resource type. */
        errorText: string, /* User friendly error message. */
        [@yojson.option]
        canceled: option(bool), /* True if loading was canceled. */
        [@yojson.option]
        blockedReason: option(Types.BlockedReason.t), /* The reason why loading was blocked, if any. */
        [@yojson.option]
        corsErrorStatus: option(Types.CorsErrorStatus.t) /* The reason why loading was blocked by CORS, if any. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when HTTP request has finished loading. */
    module LoadingFinished = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        encodedDataLength: float, /* Total number of bytes received for this request. */
        [@yojson.option]
        shouldReportCorbBlocking: option(bool) /* Set when 1) response was blocked by Cross-Origin Read Blocking and also
2) this needs to be reported to the DevTools console. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Details of an intercepted HTTP request, which must be either allowed, blocked, modified or
       mocked.
       Deprecated, use Fetch.requestPaused instead. */
    module RequestIntercepted = {
      [@deriving yojson]
      type result = {
        interceptionId: Types.InterceptionId.t, /* Each request the page makes will have a unique id, however if any redirects are encountered
while processing that fetch, they will be reported with the same id as the original fetch.
Likewise if HTTP authentication is needed then the same fetch id will be used. */
        request: Types.Request.t, /* No description provided */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Types.ResourceType.t, /* How the requested resource will be used. */
        isNavigationRequest: bool, /* Whether this is a navigation request, which can abort the navigation completely. */
        [@yojson.option]
        isDownload: option(bool), /* Set if the request is a navigation that will result in a download.
Only present after response is received from the server (i.e. HeadersReceived stage). */
        [@yojson.option]
        redirectUrl: option(string), /* Redirect location, only sent if a redirect was intercepted. */
        [@yojson.option]
        authChallenge: option(Types.AuthChallenge.t), /* Details of the Authorization Challenge encountered. If this is set then
continueInterceptedRequest must contain an authChallengeResponse. */
        [@yojson.option]
        responseErrorReason: option(Types.ErrorReason.t), /* Response error if intercepted at response stage or if redirect occurred while intercepting
request. */
        [@yojson.option]
        responseStatusCode: option(float), /* Response code if intercepted at response stage or if redirect occurred while intercepting
request or auth retry occurred. */
        [@yojson.option]
        responseHeaders: option(Types.Headers.t), /* Response headers if intercepted at the response stage or if redirect occurred while
intercepting request or auth retry occurred. */
        [@yojson.option]
        requestId: option(Types.RequestId.t) /* If the intercepted request had a corresponding requestWillBeSent event fired for it, then
this requestId will be the same as the requestId present in the requestWillBeSent event. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired if request ended up loading from cache. */
    module RequestServedFromCache = {
      [@deriving yojson]
      type result = {requestId: Types.RequestId.t /* Request identifier. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when page is about to send HTTP request. */
    module RequestWillBeSent = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        loaderId: Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        documentURL: string, /* URL of the document this request is loaded for. */
        request: Types.Request.t, /* Request data. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        wallTime: Types.TimeSinceEpoch.t, /* Timestamp. */
        initiator: Types.Initiator.t, /* Request initiator. */
        [@yojson.option]
        redirectResponse: option(Types.Response.t), /* Redirect response data. */
        [@yojson.option] [@key "type"]
        type_: option(Types.ResourceType.t), /* Type of this resource. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t), /* Frame identifier. */
        [@yojson.option]
        hasUserGesture: option(bool) /* Whether the request is initiated by a user gesture. Defaults to false. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when resource loading priority is changed */
    module ResourceChangedPriority = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        newPriority: Types.ResourcePriority.t, /* New priority */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when a signed exchange was received over the network */
    module SignedExchangeReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        info: Types.SignedExchangeInfo.t /* Information about the signed exchange response. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when HTTP response is available. */
    module ResponseReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        loaderId: Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@key "type"]
        type_: Types.ResourceType.t, /* Resource type. */
        response: Types.Response.t, /* Response data. */
        [@yojson.option]
        frameId: option(Page.Types.FrameId.t) /* Frame identifier. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket is closed. */
    module WebSocketClosed = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired upon WebSocket creation. */
    module WebSocketCreated = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        url: string, /* WebSocket request URL. */
        [@yojson.option]
        initiator: option(Types.Initiator.t) /* Request initiator. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket message error occurs. */
    module WebSocketFrameError = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        errorMessage: string /* WebSocket error message. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket message is received. */
    module WebSocketFrameReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketFrame.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket message is sent. */
    module WebSocketFrameSent = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketFrame.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket handshake response becomes available. */
    module WebSocketHandshakeResponseReceived = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        response: Types.WebSocketResponse.t /* WebSocket response data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebSocket is about to initiate handshake. */
    module WebSocketWillSendHandshakeRequest = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        wallTime: Types.TimeSinceEpoch.t, /* UTC Timestamp. */
        request: Types.WebSocketRequest.t /* WebSocket request data. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired upon WebTransport creation. */
    module WebTransportCreated = {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        url: string, /* WebTransport request URL. */
        timestamp: Types.MonotonicTime.t, /* Timestamp. */
        [@yojson.option]
        initiator: option(Types.Initiator.t) /* Request initiator. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebTransport handshake is finished. */
    module WebTransportConnectionEstablished = {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when WebTransport is disposed. */
    module WebTransportClosed = {
      [@deriving yojson]
      type result = {
        transportId: Types.RequestId.t, /* WebTransport identifier. */
        timestamp: Types.MonotonicTime.t /* Timestamp. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when additional information about a requestWillBeSent event is available from the
       network stack. Not every requestWillBeSent event will have an additional
       requestWillBeSentExtraInfo fired for it, and there is no guarantee whether requestWillBeSent
       or requestWillBeSentExtraInfo will be fired first for the same request. */
    module RequestWillBeSentExtraInfo = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. Used to match this information to an existing requestWillBeSent event. */
        associatedCookies: array(Types.BlockedCookieWithReason.t), /* A list of cookies potentially associated to the requested URL. This includes both cookies sent with
the request and the ones not sent; the latter are distinguished by having blockedReason field set. */
        headers: Types.Headers.t, /* Raw request headers as they will be sent over the wire. */
        [@yojson.option]
        clientSecurityState: option(Types.ClientSecurityState.t) /* The client security state set for the request. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when additional information about a responseReceived event is available from the network
       stack. Not every responseReceived event will have an additional responseReceivedExtraInfo for
       it, and responseReceivedExtraInfo may be fired before or after responseReceived. */
    module ResponseReceivedExtraInfo = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Request identifier. Used to match this information to another responseReceived event. */
        blockedCookies: array(Types.BlockedSetCookieWithReason.t), /* A list of cookies which were not stored from the response along with the corresponding
reasons for blocking. The cookies here may not be valid due to syntax errors, which
are represented by the invalid cookie line string instead of a proper cookie. */
        headers: Types.Headers.t, /* Raw response headers as they were received over the wire. */
        resourceIPAddressSpace: Types.IPAddressSpace.t, /* The IP address space of the resource. The address space can only be determined once the transport
established the connection, so we can't send it in `requestWillBeSentExtraInfo`. */
        [@yojson.option]
        headersText: option(string) /* Raw response header text as it was received over the wire. The raw text may not always be
available, such as in the case of HTTP/2 or QUIC. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired exactly once for each Trust Token operation. Depending on
       the type of the operation and whether the operation succeeded or
       failed, the event is fired before the corresponding request was sent
       or after the response was received. */
    module TrustTokenOperationDone = {
      [@deriving yojson]
      type result = {
        status: string, /* Detailed success or error status of the operation.
'AlreadyExists' also signifies a successful operation, as the result
of the operation already exists und thus, the operation was abort
preemptively (e.g. a cache hit). */
        [@key "type"]
        type_: Types.TrustTokenOperationType.t, /* No description provided */
        requestId: Types.RequestId.t, /* No description provided */
        [@yojson.option]
        topLevelOrigin: option(string), /* Top level origin. The context in which the operation was attempted. */
        [@yojson.option]
        issuerOrigin: option(string), /* Origin of the issuer in case of a "Issuance" or "Redemption" operation. */
        [@yojson.option]
        issuedTokenCount: option(float) /* The number of obtained Trust Tokens on a successful "Issuance" operation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Overlay: {
  module Types: {
    module rec SourceOrderConfig: {
      /* Configuration data for drawing the source order of an elements children. */
      [@deriving yojson]
      type t = {
        parentOutlineColor: DOM.Types.RGBA.t, /* the color to outline the givent element in. */
        childOutlineColor: DOM.Types.RGBA.t /* the color to outline the child elements in. */,
      };
    }
    and GridHighlightConfig: {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        [@yojson.option]
        showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
        [@yojson.option]
        showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
        [@yojson.option]
        showAreaNames: option(bool), /* Show area name labels (default: false). */
        [@yojson.option]
        showLineNames: option(bool), /* Show line name labels (default: false). */
        [@yojson.option]
        showTrackSizes: option(bool), /* Show track size labels (default: false). */
        [@yojson.option]
        gridBorderColor: option(DOM.Types.RGBA.t), /* The grid container border highlight color (default: transparent). */
        [@yojson.option]
        cellBorderColor: option(DOM.Types.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        [@yojson.option]
        rowLineColor: option(DOM.Types.RGBA.t), /* The row line color (default: transparent). */
        [@yojson.option]
        columnLineColor: option(DOM.Types.RGBA.t), /* The column line color (default: transparent). */
        [@yojson.option]
        gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
        [@yojson.option]
        cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        [@yojson.option]
        rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
        [@yojson.option]
        columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
        [@yojson.option]
        rowGapColor: option(DOM.Types.RGBA.t), /* The row gap highlight fill color (default: transparent). */
        [@yojson.option]
        rowHatchColor: option(DOM.Types.RGBA.t), /* The row gap hatching fill color (default: transparent). */
        [@yojson.option]
        columnGapColor: option(DOM.Types.RGBA.t), /* The column gap highlight fill color (default: transparent). */
        [@yojson.option]
        columnHatchColor: option(DOM.Types.RGBA.t), /* The column gap hatching fill color (default: transparent). */
        [@yojson.option]
        areaBorderColor: option(DOM.Types.RGBA.t), /* The named grid areas border color (Default: transparent). */
        [@yojson.option]
        gridBackgroundColor: option(DOM.Types.RGBA.t) /* The grid container background color (Default: transparent). */,
      };
    }
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        containerBorder: option(LineStyle.t), /* The style of the container border */
        [@yojson.option]
        lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
        [@yojson.option]
        itemSeparator: option(LineStyle.t), /* The style of the separator between items */
        [@yojson.option]
        mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
        [@yojson.option]
        crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
        [@yojson.option]
        rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
        [@yojson.option]
        columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
        [@yojson.option]
        crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
      };
    }
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
        [@yojson.option]
        baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
        [@yojson.option]
        flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
      };
    }
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        color: option(DOM.Types.RGBA.t), /* The color of the line (default: transparent) */
        [@yojson.option]
        pattern: option(string) /* The line pattern (default: solid) */,
      };
    }
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        fillColor: option(DOM.Types.RGBA.t), /* The background color for the box (default: transparent) */
        [@yojson.option]
        hatchColor: option(DOM.Types.RGBA.t) /* The hatching color for the box (default: transparent) */,
      };
    }
    and ContrastAlgorithm: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HighlightConfig: {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
        [@yojson.option]
        showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
        [@yojson.option]
        showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
        [@yojson.option]
        showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
        [@yojson.option]
        showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: transparent). */
        [@yojson.option]
        paddingColor: option(DOM.Types.RGBA.t), /* The padding highlight fill color (default: transparent). */
        [@yojson.option]
        borderColor: option(DOM.Types.RGBA.t), /* The border highlight fill color (default: transparent). */
        [@yojson.option]
        marginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        eventTargetColor: option(DOM.Types.RGBA.t), /* The event target element highlight fill color (default: transparent). */
        [@yojson.option]
        shapeColor: option(DOM.Types.RGBA.t), /* The shape outside fill color (default: transparent). */
        [@yojson.option]
        shapeMarginColor: option(DOM.Types.RGBA.t), /* The shape margin fill color (default: transparent). */
        [@yojson.option]
        cssGridColor: option(DOM.Types.RGBA.t), /* The grid layout color (default: transparent). */
        [@yojson.option]
        colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
        [@yojson.option]
        gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
        [@yojson.option]
        flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
        [@yojson.option]
        flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
        [@yojson.option]
        contrastAlgorithm: option(ContrastAlgorithm.t) /* The contrast algorithm to use for the contrast ratio (default: aa). */,
      };
    }
    and ColorFormat: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and GridNodeHighlightConfig: {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {
        gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and FlexNodeHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and ScrollSnapContainerHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
        [@yojson.option]
        snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
        [@yojson.option]
        scrollMarginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        scrollPaddingColor: option(DOM.Types.RGBA.t) /* The padding highlight fill color (default: transparent). */,
      };
    }
    and ScrollSnapHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and HingeConfig: {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* A rectangle represent hinge */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: a dark color). */
        [@yojson.option]
        outlineColor: option(DOM.Types.RGBA.t) /* The content box highlight outline color (default: transparent). */,
      };
    }
    and InspectMode: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events: {
    /* Fired when the node should be inspected. This happens after call to `setInspectMode` or when
       user manually inspects an element. */
    module InspectNodeRequested: {
      [@deriving yojson]
      type result = {
        backendNodeId: DOM.Types.BackendNodeId.t /* Id of the node to inspect. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when the node should be highlighted. This happens after call to `setInspectMode`. */
    module NodeHighlightRequested: {
      [@deriving yojson]
      type result = {
        nodeId: DOM.Types.NodeId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when user asks to capture screenshot of some area on the page. */
    module ScreenshotRequested: {
      [@deriving yojson]
      type result = {
        viewport: Page.Types.Viewport.t /* Viewport to capture, in device independent pixels (dip). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when user cancels the inspect mode. */
    module InspectModeCanceled: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec SourceOrderConfig: {
      /* Configuration data for drawing the source order of an elements children. */
      [@deriving yojson]
      type t = {
        parentOutlineColor: DOM.Types.RGBA.t, /* the color to outline the givent element in. */
        childOutlineColor: DOM.Types.RGBA.t /* the color to outline the child elements in. */,
      };
    }
    and GridHighlightConfig: {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        [@yojson.option]
        showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
        [@yojson.option]
        showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
        [@yojson.option]
        showAreaNames: option(bool), /* Show area name labels (default: false). */
        [@yojson.option]
        showLineNames: option(bool), /* Show line name labels (default: false). */
        [@yojson.option]
        showTrackSizes: option(bool), /* Show track size labels (default: false). */
        [@yojson.option]
        gridBorderColor: option(DOM.Types.RGBA.t), /* The grid container border highlight color (default: transparent). */
        [@yojson.option]
        cellBorderColor: option(DOM.Types.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        [@yojson.option]
        rowLineColor: option(DOM.Types.RGBA.t), /* The row line color (default: transparent). */
        [@yojson.option]
        columnLineColor: option(DOM.Types.RGBA.t), /* The column line color (default: transparent). */
        [@yojson.option]
        gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
        [@yojson.option]
        cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        [@yojson.option]
        rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
        [@yojson.option]
        columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
        [@yojson.option]
        rowGapColor: option(DOM.Types.RGBA.t), /* The row gap highlight fill color (default: transparent). */
        [@yojson.option]
        rowHatchColor: option(DOM.Types.RGBA.t), /* The row gap hatching fill color (default: transparent). */
        [@yojson.option]
        columnGapColor: option(DOM.Types.RGBA.t), /* The column gap highlight fill color (default: transparent). */
        [@yojson.option]
        columnHatchColor: option(DOM.Types.RGBA.t), /* The column gap hatching fill color (default: transparent). */
        [@yojson.option]
        areaBorderColor: option(DOM.Types.RGBA.t), /* The named grid areas border color (Default: transparent). */
        [@yojson.option]
        gridBackgroundColor: option(DOM.Types.RGBA.t) /* The grid container background color (Default: transparent). */,
      };
    }
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        containerBorder: option(LineStyle.t), /* The style of the container border */
        [@yojson.option]
        lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
        [@yojson.option]
        itemSeparator: option(LineStyle.t), /* The style of the separator between items */
        [@yojson.option]
        mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
        [@yojson.option]
        crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
        [@yojson.option]
        rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
        [@yojson.option]
        columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
        [@yojson.option]
        crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
      };
    }
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
        [@yojson.option]
        baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
        [@yojson.option]
        flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
      };
    }
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        color: option(DOM.Types.RGBA.t), /* The color of the line (default: transparent) */
        [@yojson.option]
        pattern: option(string) /* The line pattern (default: solid) */,
      };
    }
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        fillColor: option(DOM.Types.RGBA.t), /* The background color for the box (default: transparent) */
        [@yojson.option]
        hatchColor: option(DOM.Types.RGBA.t) /* The hatching color for the box (default: transparent) */,
      };
    }
    and ContrastAlgorithm: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HighlightConfig: {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
        [@yojson.option]
        showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
        [@yojson.option]
        showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
        [@yojson.option]
        showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
        [@yojson.option]
        showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: transparent). */
        [@yojson.option]
        paddingColor: option(DOM.Types.RGBA.t), /* The padding highlight fill color (default: transparent). */
        [@yojson.option]
        borderColor: option(DOM.Types.RGBA.t), /* The border highlight fill color (default: transparent). */
        [@yojson.option]
        marginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        eventTargetColor: option(DOM.Types.RGBA.t), /* The event target element highlight fill color (default: transparent). */
        [@yojson.option]
        shapeColor: option(DOM.Types.RGBA.t), /* The shape outside fill color (default: transparent). */
        [@yojson.option]
        shapeMarginColor: option(DOM.Types.RGBA.t), /* The shape margin fill color (default: transparent). */
        [@yojson.option]
        cssGridColor: option(DOM.Types.RGBA.t), /* The grid layout color (default: transparent). */
        [@yojson.option]
        colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
        [@yojson.option]
        gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
        [@yojson.option]
        flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
        [@yojson.option]
        flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
        [@yojson.option]
        contrastAlgorithm: option(ContrastAlgorithm.t) /* The contrast algorithm to use for the contrast ratio (default: aa). */,
      };
    }
    and ColorFormat: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and GridNodeHighlightConfig: {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {
        gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and FlexNodeHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and ScrollSnapContainerHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
        [@yojson.option]
        snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
        [@yojson.option]
        scrollMarginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        scrollPaddingColor: option(DOM.Types.RGBA.t) /* The padding highlight fill color (default: transparent). */,
      };
    }
    and ScrollSnapHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and HingeConfig: {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* A rectangle represent hinge */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: a dark color). */
        [@yojson.option]
        outlineColor: option(DOM.Types.RGBA.t) /* The content box highlight outline color (default: transparent). */,
      };
    }
    and InspectMode: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec SourceOrderConfig: {
      /* Configuration data for drawing the source order of an elements children. */
      [@deriving yojson]
      type t = {
        parentOutlineColor: DOM.Types.RGBA.t, /* the color to outline the givent element in. */
        childOutlineColor: DOM.Types.RGBA.t /* the color to outline the child elements in. */,
      };
    } = {
      /* Configuration data for drawing the source order of an elements children. */
      [@deriving yojson]
      type t = {
        parentOutlineColor: DOM.Types.RGBA.t, /* the color to outline the givent element in. */
        childOutlineColor: DOM.Types.RGBA.t /* the color to outline the child elements in. */,
      };
    }
    and GridHighlightConfig: {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        [@yojson.option]
        showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
        [@yojson.option]
        showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
        [@yojson.option]
        showAreaNames: option(bool), /* Show area name labels (default: false). */
        [@yojson.option]
        showLineNames: option(bool), /* Show line name labels (default: false). */
        [@yojson.option]
        showTrackSizes: option(bool), /* Show track size labels (default: false). */
        [@yojson.option]
        gridBorderColor: option(DOM.Types.RGBA.t), /* The grid container border highlight color (default: transparent). */
        [@yojson.option]
        cellBorderColor: option(DOM.Types.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        [@yojson.option]
        rowLineColor: option(DOM.Types.RGBA.t), /* The row line color (default: transparent). */
        [@yojson.option]
        columnLineColor: option(DOM.Types.RGBA.t), /* The column line color (default: transparent). */
        [@yojson.option]
        gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
        [@yojson.option]
        cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        [@yojson.option]
        rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
        [@yojson.option]
        columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
        [@yojson.option]
        rowGapColor: option(DOM.Types.RGBA.t), /* The row gap highlight fill color (default: transparent). */
        [@yojson.option]
        rowHatchColor: option(DOM.Types.RGBA.t), /* The row gap hatching fill color (default: transparent). */
        [@yojson.option]
        columnGapColor: option(DOM.Types.RGBA.t), /* The column gap highlight fill color (default: transparent). */
        [@yojson.option]
        columnHatchColor: option(DOM.Types.RGBA.t), /* The column gap hatching fill color (default: transparent). */
        [@yojson.option]
        areaBorderColor: option(DOM.Types.RGBA.t), /* The named grid areas border color (Default: transparent). */
        [@yojson.option]
        gridBackgroundColor: option(DOM.Types.RGBA.t) /* The grid container background color (Default: transparent). */,
      };
    } = {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        [@yojson.option]
        showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
        [@yojson.option]
        showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
        [@yojson.option]
        showAreaNames: option(bool), /* Show area name labels (default: false). */
        [@yojson.option]
        showLineNames: option(bool), /* Show line name labels (default: false). */
        [@yojson.option]
        showTrackSizes: option(bool), /* Show track size labels (default: false). */
        [@yojson.option]
        gridBorderColor: option(DOM.Types.RGBA.t), /* The grid container border highlight color (default: transparent). */
        [@yojson.option]
        cellBorderColor: option(DOM.Types.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        [@yojson.option]
        rowLineColor: option(DOM.Types.RGBA.t), /* The row line color (default: transparent). */
        [@yojson.option]
        columnLineColor: option(DOM.Types.RGBA.t), /* The column line color (default: transparent). */
        [@yojson.option]
        gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
        [@yojson.option]
        cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        [@yojson.option]
        rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
        [@yojson.option]
        columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
        [@yojson.option]
        rowGapColor: option(DOM.Types.RGBA.t), /* The row gap highlight fill color (default: transparent). */
        [@yojson.option]
        rowHatchColor: option(DOM.Types.RGBA.t), /* The row gap hatching fill color (default: transparent). */
        [@yojson.option]
        columnGapColor: option(DOM.Types.RGBA.t), /* The column gap highlight fill color (default: transparent). */
        [@yojson.option]
        columnHatchColor: option(DOM.Types.RGBA.t), /* The column gap hatching fill color (default: transparent). */
        [@yojson.option]
        areaBorderColor: option(DOM.Types.RGBA.t), /* The named grid areas border color (Default: transparent). */
        [@yojson.option]
        gridBackgroundColor: option(DOM.Types.RGBA.t) /* The grid container background color (Default: transparent). */,
      };
    }
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        containerBorder: option(LineStyle.t), /* The style of the container border */
        [@yojson.option]
        lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
        [@yojson.option]
        itemSeparator: option(LineStyle.t), /* The style of the separator between items */
        [@yojson.option]
        mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
        [@yojson.option]
        crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
        [@yojson.option]
        rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
        [@yojson.option]
        columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
        [@yojson.option]
        crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
      };
    } = {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        containerBorder: option(LineStyle.t), /* The style of the container border */
        [@yojson.option]
        lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
        [@yojson.option]
        itemSeparator: option(LineStyle.t), /* The style of the separator between items */
        [@yojson.option]
        mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
        [@yojson.option]
        crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
        [@yojson.option]
        rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
        [@yojson.option]
        columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
        [@yojson.option]
        crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
      };
    }
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
        [@yojson.option]
        baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
        [@yojson.option]
        flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
      };
    } = {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
        [@yojson.option]
        baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
        [@yojson.option]
        flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
      };
    }
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        color: option(DOM.Types.RGBA.t), /* The color of the line (default: transparent) */
        [@yojson.option]
        pattern: option(string) /* The line pattern (default: solid) */,
      };
    } = {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        color: option(DOM.Types.RGBA.t), /* The color of the line (default: transparent) */
        [@yojson.option]
        pattern: option(string) /* The line pattern (default: solid) */,
      };
    }
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        fillColor: option(DOM.Types.RGBA.t), /* The background color for the box (default: transparent) */
        [@yojson.option]
        hatchColor: option(DOM.Types.RGBA.t) /* The hatching color for the box (default: transparent) */,
      };
    } = {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        fillColor: option(DOM.Types.RGBA.t), /* The background color for the box (default: transparent) */
        [@yojson.option]
        hatchColor: option(DOM.Types.RGBA.t) /* The hatching color for the box (default: transparent) */,
      };
    }
    and ContrastAlgorithm: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HighlightConfig: {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
        [@yojson.option]
        showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
        [@yojson.option]
        showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
        [@yojson.option]
        showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
        [@yojson.option]
        showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: transparent). */
        [@yojson.option]
        paddingColor: option(DOM.Types.RGBA.t), /* The padding highlight fill color (default: transparent). */
        [@yojson.option]
        borderColor: option(DOM.Types.RGBA.t), /* The border highlight fill color (default: transparent). */
        [@yojson.option]
        marginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        eventTargetColor: option(DOM.Types.RGBA.t), /* The event target element highlight fill color (default: transparent). */
        [@yojson.option]
        shapeColor: option(DOM.Types.RGBA.t), /* The shape outside fill color (default: transparent). */
        [@yojson.option]
        shapeMarginColor: option(DOM.Types.RGBA.t), /* The shape margin fill color (default: transparent). */
        [@yojson.option]
        cssGridColor: option(DOM.Types.RGBA.t), /* The grid layout color (default: transparent). */
        [@yojson.option]
        colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
        [@yojson.option]
        gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
        [@yojson.option]
        flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
        [@yojson.option]
        flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
        [@yojson.option]
        contrastAlgorithm: option(ContrastAlgorithm.t) /* The contrast algorithm to use for the contrast ratio (default: aa). */,
      };
    } = {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
        [@yojson.option]
        showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
        [@yojson.option]
        showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
        [@yojson.option]
        showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
        [@yojson.option]
        showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: transparent). */
        [@yojson.option]
        paddingColor: option(DOM.Types.RGBA.t), /* The padding highlight fill color (default: transparent). */
        [@yojson.option]
        borderColor: option(DOM.Types.RGBA.t), /* The border highlight fill color (default: transparent). */
        [@yojson.option]
        marginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        eventTargetColor: option(DOM.Types.RGBA.t), /* The event target element highlight fill color (default: transparent). */
        [@yojson.option]
        shapeColor: option(DOM.Types.RGBA.t), /* The shape outside fill color (default: transparent). */
        [@yojson.option]
        shapeMarginColor: option(DOM.Types.RGBA.t), /* The shape margin fill color (default: transparent). */
        [@yojson.option]
        cssGridColor: option(DOM.Types.RGBA.t), /* The grid layout color (default: transparent). */
        [@yojson.option]
        colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
        [@yojson.option]
        gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
        [@yojson.option]
        flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
        [@yojson.option]
        flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
        [@yojson.option]
        contrastAlgorithm: option(ContrastAlgorithm.t) /* The contrast algorithm to use for the contrast ratio (default: aa). */,
      };
    }
    and ColorFormat: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and GridNodeHighlightConfig: {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {
        gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {
        gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and FlexNodeHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and ScrollSnapContainerHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
        [@yojson.option]
        snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
        [@yojson.option]
        scrollMarginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        scrollPaddingColor: option(DOM.Types.RGBA.t) /* The padding highlight fill color (default: transparent). */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
        [@yojson.option]
        snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
        [@yojson.option]
        scrollMarginColor: option(DOM.Types.RGBA.t), /* The margin highlight fill color (default: transparent). */
        [@yojson.option]
        scrollPaddingColor: option(DOM.Types.RGBA.t) /* The padding highlight fill color (default: transparent). */,
      };
    }
    and ScrollSnapHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    }
    and HingeConfig: {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* A rectangle represent hinge */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: a dark color). */
        [@yojson.option]
        outlineColor: option(DOM.Types.RGBA.t) /* The content box highlight outline color (default: transparent). */,
      };
    } = {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* A rectangle represent hinge */
        [@yojson.option]
        contentColor: option(DOM.Types.RGBA.t), /* The content box highlight fill color (default: a dark color). */
        [@yojson.option]
        outlineColor: option(DOM.Types.RGBA.t) /* The content box highlight outline color (default: transparent). */,
      };
    }
    and InspectMode: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events = {
    /* Fired when the node should be inspected. This happens after call to `setInspectMode` or when
       user manually inspects an element. */
    module InspectNodeRequested = {
      [@deriving yojson]
      type result = {
        backendNodeId: DOM.Types.BackendNodeId.t /* Id of the node to inspect. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when the node should be highlighted. This happens after call to `setInspectMode`. */
    module NodeHighlightRequested = {
      [@deriving yojson]
      type result = {
        nodeId: DOM.Types.NodeId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when user asks to capture screenshot of some area on the page. */
    module ScreenshotRequested = {
      [@deriving yojson]
      type result = {
        viewport: Page.Types.Viewport.t /* Viewport to capture, in device independent pixels (dip). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when user cancels the inspect mode. */
    module InspectModeCanceled = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Page: {
  module Types: {
    module rec FrameId: {
      /* Unique frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AdFrameType: {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    }
    and SecureContextType: {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginIsolatedContextType: {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and GatedAPIFeatures: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyFeature: {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockReason: {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockLocator: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: FrameId.t, /* No description provided */
        blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
      };
    }
    and PermissionsPolicyFeatureState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        feature: PermissionsPolicyFeature.t, /* No description provided */
        allowed: bool, /* No description provided */
        [@yojson.option]
        locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
      };
    }
    and OriginTrialTokenStatus: {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialStatus: {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialUsageRestriction: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialToken: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        origin: string, /* No description provided */
        matchSubDomains: bool, /* No description provided */
        trialName: string, /* No description provided */
        expiryTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        isThirdParty: bool, /* No description provided */
        usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
      };
    }
    and OriginTrialTokenWithStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        rawTokenText: string, /* No description provided */
        [@yojson.option]
        parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
        status: OriginTrialTokenStatus.t /* No description provided */,
      };
    }
    and OriginTrial: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        trialName: string, /* No description provided */
        status: OriginTrialStatus.t, /* No description provided */
        tokensWithStatus: array(OriginTrialTokenWithStatus.t) /* No description provided */,
      };
    }
    and Frame: {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {
        id: FrameId.t, /* Frame unique identifier. */
        [@yojson.option]
        parentId: option(string), /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        [@yojson.option]
        name: option(string), /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        [@yojson.option]
        urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        [@yojson.option]
        unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        [@yojson.option]
        adFrameType: option(AdFrameType.t), /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        [@yojson.option]
        originTrials: option(array(OriginTrial.t)) /* Frame document's origin trials with at least one token present. */,
      };
    }
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        [@key "type"]
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        lastModified: option(Network.Types.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
        [@yojson.option]
        contentSize: option(float), /* Resource content size. */
        [@yojson.option]
        failed: option(bool), /* True if the resource failed to load. */
        [@yojson.option]
        canceled: option(bool) /* True if the resource was canceled during loading. */,
      };
    }
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameResourceTree.t)), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    }
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameTree.t)) /* Child frames. */,
      };
    }
    and ScriptIdentifier: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and TransitionType: {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    }
    and NavigationEntry: {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the navigation history entry. */
        url: string, /* URL of the navigation history entry. */
        userTypedURL: string, /* URL that the user typed in the url bar. */
        title: string, /* Title of the navigation history entry. */
        transitionType: TransitionType.t /* Transition type. */,
      };
    }
    and ScreencastFrameMetadata: {
      /* Screencast frame metadata. */
      [@deriving yojson]
      type t = {
        offsetTop: float, /* Top offset in DIP. */
        pageScaleFactor: float, /* Page scale factor. */
        deviceWidth: float, /* Device screen width in DIP. */
        deviceHeight: float, /* Device screen height in DIP. */
        scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
        scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
        [@yojson.option]
        timestamp: option(Network.Types.TimeSinceEpoch.t) /* Frame swap timestamp. */,
      };
    }
    and DialogType: {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    }
    and AppManifestError: {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        critical: float, /* If criticial, this is a non-recoverable parse error. */
        line: float, /* Error line. */
        column: float /* Error column. */,
      };
    }
    and AppManifestParsedProperties: {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {scope: string /* Computed scope value */};
    }
    and LayoutViewport: {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
      };
    }
    and VisualViewport: {
      /* Visual viewport position, dimensions, and scale. */
      [@deriving yojson]
      type t = {
        offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
        offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
        scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
        [@yojson.option]
        zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
      };
    }
    and Viewport: {
      /* Viewport for capturing screenshot. */
      [@deriving yojson]
      type t = {
        x: float, /* X offset in device independent pixels (dip). */
        y: float, /* Y offset in device independent pixels (dip). */
        width: float, /* Rectangle width in device independent pixels (dip). */
        height: float, /* Rectangle height in device independent pixels (dip). */
        scale: float /* Page scale factor. */,
      };
    }
    and FontFamilies: {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(string), /* The standard font-family. */
        [@yojson.option]
        fixed: option(string), /* The fixed font-family. */
        [@yojson.option]
        serif: option(string), /* The serif font-family. */
        [@yojson.option]
        sansSerif: option(string), /* The sansSerif font-family. */
        [@yojson.option]
        cursive: option(string), /* The cursive font-family. */
        [@yojson.option]
        fantasy: option(string), /* The fantasy font-family. */
        [@yojson.option]
        pictograph: option(string) /* The pictograph font-family. */,
      };
    }
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(float), /* Default standard font size. */
        [@yojson.option]
        fixed: option(float) /* Default fixed font size. */,
      };
    }
    and ClientNavigationReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientNavigationDisposition: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and InstallabilityErrorArgument: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
        value: string /* Argument value (e.g. value:'64'). */,
      };
    }
    and InstallabilityError: {
      /* The installability error */
      [@deriving yojson]
      type t = {
        errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
        errorArguments: array(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
      };
    }
    and ReferrerPolicy: {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    }
    and CompilationCacheParams: {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {
        url: string, /* The URL of the script to produce a compilation cache entry for. */
        [@yojson.option]
        eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    }
    and NavigationType: {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events: {
    /* No description provided */
    module DomContentEventFired: {
      [@deriving yojson]
      type result = {
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Emitted only when `page.interceptFileChooser` is enabled. */
    module FileChooserOpened: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame containing input node. */
        backendNodeId: DOM.Types.BackendNodeId.t, /* Input node id. */
        mode: string /* Input mode. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame has been attached to its parent. */
    module FrameAttached: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has been attached. */
        parentFrameId: Types.FrameId.t, /* Parent frame identifier. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t) /* JavaScript stack trace of when frame was attached, only set if frame initiated from script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame no longer has a scheduled navigation. */
    module FrameClearedScheduledNavigation: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has cleared its scheduled navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame has been detached from its parent. */
    module FrameDetached: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has been detached. */
        reason: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired once navigation of the frame has completed. Frame is now associated with the new loader. */
    module FrameNavigated: {
      [@deriving yojson]
      type result = {
        frame: Types.Frame.t, /* Frame object. */
        [@key "type"]
        type_: Types.NavigationType.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when opening document to write to. */
    module DocumentOpened: {
      [@deriving yojson]
      type result = {frame: Types.Frame.t /* Frame object. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module FrameResized: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when a renderer-initiated navigation is requested.
       Navigation may still be cancelled after the event is issued. */
    module FrameRequestedNavigation: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that is being navigated. */
        reason: Types.ClientNavigationReason.t, /* The reason for the navigation. */
        url: string, /* The destination URL for the requested navigation. */
        disposition: Types.ClientNavigationDisposition.t /* The disposition for the navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame schedules a potential navigation. */
    module FrameScheduledNavigation: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has scheduled a navigation. */
        delay: float, /* Delay (in seconds) until the navigation is scheduled to begin. The navigation is not
guaranteed to start. */
        reason: Types.ClientNavigationReason.t, /* The reason for the navigation. */
        url: string /* The destination URL for the scheduled navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame has started loading. */
    module FrameStartedLoading: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has started loading. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when frame has stopped loading. */
    module FrameStoppedLoading: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has stopped loading. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when page is about to start a download.
       Deprecated. Use Browser.downloadWillBegin instead. */
    module DownloadWillBegin: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that caused download to begin. */
        guid: string, /* Global unique identifier of the download. */
        url: string, /* URL of the resource being downloaded. */
        suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when download makes progress. Last call has |done| == true.
       Deprecated. Use Browser.downloadProgress instead. */
    module DownloadProgress: {
      [@deriving yojson]
      type result = {
        guid: string, /* Global unique identifier of the download. */
        totalBytes: float, /* Total expected bytes to download. */
        receivedBytes: float, /* Total bytes received. */
        state: string /* Download status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when interstitial page was hidden */
    module InterstitialHidden: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when interstitial page was shown */
    module InterstitialShown: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) has been
       closed. */
    module JavascriptDialogClosed: {
      [@deriving yojson]
      type result = {
        result: bool, /* Whether dialog was confirmed. */
        userInput: string /* User input in case of prompt. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) is about to
       open. */
    module JavascriptDialogOpening: {
      [@deriving yojson]
      type result = {
        url: string, /* Frame url. */
        message: string, /* Message that will be displayed by the dialog. */
        [@key "type"]
        type_: Types.DialogType.t, /* Dialog type. */
        hasBrowserHandler: bool, /* True iff browser is capable showing or acting on the given dialog. When browser has no
dialog handler for given target, calling alert while Page domain is engaged will stall
the page execution. Execution can be resumed via calling Page.handleJavaScriptDialog. */
        [@yojson.option]
        defaultPrompt: option(string) /* Default dialog prompt. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired for top level page lifecycle events such as navigation, load, paint, etc. */
    module LifecycleEvent: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame. */
        loaderId: Network.Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        name: string, /* No description provided */
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired for failed bfcache history navigations if BackForwardCache feature is enabled. Do
       not assume any ordering with the Page.frameNavigated event. This event is fired only for
       main-frame history navigation where the document changes (non-same-document navigations),
       when bfcache navigation fails. */
    module BackForwardCacheNotUsed: {
      [@deriving yojson]
      type result = {
        loaderId: Network.Types.LoaderId.t, /* The loader id for the associated navgation. */
        frameId: Types.FrameId.t /* The frame id of the associated frame. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module LoadEventFired: {
      [@deriving yojson]
      type result = {
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when same-document navigation happens, e.g. due to history API usage or anchor navigation. */
    module NavigatedWithinDocument: {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame. */
        url: string /* Frame's new url. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Compressed image data requested by the `startScreencast`. */
    module ScreencastFrame: {
      [@deriving yojson]
      type result = {
        data: string, /* Base64-encoded compressed image. (Encoded as a base64 string when passed over JSON) */
        metadata: Types.ScreencastFrameMetadata.t, /* Screencast frame metadata. */
        sessionId: float /* Frame number. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when the page with currently enabled screencast was shown or hidden `. */
    module ScreencastVisibilityChanged: {
      [@deriving yojson]
      type result = {visible: bool /* True if the page is visible. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Fired when a new window is going to be opened, via window.open(), link click, form submission,
       etc. */
    module WindowOpen: {
      [@deriving yojson]
      type result = {
        url: string, /* The URL for the new window. */
        windowName: string, /* Window name. */
        windowFeatures: array(string), /* An array of enabled window features. */
        userGesture: bool /* Whether or not it was triggered by user gesture. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued for every compilation cache generated. Is only available
       if Page.setGenerateCompilationCache is enabled. */
    module CompilationCacheProduced: {
      [@deriving yojson]
      type result = {
        url: string, /* No description provided */
        data: string /* Base64-encoded data (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec FrameId: {
      /* Unique frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AdFrameType: {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    }
    and SecureContextType: {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginIsolatedContextType: {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and GatedAPIFeatures: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyFeature: {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockReason: {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockLocator: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: FrameId.t, /* No description provided */
        blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
      };
    }
    and PermissionsPolicyFeatureState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        feature: PermissionsPolicyFeature.t, /* No description provided */
        allowed: bool, /* No description provided */
        [@yojson.option]
        locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
      };
    }
    and OriginTrialTokenStatus: {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialStatus: {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialUsageRestriction: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialToken: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        origin: string, /* No description provided */
        matchSubDomains: bool, /* No description provided */
        trialName: string, /* No description provided */
        expiryTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        isThirdParty: bool, /* No description provided */
        usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
      };
    }
    and OriginTrialTokenWithStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        rawTokenText: string, /* No description provided */
        [@yojson.option]
        parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
        status: OriginTrialTokenStatus.t /* No description provided */,
      };
    }
    and OriginTrial: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        trialName: string, /* No description provided */
        status: OriginTrialStatus.t, /* No description provided */
        tokensWithStatus: array(OriginTrialTokenWithStatus.t) /* No description provided */,
      };
    }
    and Frame: {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {
        id: FrameId.t, /* Frame unique identifier. */
        [@yojson.option]
        parentId: option(string), /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        [@yojson.option]
        name: option(string), /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        [@yojson.option]
        urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        [@yojson.option]
        unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        [@yojson.option]
        adFrameType: option(AdFrameType.t), /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        [@yojson.option]
        originTrials: option(array(OriginTrial.t)) /* Frame document's origin trials with at least one token present. */,
      };
    }
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        [@key "type"]
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        lastModified: option(Network.Types.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
        [@yojson.option]
        contentSize: option(float), /* Resource content size. */
        [@yojson.option]
        failed: option(bool), /* True if the resource failed to load. */
        [@yojson.option]
        canceled: option(bool) /* True if the resource was canceled during loading. */,
      };
    }
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameResourceTree.t)), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    }
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameTree.t)) /* Child frames. */,
      };
    }
    and ScriptIdentifier: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and TransitionType: {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    }
    and NavigationEntry: {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the navigation history entry. */
        url: string, /* URL of the navigation history entry. */
        userTypedURL: string, /* URL that the user typed in the url bar. */
        title: string, /* Title of the navigation history entry. */
        transitionType: TransitionType.t /* Transition type. */,
      };
    }
    and ScreencastFrameMetadata: {
      /* Screencast frame metadata. */
      [@deriving yojson]
      type t = {
        offsetTop: float, /* Top offset in DIP. */
        pageScaleFactor: float, /* Page scale factor. */
        deviceWidth: float, /* Device screen width in DIP. */
        deviceHeight: float, /* Device screen height in DIP. */
        scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
        scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
        [@yojson.option]
        timestamp: option(Network.Types.TimeSinceEpoch.t) /* Frame swap timestamp. */,
      };
    }
    and DialogType: {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    }
    and AppManifestError: {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        critical: float, /* If criticial, this is a non-recoverable parse error. */
        line: float, /* Error line. */
        column: float /* Error column. */,
      };
    }
    and AppManifestParsedProperties: {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {scope: string /* Computed scope value */};
    }
    and LayoutViewport: {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
      };
    }
    and VisualViewport: {
      /* Visual viewport position, dimensions, and scale. */
      [@deriving yojson]
      type t = {
        offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
        offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
        scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
        [@yojson.option]
        zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
      };
    }
    and Viewport: {
      /* Viewport for capturing screenshot. */
      [@deriving yojson]
      type t = {
        x: float, /* X offset in device independent pixels (dip). */
        y: float, /* Y offset in device independent pixels (dip). */
        width: float, /* Rectangle width in device independent pixels (dip). */
        height: float, /* Rectangle height in device independent pixels (dip). */
        scale: float /* Page scale factor. */,
      };
    }
    and FontFamilies: {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(string), /* The standard font-family. */
        [@yojson.option]
        fixed: option(string), /* The fixed font-family. */
        [@yojson.option]
        serif: option(string), /* The serif font-family. */
        [@yojson.option]
        sansSerif: option(string), /* The sansSerif font-family. */
        [@yojson.option]
        cursive: option(string), /* The cursive font-family. */
        [@yojson.option]
        fantasy: option(string), /* The fantasy font-family. */
        [@yojson.option]
        pictograph: option(string) /* The pictograph font-family. */,
      };
    }
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(float), /* Default standard font size. */
        [@yojson.option]
        fixed: option(float) /* Default fixed font size. */,
      };
    }
    and ClientNavigationReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientNavigationDisposition: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and InstallabilityErrorArgument: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
        value: string /* Argument value (e.g. value:'64'). */,
      };
    }
    and InstallabilityError: {
      /* The installability error */
      [@deriving yojson]
      type t = {
        errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
        errorArguments: array(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
      };
    }
    and ReferrerPolicy: {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    }
    and CompilationCacheParams: {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {
        url: string, /* The URL of the script to produce a compilation cache entry for. */
        [@yojson.option]
        eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    }
    and NavigationType: {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec FrameId: {
      /* Unique frame identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AdFrameType: {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    }
    and SecureContextType: {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginIsolatedContextType: {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and GatedAPIFeatures: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyFeature: {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    } = {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockReason: {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockLocator: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: FrameId.t, /* No description provided */
        blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: FrameId.t, /* No description provided */
        blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
      };
    }
    and PermissionsPolicyFeatureState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        feature: PermissionsPolicyFeature.t, /* No description provided */
        allowed: bool, /* No description provided */
        [@yojson.option]
        locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        feature: PermissionsPolicyFeature.t, /* No description provided */
        allowed: bool, /* No description provided */
        [@yojson.option]
        locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
      };
    }
    and OriginTrialTokenStatus: {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialStatus: {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialUsageRestriction: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialToken: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        origin: string, /* No description provided */
        matchSubDomains: bool, /* No description provided */
        trialName: string, /* No description provided */
        expiryTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        isThirdParty: bool, /* No description provided */
        usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        origin: string, /* No description provided */
        matchSubDomains: bool, /* No description provided */
        trialName: string, /* No description provided */
        expiryTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        isThirdParty: bool, /* No description provided */
        usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
      };
    }
    and OriginTrialTokenWithStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        rawTokenText: string, /* No description provided */
        [@yojson.option]
        parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
        status: OriginTrialTokenStatus.t /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        rawTokenText: string, /* No description provided */
        [@yojson.option]
        parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
        status: OriginTrialTokenStatus.t /* No description provided */,
      };
    }
    and OriginTrial: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        trialName: string, /* No description provided */
        status: OriginTrialStatus.t, /* No description provided */
        tokensWithStatus: array(OriginTrialTokenWithStatus.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        trialName: string, /* No description provided */
        status: OriginTrialStatus.t, /* No description provided */
        tokensWithStatus: array(OriginTrialTokenWithStatus.t) /* No description provided */,
      };
    }
    and Frame: {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {
        id: FrameId.t, /* Frame unique identifier. */
        [@yojson.option]
        parentId: option(string), /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        [@yojson.option]
        name: option(string), /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        [@yojson.option]
        urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        [@yojson.option]
        unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        [@yojson.option]
        adFrameType: option(AdFrameType.t), /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        [@yojson.option]
        originTrials: option(array(OriginTrial.t)) /* Frame document's origin trials with at least one token present. */,
      };
    } = {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {
        id: FrameId.t, /* Frame unique identifier. */
        [@yojson.option]
        parentId: option(string), /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        [@yojson.option]
        name: option(string), /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        [@yojson.option]
        urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        [@yojson.option]
        unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        [@yojson.option]
        adFrameType: option(AdFrameType.t), /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        [@yojson.option]
        originTrials: option(array(OriginTrial.t)) /* Frame document's origin trials with at least one token present. */,
      };
    }
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        [@key "type"]
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        lastModified: option(Network.Types.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
        [@yojson.option]
        contentSize: option(float), /* Resource content size. */
        [@yojson.option]
        failed: option(bool), /* True if the resource failed to load. */
        [@yojson.option]
        canceled: option(bool) /* True if the resource was canceled during loading. */,
      };
    } = {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        [@key "type"]
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        [@yojson.option]
        lastModified: option(Network.Types.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
        [@yojson.option]
        contentSize: option(float), /* Resource content size. */
        [@yojson.option]
        failed: option(bool), /* True if the resource failed to load. */
        [@yojson.option]
        canceled: option(bool) /* True if the resource was canceled during loading. */,
      };
    }
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameResourceTree.t)), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    } = {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameResourceTree.t)), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    }
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameTree.t)) /* Child frames. */,
      };
    } = {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        [@yojson.option]
        childFrames: option(array(FrameTree.t)) /* Child frames. */,
      };
    }
    and ScriptIdentifier: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and TransitionType: {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    }
    and NavigationEntry: {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the navigation history entry. */
        url: string, /* URL of the navigation history entry. */
        userTypedURL: string, /* URL that the user typed in the url bar. */
        title: string, /* Title of the navigation history entry. */
        transitionType: TransitionType.t /* Transition type. */,
      };
    } = {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the navigation history entry. */
        url: string, /* URL of the navigation history entry. */
        userTypedURL: string, /* URL that the user typed in the url bar. */
        title: string, /* Title of the navigation history entry. */
        transitionType: TransitionType.t /* Transition type. */,
      };
    }
    and ScreencastFrameMetadata: {
      /* Screencast frame metadata. */
      [@deriving yojson]
      type t = {
        offsetTop: float, /* Top offset in DIP. */
        pageScaleFactor: float, /* Page scale factor. */
        deviceWidth: float, /* Device screen width in DIP. */
        deviceHeight: float, /* Device screen height in DIP. */
        scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
        scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
        [@yojson.option]
        timestamp: option(Network.Types.TimeSinceEpoch.t) /* Frame swap timestamp. */,
      };
    } = {
      /* Screencast frame metadata. */
      [@deriving yojson]
      type t = {
        offsetTop: float, /* Top offset in DIP. */
        pageScaleFactor: float, /* Page scale factor. */
        deviceWidth: float, /* Device screen width in DIP. */
        deviceHeight: float, /* Device screen height in DIP. */
        scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
        scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
        [@yojson.option]
        timestamp: option(Network.Types.TimeSinceEpoch.t) /* Frame swap timestamp. */,
      };
    }
    and DialogType: {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    }
    and AppManifestError: {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        critical: float, /* If criticial, this is a non-recoverable parse error. */
        line: float, /* Error line. */
        column: float /* Error column. */,
      };
    } = {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        critical: float, /* If criticial, this is a non-recoverable parse error. */
        line: float, /* Error line. */
        column: float /* Error column. */,
      };
    }
    and AppManifestParsedProperties: {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {scope: string /* Computed scope value */};
    } = {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {scope: string /* Computed scope value */};
    }
    and LayoutViewport: {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
      };
    } = {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
      };
    }
    and VisualViewport: {
      /* Visual viewport position, dimensions, and scale. */
      [@deriving yojson]
      type t = {
        offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
        offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
        scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
        [@yojson.option]
        zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
      };
    } = {
      /* Visual viewport position, dimensions, and scale. */
      [@deriving yojson]
      type t = {
        offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
        offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
        pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: float, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
        scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
        [@yojson.option]
        zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
      };
    }
    and Viewport: {
      /* Viewport for capturing screenshot. */
      [@deriving yojson]
      type t = {
        x: float, /* X offset in device independent pixels (dip). */
        y: float, /* Y offset in device independent pixels (dip). */
        width: float, /* Rectangle width in device independent pixels (dip). */
        height: float, /* Rectangle height in device independent pixels (dip). */
        scale: float /* Page scale factor. */,
      };
    } = {
      /* Viewport for capturing screenshot. */
      [@deriving yojson]
      type t = {
        x: float, /* X offset in device independent pixels (dip). */
        y: float, /* Y offset in device independent pixels (dip). */
        width: float, /* Rectangle width in device independent pixels (dip). */
        height: float, /* Rectangle height in device independent pixels (dip). */
        scale: float /* Page scale factor. */,
      };
    }
    and FontFamilies: {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(string), /* The standard font-family. */
        [@yojson.option]
        fixed: option(string), /* The fixed font-family. */
        [@yojson.option]
        serif: option(string), /* The serif font-family. */
        [@yojson.option]
        sansSerif: option(string), /* The sansSerif font-family. */
        [@yojson.option]
        cursive: option(string), /* The cursive font-family. */
        [@yojson.option]
        fantasy: option(string), /* The fantasy font-family. */
        [@yojson.option]
        pictograph: option(string) /* The pictograph font-family. */,
      };
    } = {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(string), /* The standard font-family. */
        [@yojson.option]
        fixed: option(string), /* The fixed font-family. */
        [@yojson.option]
        serif: option(string), /* The serif font-family. */
        [@yojson.option]
        sansSerif: option(string), /* The sansSerif font-family. */
        [@yojson.option]
        cursive: option(string), /* The cursive font-family. */
        [@yojson.option]
        fantasy: option(string), /* The fantasy font-family. */
        [@yojson.option]
        pictograph: option(string) /* The pictograph font-family. */,
      };
    }
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(float), /* Default standard font size. */
        [@yojson.option]
        fixed: option(float) /* Default fixed font size. */,
      };
    } = {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        standard: option(float), /* Default standard font size. */
        [@yojson.option]
        fixed: option(float) /* Default fixed font size. */,
      };
    }
    and ClientNavigationReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientNavigationDisposition: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and InstallabilityErrorArgument: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
        value: string /* Argument value (e.g. value:'64'). */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
        value: string /* Argument value (e.g. value:'64'). */,
      };
    }
    and InstallabilityError: {
      /* The installability error */
      [@deriving yojson]
      type t = {
        errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
        errorArguments: array(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
      };
    } = {
      /* The installability error */
      [@deriving yojson]
      type t = {
        errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
        errorArguments: array(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
      };
    }
    and ReferrerPolicy: {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    }
    and CompilationCacheParams: {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {
        url: string, /* The URL of the script to produce a compilation cache entry for. */
        [@yojson.option]
        eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    } = {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {
        url: string, /* The URL of the script to produce a compilation cache entry for. */
        [@yojson.option]
        eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    }
    and NavigationType: {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events = {
    /* No description provided */
    module DomContentEventFired = {
      [@deriving yojson]
      type result = {
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Emitted only when `page.interceptFileChooser` is enabled. */
    module FileChooserOpened = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame containing input node. */
        backendNodeId: DOM.Types.BackendNodeId.t, /* Input node id. */
        mode: string /* Input mode. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame has been attached to its parent. */
    module FrameAttached = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has been attached. */
        parentFrameId: Types.FrameId.t, /* Parent frame identifier. */
        [@yojson.option]
        stack: option(Runtime.Types.StackTrace.t) /* JavaScript stack trace of when frame was attached, only set if frame initiated from script. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame no longer has a scheduled navigation. */
    module FrameClearedScheduledNavigation = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has cleared its scheduled navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame has been detached from its parent. */
    module FrameDetached = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has been detached. */
        reason: string /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired once navigation of the frame has completed. Frame is now associated with the new loader. */
    module FrameNavigated = {
      [@deriving yojson]
      type result = {
        frame: Types.Frame.t, /* Frame object. */
        [@key "type"]
        type_: Types.NavigationType.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when opening document to write to. */
    module DocumentOpened = {
      [@deriving yojson]
      type result = {frame: Types.Frame.t /* Frame object. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module FrameResized = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when a renderer-initiated navigation is requested.
       Navigation may still be cancelled after the event is issued. */
    module FrameRequestedNavigation = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that is being navigated. */
        reason: Types.ClientNavigationReason.t, /* The reason for the navigation. */
        url: string, /* The destination URL for the requested navigation. */
        disposition: Types.ClientNavigationDisposition.t /* The disposition for the navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame schedules a potential navigation. */
    module FrameScheduledNavigation = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that has scheduled a navigation. */
        delay: float, /* Delay (in seconds) until the navigation is scheduled to begin. The navigation is not
guaranteed to start. */
        reason: Types.ClientNavigationReason.t, /* The reason for the navigation. */
        url: string /* The destination URL for the scheduled navigation. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame has started loading. */
    module FrameStartedLoading = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has started loading. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when frame has stopped loading. */
    module FrameStoppedLoading = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t /* Id of the frame that has stopped loading. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when page is about to start a download.
       Deprecated. Use Browser.downloadWillBegin instead. */
    module DownloadWillBegin = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame that caused download to begin. */
        guid: string, /* Global unique identifier of the download. */
        url: string, /* URL of the resource being downloaded. */
        suggestedFilename: string /* Suggested file name of the resource (the actual name of the file saved on disk may differ). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when download makes progress. Last call has |done| == true.
       Deprecated. Use Browser.downloadProgress instead. */
    module DownloadProgress = {
      [@deriving yojson]
      type result = {
        guid: string, /* Global unique identifier of the download. */
        totalBytes: float, /* Total expected bytes to download. */
        receivedBytes: float, /* Total bytes received. */
        state: string /* Download status. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when interstitial page was hidden */
    module InterstitialHidden = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when interstitial page was shown */
    module InterstitialShown = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) has been
       closed. */
    module JavascriptDialogClosed = {
      [@deriving yojson]
      type result = {
        result: bool, /* Whether dialog was confirmed. */
        userInput: string /* User input in case of prompt. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when a JavaScript initiated dialog (alert, confirm, prompt, or onbeforeunload) is about to
       open. */
    module JavascriptDialogOpening = {
      [@deriving yojson]
      type result = {
        url: string, /* Frame url. */
        message: string, /* Message that will be displayed by the dialog. */
        [@key "type"]
        type_: Types.DialogType.t, /* Dialog type. */
        hasBrowserHandler: bool, /* True iff browser is capable showing or acting on the given dialog. When browser has no
dialog handler for given target, calling alert while Page domain is engaged will stall
the page execution. Execution can be resumed via calling Page.handleJavaScriptDialog. */
        [@yojson.option]
        defaultPrompt: option(string) /* Default dialog prompt. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired for top level page lifecycle events such as navigation, load, paint, etc. */
    module LifecycleEvent = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame. */
        loaderId: Network.Types.LoaderId.t, /* Loader identifier. Empty string if the request is fetched from worker. */
        name: string, /* No description provided */
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired for failed bfcache history navigations if BackForwardCache feature is enabled. Do
       not assume any ordering with the Page.frameNavigated event. This event is fired only for
       main-frame history navigation where the document changes (non-same-document navigations),
       when bfcache navigation fails. */
    module BackForwardCacheNotUsed = {
      [@deriving yojson]
      type result = {
        loaderId: Network.Types.LoaderId.t, /* The loader id for the associated navgation. */
        frameId: Types.FrameId.t /* The frame id of the associated frame. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module LoadEventFired = {
      [@deriving yojson]
      type result = {
        timestamp: Network.Types.MonotonicTime.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when same-document navigation happens, e.g. due to history API usage or anchor navigation. */
    module NavigatedWithinDocument = {
      [@deriving yojson]
      type result = {
        frameId: Types.FrameId.t, /* Id of the frame. */
        url: string /* Frame's new url. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Compressed image data requested by the `startScreencast`. */
    module ScreencastFrame = {
      [@deriving yojson]
      type result = {
        data: string, /* Base64-encoded compressed image. (Encoded as a base64 string when passed over JSON) */
        metadata: Types.ScreencastFrameMetadata.t, /* Screencast frame metadata. */
        sessionId: float /* Frame number. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when the page with currently enabled screencast was shown or hidden `. */
    module ScreencastVisibilityChanged = {
      [@deriving yojson]
      type result = {visible: bool /* True if the page is visible. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Fired when a new window is going to be opened, via window.open(), link click, form submission,
       etc. */
    module WindowOpen = {
      [@deriving yojson]
      type result = {
        url: string, /* The URL for the new window. */
        windowName: string, /* Window name. */
        windowFeatures: array(string), /* An array of enabled window features. */
        userGesture: bool /* Whether or not it was triggered by user gesture. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued for every compilation cache generated. Is only available
       if Page.setGenerateCompilationCache is enabled. */
    module CompilationCacheProduced = {
      [@deriving yojson]
      type result = {
        url: string, /* No description provided */
        data: string /* Base64-encoded data (Encoded as a base64 string when passed over JSON) */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Performance: {
  module Types: {
    module rec Metric: {
      /* Run-time execution metric. */
      [@deriving yojson]
      type t = {
        name: string, /* Metric name. */
        value: float /* Metric value. */,
      };
    };
  };

  module Events: {
    /* Current values of the metrics. */
    module Metrics: {
      [@deriving yojson]
      type result = {
        metrics: array(Types.Metric.t), /* Current values of the metrics. */
        title: string /* Timestamp title. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec Metric: {
      /* Run-time execution metric. */
      [@deriving yojson]
      type t = {
        name: string, /* Metric name. */
        value: float /* Metric value. */,
      };
    };
  } = {
    module rec Metric: {
      /* Run-time execution metric. */
      [@deriving yojson]
      type t = {
        name: string, /* Metric name. */
        value: float /* Metric value. */,
      };
    } = {
      /* Run-time execution metric. */
      [@deriving yojson]
      type t = {
        name: string, /* Metric name. */
        value: float /* Metric value. */,
      };
    };
  };

  module Events = {
    /* Current values of the metrics. */
    module Metrics = {
      [@deriving yojson]
      type result = {
        metrics: array(Types.Metric.t), /* Current values of the metrics. */
        title: string /* Timestamp title. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and PerformanceTimeline: {
  module Types: {
    module rec LargestContentfulPaint: {
      /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
      [@deriving yojson]
      type t = {
        renderTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        loadTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        size: float, /* The number of pixels being painted. */
        [@yojson.option]
        elementId: option(string), /* The id attribute of the element, if available. */
        [@yojson.option]
        url: option(string), /* The URL of the image (may be trimmed). */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShift: {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {
        value: float, /* Score increment produced by this event. */
        hadRecentInput: bool, /* No description provided */
        lastInputTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        sources: array(LayoutShiftAttribution.t) /* No description provided */,
      };
    }
    and TimelineEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
        [@key "type"]
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        [@yojson.option]
        duration: option(float), /* Event duration, if applicable. */
        [@yojson.option]
        lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
        [@yojson.option]
        layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
      };
    };
  };

  module Events: {
    /* Sent when a performance timeline event is added. See reportPerformanceTimeline method. */
    module TimelineEventAdded: {
      [@deriving yojson]
      type result = {
        event: Types.TimelineEvent.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec LargestContentfulPaint: {
      /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
      [@deriving yojson]
      type t = {
        renderTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        loadTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        size: float, /* The number of pixels being painted. */
        [@yojson.option]
        elementId: option(string), /* The id attribute of the element, if available. */
        [@yojson.option]
        url: option(string), /* The URL of the image (may be trimmed). */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShift: {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {
        value: float, /* Score increment produced by this event. */
        hadRecentInput: bool, /* No description provided */
        lastInputTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        sources: array(LayoutShiftAttribution.t) /* No description provided */,
      };
    }
    and TimelineEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
        [@key "type"]
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        [@yojson.option]
        duration: option(float), /* Event duration, if applicable. */
        [@yojson.option]
        lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
        [@yojson.option]
        layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
      };
    };
  } = {
    module rec LargestContentfulPaint: {
      /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
      [@deriving yojson]
      type t = {
        renderTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        loadTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        size: float, /* The number of pixels being painted. */
        [@yojson.option]
        elementId: option(string), /* The id attribute of the element, if available. */
        [@yojson.option]
        url: option(string), /* The URL of the image (may be trimmed). */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    } = {
      /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
      [@deriving yojson]
      type t = {
        renderTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        loadTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        size: float, /* The number of pixels being painted. */
        [@yojson.option]
        elementId: option(string), /* The id attribute of the element, if available. */
        [@yojson.option]
        url: option(string), /* The URL of the image (may be trimmed). */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        [@yojson.option]
        nodeId: option(DOM.Types.BackendNodeId.t) /* No description provided */,
      };
    }
    and LayoutShift: {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {
        value: float, /* Score increment produced by this event. */
        hadRecentInput: bool, /* No description provided */
        lastInputTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        sources: array(LayoutShiftAttribution.t) /* No description provided */,
      };
    } = {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {
        value: float, /* Score increment produced by this event. */
        hadRecentInput: bool, /* No description provided */
        lastInputTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        sources: array(LayoutShiftAttribution.t) /* No description provided */,
      };
    }
    and TimelineEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
        [@key "type"]
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        [@yojson.option]
        duration: option(float), /* Event duration, if applicable. */
        [@yojson.option]
        lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
        [@yojson.option]
        layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
        [@key "type"]
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        [@yojson.option]
        duration: option(float), /* Event duration, if applicable. */
        [@yojson.option]
        lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
        [@yojson.option]
        layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
      };
    };
  };

  module Events = {
    /* Sent when a performance timeline event is added. See reportPerformanceTimeline method. */
    module TimelineEventAdded = {
      [@deriving yojson]
      type result = {
        event: Types.TimelineEvent.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Profiler: {
  module Types: {
    module rec ProfileNode: {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        [@yojson.option]
        hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
        [@yojson.option]
        children: option(array(float)), /* Child node ids. */
        [@yojson.option]
        deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        [@yojson.option]
        positionTicks: option(array(PositionTickInfo.t)) /* An array of source position ticks. */,
      };
    }
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        [@yojson.option]
        samples: option(array(float)), /* Ids of samples top nodes. */
        [@yojson.option]
        timeDeltas: option(array(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    }
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: float, /* Source line number (1-based). */
        ticks: float /* Number of samples attributed to the source line. */,
      };
    }
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: float, /* JavaScript script source offset for the range start. */
        endOffset: float, /* JavaScript script source offset for the range end. */
        count: float /* Collected execution count of the source range. */,
      };
    }
    and FunctionCoverage: {
      /* Coverage data for a JavaScript function. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        ranges: array(CoverageRange.t), /* Source ranges inside the function with coverage data. */
        isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
      };
    }
    and ScriptCoverage: {
      /* Coverage data for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        functions: array(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
      };
    }
    and TypeObject: {
      /* Describes a type collected during runtime. */
      [@deriving yojson]
      type t = {
        name: string /* Name of a type collected with type profiling. */,
      };
    }
    and TypeProfileEntry: {
      /* Source offset and types for a parameter or return value. */
      [@deriving yojson]
      type t = {
        offset: float, /* Source offset of the parameter or end of function for return values. */
        types: array(TypeObject.t) /* The types for this parameter or return value. */,
      };
    }
    and ScriptTypeProfile: {
      /* Type profile data collected during runtime for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        entries: array(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
      };
    }
    and CounterInfo: {
      /* Collected counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float /* Counter value. */,
      };
    }
    and RuntimeCallCounterInfo: {
      /* Runtime call counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float, /* Counter value. */
        time: float /* Counter time in seconds. */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module ConsoleProfileFinished: {
      [@deriving yojson]
      type result = {
        id: string, /* No description provided */
        location: Debugger.Types.Location.t, /* Location of console.profileEnd(). */
        profile: Types.Profile.t, /* No description provided */
        [@yojson.option]
        title: option(string) /* Profile title passed as an argument to console.profile(). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Sent when new profile recording is started using console.profile() call. */
    module ConsoleProfileStarted: {
      [@deriving yojson]
      type result = {
        id: string, /* No description provided */
        location: Debugger.Types.Location.t, /* Location of console.profile(). */
        [@yojson.option]
        title: option(string) /* Profile title passed as an argument to console.profile(). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Reports coverage delta since the last poll (either from an event like this, or from
       `takePreciseCoverage` for the current isolate. May only be sent if precise code
       coverage has been started. This event can be trigged by the embedder to, for example,
       trigger collection of coverage data immediatelly at a certain point in time. */
    module PreciseCoverageDeltaUpdate: {
      [@deriving yojson]
      type result = {
        timestamp: float, /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */
        occassion: string, /* Identifier for distinguishing coverage events. */
        result: array(Types.ScriptCoverage.t) /* Coverage data for the current isolate. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ProfileNode: {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        [@yojson.option]
        hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
        [@yojson.option]
        children: option(array(float)), /* Child node ids. */
        [@yojson.option]
        deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        [@yojson.option]
        positionTicks: option(array(PositionTickInfo.t)) /* An array of source position ticks. */,
      };
    }
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        [@yojson.option]
        samples: option(array(float)), /* Ids of samples top nodes. */
        [@yojson.option]
        timeDeltas: option(array(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    }
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: float, /* Source line number (1-based). */
        ticks: float /* Number of samples attributed to the source line. */,
      };
    }
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: float, /* JavaScript script source offset for the range start. */
        endOffset: float, /* JavaScript script source offset for the range end. */
        count: float /* Collected execution count of the source range. */,
      };
    }
    and FunctionCoverage: {
      /* Coverage data for a JavaScript function. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        ranges: array(CoverageRange.t), /* Source ranges inside the function with coverage data. */
        isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
      };
    }
    and ScriptCoverage: {
      /* Coverage data for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        functions: array(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
      };
    }
    and TypeObject: {
      /* Describes a type collected during runtime. */
      [@deriving yojson]
      type t = {
        name: string /* Name of a type collected with type profiling. */,
      };
    }
    and TypeProfileEntry: {
      /* Source offset and types for a parameter or return value. */
      [@deriving yojson]
      type t = {
        offset: float, /* Source offset of the parameter or end of function for return values. */
        types: array(TypeObject.t) /* The types for this parameter or return value. */,
      };
    }
    and ScriptTypeProfile: {
      /* Type profile data collected during runtime for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        entries: array(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
      };
    }
    and CounterInfo: {
      /* Collected counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float /* Counter value. */,
      };
    }
    and RuntimeCallCounterInfo: {
      /* Runtime call counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float, /* Counter value. */
        time: float /* Counter time in seconds. */,
      };
    };
  } = {
    module rec ProfileNode: {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        [@yojson.option]
        hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
        [@yojson.option]
        children: option(array(float)), /* Child node ids. */
        [@yojson.option]
        deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        [@yojson.option]
        positionTicks: option(array(PositionTickInfo.t)) /* An array of source position ticks. */,
      };
    } = {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: float, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        [@yojson.option]
        hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
        [@yojson.option]
        children: option(array(float)), /* Child node ids. */
        [@yojson.option]
        deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        [@yojson.option]
        positionTicks: option(array(PositionTickInfo.t)) /* An array of source position ticks. */,
      };
    }
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        [@yojson.option]
        samples: option(array(float)), /* Ids of samples top nodes. */
        [@yojson.option]
        timeDeltas: option(array(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    } = {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        [@yojson.option]
        samples: option(array(float)), /* Ids of samples top nodes. */
        [@yojson.option]
        timeDeltas: option(array(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    }
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: float, /* Source line number (1-based). */
        ticks: float /* Number of samples attributed to the source line. */,
      };
    } = {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: float, /* Source line number (1-based). */
        ticks: float /* Number of samples attributed to the source line. */,
      };
    }
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: float, /* JavaScript script source offset for the range start. */
        endOffset: float, /* JavaScript script source offset for the range end. */
        count: float /* Collected execution count of the source range. */,
      };
    } = {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: float, /* JavaScript script source offset for the range start. */
        endOffset: float, /* JavaScript script source offset for the range end. */
        count: float /* Collected execution count of the source range. */,
      };
    }
    and FunctionCoverage: {
      /* Coverage data for a JavaScript function. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        ranges: array(CoverageRange.t), /* Source ranges inside the function with coverage data. */
        isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
      };
    } = {
      /* Coverage data for a JavaScript function. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        ranges: array(CoverageRange.t), /* Source ranges inside the function with coverage data. */
        isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
      };
    }
    and ScriptCoverage: {
      /* Coverage data for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        functions: array(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
      };
    } = {
      /* Coverage data for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        functions: array(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
      };
    }
    and TypeObject: {
      /* Describes a type collected during runtime. */
      [@deriving yojson]
      type t = {
        name: string /* Name of a type collected with type profiling. */,
      };
    } = {
      /* Describes a type collected during runtime. */
      [@deriving yojson]
      type t = {
        name: string /* Name of a type collected with type profiling. */,
      };
    }
    and TypeProfileEntry: {
      /* Source offset and types for a parameter or return value. */
      [@deriving yojson]
      type t = {
        offset: float, /* Source offset of the parameter or end of function for return values. */
        types: array(TypeObject.t) /* The types for this parameter or return value. */,
      };
    } = {
      /* Source offset and types for a parameter or return value. */
      [@deriving yojson]
      type t = {
        offset: float, /* Source offset of the parameter or end of function for return values. */
        types: array(TypeObject.t) /* The types for this parameter or return value. */,
      };
    }
    and ScriptTypeProfile: {
      /* Type profile data collected during runtime for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        entries: array(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
      };
    } = {
      /* Type profile data collected during runtime for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        entries: array(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
      };
    }
    and CounterInfo: {
      /* Collected counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float /* Counter value. */,
      };
    } = {
      /* Collected counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float /* Counter value. */,
      };
    }
    and RuntimeCallCounterInfo: {
      /* Runtime call counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float, /* Counter value. */
        time: float /* Counter time in seconds. */,
      };
    } = {
      /* Runtime call counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float, /* Counter value. */
        time: float /* Counter time in seconds. */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module ConsoleProfileFinished = {
      [@deriving yojson]
      type result = {
        id: string, /* No description provided */
        location: Debugger.Types.Location.t, /* Location of console.profileEnd(). */
        profile: Types.Profile.t, /* No description provided */
        [@yojson.option]
        title: option(string) /* Profile title passed as an argument to console.profile(). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Sent when new profile recording is started using console.profile() call. */
    module ConsoleProfileStarted = {
      [@deriving yojson]
      type result = {
        id: string, /* No description provided */
        location: Debugger.Types.Location.t, /* Location of console.profile(). */
        [@yojson.option]
        title: option(string) /* Profile title passed as an argument to console.profile(). */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Reports coverage delta since the last poll (either from an event like this, or from
       `takePreciseCoverage` for the current isolate. May only be sent if precise code
       coverage has been started. This event can be trigged by the embedder to, for example,
       trigger collection of coverage data immediatelly at a certain point in time. */
    module PreciseCoverageDeltaUpdate = {
      [@deriving yojson]
      type result = {
        timestamp: float, /* Monotonically increasing time (in seconds) when the coverage update was taken in the backend. */
        occassion: string, /* Identifier for distinguishing coverage events. */
        result: array(Types.ScriptCoverage.t) /* Coverage data for the current isolate. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Runtime: {
  module Types: {
    module rec ScriptId: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObjectId: {
      /* Unique object identifier. */
      [@deriving yojson]
      type t = string;
    }
    and UnserializableValue: {
      /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
         `-Infinity`, and bigint literals. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObject: {
      /* Mirror object referencing original JavaScript object. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        [@yojson.option]
        className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
        [@yojson.option]
        value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
        [@yojson.option]
        preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
        [@yojson.option]
        customPreview: option(CustomPreview.t) /* No description provided */,
      };
    }
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        [@yojson.option]
        bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    }
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        [@yojson.option]
        entries: option(array(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    }
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        [@key "type"]
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        [@yojson.option]
        value: option(string), /* User-friendly property value string. */
        [@yojson.option]
        valuePreview: option(ObjectPreview.t), /* Nested value preview. */
        [@yojson.option]
        subtype: option(string) /* Object subtype hint. Specified for `object` type values only. */,
      };
    }
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    }
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the property. */
        [@yojson.option]
        writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        [@yojson.option]
        wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
        [@yojson.option]
        isOwn: option(bool), /* True if the property is owned for the object. */
        [@yojson.option]
        symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
      };
    }
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        [@yojson.option]
        value: option(RemoteObject.t) /* The value associated with the property. */,
      };
    }
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the private property. */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    }
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        value: option(string), /* Primitive value or serializable javascript object. */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t) /* Remote object handle. */,
      };
    }
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = float;
    }
    and ExecutionContextDescription: {
      /* Description of an isolated world. */
      [@deriving yojson]
      type t = {
        id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
        origin: string, /* Execution context origin. */
        name: string, /* Human readable name describing given context. */
        uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique accross
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
        [@yojson.option]
        auxData: option(assoc) /* Embedder-specific auxiliary data. */,
      };
    }
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: float, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: float, /* Line number of the exception location (0-based). */
        columnNumber: float, /* Column number of the exception location (0-based). */
        [@yojson.option]
        scriptId: option(ScriptId.t), /* Script ID of the exception location. */
        [@yojson.option]
        url: option(string), /* URL of the exception location, to be used when the script was not reported. */
        [@yojson.option]
        stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
        [@yojson.option] [@key "exception"]
        exception_: option(RemoteObject.t), /* Exception object if available. */
        [@yojson.option]
        executionContextId: option(ExecutionContextId.t) /* Identifier of the context where exception happened. */,
      };
    }
    and Timestamp: {
      /* Number of milliseconds since epoch. */
      [@deriving yojson]
      type t = float;
    }
    and TimeDelta: {
      /* Number of milliseconds. */
      [@deriving yojson]
      type t = float;
    }
    and CallFrame: {
      /* Stack entry for runtime errors and assertions. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        scriptId: ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        lineNumber: float, /* JavaScript script line number (0-based). */
        columnNumber: float /* JavaScript script column number (0-based). */,
      };
    }
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        [@yojson.option]
        parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        [@yojson.option]
        parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
      };
    }
    and UniqueDebuggerId: {
      /* Unique identifier of current debugger. */
      [@deriving yojson]
      type t = string;
    }
    and StackTraceId: {
      /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
         allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
      [@deriving yojson]
      type t = {
        id: string, /* No description provided */
        [@yojson.option]
        debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
      };
    };
  };

  module Events: {
    /* Notification is issued every time when binding is called. */
    module BindingCalled: {
      [@deriving yojson]
      type result = {
        name: string, /* No description provided */
        payload: string, /* No description provided */
        executionContextId: Types.ExecutionContextId.t /* Identifier of the context where the call was made. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when console API was called. */
    module ConsoleAPICalled: {
      [@deriving yojson]
      type result = {
        [@key "type"]
        type_: string, /* Type of the call. */
        args: array(Types.RemoteObject.t), /* Call arguments. */
        executionContextId: Types.ExecutionContextId.t, /* Identifier of the context where the call was made. */
        timestamp: Types.Timestamp.t, /* Call timestamp. */
        [@yojson.option]
        stackTrace: option(Types.StackTrace.t), /* Stack trace captured when the call was made. The async stack chain is automatically reported for
the following call types: `assert`, `error`, `trace`, `warning`. For other types the async call
chain can be retrieved using `Debugger.getStackTrace` and `stackTrace.parentId` field. */
        [@yojson.option]
        context: option(string) /* Console context descriptor for calls on non-default console context (not console.*):
'anonymous#unique-logger-id' for call on unnamed context, 'name#unique-logger-id' for call
on named context. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when unhandled exception was revoked. */
    module ExceptionRevoked: {
      [@deriving yojson]
      type result = {
        reason: string, /* Reason describing why exception was revoked. */
        exceptionId: float /* The id of revoked exception, as reported in `exceptionThrown`. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when exception was thrown and unhandled. */
    module ExceptionThrown: {
      [@deriving yojson]
      type result = {
        timestamp: Types.Timestamp.t, /* Timestamp of the exception. */
        exceptionDetails: Types.ExceptionDetails.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when new execution context is created. */
    module ExecutionContextCreated: {
      [@deriving yojson]
      type result = {
        context: Types.ExecutionContextDescription.t /* A newly created execution context. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when execution context is destroyed. */
    module ExecutionContextDestroyed: {
      [@deriving yojson]
      type result = {
        executionContextId: Types.ExecutionContextId.t /* Id of the destroyed context */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when all executionContexts were cleared in browser */
    module ExecutionContextsCleared: {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when object should be inspected (for example, as a result of inspect() command line API
       call). */
    module InspectRequested: {
      [@deriving yojson]
      type result = {
        [@key "object"]
        object_: Types.RemoteObject.t, /* No description provided */
        hints: assoc /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec ScriptId: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObjectId: {
      /* Unique object identifier. */
      [@deriving yojson]
      type t = string;
    }
    and UnserializableValue: {
      /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
         `-Infinity`, and bigint literals. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObject: {
      /* Mirror object referencing original JavaScript object. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        [@yojson.option]
        className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
        [@yojson.option]
        value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
        [@yojson.option]
        preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
        [@yojson.option]
        customPreview: option(CustomPreview.t) /* No description provided */,
      };
    }
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        [@yojson.option]
        bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    }
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        [@yojson.option]
        entries: option(array(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    }
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        [@key "type"]
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        [@yojson.option]
        value: option(string), /* User-friendly property value string. */
        [@yojson.option]
        valuePreview: option(ObjectPreview.t), /* Nested value preview. */
        [@yojson.option]
        subtype: option(string) /* Object subtype hint. Specified for `object` type values only. */,
      };
    }
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    }
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the property. */
        [@yojson.option]
        writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        [@yojson.option]
        wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
        [@yojson.option]
        isOwn: option(bool), /* True if the property is owned for the object. */
        [@yojson.option]
        symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
      };
    }
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        [@yojson.option]
        value: option(RemoteObject.t) /* The value associated with the property. */,
      };
    }
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the private property. */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    }
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        value: option(string), /* Primitive value or serializable javascript object. */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t) /* Remote object handle. */,
      };
    }
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = float;
    }
    and ExecutionContextDescription: {
      /* Description of an isolated world. */
      [@deriving yojson]
      type t = {
        id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
        origin: string, /* Execution context origin. */
        name: string, /* Human readable name describing given context. */
        uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique accross
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
        [@yojson.option]
        auxData: option(assoc) /* Embedder-specific auxiliary data. */,
      };
    }
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: float, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: float, /* Line number of the exception location (0-based). */
        columnNumber: float, /* Column number of the exception location (0-based). */
        [@yojson.option]
        scriptId: option(ScriptId.t), /* Script ID of the exception location. */
        [@yojson.option]
        url: option(string), /* URL of the exception location, to be used when the script was not reported. */
        [@yojson.option]
        stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
        [@yojson.option] [@key "exception"]
        exception_: option(RemoteObject.t), /* Exception object if available. */
        [@yojson.option]
        executionContextId: option(ExecutionContextId.t) /* Identifier of the context where exception happened. */,
      };
    }
    and Timestamp: {
      /* Number of milliseconds since epoch. */
      [@deriving yojson]
      type t = float;
    }
    and TimeDelta: {
      /* Number of milliseconds. */
      [@deriving yojson]
      type t = float;
    }
    and CallFrame: {
      /* Stack entry for runtime errors and assertions. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        scriptId: ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        lineNumber: float, /* JavaScript script line number (0-based). */
        columnNumber: float /* JavaScript script column number (0-based). */,
      };
    }
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        [@yojson.option]
        parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        [@yojson.option]
        parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
      };
    }
    and UniqueDebuggerId: {
      /* Unique identifier of current debugger. */
      [@deriving yojson]
      type t = string;
    }
    and StackTraceId: {
      /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
         allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
      [@deriving yojson]
      type t = {
        id: string, /* No description provided */
        [@yojson.option]
        debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
      };
    };
  } = {
    module rec ScriptId: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObjectId: {
      /* Unique object identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique object identifier. */
      [@deriving yojson]
      type t = string;
    }
    and UnserializableValue: {
      /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
         `-Infinity`, and bigint literals. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
         `-Infinity`, and bigint literals. */
      [@deriving yojson]
      type t = string;
    }
    and RemoteObject: {
      /* Mirror object referencing original JavaScript object. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        [@yojson.option]
        className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
        [@yojson.option]
        value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
        [@yojson.option]
        preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
        [@yojson.option]
        customPreview: option(CustomPreview.t) /* No description provided */,
      };
    } = {
      /* Mirror object referencing original JavaScript object. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        [@yojson.option]
        className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
        [@yojson.option]
        value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
        [@yojson.option]
        preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
        [@yojson.option]
        customPreview: option(CustomPreview.t) /* No description provided */,
      };
    }
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        [@yojson.option]
        bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        [@yojson.option]
        bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    }
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        [@yojson.option]
        entries: option(array(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    } = {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Object type. */
        [@yojson.option]
        subtype: option(string), /* Object subtype hint. Specified for `object` type values only. */
        [@yojson.option]
        description: option(string), /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        [@yojson.option]
        entries: option(array(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    }
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        [@key "type"]
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        [@yojson.option]
        value: option(string), /* User-friendly property value string. */
        [@yojson.option]
        valuePreview: option(ObjectPreview.t), /* Nested value preview. */
        [@yojson.option]
        subtype: option(string) /* Object subtype hint. Specified for `object` type values only. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        [@key "type"]
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        [@yojson.option]
        value: option(string), /* User-friendly property value string. */
        [@yojson.option]
        valuePreview: option(ObjectPreview.t), /* Nested value preview. */
        [@yojson.option]
        subtype: option(string) /* Object subtype hint. Specified for `object` type values only. */,
      };
    }
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    }
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the property. */
        [@yojson.option]
        writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        [@yojson.option]
        wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
        [@yojson.option]
        isOwn: option(bool), /* True if the property is owned for the object. */
        [@yojson.option]
        symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
      };
    } = {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the property. */
        [@yojson.option]
        writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        [@yojson.option]
        wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
        [@yojson.option]
        isOwn: option(bool), /* True if the property is owned for the object. */
        [@yojson.option]
        symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
      };
    }
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        [@yojson.option]
        value: option(RemoteObject.t) /* The value associated with the property. */,
      };
    } = {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        [@yojson.option]
        value: option(RemoteObject.t) /* The value associated with the property. */,
      };
    }
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the private property. */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    } = {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        [@yojson.option]
        value: option(RemoteObject.t), /* The value associated with the private property. */
        [@yojson.option]
        get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        [@yojson.option]
        set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    }
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        value: option(string), /* Primitive value or serializable javascript object. */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t) /* Remote object handle. */,
      };
    } = {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        value: option(string), /* Primitive value or serializable javascript object. */
        [@yojson.option]
        unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
        [@yojson.option]
        objectId: option(RemoteObjectId.t) /* Remote object handle. */,
      };
    }
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = float;
    }
    and ExecutionContextDescription: {
      /* Description of an isolated world. */
      [@deriving yojson]
      type t = {
        id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
        origin: string, /* Execution context origin. */
        name: string, /* Human readable name describing given context. */
        uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique accross
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
        [@yojson.option]
        auxData: option(assoc) /* Embedder-specific auxiliary data. */,
      };
    } = {
      /* Description of an isolated world. */
      [@deriving yojson]
      type t = {
        id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
        origin: string, /* Execution context origin. */
        name: string, /* Human readable name describing given context. */
        uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique accross
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
        [@yojson.option]
        auxData: option(assoc) /* Embedder-specific auxiliary data. */,
      };
    }
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: float, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: float, /* Line number of the exception location (0-based). */
        columnNumber: float, /* Column number of the exception location (0-based). */
        [@yojson.option]
        scriptId: option(ScriptId.t), /* Script ID of the exception location. */
        [@yojson.option]
        url: option(string), /* URL of the exception location, to be used when the script was not reported. */
        [@yojson.option]
        stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
        [@yojson.option] [@key "exception"]
        exception_: option(RemoteObject.t), /* Exception object if available. */
        [@yojson.option]
        executionContextId: option(ExecutionContextId.t) /* Identifier of the context where exception happened. */,
      };
    } = {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: float, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: float, /* Line number of the exception location (0-based). */
        columnNumber: float, /* Column number of the exception location (0-based). */
        [@yojson.option]
        scriptId: option(ScriptId.t), /* Script ID of the exception location. */
        [@yojson.option]
        url: option(string), /* URL of the exception location, to be used when the script was not reported. */
        [@yojson.option]
        stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
        [@yojson.option] [@key "exception"]
        exception_: option(RemoteObject.t), /* Exception object if available. */
        [@yojson.option]
        executionContextId: option(ExecutionContextId.t) /* Identifier of the context where exception happened. */,
      };
    }
    and Timestamp: {
      /* Number of milliseconds since epoch. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Number of milliseconds since epoch. */
      [@deriving yojson]
      type t = float;
    }
    and TimeDelta: {
      /* Number of milliseconds. */
      [@deriving yojson]
      type t = float;
    } = {
      /* Number of milliseconds. */
      [@deriving yojson]
      type t = float;
    }
    and CallFrame: {
      /* Stack entry for runtime errors and assertions. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        scriptId: ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        lineNumber: float, /* JavaScript script line number (0-based). */
        columnNumber: float /* JavaScript script column number (0-based). */,
      };
    } = {
      /* Stack entry for runtime errors and assertions. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        scriptId: ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        lineNumber: float, /* JavaScript script line number (0-based). */
        columnNumber: float /* JavaScript script column number (0-based). */,
      };
    }
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        [@yojson.option]
        parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        [@yojson.option]
        parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
      };
    } = {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        [@yojson.option]
        parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        [@yojson.option]
        parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
      };
    }
    and UniqueDebuggerId: {
      /* Unique identifier of current debugger. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique identifier of current debugger. */
      [@deriving yojson]
      type t = string;
    }
    and StackTraceId: {
      /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
         allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
      [@deriving yojson]
      type t = {
        id: string, /* No description provided */
        [@yojson.option]
        debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
      };
    } = {
      /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
         allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
      [@deriving yojson]
      type t = {
        id: string, /* No description provided */
        [@yojson.option]
        debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
      };
    };
  };

  module Events = {
    /* Notification is issued every time when binding is called. */
    module BindingCalled = {
      [@deriving yojson]
      type result = {
        name: string, /* No description provided */
        payload: string, /* No description provided */
        executionContextId: Types.ExecutionContextId.t /* Identifier of the context where the call was made. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when console API was called. */
    module ConsoleAPICalled = {
      [@deriving yojson]
      type result = {
        [@key "type"]
        type_: string, /* Type of the call. */
        args: array(Types.RemoteObject.t), /* Call arguments. */
        executionContextId: Types.ExecutionContextId.t, /* Identifier of the context where the call was made. */
        timestamp: Types.Timestamp.t, /* Call timestamp. */
        [@yojson.option]
        stackTrace: option(Types.StackTrace.t), /* Stack trace captured when the call was made. The async stack chain is automatically reported for
the following call types: `assert`, `error`, `trace`, `warning`. For other types the async call
chain can be retrieved using `Debugger.getStackTrace` and `stackTrace.parentId` field. */
        [@yojson.option]
        context: option(string) /* Console context descriptor for calls on non-default console context (not console.*):
'anonymous#unique-logger-id' for call on unnamed context, 'name#unique-logger-id' for call
on named context. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when unhandled exception was revoked. */
    module ExceptionRevoked = {
      [@deriving yojson]
      type result = {
        reason: string, /* Reason describing why exception was revoked. */
        exceptionId: float /* The id of revoked exception, as reported in `exceptionThrown`. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when exception was thrown and unhandled. */
    module ExceptionThrown = {
      [@deriving yojson]
      type result = {
        timestamp: Types.Timestamp.t, /* Timestamp of the exception. */
        exceptionDetails: Types.ExceptionDetails.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when new execution context is created. */
    module ExecutionContextCreated = {
      [@deriving yojson]
      type result = {
        context: Types.ExecutionContextDescription.t /* A newly created execution context. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when execution context is destroyed. */
    module ExecutionContextDestroyed = {
      [@deriving yojson]
      type result = {
        executionContextId: Types.ExecutionContextId.t /* Id of the destroyed context */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when all executionContexts were cleared in browser */
    module ExecutionContextsCleared = {
      [@deriving yojson]
      type result = empty;

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when object should be inspected (for example, as a result of inspect() command line API
       call). */
    module InspectRequested = {
      [@deriving yojson]
      type result = {
        [@key "object"]
        object_: Types.RemoteObject.t, /* No description provided */
        hints: assoc /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Schema: {
  module Types: {
    module rec Domain: {
      /* Description of the protocol domain. */
      [@deriving yojson]
      type t = {
        name: string, /* Domain name. */
        version: string /* Domain version. */,
      };
    };
  };
} = {
  module Types: {
    module rec Domain: {
      /* Description of the protocol domain. */
      [@deriving yojson]
      type t = {
        name: string, /* Domain name. */
        version: string /* Domain version. */,
      };
    };
  } = {
    module rec Domain: {
      /* Description of the protocol domain. */
      [@deriving yojson]
      type t = {
        name: string, /* Domain name. */
        version: string /* Domain version. */,
      };
    } = {
      /* Description of the protocol domain. */
      [@deriving yojson]
      type t = {
        name: string, /* Domain name. */
        version: string /* Domain version. */,
      };
    };
  };
}
and Security: {
  module Types: {
    module rec CertificateId: {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = float;
    }
    and MixedContentType: {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    }
    and SecurityState: {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    }
    and CertificateSecurityState: {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        [@yojson.option]
        certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
        certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
        certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
        modernSSL: bool, /* True if modern SSL */
        obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
        obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
        obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
        obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
      };
    }
    and SafetyTipStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SafetyTipInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
        [@yojson.option]
        safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    }
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        [@yojson.option]
        certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
        [@yojson.option]
        safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
        securityStateIssueIds: array(string) /* Array of security state issues ids. */,
      };
    }
    and SecurityStateExplanation: {
      /* An explanation of an factor contributing to the security state. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
        title: string, /* Title describing the type of factor. */
        summary: string, /* Short phrase describing the type of factor. */
        description: string, /* Full text explanation of the factor. */
        mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
        certificate: array(string), /* Page certificate. */
        [@yojson.option]
        recommendations: option(array(string)) /* Recommendations to fix any issues. */,
      };
    }
    and InsecureContentStatus: {
      /* Information about insecure content on the page. */
      [@deriving yojson]
      type t = {
        ranMixedContent: bool, /* Always false. */
        displayedMixedContent: bool, /* Always false. */
        containedMixedForm: bool, /* Always false. */
        ranContentWithCertErrors: bool, /* Always false. */
        displayedContentWithCertErrors: bool, /* Always false. */
        ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
        displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
      };
    }
    and CertificateErrorAction: {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events: {
    /* There is a certificate error. If overriding certificate errors is enabled, then it should be
       handled with the `handleCertificateError` command. Note: this event does not fire if the
       certificate error has been allowed internally. Only one client per target should override
       certificate errors at the same time. */
    module CertificateError: {
      [@deriving yojson]
      type result = {
        eventId: float, /* The ID of the event. */
        errorType: string, /* The type of the error. */
        requestURL: string /* The url that was requested. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* The security state of the page changed. */
    module VisibleSecurityStateChanged: {
      [@deriving yojson]
      type result = {
        visibleSecurityState: Types.VisibleSecurityState.t /* Security state information about the page. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* The security state of the page changed. */
    module SecurityStateChanged: {
      [@deriving yojson]
      type result = {
        securityState: Types.SecurityState.t, /* Security state. */
        schemeIsCryptographic: bool, /* True if the page was loaded over cryptographic transport such as HTTPS. */
        explanations: array(Types.SecurityStateExplanation.t), /* List of explanations for the security state. If the overall security state is `insecure` or
`warning`, at least one corresponding explanation should be included. */
        insecureContentStatus: Types.InsecureContentStatus.t, /* Information about insecure content on the page. */
        [@yojson.option]
        summary: option(string) /* Overrides user-visible description of the state. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec CertificateId: {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = float;
    }
    and MixedContentType: {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    }
    and SecurityState: {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    }
    and CertificateSecurityState: {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        [@yojson.option]
        certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
        certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
        certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
        modernSSL: bool, /* True if modern SSL */
        obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
        obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
        obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
        obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
      };
    }
    and SafetyTipStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SafetyTipInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
        [@yojson.option]
        safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    }
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        [@yojson.option]
        certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
        [@yojson.option]
        safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
        securityStateIssueIds: array(string) /* Array of security state issues ids. */,
      };
    }
    and SecurityStateExplanation: {
      /* An explanation of an factor contributing to the security state. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
        title: string, /* Title describing the type of factor. */
        summary: string, /* Short phrase describing the type of factor. */
        description: string, /* Full text explanation of the factor. */
        mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
        certificate: array(string), /* Page certificate. */
        [@yojson.option]
        recommendations: option(array(string)) /* Recommendations to fix any issues. */,
      };
    }
    and InsecureContentStatus: {
      /* Information about insecure content on the page. */
      [@deriving yojson]
      type t = {
        ranMixedContent: bool, /* Always false. */
        displayedMixedContent: bool, /* Always false. */
        containedMixedForm: bool, /* Always false. */
        ranContentWithCertErrors: bool, /* Always false. */
        displayedContentWithCertErrors: bool, /* Always false. */
        ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
        displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
      };
    }
    and CertificateErrorAction: {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec CertificateId: {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = float;
    } = {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = float;
    }
    and MixedContentType: {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    } = {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    }
    and SecurityState: {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    }
    and CertificateSecurityState: {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        [@yojson.option]
        certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
        certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
        certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
        modernSSL: bool, /* True if modern SSL */
        obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
        obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
        obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
        obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
      };
    } = {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        [@yojson.option]
        keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        [@yojson.option]
        mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        [@yojson.option]
        certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
        certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
        certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
        modernSSL: bool, /* True if modern SSL */
        obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
        obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
        obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
        obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
      };
    }
    and SafetyTipStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SafetyTipInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
        [@yojson.option]
        safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
        [@yojson.option]
        safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    }
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        [@yojson.option]
        certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
        [@yojson.option]
        safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
        securityStateIssueIds: array(string) /* Array of security state issues ids. */,
      };
    } = {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        [@yojson.option]
        certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
        [@yojson.option]
        safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
        securityStateIssueIds: array(string) /* Array of security state issues ids. */,
      };
    }
    and SecurityStateExplanation: {
      /* An explanation of an factor contributing to the security state. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
        title: string, /* Title describing the type of factor. */
        summary: string, /* Short phrase describing the type of factor. */
        description: string, /* Full text explanation of the factor. */
        mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
        certificate: array(string), /* Page certificate. */
        [@yojson.option]
        recommendations: option(array(string)) /* Recommendations to fix any issues. */,
      };
    } = {
      /* An explanation of an factor contributing to the security state. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
        title: string, /* Title describing the type of factor. */
        summary: string, /* Short phrase describing the type of factor. */
        description: string, /* Full text explanation of the factor. */
        mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
        certificate: array(string), /* Page certificate. */
        [@yojson.option]
        recommendations: option(array(string)) /* Recommendations to fix any issues. */,
      };
    }
    and InsecureContentStatus: {
      /* Information about insecure content on the page. */
      [@deriving yojson]
      type t = {
        ranMixedContent: bool, /* Always false. */
        displayedMixedContent: bool, /* Always false. */
        containedMixedForm: bool, /* Always false. */
        ranContentWithCertErrors: bool, /* Always false. */
        displayedContentWithCertErrors: bool, /* Always false. */
        ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
        displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
      };
    } = {
      /* Information about insecure content on the page. */
      [@deriving yojson]
      type t = {
        ranMixedContent: bool, /* Always false. */
        displayedMixedContent: bool, /* Always false. */
        containedMixedForm: bool, /* Always false. */
        ranContentWithCertErrors: bool, /* Always false. */
        displayedContentWithCertErrors: bool, /* Always false. */
        ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
        displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
      };
    }
    and CertificateErrorAction: {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    } = {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events = {
    /* There is a certificate error. If overriding certificate errors is enabled, then it should be
       handled with the `handleCertificateError` command. Note: this event does not fire if the
       certificate error has been allowed internally. Only one client per target should override
       certificate errors at the same time. */
    module CertificateError = {
      [@deriving yojson]
      type result = {
        eventId: float, /* The ID of the event. */
        errorType: string, /* The type of the error. */
        requestURL: string /* The url that was requested. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* The security state of the page changed. */
    module VisibleSecurityStateChanged = {
      [@deriving yojson]
      type result = {
        visibleSecurityState: Types.VisibleSecurityState.t /* Security state information about the page. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* The security state of the page changed. */
    module SecurityStateChanged = {
      [@deriving yojson]
      type result = {
        securityState: Types.SecurityState.t, /* Security state. */
        schemeIsCryptographic: bool, /* True if the page was loaded over cryptographic transport such as HTTPS. */
        explanations: array(Types.SecurityStateExplanation.t), /* List of explanations for the security state. If the overall security state is `insecure` or
`warning`, at least one corresponding explanation should be included. */
        insecureContentStatus: Types.InsecureContentStatus.t, /* Information about insecure content on the page. */
        [@yojson.option]
        summary: option(string) /* Overrides user-visible description of the state. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and ServiceWorker: {
  module Types: {
    module rec RegistrationID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerRegistration: {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {
        registrationId: RegistrationID.t, /* No description provided */
        scopeURL: string, /* No description provided */
        isDeleted: bool /* No description provided */,
      };
    }
    and ServiceWorkerVersionRunningStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersion: {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {
        versionId: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        scriptURL: string, /* No description provided */
        runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
        status: ServiceWorkerVersionStatus.t, /* No description provided */
        [@yojson.option]
        scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
        [@yojson.option]
        scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        [@yojson.option]
        controlledClients: option(array(Target.Types.TargetID.t)), /* No description provided */
        [@yojson.option]
        targetId: option(Target.Types.TargetID.t) /* No description provided */,
      };
    }
    and ServiceWorkerErrorMessage: {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {
        errorMessage: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        versionId: string, /* No description provided */
        sourceURL: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    };
  };

  module Events: {
    /* No description provided */
    module WorkerErrorReported: {
      [@deriving yojson]
      type result = {
        errorMessage: Types.ServiceWorkerErrorMessage.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module WorkerRegistrationUpdated: {
      [@deriving yojson]
      type result = {
        registrations: array(Types.ServiceWorkerRegistration.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* No description provided */
    module WorkerVersionUpdated: {
      [@deriving yojson]
      type result = {
        versions: array(Types.ServiceWorkerVersion.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec RegistrationID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerRegistration: {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {
        registrationId: RegistrationID.t, /* No description provided */
        scopeURL: string, /* No description provided */
        isDeleted: bool /* No description provided */,
      };
    }
    and ServiceWorkerVersionRunningStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersion: {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {
        versionId: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        scriptURL: string, /* No description provided */
        runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
        status: ServiceWorkerVersionStatus.t, /* No description provided */
        [@yojson.option]
        scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
        [@yojson.option]
        scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        [@yojson.option]
        controlledClients: option(array(Target.Types.TargetID.t)), /* No description provided */
        [@yojson.option]
        targetId: option(Target.Types.TargetID.t) /* No description provided */,
      };
    }
    and ServiceWorkerErrorMessage: {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {
        errorMessage: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        versionId: string, /* No description provided */
        sourceURL: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    };
  } = {
    module rec RegistrationID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerRegistration: {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {
        registrationId: RegistrationID.t, /* No description provided */
        scopeURL: string, /* No description provided */
        isDeleted: bool /* No description provided */,
      };
    } = {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {
        registrationId: RegistrationID.t, /* No description provided */
        scopeURL: string, /* No description provided */
        isDeleted: bool /* No description provided */,
      };
    }
    and ServiceWorkerVersionRunningStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersion: {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {
        versionId: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        scriptURL: string, /* No description provided */
        runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
        status: ServiceWorkerVersionStatus.t, /* No description provided */
        [@yojson.option]
        scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
        [@yojson.option]
        scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        [@yojson.option]
        controlledClients: option(array(Target.Types.TargetID.t)), /* No description provided */
        [@yojson.option]
        targetId: option(Target.Types.TargetID.t) /* No description provided */,
      };
    } = {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {
        versionId: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        scriptURL: string, /* No description provided */
        runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
        status: ServiceWorkerVersionStatus.t, /* No description provided */
        [@yojson.option]
        scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
        [@yojson.option]
        scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        [@yojson.option]
        controlledClients: option(array(Target.Types.TargetID.t)), /* No description provided */
        [@yojson.option]
        targetId: option(Target.Types.TargetID.t) /* No description provided */,
      };
    }
    and ServiceWorkerErrorMessage: {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {
        errorMessage: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        versionId: string, /* No description provided */
        sourceURL: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    } = {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {
        errorMessage: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        versionId: string, /* No description provided */
        sourceURL: string, /* No description provided */
        lineNumber: float, /* No description provided */
        columnNumber: float /* No description provided */,
      };
    };
  };

  module Events = {
    /* No description provided */
    module WorkerErrorReported = {
      [@deriving yojson]
      type result = {
        errorMessage: Types.ServiceWorkerErrorMessage.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module WorkerRegistrationUpdated = {
      [@deriving yojson]
      type result = {
        registrations: array(Types.ServiceWorkerRegistration.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* No description provided */
    module WorkerVersionUpdated = {
      [@deriving yojson]
      type result = {
        versions: array(Types.ServiceWorkerVersion.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Storage: {
  module Types: {
    module rec StorageType: {
      /* Enum of possible storage types. */
      [@deriving yojson]
      type t = string;
    }
    and UsageForType: {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {
        storageType: StorageType.t, /* Name of storage type. */
        usage: float /* Storage usage (bytes). */,
      };
    }
    and TrustTokens: {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {
        issuerOrigin: string, /* No description provided */
        count: float /* No description provided */,
      };
    };
  };

  module Events: {
    /* A cache's contents have been modified. */
    module CacheStorageContentUpdated: {
      [@deriving yojson]
      type result = {
        origin: string, /* Origin to update. */
        cacheName: string /* Name of cache in origin. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* A cache has been added/deleted. */
    module CacheStorageListUpdated: {
      [@deriving yojson]
      type result = {origin: string /* Origin to update. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* The origin's IndexedDB object store has been modified. */
    module IndexedDBContentUpdated: {
      [@deriving yojson]
      type result = {
        origin: string, /* Origin to update. */
        databaseName: string, /* Database to update. */
        objectStoreName: string /* ObjectStore to update. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* The origin's IndexedDB database list has been modified. */
    module IndexedDBListUpdated: {
      [@deriving yojson]
      type result = {origin: string /* Origin to update. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec StorageType: {
      /* Enum of possible storage types. */
      [@deriving yojson]
      type t = string;
    }
    and UsageForType: {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {
        storageType: StorageType.t, /* Name of storage type. */
        usage: float /* Storage usage (bytes). */,
      };
    }
    and TrustTokens: {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {
        issuerOrigin: string, /* No description provided */
        count: float /* No description provided */,
      };
    };
  } = {
    module rec StorageType: {
      /* Enum of possible storage types. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of possible storage types. */
      [@deriving yojson]
      type t = string;
    }
    and UsageForType: {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {
        storageType: StorageType.t, /* Name of storage type. */
        usage: float /* Storage usage (bytes). */,
      };
    } = {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {
        storageType: StorageType.t, /* Name of storage type. */
        usage: float /* Storage usage (bytes). */,
      };
    }
    and TrustTokens: {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {
        issuerOrigin: string, /* No description provided */
        count: float /* No description provided */,
      };
    } = {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {
        issuerOrigin: string, /* No description provided */
        count: float /* No description provided */,
      };
    };
  };

  module Events = {
    /* A cache's contents have been modified. */
    module CacheStorageContentUpdated = {
      [@deriving yojson]
      type result = {
        origin: string, /* Origin to update. */
        cacheName: string /* Name of cache in origin. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* A cache has been added/deleted. */
    module CacheStorageListUpdated = {
      [@deriving yojson]
      type result = {origin: string /* Origin to update. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* The origin's IndexedDB object store has been modified. */
    module IndexedDBContentUpdated = {
      [@deriving yojson]
      type result = {
        origin: string, /* Origin to update. */
        databaseName: string, /* Database to update. */
        objectStoreName: string /* ObjectStore to update. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* The origin's IndexedDB database list has been modified. */
    module IndexedDBListUpdated = {
      [@deriving yojson]
      type result = {origin: string /* Origin to update. */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and SystemInfo: {
  module Types: {
    module rec GPUDevice: {
      /* Describes a single graphics processor (GPU). */
      [@deriving yojson]
      type t = {
        vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
        deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
        [@yojson.option]
        subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
        [@yojson.option]
        revision: option(float), /* Revision of the GPU, only available on Windows. */
        vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
        deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
        driverVendor: string, /* String description of the GPU driver vendor. */
        driverVersion: string /* String description of the GPU driver version. */,
      };
    }
    and Size: {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {
        width: float, /* Width in pixels. */
        height: float /* Height in pixels. */,
      };
    }
    and VideoDecodeAcceleratorCapability: {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
      };
    }
    and VideoEncodeAcceleratorCapability: {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g H264 Main. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: float /* No description provided */,
      };
    }
    and SubsamplingFormat: {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageType: {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageDecodeAcceleratorCapability: {
      /* Describes a supported image decoding profile with its associated minimum and
         maximum resolutions and subsampling. */
      [@deriving yojson]
      type t = {
        imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
        maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
        minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
        subsamplings: array(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
      };
    }
    and GPUInfo: {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {
        devices: array(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
        [@yojson.option]
        auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
        [@yojson.option]
        featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
        driverBugWorkarounds: array(string), /* An optional array of GPU driver bug workarounds. */
        videoDecoding: array(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
        videoEncoding: array(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
        imageDecoding: array(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
      };
    }
    and ProcessInfo: {
      /* Represents process info. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Specifies process type. */
        id: float, /* Specifies process id. */
        cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
      };
    };
  };
} = {
  module Types: {
    module rec GPUDevice: {
      /* Describes a single graphics processor (GPU). */
      [@deriving yojson]
      type t = {
        vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
        deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
        [@yojson.option]
        subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
        [@yojson.option]
        revision: option(float), /* Revision of the GPU, only available on Windows. */
        vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
        deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
        driverVendor: string, /* String description of the GPU driver vendor. */
        driverVersion: string /* String description of the GPU driver version. */,
      };
    }
    and Size: {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {
        width: float, /* Width in pixels. */
        height: float /* Height in pixels. */,
      };
    }
    and VideoDecodeAcceleratorCapability: {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
      };
    }
    and VideoEncodeAcceleratorCapability: {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g H264 Main. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: float /* No description provided */,
      };
    }
    and SubsamplingFormat: {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageType: {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageDecodeAcceleratorCapability: {
      /* Describes a supported image decoding profile with its associated minimum and
         maximum resolutions and subsampling. */
      [@deriving yojson]
      type t = {
        imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
        maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
        minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
        subsamplings: array(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
      };
    }
    and GPUInfo: {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {
        devices: array(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
        [@yojson.option]
        auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
        [@yojson.option]
        featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
        driverBugWorkarounds: array(string), /* An optional array of GPU driver bug workarounds. */
        videoDecoding: array(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
        videoEncoding: array(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
        imageDecoding: array(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
      };
    }
    and ProcessInfo: {
      /* Represents process info. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Specifies process type. */
        id: float, /* Specifies process id. */
        cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
      };
    };
  } = {
    module rec GPUDevice: {
      /* Describes a single graphics processor (GPU). */
      [@deriving yojson]
      type t = {
        vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
        deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
        [@yojson.option]
        subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
        [@yojson.option]
        revision: option(float), /* Revision of the GPU, only available on Windows. */
        vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
        deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
        driverVendor: string, /* String description of the GPU driver vendor. */
        driverVersion: string /* String description of the GPU driver version. */,
      };
    } = {
      /* Describes a single graphics processor (GPU). */
      [@deriving yojson]
      type t = {
        vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
        deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
        [@yojson.option]
        subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
        [@yojson.option]
        revision: option(float), /* Revision of the GPU, only available on Windows. */
        vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
        deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
        driverVendor: string, /* String description of the GPU driver vendor. */
        driverVersion: string /* String description of the GPU driver version. */,
      };
    }
    and Size: {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {
        width: float, /* Width in pixels. */
        height: float /* Height in pixels. */,
      };
    } = {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {
        width: float, /* Width in pixels. */
        height: float /* Height in pixels. */,
      };
    }
    and VideoDecodeAcceleratorCapability: {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
      };
    } = {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
      };
    }
    and VideoEncodeAcceleratorCapability: {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g H264 Main. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: float /* No description provided */,
      };
    } = {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g H264 Main. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: float /* No description provided */,
      };
    }
    and SubsamplingFormat: {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    } = {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageType: {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageDecodeAcceleratorCapability: {
      /* Describes a supported image decoding profile with its associated minimum and
         maximum resolutions and subsampling. */
      [@deriving yojson]
      type t = {
        imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
        maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
        minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
        subsamplings: array(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
      };
    } = {
      /* Describes a supported image decoding profile with its associated minimum and
         maximum resolutions and subsampling. */
      [@deriving yojson]
      type t = {
        imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
        maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
        minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
        subsamplings: array(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
      };
    }
    and GPUInfo: {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {
        devices: array(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
        [@yojson.option]
        auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
        [@yojson.option]
        featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
        driverBugWorkarounds: array(string), /* An optional array of GPU driver bug workarounds. */
        videoDecoding: array(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
        videoEncoding: array(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
        imageDecoding: array(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
      };
    } = {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {
        devices: array(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
        [@yojson.option]
        auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
        [@yojson.option]
        featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
        driverBugWorkarounds: array(string), /* An optional array of GPU driver bug workarounds. */
        videoDecoding: array(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
        videoEncoding: array(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
        imageDecoding: array(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
      };
    }
    and ProcessInfo: {
      /* Represents process info. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Specifies process type. */
        id: float, /* Specifies process id. */
        cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
      };
    } = {
      /* Represents process info. */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* Specifies process type. */
        id: float, /* Specifies process id. */
        cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
      };
    };
  };
}
and Target: {
  module Types: {
    module rec TargetID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SessionID: {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    }
    and TargetInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        targetId: TargetID.t, /* No description provided */
        [@key "type"]
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        [@yojson.option]
        openerId: option(TargetID.t), /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        [@yojson.option]
        openerFrameId: option(Page.Types.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
        [@yojson.option]
        browserContextId: option(Browser.Types.BrowserContextID.t) /* No description provided */,
      };
    }
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: float /* No description provided */,
      };
    };
  };

  module Events: {
    /* Issued when attached to target because of auto-attach or `attachToTarget` command. */
    module AttachedToTarget: {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Identifier assigned to the session used to send/receive messages. */
        targetInfo: Types.TargetInfo.t, /* No description provided */
        waitingForDebugger: bool /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when detached from target for any reason (including `detachFromTarget` command). Can be
       issued multiple times per target if multiple sessions have been attached to it. */
    module DetachedFromTarget: {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Detached session identifier. */
        [@yojson.option]
        targetId: option(Types.TargetID.t) /* Deprecated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies about a new protocol message received from the session (as reported in
       `attachedToTarget` event). */
    module ReceivedMessageFromTarget: {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Identifier of a session which sends a message. */
        message: string, /* No description provided */
        [@yojson.option]
        targetId: option(Types.TargetID.t) /* Deprecated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when a possible inspection target is created. */
    module TargetCreated: {
      [@deriving yojson]
      type result = {
        targetInfo: Types.TargetInfo.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when a target is destroyed. */
    module TargetDestroyed: {
      [@deriving yojson]
      type result = {
        targetId: Types.TargetID.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when a target has crashed. */
    module TargetCrashed: {
      [@deriving yojson]
      type result = {
        targetId: Types.TargetID.t, /* No description provided */
        status: string, /* Termination status type. */
        errorCode: float /* Termination error code. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when some information about a target has changed. This only happens between
       `targetCreated` and `targetDestroyed`. */
    module TargetInfoChanged: {
      [@deriving yojson]
      type result = {
        targetInfo: Types.TargetInfo.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec TargetID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SessionID: {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    }
    and TargetInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        targetId: TargetID.t, /* No description provided */
        [@key "type"]
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        [@yojson.option]
        openerId: option(TargetID.t), /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        [@yojson.option]
        openerFrameId: option(Page.Types.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
        [@yojson.option]
        browserContextId: option(Browser.Types.BrowserContextID.t) /* No description provided */,
      };
    }
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: float /* No description provided */,
      };
    };
  } = {
    module rec TargetID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SessionID: {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    }
    and TargetInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        targetId: TargetID.t, /* No description provided */
        [@key "type"]
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        [@yojson.option]
        openerId: option(TargetID.t), /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        [@yojson.option]
        openerFrameId: option(Page.Types.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
        [@yojson.option]
        browserContextId: option(Browser.Types.BrowserContextID.t) /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        targetId: TargetID.t, /* No description provided */
        [@key "type"]
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        [@yojson.option]
        openerId: option(TargetID.t), /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        [@yojson.option]
        openerFrameId: option(Page.Types.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
        [@yojson.option]
        browserContextId: option(Browser.Types.BrowserContextID.t) /* No description provided */,
      };
    }
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: float /* No description provided */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: float /* No description provided */,
      };
    };
  };

  module Events = {
    /* Issued when attached to target because of auto-attach or `attachToTarget` command. */
    module AttachedToTarget = {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Identifier assigned to the session used to send/receive messages. */
        targetInfo: Types.TargetInfo.t, /* No description provided */
        waitingForDebugger: bool /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when detached from target for any reason (including `detachFromTarget` command). Can be
       issued multiple times per target if multiple sessions have been attached to it. */
    module DetachedFromTarget = {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Detached session identifier. */
        [@yojson.option]
        targetId: option(Types.TargetID.t) /* Deprecated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies about a new protocol message received from the session (as reported in
       `attachedToTarget` event). */
    module ReceivedMessageFromTarget = {
      [@deriving yojson]
      type result = {
        sessionId: Types.SessionID.t, /* Identifier of a session which sends a message. */
        message: string, /* No description provided */
        [@yojson.option]
        targetId: option(Types.TargetID.t) /* Deprecated. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when a possible inspection target is created. */
    module TargetCreated = {
      [@deriving yojson]
      type result = {
        targetInfo: Types.TargetInfo.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when a target is destroyed. */
    module TargetDestroyed = {
      [@deriving yojson]
      type result = {
        targetId: Types.TargetID.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when a target has crashed. */
    module TargetCrashed = {
      [@deriving yojson]
      type result = {
        targetId: Types.TargetID.t, /* No description provided */
        status: string, /* Termination status type. */
        errorCode: float /* Termination error code. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when some information about a target has changed. This only happens between
       `targetCreated` and `targetDestroyed`. */
    module TargetInfoChanged = {
      [@deriving yojson]
      type result = {
        targetInfo: Types.TargetInfo.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Tethering: {
  module Events: {
    /* Informs that port was successfully bound and got a specified connection id. */
    module Accepted: {
      [@deriving yojson]
      type result = {
        port: float, /* Port number that was successfully bound. */
        connectionId: string /* Connection id to be used. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Events = {
    /* Informs that port was successfully bound and got a specified connection id. */
    module Accepted = {
      [@deriving yojson]
      type result = {
        port: float, /* Port number that was successfully bound. */
        connectionId: string /* Connection id to be used. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Tracing: {
  module Types: {
    module rec MemoryDumpConfig: {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = assoc;
    }
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        recordMode: option(string), /* Controls how the trace buffer stores data. */
        [@yojson.option]
        enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
        [@yojson.option]
        enableSystrace: option(bool), /* Turns on system tracing. */
        [@yojson.option]
        enableArgumentFilter: option(bool), /* Turns on argument filter. */
        [@yojson.option]
        includedCategories: option(array(string)), /* Included category filters. */
        [@yojson.option]
        excludedCategories: option(array(string)), /* Excluded category filters. */
        [@yojson.option]
        syntheticDelays: option(array(string)), /* Configuration to synthesize the delays in tracing. */
        [@yojson.option]
        memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
      };
    }
    and StreamFormat: {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    }
    and StreamCompression: {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    }
    and MemoryDumpLevelOfDetail: {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    }
    and TracingBackend: {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events: {
    /* No description provided */
    module BufferUsage: {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        percentFull: option(float), /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */
        [@yojson.option]
        eventCount: option(float), /* An approximate number of events in the trace log. */
        [@yojson.option]
        value: option(float) /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Contains an bucket of collected trace events. When tracing is stopped collected events will be
       send as a sequence of dataCollected events followed by tracingComplete event. */
    module DataCollected: {
      [@deriving yojson]
      type result = {value: array(assoc) /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Signals that tracing is stopped and there is no trace buffers pending flush, all data were
       delivered via dataCollected events. */
    module TracingComplete: {
      [@deriving yojson]
      type result = {
        dataLossOccurred: bool, /* Indicates whether some trace data is known to have been lost, e.g. because the trace ring
buffer wrapped around. */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* A handle of the stream that holds resulting trace data. */
        [@yojson.option]
        traceFormat: option(Types.StreamFormat.t), /* Trace data format of returned stream. */
        [@yojson.option]
        streamCompression: option(Types.StreamCompression.t) /* Compression format of returned stream. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec MemoryDumpConfig: {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = assoc;
    }
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        recordMode: option(string), /* Controls how the trace buffer stores data. */
        [@yojson.option]
        enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
        [@yojson.option]
        enableSystrace: option(bool), /* Turns on system tracing. */
        [@yojson.option]
        enableArgumentFilter: option(bool), /* Turns on argument filter. */
        [@yojson.option]
        includedCategories: option(array(string)), /* Included category filters. */
        [@yojson.option]
        excludedCategories: option(array(string)), /* Excluded category filters. */
        [@yojson.option]
        syntheticDelays: option(array(string)), /* Configuration to synthesize the delays in tracing. */
        [@yojson.option]
        memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
      };
    }
    and StreamFormat: {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    }
    and StreamCompression: {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    }
    and MemoryDumpLevelOfDetail: {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    }
    and TracingBackend: {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    };
  } = {
    module rec MemoryDumpConfig: {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = assoc;
    } = {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = assoc;
    }
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        recordMode: option(string), /* Controls how the trace buffer stores data. */
        [@yojson.option]
        enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
        [@yojson.option]
        enableSystrace: option(bool), /* Turns on system tracing. */
        [@yojson.option]
        enableArgumentFilter: option(bool), /* Turns on argument filter. */
        [@yojson.option]
        includedCategories: option(array(string)), /* Included category filters. */
        [@yojson.option]
        excludedCategories: option(array(string)), /* Excluded category filters. */
        [@yojson.option]
        syntheticDelays: option(array(string)), /* Configuration to synthesize the delays in tracing. */
        [@yojson.option]
        memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        recordMode: option(string), /* Controls how the trace buffer stores data. */
        [@yojson.option]
        enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
        [@yojson.option]
        enableSystrace: option(bool), /* Turns on system tracing. */
        [@yojson.option]
        enableArgumentFilter: option(bool), /* Turns on argument filter. */
        [@yojson.option]
        includedCategories: option(array(string)), /* Included category filters. */
        [@yojson.option]
        excludedCategories: option(array(string)), /* Excluded category filters. */
        [@yojson.option]
        syntheticDelays: option(array(string)), /* Configuration to synthesize the delays in tracing. */
        [@yojson.option]
        memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
      };
    }
    and StreamFormat: {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    }
    and StreamCompression: {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    }
    and MemoryDumpLevelOfDetail: {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    } = {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    }
    and TracingBackend: {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    };
  };

  module Events = {
    /* No description provided */
    module BufferUsage = {
      [@deriving yojson]
      type result = {
        [@yojson.option]
        percentFull: option(float), /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */
        [@yojson.option]
        eventCount: option(float), /* An approximate number of events in the trace log. */
        [@yojson.option]
        value: option(float) /* A number in range [0..1] that indicates the used size of event buffer as a fraction of its
total size. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Contains an bucket of collected trace events. When tracing is stopped collected events will be
       send as a sequence of dataCollected events followed by tracingComplete event. */
    module DataCollected = {
      [@deriving yojson]
      type result = {value: array(assoc) /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Signals that tracing is stopped and there is no trace buffers pending flush, all data were
       delivered via dataCollected events. */
    module TracingComplete = {
      [@deriving yojson]
      type result = {
        dataLossOccurred: bool, /* Indicates whether some trace data is known to have been lost, e.g. because the trace ring
buffer wrapped around. */
        [@yojson.option]
        stream: option(IO.Types.StreamHandle.t), /* A handle of the stream that holds resulting trace data. */
        [@yojson.option]
        traceFormat: option(Types.StreamFormat.t), /* Trace data format of returned stream. */
        [@yojson.option]
        streamCompression: option(Types.StreamCompression.t) /* Compression format of returned stream. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and Fetch: {
  module Types: {
    module rec RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestStage: {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(Network.Types.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and HeaderEntry: {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    };
  };

  module Events: {
    /* Issued when the domain is enabled and the request URL matches the
       specified filter. The request is paused until the client responds
       with one of continueRequest, failRequest or fulfillRequest.
       The stage of the request can be determined by presence of responseErrorReason
       and responseStatusCode -- the request is at the response stage if either
       of these fields is present and in the request stage otherwise. */
    module RequestPaused: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Each request the page makes will have a unique id. */
        request: Network.Types.Request.t, /* The details of the request. */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Network.Types.ResourceType.t, /* How the requested resource will be used. */
        [@yojson.option]
        responseErrorReason: option(Network.Types.ErrorReason.t), /* Response error if intercepted at response stage. */
        [@yojson.option]
        responseStatusCode: option(float), /* Response code if intercepted at response stage. */
        [@yojson.option]
        responseHeaders: option(array(Types.HeaderEntry.t)), /* Response headers if intercepted at the response stage. */
        [@yojson.option]
        networkId: option(Types.RequestId.t) /* If the intercepted request had a corresponding Network.requestWillBeSent event fired for it,
then this networkId will be the same as the requestId present in the requestWillBeSent event. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Issued when the domain is enabled with handleAuthRequests set to true.
       The request is paused until client responds with continueWithAuth. */
    module AuthRequired: {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Each request the page makes will have a unique id. */
        request: Network.Types.Request.t, /* The details of the request. */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Network.Types.ResourceType.t, /* How the requested resource will be used. */
        authChallenge: Types.AuthChallenge.t /* Details of the Authorization Challenge encountered.
If this is set, client should respond with continueRequest that
contains AuthChallengeResponse. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestStage: {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(Network.Types.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and HeaderEntry: {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    };
  } = {
    module rec RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestStage: {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(Network.Types.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        [@yojson.option]
        resourceType: option(Network.Types.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
        [@yojson.option]
        requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    }
    and HeaderEntry: {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    } = {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        [@yojson.option]
        source: option(string), /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    }
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    } = {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        [@yojson.option]
        username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        [@yojson.option]
        password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    };
  };

  module Events = {
    /* Issued when the domain is enabled and the request URL matches the
       specified filter. The request is paused until the client responds
       with one of continueRequest, failRequest or fulfillRequest.
       The stage of the request can be determined by presence of responseErrorReason
       and responseStatusCode -- the request is at the response stage if either
       of these fields is present and in the request stage otherwise. */
    module RequestPaused = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Each request the page makes will have a unique id. */
        request: Network.Types.Request.t, /* The details of the request. */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Network.Types.ResourceType.t, /* How the requested resource will be used. */
        [@yojson.option]
        responseErrorReason: option(Network.Types.ErrorReason.t), /* Response error if intercepted at response stage. */
        [@yojson.option]
        responseStatusCode: option(float), /* Response code if intercepted at response stage. */
        [@yojson.option]
        responseHeaders: option(array(Types.HeaderEntry.t)), /* Response headers if intercepted at the response stage. */
        [@yojson.option]
        networkId: option(Types.RequestId.t) /* If the intercepted request had a corresponding Network.requestWillBeSent event fired for it,
then this networkId will be the same as the requestId present in the requestWillBeSent event. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Issued when the domain is enabled with handleAuthRequests set to true.
       The request is paused until client responds with continueWithAuth. */
    module AuthRequired = {
      [@deriving yojson]
      type result = {
        requestId: Types.RequestId.t, /* Each request the page makes will have a unique id. */
        request: Network.Types.Request.t, /* The details of the request. */
        frameId: Page.Types.FrameId.t, /* The id of the frame that initiated the request. */
        resourceType: Network.Types.ResourceType.t, /* How the requested resource will be used. */
        authChallenge: Types.AuthChallenge.t /* Details of the Authorization Challenge encountered.
If this is set, client should respond with continueRequest that
contains AuthChallengeResponse. */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and WebAudio: {
  module Types: {
    module rec GraphObjectId: {
      /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
      [@deriving yojson]
      type t = string;
    }
    and ContextType: {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    }
    and ContextState: {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    }
    and NodeType: {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    }
    and ChannelCountMode: {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ChannelInterpretation: {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ParamType: {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    }
    and AutomationRate: {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ContextRealtimeData: {
      /* Fields in AudioContext that change in real-time. */
      [@deriving yojson]
      type t = {
        currentTime: float, /* The current context time in second in BaseAudioContext. */
        renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
        callbackIntervalMean: float, /* A running mean of callback interval. */
        callbackIntervalVariance: float /* A running variance of callback interval. */,
      };
    }
    and BaseAudioContext: {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {
        contextId: GraphObjectId.t, /* No description provided */
        contextType: ContextType.t, /* No description provided */
        contextState: ContextState.t, /* No description provided */
        [@yojson.option]
        realtimeData: option(ContextRealtimeData.t), /* No description provided */
        callbackBufferSize: float, /* Platform-dependent callback buffer size. */
        maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
        sampleRate: float /* Context sample rate. */,
      };
    }
    and AudioListener: {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {
        listenerId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t /* No description provided */,
      };
    }
    and AudioNode: {
      /* Protocol object for AudioNode */
      [@deriving yojson]
      type t = {
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        nodeType: NodeType.t, /* No description provided */
        numberOfInputs: float, /* No description provided */
        numberOfOutputs: float, /* No description provided */
        channelCount: float, /* No description provided */
        channelCountMode: ChannelCountMode.t, /* No description provided */
        channelInterpretation: ChannelInterpretation.t /* No description provided */,
      };
    }
    and AudioParam: {
      /* Protocol object for AudioParam */
      [@deriving yojson]
      type t = {
        paramId: GraphObjectId.t, /* No description provided */
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        paramType: ParamType.t, /* No description provided */
        rate: AutomationRate.t, /* No description provided */
        defaultValue: float, /* No description provided */
        minValue: float, /* No description provided */
        maxValue: float /* No description provided */,
      };
    };
  };

  module Events: {
    /* Notifies that a new BaseAudioContext has been created. */
    module ContextCreated: {
      [@deriving yojson]
      type result = {
        context: Types.BaseAudioContext.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that an existing BaseAudioContext will be destroyed. */
    module ContextWillBeDestroyed: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that existing BaseAudioContext has changed some properties (id stays the same).. */
    module ContextChanged: {
      [@deriving yojson]
      type result = {
        context: Types.BaseAudioContext.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that the construction of an AudioListener has finished. */
    module AudioListenerCreated: {
      [@deriving yojson]
      type result = {
        listener: Types.AudioListener.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that a new AudioListener has been created. */
    module AudioListenerWillBeDestroyed: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        listenerId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that a new AudioNode has been created. */
    module AudioNodeCreated: {
      [@deriving yojson]
      type result = {node: Types.AudioNode.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that an existing AudioNode has been destroyed. */
    module AudioNodeWillBeDestroyed: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        nodeId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that a new AudioParam has been created. */
    module AudioParamCreated: {
      [@deriving yojson]
      type result = {param: Types.AudioParam.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that an existing AudioParam has been destroyed. */
    module AudioParamWillBeDestroyed: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        nodeId: Types.GraphObjectId.t, /* No description provided */
        paramId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that two AudioNodes are connected. */
    module NodesConnected: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float), /* No description provided */
        [@yojson.option]
        destinationInputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected. */
    module NodesDisconnected: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float), /* No description provided */
        [@yojson.option]
        destinationInputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that an AudioNode is connected to an AudioParam. */
    module NodeParamConnected: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Notifies that an AudioNode is disconnected to an AudioParam. */
    module NodeParamDisconnected: {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec GraphObjectId: {
      /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
      [@deriving yojson]
      type t = string;
    }
    and ContextType: {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    }
    and ContextState: {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    }
    and NodeType: {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    }
    and ChannelCountMode: {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ChannelInterpretation: {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ParamType: {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    }
    and AutomationRate: {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ContextRealtimeData: {
      /* Fields in AudioContext that change in real-time. */
      [@deriving yojson]
      type t = {
        currentTime: float, /* The current context time in second in BaseAudioContext. */
        renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
        callbackIntervalMean: float, /* A running mean of callback interval. */
        callbackIntervalVariance: float /* A running variance of callback interval. */,
      };
    }
    and BaseAudioContext: {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {
        contextId: GraphObjectId.t, /* No description provided */
        contextType: ContextType.t, /* No description provided */
        contextState: ContextState.t, /* No description provided */
        [@yojson.option]
        realtimeData: option(ContextRealtimeData.t), /* No description provided */
        callbackBufferSize: float, /* Platform-dependent callback buffer size. */
        maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
        sampleRate: float /* Context sample rate. */,
      };
    }
    and AudioListener: {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {
        listenerId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t /* No description provided */,
      };
    }
    and AudioNode: {
      /* Protocol object for AudioNode */
      [@deriving yojson]
      type t = {
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        nodeType: NodeType.t, /* No description provided */
        numberOfInputs: float, /* No description provided */
        numberOfOutputs: float, /* No description provided */
        channelCount: float, /* No description provided */
        channelCountMode: ChannelCountMode.t, /* No description provided */
        channelInterpretation: ChannelInterpretation.t /* No description provided */,
      };
    }
    and AudioParam: {
      /* Protocol object for AudioParam */
      [@deriving yojson]
      type t = {
        paramId: GraphObjectId.t, /* No description provided */
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        paramType: ParamType.t, /* No description provided */
        rate: AutomationRate.t, /* No description provided */
        defaultValue: float, /* No description provided */
        minValue: float, /* No description provided */
        maxValue: float /* No description provided */,
      };
    };
  } = {
    module rec GraphObjectId: {
      /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
      [@deriving yojson]
      type t = string;
    } = {
      /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
      [@deriving yojson]
      type t = string;
    }
    and ContextType: {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    }
    and ContextState: {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    }
    and NodeType: {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    }
    and ChannelCountMode: {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ChannelInterpretation: {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ParamType: {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    }
    and AutomationRate: {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    } = {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ContextRealtimeData: {
      /* Fields in AudioContext that change in real-time. */
      [@deriving yojson]
      type t = {
        currentTime: float, /* The current context time in second in BaseAudioContext. */
        renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
        callbackIntervalMean: float, /* A running mean of callback interval. */
        callbackIntervalVariance: float /* A running variance of callback interval. */,
      };
    } = {
      /* Fields in AudioContext that change in real-time. */
      [@deriving yojson]
      type t = {
        currentTime: float, /* The current context time in second in BaseAudioContext. */
        renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
        callbackIntervalMean: float, /* A running mean of callback interval. */
        callbackIntervalVariance: float /* A running variance of callback interval. */,
      };
    }
    and BaseAudioContext: {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {
        contextId: GraphObjectId.t, /* No description provided */
        contextType: ContextType.t, /* No description provided */
        contextState: ContextState.t, /* No description provided */
        [@yojson.option]
        realtimeData: option(ContextRealtimeData.t), /* No description provided */
        callbackBufferSize: float, /* Platform-dependent callback buffer size. */
        maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
        sampleRate: float /* Context sample rate. */,
      };
    } = {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {
        contextId: GraphObjectId.t, /* No description provided */
        contextType: ContextType.t, /* No description provided */
        contextState: ContextState.t, /* No description provided */
        [@yojson.option]
        realtimeData: option(ContextRealtimeData.t), /* No description provided */
        callbackBufferSize: float, /* Platform-dependent callback buffer size. */
        maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
        sampleRate: float /* Context sample rate. */,
      };
    }
    and AudioListener: {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {
        listenerId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t /* No description provided */,
      };
    } = {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {
        listenerId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t /* No description provided */,
      };
    }
    and AudioNode: {
      /* Protocol object for AudioNode */
      [@deriving yojson]
      type t = {
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        nodeType: NodeType.t, /* No description provided */
        numberOfInputs: float, /* No description provided */
        numberOfOutputs: float, /* No description provided */
        channelCount: float, /* No description provided */
        channelCountMode: ChannelCountMode.t, /* No description provided */
        channelInterpretation: ChannelInterpretation.t /* No description provided */,
      };
    } = {
      /* Protocol object for AudioNode */
      [@deriving yojson]
      type t = {
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        nodeType: NodeType.t, /* No description provided */
        numberOfInputs: float, /* No description provided */
        numberOfOutputs: float, /* No description provided */
        channelCount: float, /* No description provided */
        channelCountMode: ChannelCountMode.t, /* No description provided */
        channelInterpretation: ChannelInterpretation.t /* No description provided */,
      };
    }
    and AudioParam: {
      /* Protocol object for AudioParam */
      [@deriving yojson]
      type t = {
        paramId: GraphObjectId.t, /* No description provided */
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        paramType: ParamType.t, /* No description provided */
        rate: AutomationRate.t, /* No description provided */
        defaultValue: float, /* No description provided */
        minValue: float, /* No description provided */
        maxValue: float /* No description provided */,
      };
    } = {
      /* Protocol object for AudioParam */
      [@deriving yojson]
      type t = {
        paramId: GraphObjectId.t, /* No description provided */
        nodeId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t, /* No description provided */
        paramType: ParamType.t, /* No description provided */
        rate: AutomationRate.t, /* No description provided */
        defaultValue: float, /* No description provided */
        minValue: float, /* No description provided */
        maxValue: float /* No description provided */,
      };
    };
  };

  module Events = {
    /* Notifies that a new BaseAudioContext has been created. */
    module ContextCreated = {
      [@deriving yojson]
      type result = {
        context: Types.BaseAudioContext.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that an existing BaseAudioContext will be destroyed. */
    module ContextWillBeDestroyed = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that existing BaseAudioContext has changed some properties (id stays the same).. */
    module ContextChanged = {
      [@deriving yojson]
      type result = {
        context: Types.BaseAudioContext.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that the construction of an AudioListener has finished. */
    module AudioListenerCreated = {
      [@deriving yojson]
      type result = {
        listener: Types.AudioListener.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that a new AudioListener has been created. */
    module AudioListenerWillBeDestroyed = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        listenerId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that a new AudioNode has been created. */
    module AudioNodeCreated = {
      [@deriving yojson]
      type result = {node: Types.AudioNode.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that an existing AudioNode has been destroyed. */
    module AudioNodeWillBeDestroyed = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        nodeId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that a new AudioParam has been created. */
    module AudioParamCreated = {
      [@deriving yojson]
      type result = {param: Types.AudioParam.t /* No description provided */};

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that an existing AudioParam has been destroyed. */
    module AudioParamWillBeDestroyed = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        nodeId: Types.GraphObjectId.t, /* No description provided */
        paramId: Types.GraphObjectId.t /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that two AudioNodes are connected. */
    module NodesConnected = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float), /* No description provided */
        [@yojson.option]
        destinationInputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that AudioNodes are disconnected. The destination can be null, and it means all the outgoing connections from the source are disconnected. */
    module NodesDisconnected = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float), /* No description provided */
        [@yojson.option]
        destinationInputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that an AudioNode is connected to an AudioParam. */
    module NodeParamConnected = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Notifies that an AudioNode is disconnected to an AudioParam. */
    module NodeParamDisconnected = {
      [@deriving yojson]
      type result = {
        contextId: Types.GraphObjectId.t, /* No description provided */
        sourceId: Types.GraphObjectId.t, /* No description provided */
        destinationId: Types.GraphObjectId.t, /* No description provided */
        [@yojson.option]
        sourceOutputIndex: option(float) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
}
and WebAuthn: {
  module Types: {
    module rec AuthenticatorId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorProtocol: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Ctap2Version: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorTransport: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and VirtualAuthenticatorOptions: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        protocol: AuthenticatorProtocol.t, /* No description provided */
        [@yojson.option]
        ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        [@yojson.option]
        hasResidentKey: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasUserVerification: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        [@yojson.option]
        hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        [@yojson.option]
        automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        [@yojson.option]
        isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    }
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        [@yojson.option]
        rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option]
        userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        [@yojson.option]
        largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    };
  };
} = {
  module Types: {
    module rec AuthenticatorId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorProtocol: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Ctap2Version: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorTransport: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and VirtualAuthenticatorOptions: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        protocol: AuthenticatorProtocol.t, /* No description provided */
        [@yojson.option]
        ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        [@yojson.option]
        hasResidentKey: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasUserVerification: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        [@yojson.option]
        hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        [@yojson.option]
        automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        [@yojson.option]
        isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    }
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        [@yojson.option]
        rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option]
        userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        [@yojson.option]
        largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    };
  } = {
    module rec AuthenticatorId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorProtocol: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Ctap2Version: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorTransport: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and VirtualAuthenticatorOptions: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        protocol: AuthenticatorProtocol.t, /* No description provided */
        [@yojson.option]
        ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        [@yojson.option]
        hasResidentKey: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasUserVerification: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        [@yojson.option]
        hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        [@yojson.option]
        automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        [@yojson.option]
        isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        protocol: AuthenticatorProtocol.t, /* No description provided */
        [@yojson.option]
        ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        [@yojson.option]
        hasResidentKey: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasUserVerification: option(bool), /* Defaults to false. */
        [@yojson.option]
        hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        [@yojson.option]
        hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        [@yojson.option]
        automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        [@yojson.option]
        isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    }
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        [@yojson.option]
        rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option]
        userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        [@yojson.option]
        largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        [@yojson.option]
        rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        [@yojson.option]
        userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        [@yojson.option]
        largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    };
  };
}
and Media: {
  module Types: {
    module rec PlayerId: {
      /* Players will get an ID that is unique within the agent context. */
      [@deriving yojson]
      type t = string;
    }
    and Timestamp: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and PlayerMessage: {
      /* Have one type per entry in MediaLogRecord::Type
         Corresponds to kMessage */
      [@deriving yojson]
      type t = {
        level: string, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
        message: string /* No description provided */,
      };
    }
    and PlayerProperty: {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerEvent: {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {
        timestamp: Timestamp.t, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerError: {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
    };
  };

  module Events: {
    /* This can be called multiple times, and can be used to set / override /
       remove player properties. A null propValue indicates removal. */
    module PlayerPropertiesChanged: {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        properties: array(Types.PlayerProperty.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Send events as a list, allowing them to be batched on the browser for less
       congestion. If batched, events must ALWAYS be in chronological order. */
    module PlayerEventsAdded: {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        events: array(Types.PlayerEvent.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Send a list of any messages that need to be delivered. */
    module PlayerMessagesLogged: {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        messages: array(Types.PlayerMessage.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Send a list of any errors that need to be delivered. */
    module PlayerErrorsRaised: {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        errors: array(Types.PlayerError.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
    /* Called whenever a player is created, or when a new agent joins and receives
       a list of active players. If an agent is restored, it will receive the full
       list of player ids and all events again. */
    module PlayersCreated: {
      [@deriving yojson]
      type result = {
        players: array(Types.PlayerId.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse: string => t;
    };
  };
} = {
  module Types: {
    module rec PlayerId: {
      /* Players will get an ID that is unique within the agent context. */
      [@deriving yojson]
      type t = string;
    }
    and Timestamp: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and PlayerMessage: {
      /* Have one type per entry in MediaLogRecord::Type
         Corresponds to kMessage */
      [@deriving yojson]
      type t = {
        level: string, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
        message: string /* No description provided */,
      };
    }
    and PlayerProperty: {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerEvent: {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {
        timestamp: Timestamp.t, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerError: {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
    };
  } = {
    module rec PlayerId: {
      /* Players will get an ID that is unique within the agent context. */
      [@deriving yojson]
      type t = string;
    } = {
      /* Players will get an ID that is unique within the agent context. */
      [@deriving yojson]
      type t = string;
    }
    and Timestamp: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    } = {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and PlayerMessage: {
      /* Have one type per entry in MediaLogRecord::Type
         Corresponds to kMessage */
      [@deriving yojson]
      type t = {
        level: string, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
        message: string /* No description provided */,
      };
    } = {
      /* Have one type per entry in MediaLogRecord::Type
         Corresponds to kMessage */
      [@deriving yojson]
      type t = {
        level: string, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
        message: string /* No description provided */,
      };
    }
    and PlayerProperty: {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerEvent: {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {
        timestamp: Timestamp.t, /* No description provided */
        value: string /* No description provided */,
      };
    } = {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {
        timestamp: Timestamp.t, /* No description provided */
        value: string /* No description provided */,
      };
    }
    and PlayerError: {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
    } = {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {
        [@key "type"]
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
    };
  };

  module Events = {
    /* This can be called multiple times, and can be used to set / override /
       remove player properties. A null propValue indicates removal. */
    module PlayerPropertiesChanged = {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        properties: array(Types.PlayerProperty.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Send events as a list, allowing them to be batched on the browser for less
       congestion. If batched, events must ALWAYS be in chronological order. */
    module PlayerEventsAdded = {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        events: array(Types.PlayerEvent.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Send a list of any messages that need to be delivered. */
    module PlayerMessagesLogged = {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        messages: array(Types.PlayerMessage.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Send a list of any errors that need to be delivered. */
    module PlayerErrorsRaised = {
      [@deriving yojson]
      type result = {
        playerId: Types.PlayerId.t, /* No description provided */
        errors: array(Types.PlayerError.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
    /* Called whenever a player is created, or when a new agent joins and receives
       a list of active players. If an agent is restored, it will receive the full
       list of player ids and all events again. */
    module PlayersCreated = {
      [@deriving yojson]
      type result = {
        players: array(Types.PlayerId.t) /* No description provided */,
      };

      [@deriving yojson]
      type t = {
        method: string,
        params: result,
        sessionId: Target.Types.SessionID.t,
      };

      let parse = event => event |> Yojson.Safe.from_string |> t_of_yojson;
    };
  };
};
