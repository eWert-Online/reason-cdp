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
        type_: AXValueSourceType.t, /* What type of source this is. */
        value: AXValue.t, /* The value of this property source. */
        attribute: string, /* The name of the relevant attribute, if any. */
        attributeValue: AXValue.t, /* The value of the relevant attribute, if any. */
        superseded: bool, /* Whether this source is superseded by a higher priority source. */
        nativeSource: AXValueNativeSourceType.t, /* The native markup source for this value, e.g. a <label> element. */
        nativeSourceValue: AXValue.t, /* The value, such as a node or node list, of the native source. */
        invalid: bool, /* Whether the value for this property is invalid. */
        invalidReason: string /* Reason for the value being invalid, if it is. */,
      };
    }
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        idref: string, /* The IDRef value provided, if any. */
        text: string /* The text alternative of this node in the current context. */,
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
        type_: AXValueType.t, /* The type of this value. */
        value: string, /* The computed value of this property. */
        relatedNodes: array(AXRelatedNode.t), /* One or more related nodes, if applicable. */
        sources: array(AXValueSource.t) /* The sources which contributed to the computation of this property. */,
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
        ignoredReasons: array(AXProperty.t), /* Collection of reasons why this node is hidden. */
        role: AXValue.t, /* This `Node`'s role, whether explicit or implicit. */
        name: AXValue.t, /* The accessible name for this `Node`. */
        description: AXValue.t, /* The accessible description for this `Node`. */
        value: AXValue.t, /* The value for this `Node`. */
        properties: array(AXProperty.t), /* All other properties */
        childIds: array(AXNodeId.t), /* IDs for each of this node's child nodes. */
        backendDOMNodeId: DOM.Types.BackendNodeId.t /* The backend ID for the associated DOM node, if any. */,
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
        type_: AXValueSourceType.t, /* What type of source this is. */
        value: AXValue.t, /* The value of this property source. */
        attribute: string, /* The name of the relevant attribute, if any. */
        attributeValue: AXValue.t, /* The value of the relevant attribute, if any. */
        superseded: bool, /* Whether this source is superseded by a higher priority source. */
        nativeSource: AXValueNativeSourceType.t, /* The native markup source for this value, e.g. a <label> element. */
        nativeSourceValue: AXValue.t, /* The value, such as a node or node list, of the native source. */
        invalid: bool, /* Whether the value for this property is invalid. */
        invalidReason: string /* Reason for the value being invalid, if it is. */,
      };
    }
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        idref: string, /* The IDRef value provided, if any. */
        text: string /* The text alternative of this node in the current context. */,
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
        type_: AXValueType.t, /* The type of this value. */
        value: string, /* The computed value of this property. */
        relatedNodes: array(AXRelatedNode.t), /* One or more related nodes, if applicable. */
        sources: array(AXValueSource.t) /* The sources which contributed to the computation of this property. */,
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
        ignoredReasons: array(AXProperty.t), /* Collection of reasons why this node is hidden. */
        role: AXValue.t, /* This `Node`'s role, whether explicit or implicit. */
        name: AXValue.t, /* The accessible name for this `Node`. */
        description: AXValue.t, /* The accessible description for this `Node`. */
        value: AXValue.t, /* The value for this `Node`. */
        properties: array(AXProperty.t), /* All other properties */
        childIds: array(AXNodeId.t), /* IDs for each of this node's child nodes. */
        backendDOMNodeId: DOM.Types.BackendNodeId.t /* The backend ID for the associated DOM node, if any. */,
      };
    };
  } = {
    module rec AXNodeId: {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    } = AXNodeId
    and AXValueType: {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    } = AXValueType
    and AXValueSourceType: {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    } = AXValueSourceType
    and AXValueNativeSourceType: {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    } = AXValueNativeSourceType
    and AXValueSource: {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {
        type_: AXValueSourceType.t, /* What type of source this is. */
        value: AXValue.t, /* The value of this property source. */
        attribute: string, /* The name of the relevant attribute, if any. */
        attributeValue: AXValue.t, /* The value of the relevant attribute, if any. */
        superseded: bool, /* Whether this source is superseded by a higher priority source. */
        nativeSource: AXValueNativeSourceType.t, /* The native markup source for this value, e.g. a <label> element. */
        nativeSourceValue: AXValue.t, /* The value, such as a node or node list, of the native source. */
        invalid: bool, /* Whether the value for this property is invalid. */
        invalidReason: string /* Reason for the value being invalid, if it is. */,
      };
    } = AXValueSource
    and AXRelatedNode: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        backendDOMNodeId: DOM.Types.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
        idref: string, /* The IDRef value provided, if any. */
        text: string /* The text alternative of this node in the current context. */,
      };
    } = AXRelatedNode
    and AXProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: AXPropertyName.t, /* The name of this property. */
        value: AXValue.t /* The value of this property. */,
      };
    } = AXProperty
    and AXValue: {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {
        type_: AXValueType.t, /* The type of this value. */
        value: string, /* The computed value of this property. */
        relatedNodes: array(AXRelatedNode.t), /* One or more related nodes, if applicable. */
        sources: array(AXValueSource.t) /* The sources which contributed to the computation of this property. */,
      };
    } = AXValue
    and AXPropertyName: {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    } = AXPropertyName
    and AXNode: {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {
        nodeId: AXNodeId.t, /* Unique identifier for this node. */
        ignored: bool, /* Whether this node is ignored for accessibility */
        ignoredReasons: array(AXProperty.t), /* Collection of reasons why this node is hidden. */
        role: AXValue.t, /* This `Node`'s role, whether explicit or implicit. */
        name: AXValue.t, /* The accessible name for this `Node`. */
        description: AXValue.t, /* The accessible description for this `Node`. */
        value: AXValue.t, /* The value for this `Node`. */
        properties: array(AXProperty.t), /* All other properties */
        childIds: array(AXNodeId.t), /* IDs for each of this node's child nodes. */
        backendDOMNodeId: DOM.Types.BackendNodeId.t /* The backend ID for the associated DOM node, if any. */,
      };
    } = AXNode;
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
        type_: string, /* Animation type of `Animation`. */
        source: AnimationEffect.t, /* `Animation`'s source animation node. */
        cssId: string /* A unique ID for `Animation` representing the sources that triggered this CSS
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
        backendNodeId: DOM.Types.BackendNodeId.t, /* `AnimationEffect`'s target node. */
        keyframesRule: KeyframesRule.t, /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    }
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        name: string, /* CSS keyframed animation's name. */
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
        type_: string, /* Animation type of `Animation`. */
        source: AnimationEffect.t, /* `Animation`'s source animation node. */
        cssId: string /* A unique ID for `Animation` representing the sources that triggered this CSS
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
        backendNodeId: DOM.Types.BackendNodeId.t, /* `AnimationEffect`'s target node. */
        keyframesRule: KeyframesRule.t, /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    }
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        name: string, /* CSS keyframed animation's name. */
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
        type_: string, /* Animation type of `Animation`. */
        source: AnimationEffect.t, /* `Animation`'s source animation node. */
        cssId: string /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
      };
    } = Animation
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
        backendNodeId: DOM.Types.BackendNodeId.t, /* `AnimationEffect`'s target node. */
        keyframesRule: KeyframesRule.t, /* `AnimationEffect`'s keyframes. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    } = AnimationEffect
    and KeyframesRule: {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {
        name: string, /* CSS keyframed animation's name. */
        keyframes: array(KeyframeStyle.t) /* List of animation keyframes. */,
      };
    } = KeyframesRule
    and KeyframeStyle: {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {
        offset: string, /* Keyframe's time offset. */
        easing: string /* `AnimationEffect`'s timing function. */,
      };
    } = KeyframeStyle;
  };
}
and ApplicationCache: {
  module Types: {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: int, /* Resource size. */
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
        status: int /* Application cache status. */,
      };
    };
  };
} = {
  module Types: {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: int, /* Resource size. */
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
        status: int /* Application cache status. */,
      };
    };
  } = {
    module rec ApplicationCacheResource: {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource url. */
        size: int, /* Resource size. */
        type_: string /* Resource type. */,
      };
    } = ApplicationCacheResource
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
    } = ApplicationCache
    and FrameWithManifest: {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Frame identifier. */
        manifestURL: string, /* Manifest URL. */
        status: int /* Application cache status. */,
      };
    } = FrameWithManifest;
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
        url: string /* No description provided */,
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
        siteForCookies: string, /* No description provided */
        cookieUrl: string, /* No description provided */
        request: AffectedRequest.t /* No description provided */,
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
        resourceType: MixedContentResourceType.t, /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        request: AffectedRequest.t, /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        frame: AffectedFrame.t /* Optional because not every mixed content issue is necessarily linked to a frame. */,
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
        parentFrame: AffectedFrame.t, /* No description provided */
        blockedFrame: AffectedFrame.t, /* No description provided */
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
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        url: string, /* No description provided */
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    }
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        blockedURL: string, /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        frameAncestor: AffectedFrame.t, /* No description provided */
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t /* No description provided */,
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
        httpStatusCode: int, /* No description provided */
        packageName: string, /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        signature: string /* The signature of the Trusted Web Activity client app. This field is only
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
        location: SourceCodeLocation.t, /* No description provided */
        initiatorOrigin: string, /* No description provided */
        resourceIPAddressSpace: Network.Types.IPAddressSpace.t, /* No description provided */
        clientSecurityState: Network.Types.ClientSecurityState.t /* No description provided */,
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
        frame: AffectedFrame.t, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        invalidParameter: string /* No description provided */,
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
        sameSiteCookieIssueDetails: SameSiteCookieIssueDetails.t, /* No description provided */
        mixedContentIssueDetails: MixedContentIssueDetails.t, /* No description provided */
        blockedByResponseIssueDetails: BlockedByResponseIssueDetails.t, /* No description provided */
        heavyAdIssueDetails: HeavyAdIssueDetails.t, /* No description provided */
        contentSecurityPolicyIssueDetails: ContentSecurityPolicyIssueDetails.t, /* No description provided */
        sharedArrayBufferIssueDetails: SharedArrayBufferIssueDetails.t, /* No description provided */
        twaQualityEnforcementDetails: TrustedWebActivityIssueDetails.t, /* No description provided */
        lowTextContrastIssueDetails: LowTextContrastIssueDetails.t, /* No description provided */
        corsIssueDetails: CorsIssueDetails.t, /* No description provided */
        attributionReportingIssueDetails: AttributionReportingIssueDetails.t, /* No description provided */
        quirksModeIssueDetails: QuirksModeIssueDetails.t /* No description provided */,
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
        url: string /* No description provided */,
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
        siteForCookies: string, /* No description provided */
        cookieUrl: string, /* No description provided */
        request: AffectedRequest.t /* No description provided */,
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
        resourceType: MixedContentResourceType.t, /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        request: AffectedRequest.t, /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        frame: AffectedFrame.t /* Optional because not every mixed content issue is necessarily linked to a frame. */,
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
        parentFrame: AffectedFrame.t, /* No description provided */
        blockedFrame: AffectedFrame.t, /* No description provided */
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
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        url: string, /* No description provided */
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    }
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        blockedURL: string, /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        frameAncestor: AffectedFrame.t, /* No description provided */
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t /* No description provided */,
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
        httpStatusCode: int, /* No description provided */
        packageName: string, /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        signature: string /* The signature of the Trusted Web Activity client app. This field is only
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
        location: SourceCodeLocation.t, /* No description provided */
        initiatorOrigin: string, /* No description provided */
        resourceIPAddressSpace: Network.Types.IPAddressSpace.t, /* No description provided */
        clientSecurityState: Network.Types.ClientSecurityState.t /* No description provided */,
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
        frame: AffectedFrame.t, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        invalidParameter: string /* No description provided */,
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
        sameSiteCookieIssueDetails: SameSiteCookieIssueDetails.t, /* No description provided */
        mixedContentIssueDetails: MixedContentIssueDetails.t, /* No description provided */
        blockedByResponseIssueDetails: BlockedByResponseIssueDetails.t, /* No description provided */
        heavyAdIssueDetails: HeavyAdIssueDetails.t, /* No description provided */
        contentSecurityPolicyIssueDetails: ContentSecurityPolicyIssueDetails.t, /* No description provided */
        sharedArrayBufferIssueDetails: SharedArrayBufferIssueDetails.t, /* No description provided */
        twaQualityEnforcementDetails: TrustedWebActivityIssueDetails.t, /* No description provided */
        lowTextContrastIssueDetails: LowTextContrastIssueDetails.t, /* No description provided */
        corsIssueDetails: CorsIssueDetails.t, /* No description provided */
        attributionReportingIssueDetails: AttributionReportingIssueDetails.t, /* No description provided */
        quirksModeIssueDetails: QuirksModeIssueDetails.t /* No description provided */,
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
    } = AffectedCookie
    and AffectedRequest: {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {
        requestId: Network.Types.RequestId.t, /* The unique request id. */
        url: string /* No description provided */,
      };
    } = AffectedRequest
    and AffectedFrame: {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {frameId: Page.Types.FrameId.t /* No description provided */};
    } = AffectedFrame
    and SameSiteCookieExclusionReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = SameSiteCookieExclusionReason
    and SameSiteCookieWarningReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = SameSiteCookieWarningReason
    and SameSiteCookieOperation: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = SameSiteCookieOperation
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
        siteForCookies: string, /* No description provided */
        cookieUrl: string, /* No description provided */
        request: AffectedRequest.t /* No description provided */,
      };
    } = SameSiteCookieIssueDetails
    and MixedContentResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = MixedContentResolutionStatus
    and MixedContentResourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = MixedContentResourceType
    and MixedContentIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resourceType: MixedContentResourceType.t, /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
        resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
        insecureURL: string, /* The unsafe http url causing the mixed content issue. */
        mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
        request: AffectedRequest.t, /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
        frame: AffectedFrame.t /* Optional because not every mixed content issue is necessarily linked to a frame. */,
      };
    } = MixedContentIssueDetails
    and BlockedByResponseReason: {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    } = BlockedByResponseReason
    and BlockedByResponseIssueDetails: {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {
        request: AffectedRequest.t, /* No description provided */
        parentFrame: AffectedFrame.t, /* No description provided */
        blockedFrame: AffectedFrame.t, /* No description provided */
        reason: BlockedByResponseReason.t /* No description provided */,
      };
    } = BlockedByResponseIssueDetails
    and HeavyAdResolutionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = HeavyAdResolutionStatus
    and HeavyAdReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = HeavyAdReason
    and HeavyAdIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
        reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
        frame: AffectedFrame.t /* The frame that was blocked. */,
      };
    } = HeavyAdIssueDetails
    and ContentSecurityPolicyViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ContentSecurityPolicyViolationType
    and SourceCodeLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        url: string, /* No description provided */
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    } = SourceCodeLocation
    and ContentSecurityPolicyIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        blockedURL: string, /* The url not included in allowed sources. */
        violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
        isReportOnly: bool, /* No description provided */
        contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
        frameAncestor: AffectedFrame.t, /* No description provided */
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t /* No description provided */,
      };
    } = ContentSecurityPolicyIssueDetails
    and SharedArrayBufferIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = SharedArrayBufferIssueType
    and SharedArrayBufferIssueDetails: {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {
        sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
        isWarning: bool, /* No description provided */
        type_: SharedArrayBufferIssueType.t /* No description provided */,
      };
    } = SharedArrayBufferIssueDetails
    and TwaQualityEnforcementViolationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = TwaQualityEnforcementViolationType
    and TrustedWebActivityIssueDetails: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        url: string, /* The url that triggers the violation. */
        violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
        httpStatusCode: int, /* No description provided */
        packageName: string, /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
        signature: string /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
      };
    } = TrustedWebActivityIssueDetails
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
    } = LowTextContrastIssueDetails
    and CorsIssueDetails: {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {
        corsErrorStatus: Network.Types.CorsErrorStatus.t, /* No description provided */
        isWarning: bool, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        location: SourceCodeLocation.t, /* No description provided */
        initiatorOrigin: string, /* No description provided */
        resourceIPAddressSpace: Network.Types.IPAddressSpace.t, /* No description provided */
        clientSecurityState: Network.Types.ClientSecurityState.t /* No description provided */,
      };
    } = CorsIssueDetails
    and AttributionReportingIssueType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = AttributionReportingIssueType
    and AttributionReportingIssueDetails: {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {
        violationType: AttributionReportingIssueType.t, /* No description provided */
        frame: AffectedFrame.t, /* No description provided */
        request: AffectedRequest.t, /* No description provided */
        violatingNodeId: DOM.Types.BackendNodeId.t, /* No description provided */
        invalidParameter: string /* No description provided */,
      };
    } = AttributionReportingIssueDetails
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
    } = QuirksModeIssueDetails
    and InspectorIssueCode: {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    } = InspectorIssueCode
    and InspectorIssueDetails: {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {
        sameSiteCookieIssueDetails: SameSiteCookieIssueDetails.t, /* No description provided */
        mixedContentIssueDetails: MixedContentIssueDetails.t, /* No description provided */
        blockedByResponseIssueDetails: BlockedByResponseIssueDetails.t, /* No description provided */
        heavyAdIssueDetails: HeavyAdIssueDetails.t, /* No description provided */
        contentSecurityPolicyIssueDetails: ContentSecurityPolicyIssueDetails.t, /* No description provided */
        sharedArrayBufferIssueDetails: SharedArrayBufferIssueDetails.t, /* No description provided */
        twaQualityEnforcementDetails: TrustedWebActivityIssueDetails.t, /* No description provided */
        lowTextContrastIssueDetails: LowTextContrastIssueDetails.t, /* No description provided */
        corsIssueDetails: CorsIssueDetails.t, /* No description provided */
        attributionReportingIssueDetails: AttributionReportingIssueDetails.t, /* No description provided */
        quirksModeIssueDetails: QuirksModeIssueDetails.t /* No description provided */,
      };
    } = InspectorIssueDetails
    and InspectorIssue: {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {
        code: InspectorIssueCode.t, /* No description provided */
        details: InspectorIssueDetails.t /* No description provided */,
      };
    } = InspectorIssue;
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
    } = ServiceName
    and EventMetadata: {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {
        key: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = EventMetadata
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
    } = BackgroundServiceEvent;
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
      type t = int;
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
        left: int, /* The offset from the left edge of the screen to the window in pixels. */
        top: int, /* The offset from the top edge of the screen to the window in pixels. */
        width: int, /* The window width in pixels. */
        height: int, /* The window height in pixels. */
        windowState: WindowState.t /* The window state. Default to normal. */,
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
        sysex: bool, /* For "midi" permission, may also specify sysex control. */
        userVisibleOnly: bool, /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        allowWithoutSanitization: bool, /* For "clipboard" permission, may specify allowWithoutSanitization. */
        panTiltZoom: bool /* For "camera" permission, may specify panTiltZoom. */,
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
        low: int, /* Minimum value (inclusive). */
        high: int, /* Maximum value (exclusive). */
        count: int /* Number of samples. */,
      };
    }
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: int, /* Sum of sample values. */
        count: int, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
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
      type t = int;
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
        left: int, /* The offset from the left edge of the screen to the window in pixels. */
        top: int, /* The offset from the top edge of the screen to the window in pixels. */
        width: int, /* The window width in pixels. */
        height: int, /* The window height in pixels. */
        windowState: WindowState.t /* The window state. Default to normal. */,
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
        sysex: bool, /* For "midi" permission, may also specify sysex control. */
        userVisibleOnly: bool, /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        allowWithoutSanitization: bool, /* For "clipboard" permission, may specify allowWithoutSanitization. */
        panTiltZoom: bool /* For "camera" permission, may specify panTiltZoom. */,
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
        low: int, /* Minimum value (inclusive). */
        high: int, /* Maximum value (exclusive). */
        count: int /* Number of samples. */,
      };
    }
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: int, /* Sum of sample values. */
        count: int, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    };
  } = {
    module rec BrowserContextID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = BrowserContextID
    and WindowID: {
      /* No description provided */
      [@deriving yojson]
      type t = int;
    } = WindowID
    and WindowState: {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    } = WindowState
    and Bounds: {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {
        left: int, /* The offset from the left edge of the screen to the window in pixels. */
        top: int, /* The offset from the top edge of the screen to the window in pixels. */
        width: int, /* The window width in pixels. */
        height: int, /* The window height in pixels. */
        windowState: WindowState.t /* The window state. Default to normal. */,
      };
    } = Bounds
    and PermissionType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = PermissionType
    and PermissionSetting: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = PermissionSetting
    and PermissionDescriptor: {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
        sysex: bool, /* For "midi" permission, may also specify sysex control. */
        userVisibleOnly: bool, /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
        allowWithoutSanitization: bool, /* For "clipboard" permission, may specify allowWithoutSanitization. */
        panTiltZoom: bool /* For "camera" permission, may specify panTiltZoom. */,
      };
    } = PermissionDescriptor
    and BrowserCommandId: {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    } = BrowserCommandId
    and Bucket: {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {
        low: int, /* Minimum value (inclusive). */
        high: int, /* Maximum value (exclusive). */
        count: int /* Number of samples. */,
      };
    } = Bucket
    and Histogram: {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {
        name: string, /* Name. */
        sum: int, /* Sum of sample values. */
        count: int, /* Total number of samples. */
        buckets: array(Bucket.t) /* Buckets. */,
      };
    } = Histogram;
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
        inlineStyle: CSSStyle.t, /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    }
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(int) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    }
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        range: SourceRange.t /* Value range in the underlying resource (if available). */,
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
        sourceMapURL: string, /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        ownerNode: DOM.Types.BackendNodeId.t, /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        hasSourceURL: bool, /* Whether the sourceURL field value comes from the sourceURL comment. */
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        media: array(CSSMedia.t) /* Media list array (for rules involving media queries). The array enumerates media queries
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
        startLine: int, /* Start line of range. */
        startColumn: int, /* Start column of range (inclusive). */
        endLine: int, /* End line of range */
        endColumn: int /* End column of range (exclusive). */,
      };
    }
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        important: bool /* Whether the property has "!important" annotation (implies `false` if absent). */,
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        cssText: string, /* Style declaration text (if available). */
        range: SourceRange.t /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    }
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        important: bool, /* Whether the property has "!important" annotation (implies `false` if absent). */
        implicit: bool, /* Whether the property is implicit (implies `false` if absent). */
        text: string, /* The full property text as specified in the style. */
        parsedOk: bool, /* Whether the property is understood by the browser (implies `true` if absent). */
        disabled: bool, /* Whether the property is disabled by the user (present for source-based properties only). */
        range: SourceRange.t /* The entire property range in the enclosing style declaration (if available). */,
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
        sourceURL: string, /* URL of the document containing the media query description. */
        range: SourceRange.t, /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        styleSheetId: StyleSheetId.t, /* Identifier of the stylesheet containing this object (if exists). */
        mediaList: array(MediaQuery.t) /* Array of media queries. */,
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
        valueRange: SourceRange.t, /* The associated range of the value text in the enclosing stylesheet (if available). */
        computedLength: float /* Computed length of media query expression (if applicable). */,
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
        fontVariationAxes: array(FontVariationAxis.t) /* Available variation settings (a.k.a. "axes"). */,
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
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
        inlineStyle: CSSStyle.t, /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    }
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(int) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    }
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        range: SourceRange.t /* Value range in the underlying resource (if available). */,
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
        sourceMapURL: string, /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        ownerNode: DOM.Types.BackendNodeId.t, /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        hasSourceURL: bool, /* Whether the sourceURL field value comes from the sourceURL comment. */
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        media: array(CSSMedia.t) /* Media list array (for rules involving media queries). The array enumerates media queries
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
        startLine: int, /* Start line of range. */
        startColumn: int, /* Start column of range (inclusive). */
        endLine: int, /* End line of range */
        endColumn: int /* End column of range (exclusive). */,
      };
    }
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        important: bool /* Whether the property has "!important" annotation (implies `false` if absent). */,
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        cssText: string, /* Style declaration text (if available). */
        range: SourceRange.t /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    }
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        important: bool, /* Whether the property has "!important" annotation (implies `false` if absent). */
        implicit: bool, /* Whether the property is implicit (implies `false` if absent). */
        text: string, /* The full property text as specified in the style. */
        parsedOk: bool, /* Whether the property is understood by the browser (implies `true` if absent). */
        disabled: bool, /* Whether the property is disabled by the user (present for source-based properties only). */
        range: SourceRange.t /* The entire property range in the enclosing style declaration (if available). */,
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
        sourceURL: string, /* URL of the document containing the media query description. */
        range: SourceRange.t, /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        styleSheetId: StyleSheetId.t, /* Identifier of the stylesheet containing this object (if exists). */
        mediaList: array(MediaQuery.t) /* Array of media queries. */,
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
        valueRange: SourceRange.t, /* The associated range of the value text in the enclosing stylesheet (if available). */
        computedLength: float /* Computed length of media query expression (if applicable). */,
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
        fontVariationAxes: array(FontVariationAxis.t) /* Available variation settings (a.k.a. "axes"). */,
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
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
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
    } = StyleSheetId
    and StyleSheetOrigin: {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    } = StyleSheetOrigin
    and PseudoElementMatches: {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {
        pseudoType: DOM.Types.PseudoType.t, /* Pseudo element type. */
        matches: array(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
      };
    } = PseudoElementMatches
    and InheritedStyleEntry: {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {
        inlineStyle: CSSStyle.t, /* The ancestor node's inline style, if any, in the style inheritance chain. */
        matchedCSSRules: array(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
      };
    } = InheritedStyleEntry
    and RuleMatch: {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {
        rule: CSSRule.t, /* CSS rule in the match. */
        matchingSelectors: array(int) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
      };
    } = RuleMatch
    and Value: {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {
        text: string, /* Value text. */
        range: SourceRange.t /* Value range in the underlying resource (if available). */,
      };
    } = Value
    and SelectorList: {
      /* Selector list data. */
      [@deriving yojson]
      type t = {
        selectors: array(Value.t), /* Selectors in the list. */
        text: string /* Rule selector text. */,
      };
    } = SelectorList
    and CSSStyleSheetHeader: {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
        frameId: Page.Types.FrameId.t, /* Owner frame identifier. */
        sourceURL: string, /* Stylesheet resource URL. */
        sourceMapURL: string, /* URL of source map associated with the stylesheet (if any). */
        origin: StyleSheetOrigin.t, /* Stylesheet origin. */
        title: string, /* Stylesheet title. */
        ownerNode: DOM.Types.BackendNodeId.t, /* The backend id for the owner node of the stylesheet. */
        disabled: bool, /* Denotes whether the stylesheet is disabled. */
        hasSourceURL: bool, /* Whether the sourceURL field value comes from the sourceURL comment. */
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
    } = CSSStyleSheetHeader
    and CSSRule: {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        selectorList: SelectorList.t, /* Rule selector data. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        style: CSSStyle.t, /* Associated style declaration. */
        media: array(CSSMedia.t) /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */,
      };
    } = CSSRule
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
    } = RuleUsage
    and SourceRange: {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {
        startLine: int, /* Start line of range. */
        startColumn: int, /* Start column of range (inclusive). */
        endLine: int, /* End line of range */
        endColumn: int /* End column of range (exclusive). */,
      };
    } = SourceRange
    and ShorthandEntry: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Shorthand name. */
        value: string, /* Shorthand value. */
        important: bool /* Whether the property has "!important" annotation (implies `false` if absent). */,
      };
    } = ShorthandEntry
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    } = CSSComputedStyleProperty
    and CSSStyle: {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        cssProperties: array(CSSProperty.t), /* CSS properties in the style. */
        shorthandEntries: array(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
        cssText: string, /* Style declaration text (if available). */
        range: SourceRange.t /* Style declaration range in the enclosing stylesheet (if available). */,
      };
    } = CSSStyle
    and CSSProperty: {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {
        name: string, /* The property name. */
        value: string, /* The property value. */
        important: bool, /* Whether the property has "!important" annotation (implies `false` if absent). */
        implicit: bool, /* Whether the property is implicit (implies `false` if absent). */
        text: string, /* The full property text as specified in the style. */
        parsedOk: bool, /* Whether the property is understood by the browser (implies `true` if absent). */
        disabled: bool, /* Whether the property is disabled by the user (present for source-based properties only). */
        range: SourceRange.t /* The entire property range in the enclosing style declaration (if available). */,
      };
    } = CSSProperty
    and CSSMedia: {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {
        text: string, /* Media query text. */
        source: string, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
        sourceURL: string, /* URL of the document containing the media query description. */
        range: SourceRange.t, /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
        styleSheetId: StyleSheetId.t, /* Identifier of the stylesheet containing this object (if exists). */
        mediaList: array(MediaQuery.t) /* Array of media queries. */,
      };
    } = CSSMedia
    and MediaQuery: {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {
        expressions: array(MediaQueryExpression.t), /* Array of media query expressions. */
        active: bool /* Whether the media query condition is satisfied. */,
      };
    } = MediaQuery
    and MediaQueryExpression: {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {
        value: float, /* Media query expression value. */
        unit: string, /* Media query expression units. */
        feature: string, /* Media query expression feature. */
        valueRange: SourceRange.t, /* The associated range of the value text in the enclosing stylesheet (if available). */
        computedLength: float /* Computed length of media query expression (if applicable). */,
      };
    } = MediaQueryExpression
    and PlatformFontUsage: {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {
        familyName: string, /* Font's family name reported by platform. */
        isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
        glyphCount: float /* Amount of glyphs that were rendered with this font. */,
      };
    } = PlatformFontUsage
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
    } = FontVariationAxis
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
        fontVariationAxes: array(FontVariationAxis.t) /* Available variation settings (a.k.a. "axes"). */,
      };
    } = FontFace
    and CSSKeyframesRule: {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {
        animationName: Value.t, /* Animation name. */
        keyframes: array(CSSKeyframeRule.t) /* List of keyframes. */,
      };
    } = CSSKeyframesRule
    and CSSKeyframeRule: {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
        origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
        keyText: Value.t, /* Associated key text. */
        style: CSSStyle.t /* Associated style declaration. */,
      };
    } = CSSKeyframeRule
    and StyleDeclarationEdit: {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {
        styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
        range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
        text: string /* New style text. */,
      };
    } = StyleDeclarationEdit;
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
        responseStatus: int, /* HTTP response status code. */
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
        responseStatus: int, /* HTTP response status code. */
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
    } = CacheId
    and CachedResponseType: {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    } = CachedResponseType
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        requestURL: string, /* Request URL. */
        requestMethod: string, /* Request method. */
        requestHeaders: array(Header.t), /* Request headers */
        responseTime: float, /* Number of seconds since epoch. */
        responseStatus: int, /* HTTP response status code. */
        responseStatusText: string, /* HTTP response status text. */
        responseType: CachedResponseType.t, /* HTTP response type */
        responseHeaders: array(Header.t) /* Response headers */,
      };
    } = DataEntry
    and Cache: {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {
        cacheId: CacheId.t, /* An opaque unique id of the cache. */
        securityOrigin: string, /* Security origin of the cache. */
        cacheName: string /* The name of the cache. */,
      };
    } = Cache
    and Header: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = Header
    and CachedResponse: {
      /* Cached response */
      [@deriving yojson]
      type t = {
        body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
      };
    } = CachedResponse;
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
        session: string /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
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
        session: string /* Text describing the current session. Present only if there is an active
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
        session: string /* Text describing the current session. Present only if there is an active
session on the sink. */,
      };
    } = Sink;
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
        url: string, /* URL of the message origin. */
        line: int, /* Line number in the resource that generated this message (1-based). */
        column: int /* Column number in the resource that generated this message (1-based). */,
      };
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
        url: string, /* URL of the message origin. */
        line: int, /* Line number in the resource that generated this message (1-based). */
        column: int /* Column number in the resource that generated this message (1-based). */,
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
        url: string, /* URL of the message origin. */
        line: int, /* Line number in the resource that generated this message (1-based). */
        column: int /* Column number in the resource that generated this message (1-based). */,
      };
    } = ConsoleMessage;
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
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int /* Column number in the script (0-based). */,
      };
    }
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    }
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        end_: ScriptPosition.t /* No description provided */,
      };
    }
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        functionLocation: Location.t, /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        returnValue: Runtime.Types.RemoteObject.t /* The value being returned, if the function is at return point. */,
      };
    }
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        type_: string, /* Scope type. */
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        name: string, /* No description provided */
        startLocation: Location.t, /* Location in the source code where scope starts */
        endLocation: Location.t /* Location in the source code where scope ends */,
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
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        type_: string /* No description provided */,
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
        type_: string, /* Type of the debug symbols. */
        externalURL: string /* URL of the external symbol source. */,
      };
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
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int /* Column number in the script (0-based). */,
      };
    }
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    }
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        end_: ScriptPosition.t /* No description provided */,
      };
    }
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        functionLocation: Location.t, /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        returnValue: Runtime.Types.RemoteObject.t /* The value being returned, if the function is at return point. */,
      };
    }
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        type_: string, /* Scope type. */
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        name: string, /* No description provided */
        startLocation: Location.t, /* Location in the source code where scope starts */
        endLocation: Location.t /* Location in the source code where scope ends */,
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
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        type_: string /* No description provided */,
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
        type_: string, /* Type of the debug symbols. */
        externalURL: string /* URL of the external symbol source. */,
      };
    };
  } = {
    module rec BreakpointId: {
      /* Breakpoint identifier. */
      [@deriving yojson]
      type t = string;
    } = BreakpointId
    and CallFrameId: {
      /* Call frame identifier. */
      [@deriving yojson]
      type t = string;
    } = CallFrameId
    and Location: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int /* Column number in the script (0-based). */,
      };
    } = Location
    and ScriptPosition: {
      /* Location in the source code. */
      [@deriving yojson]
      type t = {
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    } = ScriptPosition
    and LocationRange: {
      /* Location range within one script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* No description provided */
        start: ScriptPosition.t, /* No description provided */
        end_: ScriptPosition.t /* No description provided */,
      };
    } = LocationRange
    and CallFrame: {
      /* JavaScript call frame. Array of call frames form the call stack. */
      [@deriving yojson]
      type t = {
        callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
        functionName: string, /* Name of the JavaScript function called on this call frame. */
        functionLocation: Location.t, /* Location in the source code. */
        location: Location.t, /* Location in the source code. */
        url: string, /* JavaScript script name or url. */
        scopeChain: array(Scope.t), /* Scope chain for this call frame. */
        this: Runtime.Types.RemoteObject.t, /* `this` object for this call frame. */
        returnValue: Runtime.Types.RemoteObject.t /* The value being returned, if the function is at return point. */,
      };
    } = CallFrame
    and Scope: {
      /* Scope description. */
      [@deriving yojson]
      type t = {
        type_: string, /* Scope type. */
        object_: Runtime.Types.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
        name: string, /* No description provided */
        startLocation: Location.t, /* Location in the source code where scope starts */
        endLocation: Location.t /* Location in the source code where scope ends */,
      };
    } = Scope
    and SearchMatch: {
      /* Search match for resource. */
      [@deriving yojson]
      type t = {
        lineNumber: float, /* Line number in resource content. */
        lineContent: string /* Line with match content. */,
      };
    } = SearchMatch
    and BreakLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        type_: string /* No description provided */,
      };
    } = BreakLocation
    and ScriptLanguage: {
      /* Enum of possible script languages. */
      [@deriving yojson]
      type t = string;
    } = ScriptLanguage
    and DebugSymbols: {
      /* Debug symbols available for a wasm script. */
      [@deriving yojson]
      type t = {
        type_: string, /* Type of the debug symbols. */
        externalURL: string /* URL of the external symbol source. */,
      };
    } = DebugSymbols;
  };
}
and DOM: {
  module Types: {
    module rec NodeId: {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: int, /* `Node`'s nodeType. */
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
        parentId: NodeId.t, /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        childNodeCount: int, /* Child count for `Container` nodes. */
        children: array(Node.t), /* Child nodes of this node when requested with children. */
        attributes: array(string), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        publicId: string, /* `DocumentType`'s publicId. */
        systemId: string, /* `DocumentType`'s systemId. */
        internalSubset: string, /* `DocumentType`'s internalSubset. */
        xmlVersion: string, /* `Document`'s XML version in case of XML documents. */
        name: string, /* `Attr`'s name. */
        value: string, /* `Attr`'s value. */
        pseudoType: PseudoType.t, /* Pseudo element type for this node. */
        shadowRootType: ShadowRootType.t, /* Shadow root type. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements. */
        contentDocument: Node.t, /* Content document for frame owner elements. */
        shadowRoots: array(Node.t), /* Shadow root list for given element host. */
        templateContent: Node.t, /* Content document fragment for template elements. */
        pseudoElements: array(Node.t), /* Pseudo elements associated with this node. */
        importedDocument: Node.t, /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        distributedNodes: array(BackendNode.t), /* Distributed nodes for given insertion point. */
        isSVG: bool, /* Whether the node is SVG. */
        compatibilityMode: CompatibilityMode.t /* No description provided */,
      };
    }
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: int, /* The red component, in the [0-255] range. */
        g: int, /* The green component, in the [0-255] range. */
        b: int, /* The blue component, in the [0-255] range. */
        a: float /* The alpha component, in the [0-1] range (default: 1). */,
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
        width: int, /* Node width */
        height: int, /* Node height */
        shapeOutside: ShapeOutsideInfo.t /* Shape outside coordinates */,
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
} = {
  module Types: {
    module rec NodeId: {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: int, /* `Node`'s nodeType. */
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
        parentId: NodeId.t, /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        childNodeCount: int, /* Child count for `Container` nodes. */
        children: array(Node.t), /* Child nodes of this node when requested with children. */
        attributes: array(string), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        publicId: string, /* `DocumentType`'s publicId. */
        systemId: string, /* `DocumentType`'s systemId. */
        internalSubset: string, /* `DocumentType`'s internalSubset. */
        xmlVersion: string, /* `Document`'s XML version in case of XML documents. */
        name: string, /* `Attr`'s name. */
        value: string, /* `Attr`'s value. */
        pseudoType: PseudoType.t, /* Pseudo element type for this node. */
        shadowRootType: ShadowRootType.t, /* Shadow root type. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements. */
        contentDocument: Node.t, /* Content document for frame owner elements. */
        shadowRoots: array(Node.t), /* Shadow root list for given element host. */
        templateContent: Node.t, /* Content document fragment for template elements. */
        pseudoElements: array(Node.t), /* Pseudo elements associated with this node. */
        importedDocument: Node.t, /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        distributedNodes: array(BackendNode.t), /* Distributed nodes for given insertion point. */
        isSVG: bool, /* Whether the node is SVG. */
        compatibilityMode: CompatibilityMode.t /* No description provided */,
      };
    }
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: int, /* The red component, in the [0-255] range. */
        g: int, /* The green component, in the [0-255] range. */
        b: int, /* The blue component, in the [0-255] range. */
        a: float /* The alpha component, in the [0-1] range (default: 1). */,
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
        width: int, /* Node width */
        height: int, /* Node height */
        shapeOutside: ShapeOutsideInfo.t /* Shape outside coordinates */,
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
      type t = int;
    } = NodeId
    and BackendNodeId: {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = int;
    } = BackendNodeId
    and BackendNode: {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        backendNodeId: BackendNodeId.t /* No description provided */,
      };
    } = BackendNode
    and PseudoType: {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    } = PseudoType
    and ShadowRootType: {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    } = ShadowRootType
    and CompatibilityMode: {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    } = CompatibilityMode
    and Node: {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {
        nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
        parentId: NodeId.t, /* The id of the parent node if any. */
        backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        localName: string, /* `Node`'s localName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        childNodeCount: int, /* Child count for `Container` nodes. */
        children: array(Node.t), /* Child nodes of this node when requested with children. */
        attributes: array(string), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        publicId: string, /* `DocumentType`'s publicId. */
        systemId: string, /* `DocumentType`'s systemId. */
        internalSubset: string, /* `DocumentType`'s internalSubset. */
        xmlVersion: string, /* `Document`'s XML version in case of XML documents. */
        name: string, /* `Attr`'s name. */
        value: string, /* `Attr`'s value. */
        pseudoType: PseudoType.t, /* Pseudo element type for this node. */
        shadowRootType: ShadowRootType.t, /* Shadow root type. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements. */
        contentDocument: Node.t, /* Content document for frame owner elements. */
        shadowRoots: array(Node.t), /* Shadow root list for given element host. */
        templateContent: Node.t, /* Content document fragment for template elements. */
        pseudoElements: array(Node.t), /* Pseudo elements associated with this node. */
        importedDocument: Node.t, /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
        distributedNodes: array(BackendNode.t), /* Distributed nodes for given insertion point. */
        isSVG: bool, /* Whether the node is SVG. */
        compatibilityMode: CompatibilityMode.t /* No description provided */,
      };
    } = Node
    and RGBA: {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {
        r: int, /* The red component, in the [0-255] range. */
        g: int, /* The green component, in the [0-255] range. */
        b: int, /* The blue component, in the [0-255] range. */
        a: float /* The alpha component, in the [0-1] range (default: 1). */,
      };
    } = RGBA
    and Quad: {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(float);
    } = Quad
    and BoxModel: {
      /* Box model. */
      [@deriving yojson]
      type t = {
        content: Quad.t, /* Content box */
        padding: Quad.t, /* Padding box */
        border: Quad.t, /* Border box */
        margin: Quad.t, /* Margin box */
        width: int, /* Node width */
        height: int, /* Node height */
        shapeOutside: ShapeOutsideInfo.t /* Shape outside coordinates */,
      };
    } = BoxModel
    and ShapeOutsideInfo: {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {
        bounds: Quad.t, /* Shape bounds */
        shape: array(string), /* Shape coordinate details */
        marginShape: array(string) /* Margin shape bounds */,
      };
    } = ShapeOutsideInfo
    and Rect: {
      /* Rectangle. */
      [@deriving yojson]
      type t = {
        x: float, /* X coordinate */
        y: float, /* Y coordinate */
        width: float, /* Rectangle width */
        height: float /* Rectangle height */,
      };
    } = Rect
    and CSSComputedStyleProperty: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Computed style property name. */
        value: string /* Computed style property value. */,
      };
    } = CSSComputedStyleProperty;
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
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        handler: Runtime.Types.RemoteObject.t, /* Event handler function value. */
        originalHandler: Runtime.Types.RemoteObject.t, /* Event original handler function value. */
        backendNodeId: DOM.Types.BackendNodeId.t /* Node the listener is added to (if any). */,
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
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        handler: Runtime.Types.RemoteObject.t, /* Event handler function value. */
        originalHandler: Runtime.Types.RemoteObject.t, /* Event original handler function value. */
        backendNodeId: DOM.Types.BackendNodeId.t /* Node the listener is added to (if any). */,
      };
    };
  } = {
    module rec DOMBreakpointType: {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    } = DOMBreakpointType
    and CSPViolationType: {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    } = CSPViolationType
    and EventListener: {
      /* Object event listener. */
      [@deriving yojson]
      type t = {
        type_: string, /* `EventListener`'s type. */
        useCapture: bool, /* `EventListener`'s useCapture. */
        passive: bool, /* `EventListener`'s passive flag. */
        once: bool, /* `EventListener`'s once flag. */
        scriptId: Runtime.Types.ScriptId.t, /* Script id of the handler code. */
        lineNumber: int, /* Line number in the script (0-based). */
        columnNumber: int, /* Column number in the script (0-based). */
        handler: Runtime.Types.RemoteObject.t, /* Event handler function value. */
        originalHandler: Runtime.Types.RemoteObject.t, /* Event original handler function value. */
        backendNodeId: DOM.Types.BackendNodeId.t /* Node the listener is added to (if any). */,
      };
    } = EventListener;
  };
}
and DOMSnapshot: {
  module Types: {
    module rec DOMNode: {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        textValue: string, /* Only set for textarea elements, contains the text value. */
        inputValue: string, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: bool, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: bool, /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        childNodeIndexes: array(int), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        attributes: array(NameValue.t), /* Attributes of an `Element` node. */
        pseudoElementIndexes: array(int), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        layoutNodeIndex: int, /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: string, /* Only set for documents, contains the document's content language. */
        documentEncoding: string, /* Only set for documents, contains the document's character set encoding. */
        publicId: string, /* `DocumentType` node's publicId. */
        systemId: string, /* `DocumentType` node's systemId. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements and also for the document node. */
        contentDocumentIndex: int, /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        pseudoType: DOM.Types.PseudoType.t, /* Type of a pseudo element node. */
        shadowRootType: DOM.Types.ShadowRootType.t, /* Shadow root type. */
        isClickable: bool, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        eventListeners: array(DOMDebugger.Types.EventListener.t), /* Details of the node's event listeners, if any. */
        currentSourceURL: string, /* The selected url for nodes with a srcset attribute. */
        originURL: string, /* The url of the script (if any) that generates this node. */
        scrollOffsetX: float, /* Scroll offsets, set when this node is a Document. */
        scrollOffsetY: float /* No description provided */,
      };
    }
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: int, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: int /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    }
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: int, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        layoutText: string, /* Contents of the LayoutText, if any. */
        inlineTextNodes: array(InlineTextBox.t), /* The post-layout inline text nodes, if any. */
        styleIndex: int, /* Index into the `computedStyles` array returned by `getSnapshot`. */
        paintOrder: int, /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        isStackingContext: bool /* Set to true to indicate the element begins a new stacking context. */,
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
      type t = int;
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
        index: array(int), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    }
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(int) /* No description provided */};
    }
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(int), /* No description provided */
        value: array(int) /* No description provided */,
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
        scrollOffsetX: float, /* Horizontal scroll offset. */
        scrollOffsetY: float, /* Vertical scroll offset. */
        contentWidth: float, /* Document content width. */
        contentHeight: float /* Document content height. */,
      };
    }
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        parentIndex: array(int), /* Parent node index. */
        nodeType: array(int), /* `Node`'s nodeType. */
        nodeName: array(StringIndex.t), /* `Node`'s nodeName. */
        nodeValue: array(StringIndex.t), /* `Node`'s nodeValue. */
        backendNodeId: array(DOM.Types.BackendNodeId.t), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        attributes: array(ArrayOfStrings.t), /* Attributes of an `Element` node. Flatten name, value pairs. */
        textValue: RareStringData.t, /* Only set for textarea elements, contains the text value. */
        inputValue: RareStringData.t, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: RareBooleanData.t, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: RareBooleanData.t, /* Only set for option elements, indicates if the element has been selected */
        contentDocumentIndex: RareIntegerData.t, /* The index of the document in the list of the snapshot documents. */
        pseudoType: RareStringData.t, /* Type of a pseudo element node. */
        isClickable: RareBooleanData.t, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        currentSourceURL: RareStringData.t, /* The selected url for nodes with a srcset attribute. */
        originURL: RareStringData.t /* The url of the script (if any) that generates this node. */,
      };
    }
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(int), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        paintOrders: array(int), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        offsetRects: array(Rectangle.t), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        scrollRects: array(Rectangle.t), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        clientRects: array(Rectangle.t), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        blendedBackgroundColors: array(StringIndex.t), /* The list of background colors that are blended with colors of overlapping elements. */
        textColorOpacities: array(float) /* The list of computed text opacities. */,
      };
    }
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(int), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(int), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(int) /* The number of characters in this post layout textbox substring. Characters that would be
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
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        textValue: string, /* Only set for textarea elements, contains the text value. */
        inputValue: string, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: bool, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: bool, /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        childNodeIndexes: array(int), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        attributes: array(NameValue.t), /* Attributes of an `Element` node. */
        pseudoElementIndexes: array(int), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        layoutNodeIndex: int, /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: string, /* Only set for documents, contains the document's content language. */
        documentEncoding: string, /* Only set for documents, contains the document's character set encoding. */
        publicId: string, /* `DocumentType` node's publicId. */
        systemId: string, /* `DocumentType` node's systemId. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements and also for the document node. */
        contentDocumentIndex: int, /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        pseudoType: DOM.Types.PseudoType.t, /* Type of a pseudo element node. */
        shadowRootType: DOM.Types.ShadowRootType.t, /* Shadow root type. */
        isClickable: bool, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        eventListeners: array(DOMDebugger.Types.EventListener.t), /* Details of the node's event listeners, if any. */
        currentSourceURL: string, /* The selected url for nodes with a srcset attribute. */
        originURL: string, /* The url of the script (if any) that generates this node. */
        scrollOffsetX: float, /* Scroll offsets, set when this node is a Document. */
        scrollOffsetY: float /* No description provided */,
      };
    }
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: int, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: int /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    }
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: int, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        layoutText: string, /* Contents of the LayoutText, if any. */
        inlineTextNodes: array(InlineTextBox.t), /* The post-layout inline text nodes, if any. */
        styleIndex: int, /* Index into the `computedStyles` array returned by `getSnapshot`. */
        paintOrder: int, /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        isStackingContext: bool /* Set to true to indicate the element begins a new stacking context. */,
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
      type t = int;
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
        index: array(int), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    }
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(int) /* No description provided */};
    }
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(int), /* No description provided */
        value: array(int) /* No description provided */,
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
        scrollOffsetX: float, /* Horizontal scroll offset. */
        scrollOffsetY: float, /* Vertical scroll offset. */
        contentWidth: float, /* Document content width. */
        contentHeight: float /* Document content height. */,
      };
    }
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        parentIndex: array(int), /* Parent node index. */
        nodeType: array(int), /* `Node`'s nodeType. */
        nodeName: array(StringIndex.t), /* `Node`'s nodeName. */
        nodeValue: array(StringIndex.t), /* `Node`'s nodeValue. */
        backendNodeId: array(DOM.Types.BackendNodeId.t), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        attributes: array(ArrayOfStrings.t), /* Attributes of an `Element` node. Flatten name, value pairs. */
        textValue: RareStringData.t, /* Only set for textarea elements, contains the text value. */
        inputValue: RareStringData.t, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: RareBooleanData.t, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: RareBooleanData.t, /* Only set for option elements, indicates if the element has been selected */
        contentDocumentIndex: RareIntegerData.t, /* The index of the document in the list of the snapshot documents. */
        pseudoType: RareStringData.t, /* Type of a pseudo element node. */
        isClickable: RareBooleanData.t, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        currentSourceURL: RareStringData.t, /* The selected url for nodes with a srcset attribute. */
        originURL: RareStringData.t /* The url of the script (if any) that generates this node. */,
      };
    }
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(int), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        paintOrders: array(int), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        offsetRects: array(Rectangle.t), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        scrollRects: array(Rectangle.t), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        clientRects: array(Rectangle.t), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        blendedBackgroundColors: array(StringIndex.t), /* The list of background colors that are blended with colors of overlapping elements. */
        textColorOpacities: array(float) /* The list of computed text opacities. */,
      };
    }
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(int), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(int), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(int) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    };
  } = {
    module rec DOMNode: {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {
        nodeType: int, /* `Node`'s nodeType. */
        nodeName: string, /* `Node`'s nodeName. */
        nodeValue: string, /* `Node`'s nodeValue. */
        textValue: string, /* Only set for textarea elements, contains the text value. */
        inputValue: string, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: bool, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: bool, /* Only set for option elements, indicates if the element has been selected */
        backendNodeId: DOM.Types.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        childNodeIndexes: array(int), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
        attributes: array(NameValue.t), /* Attributes of an `Element` node. */
        pseudoElementIndexes: array(int), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
        layoutNodeIndex: int, /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
        documentURL: string, /* Document URL that `Document` or `FrameOwner` node points to. */
        baseURL: string, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
        contentLanguage: string, /* Only set for documents, contains the document's content language. */
        documentEncoding: string, /* Only set for documents, contains the document's character set encoding. */
        publicId: string, /* `DocumentType` node's publicId. */
        systemId: string, /* `DocumentType` node's systemId. */
        frameId: Page.Types.FrameId.t, /* Frame ID for frame owner elements and also for the document node. */
        contentDocumentIndex: int, /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
        pseudoType: DOM.Types.PseudoType.t, /* Type of a pseudo element node. */
        shadowRootType: DOM.Types.ShadowRootType.t, /* Shadow root type. */
        isClickable: bool, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        eventListeners: array(DOMDebugger.Types.EventListener.t), /* Details of the node's event listeners, if any. */
        currentSourceURL: string, /* The selected url for nodes with a srcset attribute. */
        originURL: string, /* The url of the script (if any) that generates this node. */
        scrollOffsetX: float, /* Scroll offsets, set when this node is a Document. */
        scrollOffsetY: float /* No description provided */,
      };
    } = DOMNode
    and InlineTextBox: {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        startCharacterIndex: int, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        numCharacters: int /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    } = InlineTextBox
    and LayoutTreeNode: {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        domNodeIndex: int, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
        boundingBox: DOM.Types.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
        layoutText: string, /* Contents of the LayoutText, if any. */
        inlineTextNodes: array(InlineTextBox.t), /* The post-layout inline text nodes, if any. */
        styleIndex: int, /* Index into the `computedStyles` array returned by `getSnapshot`. */
        paintOrder: int, /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
        isStackingContext: bool /* Set to true to indicate the element begins a new stacking context. */,
      };
    } = LayoutTreeNode
    and ComputedStyle: {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {
        properties: array(NameValue.t) /* Name/value pairs of computed style properties. */,
      };
    } = ComputedStyle
    and NameValue: {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {
        name: string, /* Attribute/property name. */
        value: string /* Attribute/property value. */,
      };
    } = NameValue
    and StringIndex: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = int;
    } = StringIndex
    and ArrayOfStrings: {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(StringIndex.t);
    } = ArrayOfStrings
    and RareStringData: {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {
        index: array(int), /* No description provided */
        value: array(StringIndex.t) /* No description provided */,
      };
    } = RareStringData
    and RareBooleanData: {
      /* No description provided */
      [@deriving yojson]
      type t = {index: array(int) /* No description provided */};
    } = RareBooleanData
    and RareIntegerData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        index: array(int), /* No description provided */
        value: array(int) /* No description provided */,
      };
    } = RareIntegerData
    and Rectangle: {
      /* No description provided */
      [@deriving yojson]
      type t = array(float);
    } = Rectangle
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
        scrollOffsetX: float, /* Horizontal scroll offset. */
        scrollOffsetY: float, /* Vertical scroll offset. */
        contentWidth: float, /* Document content width. */
        contentHeight: float /* Document content height. */,
      };
    } = DocumentSnapshot
    and NodeTreeSnapshot: {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {
        parentIndex: array(int), /* Parent node index. */
        nodeType: array(int), /* `Node`'s nodeType. */
        nodeName: array(StringIndex.t), /* `Node`'s nodeName. */
        nodeValue: array(StringIndex.t), /* `Node`'s nodeValue. */
        backendNodeId: array(DOM.Types.BackendNodeId.t), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
        attributes: array(ArrayOfStrings.t), /* Attributes of an `Element` node. Flatten name, value pairs. */
        textValue: RareStringData.t, /* Only set for textarea elements, contains the text value. */
        inputValue: RareStringData.t, /* Only set for input elements, contains the input's associated text value. */
        inputChecked: RareBooleanData.t, /* Only set for radio and checkbox input elements, indicates if the element has been checked */
        optionSelected: RareBooleanData.t, /* Only set for option elements, indicates if the element has been selected */
        contentDocumentIndex: RareIntegerData.t, /* The index of the document in the list of the snapshot documents. */
        pseudoType: RareStringData.t, /* Type of a pseudo element node. */
        isClickable: RareBooleanData.t, /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
        currentSourceURL: RareStringData.t, /* The selected url for nodes with a srcset attribute. */
        originURL: RareStringData.t /* The url of the script (if any) that generates this node. */,
      };
    } = NodeTreeSnapshot
    and LayoutTreeSnapshot: {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {
        nodeIndex: array(int), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
        styles: array(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        text: array(StringIndex.t), /* Contents of the LayoutText, if any. */
        stackingContexts: RareBooleanData.t, /* Stacking context information. */
        paintOrders: array(int), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
        offsetRects: array(Rectangle.t), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
        scrollRects: array(Rectangle.t), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
        clientRects: array(Rectangle.t), /* The client rect of nodes. Only available when includeDOMRects is set to true */
        blendedBackgroundColors: array(StringIndex.t), /* The list of background colors that are blended with colors of overlapping elements. */
        textColorOpacities: array(float) /* The list of computed text opacities. */,
      };
    } = LayoutTreeSnapshot
    and TextBoxSnapshot: {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {
        layoutIndex: array(int), /* Index of the layout tree node that owns this box collection. */
        bounds: array(Rectangle.t), /* The absolute position bounding box. */
        start: array(int), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
        length: array(int) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
      };
    } = TextBoxSnapshot;
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
    } = StorageId
    and Item: {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(string);
    } = Item;
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
        code: int /* Error code. */,
      };
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
        code: int /* Error code. */,
      };
    };
  } = {
    module rec DatabaseId: {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    } = DatabaseId
    and Database: {
      /* Database object. */
      [@deriving yojson]
      type t = {
        id: DatabaseId.t, /* Database ID. */
        domain: string, /* Database domain. */
        name: string, /* Database name. */
        version: string /* Database version. */,
      };
    } = Database
    and Error: {
      /* Database error. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        code: int /* Error code. */,
      };
    } = Error;
  };
}
and DeviceOrientation: {} = {}
and Emulation: {
  module Types: {
    module rec ScreenOrientation: {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        type_: string, /* Orientation type. */
        angle: int /* Orientation angle. */,
      };
    }
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: int, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: int /* A display feature may mask content such that it is not physically
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
        brands: array(UserAgentBrandVersion.t), /* No description provided */
        fullVersion: string, /* No description provided */
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
} = {
  module Types: {
    module rec ScreenOrientation: {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {
        type_: string, /* Orientation type. */
        angle: int /* Orientation angle. */,
      };
    }
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: int, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: int /* A display feature may mask content such that it is not physically
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
        brands: array(UserAgentBrandVersion.t), /* No description provided */
        fullVersion: string, /* No description provided */
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
        type_: string, /* Orientation type. */
        angle: int /* Orientation angle. */,
      };
    } = ScreenOrientation
    and DisplayFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        orientation: string, /* Orientation of a display feature in relation to screen */
        offset: int, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
        maskLength: int /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
      };
    } = DisplayFeature
    and MediaFeature: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = MediaFeature
    and VirtualTimePolicy: {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    } = VirtualTimePolicy
    and UserAgentBrandVersion: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {
        brand: string, /* No description provided */
        version: string /* No description provided */,
      };
    } = UserAgentBrandVersion
    and UserAgentMetadata: {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {
        brands: array(UserAgentBrandVersion.t), /* No description provided */
        fullVersion: string, /* No description provided */
        platform: string, /* No description provided */
        platformVersion: string, /* No description provided */
        architecture: string, /* No description provided */
        model: string, /* No description provided */
        mobile: bool /* No description provided */,
      };
    } = UserAgentMetadata
    and DisabledImageType: {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    } = DisabledImageType;
  };
}
and HeadlessExperimental: {
  module Types: {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        format: string, /* Image compression format (defaults to png). */
        quality: int /* Compression quality from range [0..100] (jpeg only). */,
      };
    };
  };
} = {
  module Types: {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        format: string, /* Image compression format (defaults to png). */
        quality: int /* Compression quality from range [0..100] (jpeg only). */,
      };
    };
  } = {
    module rec ScreenshotParams: {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {
        format: string, /* Image compression format (defaults to png). */
        quality: int /* Compression quality from range [0..100] (jpeg only). */,
      };
    } = ScreenshotParams;
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
        id: int, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    }
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: int, /* Id of the corresponding profile tree node. */
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
        id: int, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    }
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: int, /* Id of the corresponding profile tree node. */
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
    } = HeapSnapshotObjectId
    and SamplingHeapProfileNode: {
      /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
      [@deriving yojson]
      type t = {
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        selfSize: float, /* Allocations size in bytes for the node excluding children. */
        id: int, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
        children: array(SamplingHeapProfileNode.t) /* Child nodes. */,
      };
    } = SamplingHeapProfileNode
    and SamplingHeapProfileSample: {
      /* A single sample from a sampling profile. */
      [@deriving yojson]
      type t = {
        size: float, /* Allocation size in bytes attributed to the sample. */
        nodeId: int, /* Id of the corresponding profile tree node. */
        ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
      };
    } = SamplingHeapProfileSample
    and SamplingHeapProfile: {
      /* Sampling profile. */
      [@deriving yojson]
      type t = {
        head: SamplingHeapProfileNode.t, /* No description provided */
        samples: array(SamplingHeapProfileSample.t) /* No description provided */,
      };
    } = SamplingHeapProfile;
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
    } = StreamHandle;
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
        type_: string, /* Key type. */
        number: float, /* Number value. */
        string, /* String value. */
        date: float, /* Date value. */
        array: array(Key.t) /* Array value. */,
      };
    }
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        lower: Key.t, /* Lower bound. */
        upper: Key.t, /* Upper bound. */
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
        type_: string, /* Key path type. */
        string, /* String value. */
        array: array(string) /* Array value. */,
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
        type_: string, /* Key type. */
        number: float, /* Number value. */
        string, /* String value. */
        date: float, /* Date value. */
        array: array(Key.t) /* Array value. */,
      };
    }
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        lower: Key.t, /* Lower bound. */
        upper: Key.t, /* Upper bound. */
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
        type_: string, /* Key path type. */
        string, /* String value. */
        array: array(string) /* Array value. */,
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
    } = DatabaseWithObjectStores
    and ObjectStore: {
      /* Object store. */
      [@deriving yojson]
      type t = {
        name: string, /* Object store name. */
        keyPath: KeyPath.t, /* Object store key path. */
        autoIncrement: bool, /* If true, object store has auto increment flag set. */
        indexes: array(ObjectStoreIndex.t) /* Indexes in this object store. */,
      };
    } = ObjectStore
    and ObjectStoreIndex: {
      /* Object store index. */
      [@deriving yojson]
      type t = {
        name: string, /* Index name. */
        keyPath: KeyPath.t, /* Index key path. */
        unique: bool, /* If true, index is unique. */
        multiEntry: bool /* If true, index allows multiple entries for a key. */,
      };
    } = ObjectStoreIndex
    and Key: {
      /* Key. */
      [@deriving yojson]
      type t = {
        type_: string, /* Key type. */
        number: float, /* Number value. */
        string, /* String value. */
        date: float, /* Date value. */
        array: array(Key.t) /* Array value. */,
      };
    } = Key
    and KeyRange: {
      /* Key range. */
      [@deriving yojson]
      type t = {
        lower: Key.t, /* Lower bound. */
        upper: Key.t, /* Upper bound. */
        lowerOpen: bool, /* If true lower bound is open. */
        upperOpen: bool /* If true upper bound is open. */,
      };
    } = KeyRange
    and DataEntry: {
      /* Data entry. */
      [@deriving yojson]
      type t = {
        key: Runtime.Types.RemoteObject.t, /* Key object. */
        primaryKey: Runtime.Types.RemoteObject.t, /* Primary key object. */
        value: Runtime.Types.RemoteObject.t /* Value object. */,
      };
    } = DataEntry
    and KeyPath: {
      /* Key path. */
      [@deriving yojson]
      type t = {
        type_: string, /* Key path type. */
        string, /* String value. */
        array: array(string) /* Array value. */,
      };
    } = KeyPath;
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
        radiusX: float, /* X radius of the touch area (default: 1.0). */
        radiusY: float, /* Y radius of the touch area (default: 1.0). */
        rotationAngle: float, /* Rotation angle (default: 0.0). */
        force: float, /* Force (default: 1.0). */
        tangentialPressure: float, /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        tiltX: int, /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        tiltY: int, /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        twist: int, /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        id: float /* Identifier used to track touch sources between events, must be unique within an event. */,
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
        title: string, /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        baseURL: string /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    }
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: int /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
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
        radiusX: float, /* X radius of the touch area (default: 1.0). */
        radiusY: float, /* Y radius of the touch area (default: 1.0). */
        rotationAngle: float, /* Rotation angle (default: 0.0). */
        force: float, /* Force (default: 1.0). */
        tangentialPressure: float, /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        tiltX: int, /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        tiltY: int, /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        twist: int, /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        id: float /* Identifier used to track touch sources between events, must be unique within an event. */,
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
        title: string, /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        baseURL: string /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    }
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: int /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
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
        radiusX: float, /* X radius of the touch area (default: 1.0). */
        radiusY: float, /* Y radius of the touch area (default: 1.0). */
        rotationAngle: float, /* Rotation angle (default: 0.0). */
        force: float, /* Force (default: 1.0). */
        tangentialPressure: float, /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
        tiltX: int, /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
        tiltY: int, /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
        twist: int, /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
        id: float /* Identifier used to track touch sources between events, must be unique within an event. */,
      };
    } = TouchPoint
    and GestureSourceType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = GestureSourceType
    and MouseButton: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = MouseButton
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    } = TimeSinceEpoch
    and DragDataItem: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        mimeType: string, /* Mime type of the dragged data. */
        data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
        title: string, /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
        baseURL: string /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
      };
    } = DragDataItem
    and DragData: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        items: array(DragDataItem.t), /* No description provided */
        dragOperationsMask: int /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
      };
    } = DragData;
  };
}
and Inspector: {} = {}
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
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    }
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        nearestLayerShiftingStickyBox: LayerId.t, /* The nearest sticky layer that shifts the sticky box */
        nearestLayerShiftingContainingBlock: LayerId.t /* The nearest sticky layer that shifts the containing block */,
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
        parentLayerId: LayerId.t, /* The id of parent (not present for root). */
        backendNodeId: DOM.Types.BackendNodeId.t, /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        transform: array(float), /* Transformation matrix for layer, default is identity matrix */
        anchorX: float, /* Transform anchor point X, absent if no transform specified */
        anchorY: float, /* Transform anchor point Y, absent if no transform specified */
        anchorZ: float, /* Transform anchor point Z, absent if no transform specified */
        paintCount: int, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        invisible: bool, /* Set if layer is not visible. */
        scrollRects: array(ScrollRect.t), /* Rectangles scrolling on main thread only. */
        stickyPositionConstraint: StickyPositionConstraint.t /* Sticky position constraint information */,
      };
    }
    and PaintProfile: {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
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
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    }
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        nearestLayerShiftingStickyBox: LayerId.t, /* The nearest sticky layer that shifts the sticky box */
        nearestLayerShiftingContainingBlock: LayerId.t /* The nearest sticky layer that shifts the containing block */,
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
        parentLayerId: LayerId.t, /* The id of parent (not present for root). */
        backendNodeId: DOM.Types.BackendNodeId.t, /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        transform: array(float), /* Transformation matrix for layer, default is identity matrix */
        anchorX: float, /* Transform anchor point X, absent if no transform specified */
        anchorY: float, /* Transform anchor point Y, absent if no transform specified */
        anchorZ: float, /* Transform anchor point Z, absent if no transform specified */
        paintCount: int, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        invisible: bool, /* Set if layer is not visible. */
        scrollRects: array(ScrollRect.t), /* Rectangles scrolling on main thread only. */
        stickyPositionConstraint: StickyPositionConstraint.t /* Sticky position constraint information */,
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
    } = LayerId
    and SnapshotId: {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    } = SnapshotId
    and ScrollRect: {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* Rectangle itself. */
        type_: string /* Reason for rectangle to force scrolling on the main thread */,
      };
    } = ScrollRect
    and StickyPositionConstraint: {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {
        stickyBoxRect: DOM.Types.Rect.t, /* Layout rectangle of the sticky element before being shifted */
        containingBlockRect: DOM.Types.Rect.t, /* Layout rectangle of the containing block of the sticky element */
        nearestLayerShiftingStickyBox: LayerId.t, /* The nearest sticky layer that shifts the sticky box */
        nearestLayerShiftingContainingBlock: LayerId.t /* The nearest sticky layer that shifts the containing block */,
      };
    } = StickyPositionConstraint
    and PictureTile: {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {
        x: float, /* Offset from owning layer left boundary */
        y: float, /* Offset from owning layer top boundary */
        picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
      };
    } = PictureTile
    and Layer: {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {
        layerId: LayerId.t, /* The unique id for this layer. */
        parentLayerId: LayerId.t, /* The id of parent (not present for root). */
        backendNodeId: DOM.Types.BackendNodeId.t, /* The backend id for the node associated with this layer. */
        offsetX: float, /* Offset from parent layer, X coordinate. */
        offsetY: float, /* Offset from parent layer, Y coordinate. */
        width: float, /* Layer width. */
        height: float, /* Layer height. */
        transform: array(float), /* Transformation matrix for layer, default is identity matrix */
        anchorX: float, /* Transform anchor point X, absent if no transform specified */
        anchorY: float, /* Transform anchor point Y, absent if no transform specified */
        anchorZ: float, /* Transform anchor point Z, absent if no transform specified */
        paintCount: int, /* Indicates how many time this layer has painted. */
        drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
        invisible: bool, /* Set if layer is not visible. */
        scrollRects: array(ScrollRect.t), /* Rectangles scrolling on main thread only. */
        stickyPositionConstraint: StickyPositionConstraint.t /* Sticky position constraint information */,
      };
    } = Layer
    and PaintProfile: {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(float);
    } = PaintProfile;
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
        url: string, /* URL of the resource if known. */
        lineNumber: int, /* Line number in the resource. */
        stackTrace: Runtime.Types.StackTrace.t, /* JavaScript stack trace. */
        networkRequestId: Network.Types.RequestId.t, /* Identifier of the network request associated with this entry. */
        workerId: string, /* Identifier of the worker associated with this entry. */
        args: array(Runtime.Types.RemoteObject.t) /* Call arguments. */,
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
        url: string, /* URL of the resource if known. */
        lineNumber: int, /* Line number in the resource. */
        stackTrace: Runtime.Types.StackTrace.t, /* JavaScript stack trace. */
        networkRequestId: Network.Types.RequestId.t, /* Identifier of the network request associated with this entry. */
        workerId: string, /* Identifier of the worker associated with this entry. */
        args: array(Runtime.Types.RemoteObject.t) /* Call arguments. */,
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
        url: string, /* URL of the resource if known. */
        lineNumber: int, /* Line number in the resource. */
        stackTrace: Runtime.Types.StackTrace.t, /* JavaScript stack trace. */
        networkRequestId: Network.Types.RequestId.t, /* Identifier of the network request associated with this entry. */
        workerId: string, /* Identifier of the worker associated with this entry. */
        args: array(Runtime.Types.RemoteObject.t) /* Call arguments. */,
      };
    } = LogEntry
    and ViolationSetting: {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {
        name: string, /* Violation type. */
        threshold: float /* Time threshold to trigger upon. */,
      };
    } = ViolationSetting;
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
    } = PressureLevel
    and SamplingProfileNode: {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {
        size: float, /* Size of the sampled allocation. */
        total: float, /* Total bytes attributed to this sample. */
        stack: array(string) /* Execution stack at the point of allocation. */,
      };
    } = SamplingProfileNode
    and SamplingProfile: {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {
        samples: array(SamplingProfileNode.t), /* No description provided */
        modules: array(Module.t) /* No description provided */,
      };
    } = SamplingProfile
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
    } = Module;
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
      type t = {.};
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
      type t = {bytes: string /* No description provided */};
    }
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        urlFragment: string, /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        postData: string, /* HTTP POST request data. */
        hasPostData: bool, /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        postDataEntries: array(PostDataEntry.t), /* Request body elements. This will be converted from base64 to binary */
        mixedContentType: Security.Types.MixedContentType.t, /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        isLinkPreload: bool, /* Whether is loaded via link preload. */
        trustTokenParams: TrustTokenParams.t /* Set for requests when the TrustToken API is used. Contains the parameters
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
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
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
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        issuers: array(string) /* Origins of issuers from whom to request tokens or redemption
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
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        requestHeaders: Headers.t, /* Refined HTTP request headers that were actually transmitted over the network. */
        requestHeadersText: string, /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        remoteIPAddress: string, /* Remote IP address. */
        remotePort: int, /* Remote port. */
        fromDiskCache: bool, /* Specifies that the request was served from the disk cache. */
        fromServiceWorker: bool, /* Specifies that the request was served from the ServiceWorker. */
        fromPrefetchCache: bool, /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        timing: ResourceTiming.t, /* Timing information for the given request. */
        serviceWorkerResponseSource: ServiceWorkerResponseSource.t, /* Response source of response from ServiceWorker. */
        responseTime: TimeSinceEpoch.t, /* The time at which the returned response was generated. */
        cacheStorageCacheName: string, /* Cache Storage Cache Name. */
        protocol: string, /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        securityDetails: SecurityDetails.t /* Security details for the request. */,
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
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        requestHeaders: Headers.t, /* HTTP request headers. */
        requestHeadersText: string /* HTTP request headers text. */,
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
        type_: ResourceType.t, /* Type of this resource. */
        response: Response.t, /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    }
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        type_: string, /* Type of this initiator. */
        stack: Runtime.Types.StackTrace.t, /* Initiator JavaScript stack trace, set for Script only. */
        url: string, /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        lineNumber: float, /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        columnNumber: float, /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        requestId: RequestId.t /* Set if another request triggered this request (e.g. preflight). */,
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
        size: int, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
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
        cookie: Cookie.t /* The cookie object which represents the cookie which was not stored. It is optional because
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
        url: string, /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        secure: bool, /* True if cookie is secure. */
        httpOnly: bool, /* True if cookie is http-only. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        expires: TimeSinceEpoch.t, /* Cookie expiration date, session cookie if not set */
        priority: CookiePriority.t, /* Cookie Priority. */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        source: string, /* Source of the authentication challenge. */
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
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
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
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        interceptionStage: InterceptionStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
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
        certUrl: string, /* Signed exchange signature cert Url. */
        certSha256: string, /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: int, /* Signed exchange signature date. */
        expires: int, /* Signed exchange signature expires. */
        certificates: array(string) /* The encoded certificates. */,
      };
    }
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: int, /* Signed exchange response code. */
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
        signatureIndex: int, /* The index of the signature which caused the error. */
        errorField: SignedExchangeErrorField.t /* The field which caused the error. */,
      };
    }
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        header: SignedExchangeHeader.t, /* Information about the signed exchange header. */
        securityDetails: SecurityDetails.t, /* Security details for the signed exchange header. */
        errors: array(SignedExchangeError.t) /* Errors occurred while handling the signed exchagne. */,
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
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
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
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
      };
    }
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        coop: CrossOriginOpenerPolicyStatus.t, /* No description provided */
        coep: CrossOriginEmbedderPolicyStatus.t /* No description provided */,
      };
    }
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        netError: float, /* Optional values used for error reporting. */
        netErrorName: string, /* No description provided */
        httpStatusCode: float, /* No description provided */
        stream: IO.Types.StreamHandle.t, /* If successful, one of the following two fields holds the result. */
        headers: Network.Types.Headers.t /* Response headers. */,
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
      type t = {.};
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
      type t = {bytes: string /* No description provided */};
    }
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        urlFragment: string, /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        postData: string, /* HTTP POST request data. */
        hasPostData: bool, /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        postDataEntries: array(PostDataEntry.t), /* Request body elements. This will be converted from base64 to binary */
        mixedContentType: Security.Types.MixedContentType.t, /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        isLinkPreload: bool, /* Whether is loaded via link preload. */
        trustTokenParams: TrustTokenParams.t /* Set for requests when the TrustToken API is used. Contains the parameters
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
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
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
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        issuers: array(string) /* Origins of issuers from whom to request tokens or redemption
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
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        requestHeaders: Headers.t, /* Refined HTTP request headers that were actually transmitted over the network. */
        requestHeadersText: string, /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        remoteIPAddress: string, /* Remote IP address. */
        remotePort: int, /* Remote port. */
        fromDiskCache: bool, /* Specifies that the request was served from the disk cache. */
        fromServiceWorker: bool, /* Specifies that the request was served from the ServiceWorker. */
        fromPrefetchCache: bool, /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        timing: ResourceTiming.t, /* Timing information for the given request. */
        serviceWorkerResponseSource: ServiceWorkerResponseSource.t, /* Response source of response from ServiceWorker. */
        responseTime: TimeSinceEpoch.t, /* The time at which the returned response was generated. */
        cacheStorageCacheName: string, /* Cache Storage Cache Name. */
        protocol: string, /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        securityDetails: SecurityDetails.t /* Security details for the request. */,
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
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        requestHeaders: Headers.t, /* HTTP request headers. */
        requestHeadersText: string /* HTTP request headers text. */,
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
        type_: ResourceType.t, /* Type of this resource. */
        response: Response.t, /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    }
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        type_: string, /* Type of this initiator. */
        stack: Runtime.Types.StackTrace.t, /* Initiator JavaScript stack trace, set for Script only. */
        url: string, /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        lineNumber: float, /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        columnNumber: float, /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        requestId: RequestId.t /* Set if another request triggered this request (e.g. preflight). */,
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
        size: int, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
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
        cookie: Cookie.t /* The cookie object which represents the cookie which was not stored. It is optional because
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
        url: string, /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        secure: bool, /* True if cookie is secure. */
        httpOnly: bool, /* True if cookie is http-only. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        expires: TimeSinceEpoch.t, /* Cookie expiration date, session cookie if not set */
        priority: CookiePriority.t, /* Cookie Priority. */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    }
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        source: string, /* Source of the authentication challenge. */
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
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
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
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        interceptionStage: InterceptionStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
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
        certUrl: string, /* Signed exchange signature cert Url. */
        certSha256: string, /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: int, /* Signed exchange signature date. */
        expires: int, /* Signed exchange signature expires. */
        certificates: array(string) /* The encoded certificates. */,
      };
    }
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: int, /* Signed exchange response code. */
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
        signatureIndex: int, /* The index of the signature which caused the error. */
        errorField: SignedExchangeErrorField.t /* The field which caused the error. */,
      };
    }
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        header: SignedExchangeHeader.t, /* Information about the signed exchange header. */
        securityDetails: SecurityDetails.t, /* Security details for the signed exchange header. */
        errors: array(SignedExchangeError.t) /* Errors occurred while handling the signed exchagne. */,
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
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
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
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
      };
    }
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        coop: CrossOriginOpenerPolicyStatus.t, /* No description provided */
        coep: CrossOriginEmbedderPolicyStatus.t /* No description provided */,
      };
    }
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        netError: float, /* Optional values used for error reporting. */
        netErrorName: string, /* No description provided */
        httpStatusCode: float, /* No description provided */
        stream: IO.Types.StreamHandle.t, /* If successful, one of the following two fields holds the result. */
        headers: Network.Types.Headers.t /* Response headers. */,
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
    } = ResourceType
    and LoaderId: {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    } = LoaderId
    and RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    } = RequestId
    and InterceptionId: {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    } = InterceptionId
    and ErrorReason: {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    } = ErrorReason
    and TimeSinceEpoch: {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    } = TimeSinceEpoch
    and MonotonicTime: {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    } = MonotonicTime
    and Headers: {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = {.};
    } = Headers
    and ConnectionType: {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    } = ConnectionType
    and CookieSameSite: {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    } = CookieSameSite
    and CookiePriority: {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    } = CookiePriority
    and CookieSourceScheme: {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    } = CookieSourceScheme
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
    } = ResourceTiming
    and ResourcePriority: {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    } = ResourcePriority
    and PostDataEntry: {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {bytes: string /* No description provided */};
    } = PostDataEntry
    and Request: {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {
        url: string, /* Request URL (without fragment). */
        urlFragment: string, /* Fragment of the requested URL starting with hash, if present. */
        method: string, /* HTTP request method. */
        headers: Headers.t, /* HTTP request headers. */
        postData: string, /* HTTP POST request data. */
        hasPostData: bool, /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
        postDataEntries: array(PostDataEntry.t), /* Request body elements. This will be converted from base64 to binary */
        mixedContentType: Security.Types.MixedContentType.t, /* The mixed content type of the request. */
        initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
        referrerPolicy: string, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
        isLinkPreload: bool, /* Whether is loaded via link preload. */
        trustTokenParams: TrustTokenParams.t /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */,
      };
    } = Request
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
    } = SignedCertificateTimestamp
    and SecurityDetails: {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificateId: Security.Types.CertificateId.t, /* Certificate ID value. */
        subjectName: string, /* Certificate subject name. */
        sanList: array(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        signedCertificateTimestampList: array(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
        certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
      };
    } = SecurityDetails
    and CertificateTransparencyCompliance: {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    } = CertificateTransparencyCompliance
    and BlockedReason: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    } = BlockedReason
    and CorsError: {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    } = CorsError
    and CorsErrorStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        corsError: CorsError.t, /* No description provided */
        failedParameter: string /* No description provided */,
      };
    } = CorsErrorStatus
    and ServiceWorkerResponseSource: {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    } = ServiceWorkerResponseSource
    and TrustTokenParams: {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {
        type_: TrustTokenOperationType.t, /* No description provided */
        refreshPolicy: string, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
        issuers: array(string) /* Origins of issuers from whom to request tokens or redemption
records. */,
      };
    } = TrustTokenParams
    and TrustTokenOperationType: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = TrustTokenOperationType
    and Response: {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {
        url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        requestHeaders: Headers.t, /* Refined HTTP request headers that were actually transmitted over the network. */
        requestHeadersText: string, /* HTTP request headers text. */
        connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
        connectionId: float, /* Physical connection id that was actually used for this request. */
        remoteIPAddress: string, /* Remote IP address. */
        remotePort: int, /* Remote port. */
        fromDiskCache: bool, /* Specifies that the request was served from the disk cache. */
        fromServiceWorker: bool, /* Specifies that the request was served from the ServiceWorker. */
        fromPrefetchCache: bool, /* Specifies that the request was served from the prefetch cache. */
        encodedDataLength: float, /* Total number of bytes received for this request so far. */
        timing: ResourceTiming.t, /* Timing information for the given request. */
        serviceWorkerResponseSource: ServiceWorkerResponseSource.t, /* Response source of response from ServiceWorker. */
        responseTime: TimeSinceEpoch.t, /* The time at which the returned response was generated. */
        cacheStorageCacheName: string, /* Cache Storage Cache Name. */
        protocol: string, /* Protocol used to fetch this request. */
        securityState: Security.Types.SecurityState.t, /* Security state of the request resource. */
        securityDetails: SecurityDetails.t /* Security details for the request. */,
      };
    } = Response
    and WebSocketRequest: {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {headers: Headers.t /* HTTP request headers. */};
    } = WebSocketRequest
    and WebSocketResponse: {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {
        status: int, /* HTTP response status code. */
        statusText: string, /* HTTP response status text. */
        headers: Headers.t, /* HTTP response headers. */
        headersText: string, /* HTTP response headers text. */
        requestHeaders: Headers.t, /* HTTP request headers. */
        requestHeadersText: string /* HTTP request headers text. */,
      };
    } = WebSocketResponse
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
    } = WebSocketFrame
    and CachedResource: {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. This is the url of the original network request. */
        type_: ResourceType.t, /* Type of this resource. */
        response: Response.t, /* Cached response data. */
        bodySize: float /* Cached response body size. */,
      };
    } = CachedResource
    and Initiator: {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {
        type_: string, /* Type of this initiator. */
        stack: Runtime.Types.StackTrace.t, /* Initiator JavaScript stack trace, set for Script only. */
        url: string, /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
        lineNumber: float, /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        columnNumber: float, /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
        requestId: RequestId.t /* Set if another request triggered this request (e.g. preflight). */,
      };
    } = Initiator
    and Cookie: {
      /* Cookie object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
        size: int, /* Cookie size. */
        httpOnly: bool, /* True if cookie is http-only. */
        secure: bool, /* True if cookie is secure. */
        session: bool, /* True in case of session cookie. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        priority: CookiePriority.t, /* Cookie Priority */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    } = Cookie
    and SetCookieBlockedReason: {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    } = SetCookieBlockedReason
    and CookieBlockedReason: {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    } = CookieBlockedReason
    and BlockedSetCookieWithReason: {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
        cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
        cookie: Cookie.t /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
      };
    } = BlockedSetCookieWithReason
    and BlockedCookieWithReason: {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {
        blockedReasons: array(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
        cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
      };
    } = BlockedCookieWithReason
    and CookieParam: {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {
        name: string, /* Cookie name. */
        value: string, /* Cookie value. */
        url: string, /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
        domain: string, /* Cookie domain. */
        path: string, /* Cookie path. */
        secure: bool, /* True if cookie is secure. */
        httpOnly: bool, /* True if cookie is http-only. */
        sameSite: CookieSameSite.t, /* Cookie SameSite type. */
        expires: TimeSinceEpoch.t, /* Cookie expiration date, session cookie if not set */
        priority: CookiePriority.t, /* Cookie Priority. */
        sameParty: bool, /* True if cookie is SameParty. */
        sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
        sourcePort: int /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */,
      };
    } = CookieParam
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        source: string, /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    } = AuthChallenge
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    } = AuthChallengeResponse
    and InterceptionStage: {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    } = InterceptionStage
    and RequestPattern: {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        interceptionStage: InterceptionStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    } = RequestPattern
    and SignedExchangeSignature: {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {
        label: string, /* Signed exchange signature label. */
        signature: string, /* The hex string of signed exchange signature. */
        integrity: string, /* Signed exchange signature integrity. */
        certUrl: string, /* Signed exchange signature cert Url. */
        certSha256: string, /* The hex string of signed exchange signature cert sha256. */
        validityUrl: string, /* Signed exchange signature validity Url. */
        date: int, /* Signed exchange signature date. */
        expires: int, /* Signed exchange signature expires. */
        certificates: array(string) /* The encoded certificates. */,
      };
    } = SignedExchangeSignature
    and SignedExchangeHeader: {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {
        requestUrl: string, /* Signed exchange request URL. */
        responseCode: int, /* Signed exchange response code. */
        responseHeaders: Headers.t, /* Signed exchange response headers. */
        signatures: array(SignedExchangeSignature.t), /* Signed exchange response signature. */
        headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
      };
    } = SignedExchangeHeader
    and SignedExchangeErrorField: {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    } = SignedExchangeErrorField
    and SignedExchangeError: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        signatureIndex: int, /* The index of the signature which caused the error. */
        errorField: SignedExchangeErrorField.t /* The field which caused the error. */,
      };
    } = SignedExchangeError
    and SignedExchangeInfo: {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {
        outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
        header: SignedExchangeHeader.t, /* Information about the signed exchange header. */
        securityDetails: SecurityDetails.t, /* Security details for the signed exchange header. */
        errors: array(SignedExchangeError.t) /* Errors occurred while handling the signed exchagne. */,
      };
    } = SignedExchangeInfo
    and ContentEncoding: {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    } = ContentEncoding
    and PrivateNetworkRequestPolicy: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = PrivateNetworkRequestPolicy
    and IPAddressSpace: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = IPAddressSpace
    and ClientSecurityState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        initiatorIsSecureContext: bool, /* No description provided */
        initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
        privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
      };
    } = ClientSecurityState
    and CrossOriginOpenerPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = CrossOriginOpenerPolicyValue
    and CrossOriginOpenerPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
      };
    } = CrossOriginOpenerPolicyStatus
    and CrossOriginEmbedderPolicyValue: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = CrossOriginEmbedderPolicyValue
    and CrossOriginEmbedderPolicyStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
        reportingEndpoint: string, /* No description provided */
        reportOnlyReportingEndpoint: string /* No description provided */,
      };
    } = CrossOriginEmbedderPolicyStatus
    and SecurityIsolationStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        coop: CrossOriginOpenerPolicyStatus.t, /* No description provided */
        coep: CrossOriginEmbedderPolicyStatus.t /* No description provided */,
      };
    } = SecurityIsolationStatus
    and LoadNetworkResourcePageResult: {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {
        success: bool, /* No description provided */
        netError: float, /* Optional values used for error reporting. */
        netErrorName: string, /* No description provided */
        httpStatusCode: float, /* No description provided */
        stream: IO.Types.StreamHandle.t, /* If successful, one of the following two fields holds the result. */
        headers: Network.Types.Headers.t /* Response headers. */,
      };
    } = LoadNetworkResourcePageResult
    and LoadNetworkResourceOptions: {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {
        disableCache: bool, /* No description provided */
        includeCredentials: bool /* No description provided */,
      };
    } = LoadNetworkResourceOptions;
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
        showGridExtensionLines: bool, /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        showPositiveLineNumbers: bool, /* Show Positive line number labels (default: false). */
        showNegativeLineNumbers: bool, /* Show Negative line number labels (default: false). */
        showAreaNames: bool, /* Show area name labels (default: false). */
        showLineNames: bool, /* Show line name labels (default: false). */
        showTrackSizes: bool, /* Show track size labels (default: false). */
        gridBorderColor: DOM.Types.RGBA.t, /* The grid container border highlight color (default: transparent). */
        cellBorderColor: DOM.Types.RGBA.t, /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        rowLineColor: DOM.Types.RGBA.t, /* The row line color (default: transparent). */
        columnLineColor: DOM.Types.RGBA.t, /* The column line color (default: transparent). */
        gridBorderDash: bool, /* Whether the grid border is dashed (default: false). */
        cellBorderDash: bool, /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        rowLineDash: bool, /* Whether row lines are dashed (default: false). */
        columnLineDash: bool, /* Whether column lines are dashed (default: false). */
        rowGapColor: DOM.Types.RGBA.t, /* The row gap highlight fill color (default: transparent). */
        rowHatchColor: DOM.Types.RGBA.t, /* The row gap hatching fill color (default: transparent). */
        columnGapColor: DOM.Types.RGBA.t, /* The column gap highlight fill color (default: transparent). */
        columnHatchColor: DOM.Types.RGBA.t, /* The column gap hatching fill color (default: transparent). */
        areaBorderColor: DOM.Types.RGBA.t, /* The named grid areas border color (Default: transparent). */
        gridBackgroundColor: DOM.Types.RGBA.t /* The grid container background color (Default: transparent). */,
      };
    }
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        containerBorder: LineStyle.t, /* The style of the container border */
        lineSeparator: LineStyle.t, /* The style of the separator between lines */
        itemSeparator: LineStyle.t, /* The style of the separator between items */
        mainDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the main axis (justify-content). */
        crossDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the cross axis (align-content). */
        rowGapSpace: BoxStyle.t, /* Style of empty space caused by row gaps (gap/row-gap). */
        columnGapSpace: BoxStyle.t, /* Style of empty space caused by columns gaps (gap/column-gap). */
        crossAlignment: LineStyle.t /* Style of the self-alignment line (align-items). */,
      };
    }
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        baseSizeBox: BoxStyle.t, /* Style of the box representing the item's base size */
        baseSizeBorder: LineStyle.t, /* Style of the border around the box representing the item's base size */
        flexibilityArrow: LineStyle.t /* Style of the arrow representing if the item grew or shrank */,
      };
    }
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        color: DOM.Types.RGBA.t, /* The color of the line (default: transparent) */
        pattern: string /* The line pattern (default: solid) */,
      };
    }
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        fillColor: DOM.Types.RGBA.t, /* The background color for the box (default: transparent) */
        hatchColor: DOM.Types.RGBA.t /* The hatching color for the box (default: transparent) */,
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
        showInfo: bool, /* Whether the node info tooltip should be shown (default: false). */
        showStyles: bool, /* Whether the node styles in the tooltip (default: false). */
        showRulers: bool, /* Whether the rulers should be shown (default: false). */
        showAccessibilityInfo: bool, /* Whether the a11y info should be shown (default: true). */
        showExtensionLines: bool, /* Whether the extension lines from node to the rulers should be shown (default: false). */
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: transparent). */
        paddingColor: DOM.Types.RGBA.t, /* The padding highlight fill color (default: transparent). */
        borderColor: DOM.Types.RGBA.t, /* The border highlight fill color (default: transparent). */
        marginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        eventTargetColor: DOM.Types.RGBA.t, /* The event target element highlight fill color (default: transparent). */
        shapeColor: DOM.Types.RGBA.t, /* The shape outside fill color (default: transparent). */
        shapeMarginColor: DOM.Types.RGBA.t, /* The shape margin fill color (default: transparent). */
        cssGridColor: DOM.Types.RGBA.t, /* The grid layout color (default: transparent). */
        colorFormat: ColorFormat.t, /* The color format used to format color styles (default: hex). */
        gridHighlightConfig: GridHighlightConfig.t, /* The grid layout highlight configuration (default: all transparent). */
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* The flex container highlight configuration (default: all transparent). */
        flexItemHighlightConfig: FlexItemHighlightConfig.t, /* The flex item highlight configuration (default: all transparent). */
        contrastAlgorithm: ContrastAlgorithm.t /* The contrast algorithm to use for the contrast ratio (default: aa). */,
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
        snapportBorder: LineStyle.t, /* The style of the snapport border (default: transparent) */
        snapAreaBorder: LineStyle.t, /* The style of the snap area border (default: transparent) */
        scrollMarginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        scrollPaddingColor: DOM.Types.RGBA.t /* The padding highlight fill color (default: transparent). */,
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
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: a dark color). */
        outlineColor: DOM.Types.RGBA.t /* The content box highlight outline color (default: transparent). */,
      };
    }
    and InspectMode: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
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
        showGridExtensionLines: bool, /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        showPositiveLineNumbers: bool, /* Show Positive line number labels (default: false). */
        showNegativeLineNumbers: bool, /* Show Negative line number labels (default: false). */
        showAreaNames: bool, /* Show area name labels (default: false). */
        showLineNames: bool, /* Show line name labels (default: false). */
        showTrackSizes: bool, /* Show track size labels (default: false). */
        gridBorderColor: DOM.Types.RGBA.t, /* The grid container border highlight color (default: transparent). */
        cellBorderColor: DOM.Types.RGBA.t, /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        rowLineColor: DOM.Types.RGBA.t, /* The row line color (default: transparent). */
        columnLineColor: DOM.Types.RGBA.t, /* The column line color (default: transparent). */
        gridBorderDash: bool, /* Whether the grid border is dashed (default: false). */
        cellBorderDash: bool, /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        rowLineDash: bool, /* Whether row lines are dashed (default: false). */
        columnLineDash: bool, /* Whether column lines are dashed (default: false). */
        rowGapColor: DOM.Types.RGBA.t, /* The row gap highlight fill color (default: transparent). */
        rowHatchColor: DOM.Types.RGBA.t, /* The row gap hatching fill color (default: transparent). */
        columnGapColor: DOM.Types.RGBA.t, /* The column gap highlight fill color (default: transparent). */
        columnHatchColor: DOM.Types.RGBA.t, /* The column gap hatching fill color (default: transparent). */
        areaBorderColor: DOM.Types.RGBA.t, /* The named grid areas border color (Default: transparent). */
        gridBackgroundColor: DOM.Types.RGBA.t /* The grid container background color (Default: transparent). */,
      };
    }
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        containerBorder: LineStyle.t, /* The style of the container border */
        lineSeparator: LineStyle.t, /* The style of the separator between lines */
        itemSeparator: LineStyle.t, /* The style of the separator between items */
        mainDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the main axis (justify-content). */
        crossDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the cross axis (align-content). */
        rowGapSpace: BoxStyle.t, /* Style of empty space caused by row gaps (gap/row-gap). */
        columnGapSpace: BoxStyle.t, /* Style of empty space caused by columns gaps (gap/column-gap). */
        crossAlignment: LineStyle.t /* Style of the self-alignment line (align-items). */,
      };
    }
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        baseSizeBox: BoxStyle.t, /* Style of the box representing the item's base size */
        baseSizeBorder: LineStyle.t, /* Style of the border around the box representing the item's base size */
        flexibilityArrow: LineStyle.t /* Style of the arrow representing if the item grew or shrank */,
      };
    }
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        color: DOM.Types.RGBA.t, /* The color of the line (default: transparent) */
        pattern: string /* The line pattern (default: solid) */,
      };
    }
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        fillColor: DOM.Types.RGBA.t, /* The background color for the box (default: transparent) */
        hatchColor: DOM.Types.RGBA.t /* The hatching color for the box (default: transparent) */,
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
        showInfo: bool, /* Whether the node info tooltip should be shown (default: false). */
        showStyles: bool, /* Whether the node styles in the tooltip (default: false). */
        showRulers: bool, /* Whether the rulers should be shown (default: false). */
        showAccessibilityInfo: bool, /* Whether the a11y info should be shown (default: true). */
        showExtensionLines: bool, /* Whether the extension lines from node to the rulers should be shown (default: false). */
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: transparent). */
        paddingColor: DOM.Types.RGBA.t, /* The padding highlight fill color (default: transparent). */
        borderColor: DOM.Types.RGBA.t, /* The border highlight fill color (default: transparent). */
        marginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        eventTargetColor: DOM.Types.RGBA.t, /* The event target element highlight fill color (default: transparent). */
        shapeColor: DOM.Types.RGBA.t, /* The shape outside fill color (default: transparent). */
        shapeMarginColor: DOM.Types.RGBA.t, /* The shape margin fill color (default: transparent). */
        cssGridColor: DOM.Types.RGBA.t, /* The grid layout color (default: transparent). */
        colorFormat: ColorFormat.t, /* The color format used to format color styles (default: hex). */
        gridHighlightConfig: GridHighlightConfig.t, /* The grid layout highlight configuration (default: all transparent). */
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* The flex container highlight configuration (default: all transparent). */
        flexItemHighlightConfig: FlexItemHighlightConfig.t, /* The flex item highlight configuration (default: all transparent). */
        contrastAlgorithm: ContrastAlgorithm.t /* The contrast algorithm to use for the contrast ratio (default: aa). */,
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
        snapportBorder: LineStyle.t, /* The style of the snapport border (default: transparent) */
        snapAreaBorder: LineStyle.t, /* The style of the snap area border (default: transparent) */
        scrollMarginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        scrollPaddingColor: DOM.Types.RGBA.t /* The padding highlight fill color (default: transparent). */,
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
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: a dark color). */
        outlineColor: DOM.Types.RGBA.t /* The content box highlight outline color (default: transparent). */,
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
    } = SourceOrderConfig
    and GridHighlightConfig: {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {
        showGridExtensionLines: bool, /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
        showPositiveLineNumbers: bool, /* Show Positive line number labels (default: false). */
        showNegativeLineNumbers: bool, /* Show Negative line number labels (default: false). */
        showAreaNames: bool, /* Show area name labels (default: false). */
        showLineNames: bool, /* Show line name labels (default: false). */
        showTrackSizes: bool, /* Show track size labels (default: false). */
        gridBorderColor: DOM.Types.RGBA.t, /* The grid container border highlight color (default: transparent). */
        cellBorderColor: DOM.Types.RGBA.t, /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
        rowLineColor: DOM.Types.RGBA.t, /* The row line color (default: transparent). */
        columnLineColor: DOM.Types.RGBA.t, /* The column line color (default: transparent). */
        gridBorderDash: bool, /* Whether the grid border is dashed (default: false). */
        cellBorderDash: bool, /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
        rowLineDash: bool, /* Whether row lines are dashed (default: false). */
        columnLineDash: bool, /* Whether column lines are dashed (default: false). */
        rowGapColor: DOM.Types.RGBA.t, /* The row gap highlight fill color (default: transparent). */
        rowHatchColor: DOM.Types.RGBA.t, /* The row gap hatching fill color (default: transparent). */
        columnGapColor: DOM.Types.RGBA.t, /* The column gap highlight fill color (default: transparent). */
        columnHatchColor: DOM.Types.RGBA.t, /* The column gap hatching fill color (default: transparent). */
        areaBorderColor: DOM.Types.RGBA.t, /* The named grid areas border color (Default: transparent). */
        gridBackgroundColor: DOM.Types.RGBA.t /* The grid container background color (Default: transparent). */,
      };
    } = GridHighlightConfig
    and FlexContainerHighlightConfig: {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {
        containerBorder: LineStyle.t, /* The style of the container border */
        lineSeparator: LineStyle.t, /* The style of the separator between lines */
        itemSeparator: LineStyle.t, /* The style of the separator between items */
        mainDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the main axis (justify-content). */
        crossDistributedSpace: BoxStyle.t, /* Style of content-distribution space on the cross axis (align-content). */
        rowGapSpace: BoxStyle.t, /* Style of empty space caused by row gaps (gap/row-gap). */
        columnGapSpace: BoxStyle.t, /* Style of empty space caused by columns gaps (gap/column-gap). */
        crossAlignment: LineStyle.t /* Style of the self-alignment line (align-items). */,
      };
    } = FlexContainerHighlightConfig
    and FlexItemHighlightConfig: {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {
        baseSizeBox: BoxStyle.t, /* Style of the box representing the item's base size */
        baseSizeBorder: LineStyle.t, /* Style of the border around the box representing the item's base size */
        flexibilityArrow: LineStyle.t /* Style of the arrow representing if the item grew or shrank */,
      };
    } = FlexItemHighlightConfig
    and LineStyle: {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {
        color: DOM.Types.RGBA.t, /* The color of the line (default: transparent) */
        pattern: string /* The line pattern (default: solid) */,
      };
    } = LineStyle
    and BoxStyle: {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {
        fillColor: DOM.Types.RGBA.t, /* The background color for the box (default: transparent) */
        hatchColor: DOM.Types.RGBA.t /* The hatching color for the box (default: transparent) */,
      };
    } = BoxStyle
    and ContrastAlgorithm: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ContrastAlgorithm
    and HighlightConfig: {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {
        showInfo: bool, /* Whether the node info tooltip should be shown (default: false). */
        showStyles: bool, /* Whether the node styles in the tooltip (default: false). */
        showRulers: bool, /* Whether the rulers should be shown (default: false). */
        showAccessibilityInfo: bool, /* Whether the a11y info should be shown (default: true). */
        showExtensionLines: bool, /* Whether the extension lines from node to the rulers should be shown (default: false). */
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: transparent). */
        paddingColor: DOM.Types.RGBA.t, /* The padding highlight fill color (default: transparent). */
        borderColor: DOM.Types.RGBA.t, /* The border highlight fill color (default: transparent). */
        marginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        eventTargetColor: DOM.Types.RGBA.t, /* The event target element highlight fill color (default: transparent). */
        shapeColor: DOM.Types.RGBA.t, /* The shape outside fill color (default: transparent). */
        shapeMarginColor: DOM.Types.RGBA.t, /* The shape margin fill color (default: transparent). */
        cssGridColor: DOM.Types.RGBA.t, /* The grid layout color (default: transparent). */
        colorFormat: ColorFormat.t, /* The color format used to format color styles (default: hex). */
        gridHighlightConfig: GridHighlightConfig.t, /* The grid layout highlight configuration (default: all transparent). */
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* The flex container highlight configuration (default: all transparent). */
        flexItemHighlightConfig: FlexItemHighlightConfig.t, /* The flex item highlight configuration (default: all transparent). */
        contrastAlgorithm: ContrastAlgorithm.t /* The contrast algorithm to use for the contrast ratio (default: aa). */,
      };
    } = HighlightConfig
    and ColorFormat: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ColorFormat
    and GridNodeHighlightConfig: {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {
        gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = GridNodeHighlightConfig
    and FlexNodeHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = FlexNodeHighlightConfig
    and ScrollSnapContainerHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        snapportBorder: LineStyle.t, /* The style of the snapport border (default: transparent) */
        snapAreaBorder: LineStyle.t, /* The style of the snap area border (default: transparent) */
        scrollMarginColor: DOM.Types.RGBA.t, /* The margin highlight fill color (default: transparent). */
        scrollPaddingColor: DOM.Types.RGBA.t /* The padding highlight fill color (default: transparent). */,
      };
    } = ScrollSnapContainerHighlightConfig
    and ScrollSnapHighlightConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
        nodeId: DOM.Types.NodeId.t /* Identifier of the node to highlight. */,
      };
    } = ScrollSnapHighlightConfig
    and HingeConfig: {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {
        rect: DOM.Types.Rect.t, /* A rectangle represent hinge */
        contentColor: DOM.Types.RGBA.t, /* The content box highlight fill color (default: a dark color). */
        outlineColor: DOM.Types.RGBA.t /* The content box highlight outline color (default: transparent). */,
      };
    } = HingeConfig
    and InspectMode: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = InspectMode;
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
        locator: PermissionsPolicyBlockLocator.t /* No description provided */,
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
        parsedToken: OriginTrialToken.t, /* `parsedToken` is present only when the token is extractable and
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
        parentId: string, /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        name: string, /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        urlFragment: string, /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        unreachableUrl: string, /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        adFrameType: AdFrameType.t, /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        originTrials: array(OriginTrial.t) /* Frame document's origin trials with at least one token present. */,
      };
    }
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        lastModified: Network.Types.TimeSinceEpoch.t, /* last-modified timestamp as reported by server. */
        contentSize: float, /* Resource content size. */
        failed: bool, /* True if the resource failed to load. */
        canceled: bool /* True if the resource was canceled during loading. */,
      };
    }
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameResourceTree.t), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    }
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameTree.t) /* Child frames. */,
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
        id: int, /* Unique id of the navigation history entry. */
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
        timestamp: Network.Types.TimeSinceEpoch.t /* Frame swap timestamp. */,
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
        critical: int, /* If criticial, this is a non-recoverable parse error. */
        line: int, /* Error line. */
        column: int /* Error column. */,
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
        pageX: int, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: int, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: int, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: int /* Height (CSS pixels), excludes scrollbar if present. */,
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
        zoom: float /* Page zoom factor (CSS to device independent pixels ratio). */,
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
        standard: string, /* The standard font-family. */
        fixed: string, /* The fixed font-family. */
        serif: string, /* The serif font-family. */
        sansSerif: string, /* The sansSerif font-family. */
        cursive: string, /* The cursive font-family. */
        fantasy: string, /* The fantasy font-family. */
        pictograph: string /* The pictograph font-family. */,
      };
    }
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        standard: int, /* Default standard font size. */
        fixed: int /* Default fixed font size. */,
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
        eager: bool /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    }
    and NavigationType: {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
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
        locator: PermissionsPolicyBlockLocator.t /* No description provided */,
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
        parsedToken: OriginTrialToken.t, /* `parsedToken` is present only when the token is extractable and
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
        parentId: string, /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        name: string, /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        urlFragment: string, /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        unreachableUrl: string, /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        adFrameType: AdFrameType.t, /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        originTrials: array(OriginTrial.t) /* Frame document's origin trials with at least one token present. */,
      };
    }
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        lastModified: Network.Types.TimeSinceEpoch.t, /* last-modified timestamp as reported by server. */
        contentSize: float, /* Resource content size. */
        failed: bool, /* True if the resource failed to load. */
        canceled: bool /* True if the resource was canceled during loading. */,
      };
    }
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameResourceTree.t), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    }
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameTree.t) /* Child frames. */,
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
        id: int, /* Unique id of the navigation history entry. */
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
        timestamp: Network.Types.TimeSinceEpoch.t /* Frame swap timestamp. */,
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
        critical: int, /* If criticial, this is a non-recoverable parse error. */
        line: int, /* Error line. */
        column: int /* Error column. */,
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
        pageX: int, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: int, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: int, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: int /* Height (CSS pixels), excludes scrollbar if present. */,
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
        zoom: float /* Page zoom factor (CSS to device independent pixels ratio). */,
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
        standard: string, /* The standard font-family. */
        fixed: string, /* The fixed font-family. */
        serif: string, /* The serif font-family. */
        sansSerif: string, /* The sansSerif font-family. */
        cursive: string, /* The cursive font-family. */
        fantasy: string, /* The fantasy font-family. */
        pictograph: string /* The pictograph font-family. */,
      };
    }
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        standard: int, /* Default standard font size. */
        fixed: int /* Default fixed font size. */,
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
        eager: bool /* A hint to the backend whether eager compilation is recommended.
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
    } = FrameId
    and AdFrameType: {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    } = AdFrameType
    and SecureContextType: {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    } = SecureContextType
    and CrossOriginIsolatedContextType: {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    } = CrossOriginIsolatedContextType
    and GatedAPIFeatures: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = GatedAPIFeatures
    and PermissionsPolicyFeature: {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    } = PermissionsPolicyFeature
    and PermissionsPolicyBlockReason: {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    } = PermissionsPolicyBlockReason
    and PermissionsPolicyBlockLocator: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: FrameId.t, /* No description provided */
        blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
      };
    } = PermissionsPolicyBlockLocator
    and PermissionsPolicyFeatureState: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        feature: PermissionsPolicyFeature.t, /* No description provided */
        allowed: bool, /* No description provided */
        locator: PermissionsPolicyBlockLocator.t /* No description provided */,
      };
    } = PermissionsPolicyFeatureState
    and OriginTrialTokenStatus: {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    } = OriginTrialTokenStatus
    and OriginTrialStatus: {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    } = OriginTrialStatus
    and OriginTrialUsageRestriction: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = OriginTrialUsageRestriction
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
    } = OriginTrialToken
    and OriginTrialTokenWithStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        rawTokenText: string, /* No description provided */
        parsedToken: OriginTrialToken.t, /* `parsedToken` is present only when the token is extractable and
parsable. */
        status: OriginTrialTokenStatus.t /* No description provided */,
      };
    } = OriginTrialTokenWithStatus
    and OriginTrial: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        trialName: string, /* No description provided */
        status: OriginTrialStatus.t, /* No description provided */
        tokensWithStatus: array(OriginTrialTokenWithStatus.t) /* No description provided */,
      };
    } = OriginTrial
    and Frame: {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {
        id: FrameId.t, /* Frame unique identifier. */
        parentId: string, /* Parent frame identifier. */
        loaderId: Network.Types.LoaderId.t, /* Identifier of the loader associated with this frame. */
        name: string, /* Frame's name as specified in the tag. */
        url: string, /* Frame document's URL without fragment. */
        urlFragment: string, /* Frame document's URL fragment including the '#'. */
        domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
        securityOrigin: string, /* Frame document's security origin. */
        mimeType: string, /* Frame document's mimeType as determined by the browser. */
        unreachableUrl: string, /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
        adFrameType: AdFrameType.t, /* Indicates whether this frame was tagged as an ad. */
        secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
        crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
        gatedAPIFeatures: array(GatedAPIFeatures.t), /* Indicated which gated APIs / features are available. */
        originTrials: array(OriginTrial.t) /* Frame document's origin trials with at least one token present. */,
      };
    } = Frame
    and FrameResource: {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {
        url: string, /* Resource URL. */
        type_: Network.Types.ResourceType.t, /* Type of this resource. */
        mimeType: string, /* Resource mimeType as determined by the browser. */
        lastModified: Network.Types.TimeSinceEpoch.t, /* last-modified timestamp as reported by server. */
        contentSize: float, /* Resource content size. */
        failed: bool, /* True if the resource failed to load. */
        canceled: bool /* True if the resource was canceled during loading. */,
      };
    } = FrameResource
    and FrameResourceTree: {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameResourceTree.t), /* Child frames. */
        resources: array(FrameResource.t) /* Information about frame resources. */,
      };
    } = FrameResourceTree
    and FrameTree: {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {
        frame: Frame.t, /* Frame information for this tree item. */
        childFrames: array(FrameTree.t) /* Child frames. */,
      };
    } = FrameTree
    and ScriptIdentifier: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    } = ScriptIdentifier
    and TransitionType: {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    } = TransitionType
    and NavigationEntry: {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {
        id: int, /* Unique id of the navigation history entry. */
        url: string, /* URL of the navigation history entry. */
        userTypedURL: string, /* URL that the user typed in the url bar. */
        title: string, /* Title of the navigation history entry. */
        transitionType: TransitionType.t /* Transition type. */,
      };
    } = NavigationEntry
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
        timestamp: Network.Types.TimeSinceEpoch.t /* Frame swap timestamp. */,
      };
    } = ScreencastFrameMetadata
    and DialogType: {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    } = DialogType
    and AppManifestError: {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {
        message: string, /* Error message. */
        critical: int, /* If criticial, this is a non-recoverable parse error. */
        line: int, /* Error line. */
        column: int /* Error column. */,
      };
    } = AppManifestError
    and AppManifestParsedProperties: {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {scope: string /* Computed scope value */};
    } = AppManifestParsedProperties
    and LayoutViewport: {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {
        pageX: int, /* Horizontal offset relative to the document (CSS pixels). */
        pageY: int, /* Vertical offset relative to the document (CSS pixels). */
        clientWidth: int, /* Width (CSS pixels), excludes scrollbar if present. */
        clientHeight: int /* Height (CSS pixels), excludes scrollbar if present. */,
      };
    } = LayoutViewport
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
        zoom: float /* Page zoom factor (CSS to device independent pixels ratio). */,
      };
    } = VisualViewport
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
    } = Viewport
    and FontFamilies: {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {
        standard: string, /* The standard font-family. */
        fixed: string, /* The fixed font-family. */
        serif: string, /* The serif font-family. */
        sansSerif: string, /* The sansSerif font-family. */
        cursive: string, /* The cursive font-family. */
        fantasy: string, /* The fantasy font-family. */
        pictograph: string /* The pictograph font-family. */,
      };
    } = FontFamilies
    and FontSizes: {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {
        standard: int, /* Default standard font size. */
        fixed: int /* Default fixed font size. */,
      };
    } = FontSizes
    and ClientNavigationReason: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ClientNavigationReason
    and ClientNavigationDisposition: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ClientNavigationDisposition
    and InstallabilityErrorArgument: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
        value: string /* Argument value (e.g. value:'64'). */,
      };
    } = InstallabilityErrorArgument
    and InstallabilityError: {
      /* The installability error */
      [@deriving yojson]
      type t = {
        errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
        errorArguments: array(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
      };
    } = InstallabilityError
    and ReferrerPolicy: {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    } = ReferrerPolicy
    and CompilationCacheParams: {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {
        url: string, /* The URL of the script to produce a compilation cache entry for. */
        eager: bool /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
      };
    } = CompilationCacheParams
    and NavigationType: {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    } = NavigationType;
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
    } = Metric;
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
        elementId: string, /* The id attribute of the element, if available. */
        url: string, /* The URL of the image (may be trimmed). */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
      };
    }
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
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
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        duration: float, /* Event duration, if applicable. */
        lcpDetails: LargestContentfulPaint.t, /* No description provided */
        layoutShiftDetails: LayoutShift.t /* No description provided */,
      };
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
        elementId: string, /* The id attribute of the element, if available. */
        url: string, /* The URL of the image (may be trimmed). */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
      };
    }
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
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
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        duration: float, /* Event duration, if applicable. */
        lcpDetails: LargestContentfulPaint.t, /* No description provided */
        layoutShiftDetails: LayoutShift.t /* No description provided */,
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
        elementId: string, /* The id attribute of the element, if available. */
        url: string, /* The URL of the image (may be trimmed). */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
      };
    } = LargestContentfulPaint
    and LayoutShiftAttribution: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        previousRect: DOM.Types.Rect.t, /* No description provided */
        currentRect: DOM.Types.Rect.t, /* No description provided */
        nodeId: DOM.Types.BackendNodeId.t /* No description provided */,
      };
    } = LayoutShiftAttribution
    and LayoutShift: {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {
        value: float, /* Score increment produced by this event. */
        hadRecentInput: bool, /* No description provided */
        lastInputTime: Network.Types.TimeSinceEpoch.t, /* No description provided */
        sources: array(LayoutShiftAttribution.t) /* No description provided */,
      };
    } = LayoutShift
    and TimelineEvent: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        frameId: Page.Types.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
        type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
        name: string, /* Name may be empty depending on the type. */
        time: Network.Types.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
        duration: float, /* Event duration, if applicable. */
        lcpDetails: LargestContentfulPaint.t, /* No description provided */
        layoutShiftDetails: LayoutShift.t /* No description provided */,
      };
    } = TimelineEvent;
  };
}
and Profiler: {
  module Types: {
    module rec ProfileNode: {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: int, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        hitCount: int, /* Number of samples where this node was on top of the call stack. */
        children: array(int), /* Child node ids. */
        deoptReason: string, /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        positionTicks: array(PositionTickInfo.t) /* An array of source position ticks. */,
      };
    }
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        samples: array(int), /* Ids of samples top nodes. */
        timeDeltas: array(int) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    }
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: int, /* Source line number (1-based). */
        ticks: int /* Number of samples attributed to the source line. */,
      };
    }
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: int, /* JavaScript script source offset for the range start. */
        endOffset: int, /* JavaScript script source offset for the range end. */
        count: int /* Collected execution count of the source range. */,
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
        offset: int, /* Source offset of the parameter or end of function for return values. */
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
        value: int /* Counter value. */,
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
} = {
  module Types: {
    module rec ProfileNode: {
      /* Profile node. Holds callsite information, execution statistics and child nodes. */
      [@deriving yojson]
      type t = {
        id: int, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        hitCount: int, /* Number of samples where this node was on top of the call stack. */
        children: array(int), /* Child node ids. */
        deoptReason: string, /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        positionTicks: array(PositionTickInfo.t) /* An array of source position ticks. */,
      };
    }
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        samples: array(int), /* Ids of samples top nodes. */
        timeDeltas: array(int) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    }
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: int, /* Source line number (1-based). */
        ticks: int /* Number of samples attributed to the source line. */,
      };
    }
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: int, /* JavaScript script source offset for the range start. */
        endOffset: int, /* JavaScript script source offset for the range end. */
        count: int /* Collected execution count of the source range. */,
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
        offset: int, /* Source offset of the parameter or end of function for return values. */
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
        value: int /* Counter value. */,
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
        id: int, /* Unique id of the node. */
        callFrame: Runtime.Types.CallFrame.t, /* Function location. */
        hitCount: int, /* Number of samples where this node was on top of the call stack. */
        children: array(int), /* Child node ids. */
        deoptReason: string, /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
        positionTicks: array(PositionTickInfo.t) /* An array of source position ticks. */,
      };
    } = ProfileNode
    and Profile: {
      /* Profile. */
      [@deriving yojson]
      type t = {
        nodes: array(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
        startTime: float, /* Profiling start timestamp in microseconds. */
        endTime: float, /* Profiling end timestamp in microseconds. */
        samples: array(int), /* Ids of samples top nodes. */
        timeDeltas: array(int) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
      };
    } = Profile
    and PositionTickInfo: {
      /* Specifies a number of samples attributed to a certain source position. */
      [@deriving yojson]
      type t = {
        line: int, /* Source line number (1-based). */
        ticks: int /* Number of samples attributed to the source line. */,
      };
    } = PositionTickInfo
    and CoverageRange: {
      /* Coverage data for a source range. */
      [@deriving yojson]
      type t = {
        startOffset: int, /* JavaScript script source offset for the range start. */
        endOffset: int, /* JavaScript script source offset for the range end. */
        count: int /* Collected execution count of the source range. */,
      };
    } = CoverageRange
    and FunctionCoverage: {
      /* Coverage data for a JavaScript function. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        ranges: array(CoverageRange.t), /* Source ranges inside the function with coverage data. */
        isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
      };
    } = FunctionCoverage
    and ScriptCoverage: {
      /* Coverage data for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        functions: array(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
      };
    } = ScriptCoverage
    and TypeObject: {
      /* Describes a type collected during runtime. */
      [@deriving yojson]
      type t = {
        name: string /* Name of a type collected with type profiling. */,
      };
    } = TypeObject
    and TypeProfileEntry: {
      /* Source offset and types for a parameter or return value. */
      [@deriving yojson]
      type t = {
        offset: int, /* Source offset of the parameter or end of function for return values. */
        types: array(TypeObject.t) /* The types for this parameter or return value. */,
      };
    } = TypeProfileEntry
    and ScriptTypeProfile: {
      /* Type profile data collected during runtime for a JavaScript script. */
      [@deriving yojson]
      type t = {
        scriptId: Runtime.Types.ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        entries: array(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
      };
    } = ScriptTypeProfile
    and CounterInfo: {
      /* Collected counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: int /* Counter value. */,
      };
    } = CounterInfo
    and RuntimeCallCounterInfo: {
      /* Runtime call counter information. */
      [@deriving yojson]
      type t = {
        name: string, /* Counter name. */
        value: float, /* Counter value. */
        time: float /* Counter time in seconds. */,
      };
    } = RuntimeCallCounterInfo;
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
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        className: string, /* Object class (constructor) name. Specified for `object` type values only. */
        value: string, /* Remote object value in case of primitive values or JSON values (if it was requested). */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        description: string, /* String representation of the object. */
        objectId: RemoteObjectId.t, /* Unique object identifier (for non-primitive values). */
        preview: ObjectPreview.t, /* Preview containing abbreviated property values. Specified for `object` type values only. */
        customPreview: CustomPreview.t /* No description provided */,
      };
    }
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        bodyGetterId: RemoteObjectId.t /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    }
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only. */
        description: string, /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        entries: array(EntryPreview.t) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    }
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        value: string, /* User-friendly property value string. */
        valuePreview: ObjectPreview.t, /* Nested value preview. */
        subtype: string /* Object subtype hint. Specified for `object` type values only. */,
      };
    }
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        key: ObjectPreview.t, /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    }
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        value: RemoteObject.t, /* The value associated with the property. */
        writable: bool, /* True if the value associated with the property may be changed (data descriptors only). */
        get: RemoteObject.t, /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        set: RemoteObject.t, /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        wasThrown: bool, /* True if the result was thrown during the evaluation. */
        isOwn: bool, /* True if the property is owned for the object. */
        symbol: RemoteObject.t /* Property symbol object, if the property is of the `symbol` type. */,
      };
    }
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        value: RemoteObject.t /* The value associated with the property. */,
      };
    }
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        value: RemoteObject.t, /* The value associated with the private property. */
        get: RemoteObject.t, /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        set: RemoteObject.t /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    }
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        value: string, /* Primitive value or serializable javascript object. */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified. */
        objectId: RemoteObjectId.t /* Remote object handle. */,
      };
    }
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = int;
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
        auxData: {.} /* Embedder-specific auxiliary data. */,
      };
    }
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: int, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: int, /* Line number of the exception location (0-based). */
        columnNumber: int, /* Column number of the exception location (0-based). */
        scriptId: ScriptId.t, /* Script ID of the exception location. */
        url: string, /* URL of the exception location, to be used when the script was not reported. */
        stackTrace: StackTrace.t, /* JavaScript stack trace if available. */
        exception_: RemoteObject.t, /* Exception object if available. */
        executionContextId: ExecutionContextId.t /* Identifier of the context where exception happened. */,
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
        lineNumber: int, /* JavaScript script line number (0-based). */
        columnNumber: int /* JavaScript script column number (0-based). */,
      };
    }
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        description: string, /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        parent: StackTrace.t, /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        parentId: StackTraceId.t /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
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
        debuggerId: UniqueDebuggerId.t /* No description provided */,
      };
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
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        className: string, /* Object class (constructor) name. Specified for `object` type values only. */
        value: string, /* Remote object value in case of primitive values or JSON values (if it was requested). */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        description: string, /* String representation of the object. */
        objectId: RemoteObjectId.t, /* Unique object identifier (for non-primitive values). */
        preview: ObjectPreview.t, /* Preview containing abbreviated property values. Specified for `object` type values only. */
        customPreview: CustomPreview.t /* No description provided */,
      };
    }
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        bodyGetterId: RemoteObjectId.t /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    }
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only. */
        description: string, /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        entries: array(EntryPreview.t) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    }
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        value: string, /* User-friendly property value string. */
        valuePreview: ObjectPreview.t, /* Nested value preview. */
        subtype: string /* Object subtype hint. Specified for `object` type values only. */,
      };
    }
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        key: ObjectPreview.t, /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    }
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        value: RemoteObject.t, /* The value associated with the property. */
        writable: bool, /* True if the value associated with the property may be changed (data descriptors only). */
        get: RemoteObject.t, /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        set: RemoteObject.t, /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        wasThrown: bool, /* True if the result was thrown during the evaluation. */
        isOwn: bool, /* True if the property is owned for the object. */
        symbol: RemoteObject.t /* Property symbol object, if the property is of the `symbol` type. */,
      };
    }
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        value: RemoteObject.t /* The value associated with the property. */,
      };
    }
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        value: RemoteObject.t, /* The value associated with the private property. */
        get: RemoteObject.t, /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        set: RemoteObject.t /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    }
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        value: string, /* Primitive value or serializable javascript object. */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified. */
        objectId: RemoteObjectId.t /* Remote object handle. */,
      };
    }
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = int;
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
        auxData: {.} /* Embedder-specific auxiliary data. */,
      };
    }
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: int, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: int, /* Line number of the exception location (0-based). */
        columnNumber: int, /* Column number of the exception location (0-based). */
        scriptId: ScriptId.t, /* Script ID of the exception location. */
        url: string, /* URL of the exception location, to be used when the script was not reported. */
        stackTrace: StackTrace.t, /* JavaScript stack trace if available. */
        exception_: RemoteObject.t, /* Exception object if available. */
        executionContextId: ExecutionContextId.t /* Identifier of the context where exception happened. */,
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
        lineNumber: int, /* JavaScript script line number (0-based). */
        columnNumber: int /* JavaScript script column number (0-based). */,
      };
    }
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        description: string, /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        parent: StackTrace.t, /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        parentId: StackTraceId.t /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
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
        debuggerId: UniqueDebuggerId.t /* No description provided */,
      };
    };
  } = {
    module rec ScriptId: {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    } = ScriptId
    and RemoteObjectId: {
      /* Unique object identifier. */
      [@deriving yojson]
      type t = string;
    } = RemoteObjectId
    and UnserializableValue: {
      /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
         `-Infinity`, and bigint literals. */
      [@deriving yojson]
      type t = string;
    } = UnserializableValue
    and RemoteObject: {
      /* Mirror object referencing original JavaScript object. */
      [@deriving yojson]
      type t = {
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
        className: string, /* Object class (constructor) name. Specified for `object` type values only. */
        value: string, /* Remote object value in case of primitive values or JSON values (if it was requested). */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
        description: string, /* String representation of the object. */
        objectId: RemoteObjectId.t, /* Unique object identifier (for non-primitive values). */
        preview: ObjectPreview.t, /* Preview containing abbreviated property values. Specified for `object` type values only. */
        customPreview: CustomPreview.t /* No description provided */,
      };
    } = RemoteObject
    and CustomPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
        bodyGetterId: RemoteObjectId.t /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
      };
    } = CustomPreview
    and ObjectPreview: {
      /* Object containing abbreviated remote object value. */
      [@deriving yojson]
      type t = {
        type_: string, /* Object type. */
        subtype: string, /* Object subtype hint. Specified for `object` type values only. */
        description: string, /* String representation of the object. */
        overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
        properties: array(PropertyPreview.t), /* List of the properties. */
        entries: array(EntryPreview.t) /* List of the entries. Specified for `map` and `set` subtype values only. */,
      };
    } = ObjectPreview
    and PropertyPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        name: string, /* Property name. */
        type_: string, /* Object type. Accessor means that the property itself is an accessor property. */
        value: string, /* User-friendly property value string. */
        valuePreview: ObjectPreview.t, /* Nested value preview. */
        subtype: string /* Object subtype hint. Specified for `object` type values only. */,
      };
    } = PropertyPreview
    and EntryPreview: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        key: ObjectPreview.t, /* Preview of the key. Specified for map-like collection entries. */
        value: ObjectPreview.t /* Preview of the value. */,
      };
    } = EntryPreview
    and PropertyDescriptor: {
      /* Object property descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Property name or symbol description. */
        value: RemoteObject.t, /* The value associated with the property. */
        writable: bool, /* True if the value associated with the property may be changed (data descriptors only). */
        get: RemoteObject.t, /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
        set: RemoteObject.t, /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
        configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
        enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
        wasThrown: bool, /* True if the result was thrown during the evaluation. */
        isOwn: bool, /* True if the property is owned for the object. */
        symbol: RemoteObject.t /* Property symbol object, if the property is of the `symbol` type. */,
      };
    } = PropertyDescriptor
    and InternalPropertyDescriptor: {
      /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
      [@deriving yojson]
      type t = {
        name: string, /* Conventional property name. */
        value: RemoteObject.t /* The value associated with the property. */,
      };
    } = InternalPropertyDescriptor
    and PrivatePropertyDescriptor: {
      /* Object private field descriptor. */
      [@deriving yojson]
      type t = {
        name: string, /* Private property name. */
        value: RemoteObject.t, /* The value associated with the private property. */
        get: RemoteObject.t, /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
        set: RemoteObject.t /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
      };
    } = PrivatePropertyDescriptor
    and CallArgument: {
      /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
         unserializable primitive value or neither of (for undefined) them should be specified. */
      [@deriving yojson]
      type t = {
        value: string, /* Primitive value or serializable javascript object. */
        unserializableValue: UnserializableValue.t, /* Primitive value which can not be JSON-stringified. */
        objectId: RemoteObjectId.t /* Remote object handle. */,
      };
    } = CallArgument
    and ExecutionContextId: {
      /* Id of an execution context. */
      [@deriving yojson]
      type t = int;
    } = ExecutionContextId
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
        auxData: {.} /* Embedder-specific auxiliary data. */,
      };
    } = ExecutionContextDescription
    and ExceptionDetails: {
      /* Detailed information about exception (or error) that was thrown during script compilation or
         execution. */
      [@deriving yojson]
      type t = {
        exceptionId: int, /* Exception id. */
        text: string, /* Exception text, which should be used together with exception object when available. */
        lineNumber: int, /* Line number of the exception location (0-based). */
        columnNumber: int, /* Column number of the exception location (0-based). */
        scriptId: ScriptId.t, /* Script ID of the exception location. */
        url: string, /* URL of the exception location, to be used when the script was not reported. */
        stackTrace: StackTrace.t, /* JavaScript stack trace if available. */
        exception_: RemoteObject.t, /* Exception object if available. */
        executionContextId: ExecutionContextId.t /* Identifier of the context where exception happened. */,
      };
    } = ExceptionDetails
    and Timestamp: {
      /* Number of milliseconds since epoch. */
      [@deriving yojson]
      type t = float;
    } = Timestamp
    and TimeDelta: {
      /* Number of milliseconds. */
      [@deriving yojson]
      type t = float;
    } = TimeDelta
    and CallFrame: {
      /* Stack entry for runtime errors and assertions. */
      [@deriving yojson]
      type t = {
        functionName: string, /* JavaScript function name. */
        scriptId: ScriptId.t, /* JavaScript script id. */
        url: string, /* JavaScript script name or url. */
        lineNumber: int, /* JavaScript script line number (0-based). */
        columnNumber: int /* JavaScript script column number (0-based). */,
      };
    } = CallFrame
    and StackTrace: {
      /* Call frames for assertions or error messages. */
      [@deriving yojson]
      type t = {
        description: string, /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
        callFrames: array(CallFrame.t), /* JavaScript function name. */
        parent: StackTrace.t, /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
        parentId: StackTraceId.t /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
      };
    } = StackTrace
    and UniqueDebuggerId: {
      /* Unique identifier of current debugger. */
      [@deriving yojson]
      type t = string;
    } = UniqueDebuggerId
    and StackTraceId: {
      /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
         allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
      [@deriving yojson]
      type t = {
        id: string, /* No description provided */
        debuggerId: UniqueDebuggerId.t /* No description provided */,
      };
    } = StackTraceId;
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
    } = Domain;
  };
}
and Security: {
  module Types: {
    module rec CertificateId: {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = int;
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
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        certificateNetworkError: string, /* The highest priority network error code, if the certificate has an error. */
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
        safeUrl: string /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    }
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        certificateSecurityState: CertificateSecurityState.t, /* Security state details about the page certificate. */
        safetyTipInfo: SafetyTipInfo.t, /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
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
        recommendations: array(string) /* Recommendations to fix any issues. */,
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
} = {
  module Types: {
    module rec CertificateId: {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = int;
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
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        certificateNetworkError: string, /* The highest priority network error code, if the certificate has an error. */
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
        safeUrl: string /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    }
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        certificateSecurityState: CertificateSecurityState.t, /* Security state details about the page certificate. */
        safetyTipInfo: SafetyTipInfo.t, /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
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
        recommendations: array(string) /* Recommendations to fix any issues. */,
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
      type t = int;
    } = CertificateId
    and MixedContentType: {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    } = MixedContentType
    and SecurityState: {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    } = SecurityState
    and CertificateSecurityState: {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {
        protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
        keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
        keyExchangeGroup: string, /* (EC)DH group used by the connection, if applicable. */
        cipher: string, /* Cipher name. */
        mac: string, /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
        certificate: array(string), /* Page certificate. */
        subjectName: string, /* Certificate subject name. */
        issuer: string, /* Name of the issuing CA. */
        validFrom: Network.Types.TimeSinceEpoch.t, /* Certificate valid from date. */
        validTo: Network.Types.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
        certificateNetworkError: string, /* The highest priority network error code, if the certificate has an error. */
        certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
        certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
        modernSSL: bool, /* True if modern SSL */
        obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
        obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
        obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
        obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
      };
    } = CertificateSecurityState
    and SafetyTipStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = SafetyTipStatus
    and SafetyTipInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
        safeUrl: string /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
      };
    } = SafetyTipInfo
    and VisibleSecurityState: {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {
        securityState: SecurityState.t, /* The security level of the page. */
        certificateSecurityState: CertificateSecurityState.t, /* Security state details about the page certificate. */
        safetyTipInfo: SafetyTipInfo.t, /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
        securityStateIssueIds: array(string) /* Array of security state issues ids. */,
      };
    } = VisibleSecurityState
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
        recommendations: array(string) /* Recommendations to fix any issues. */,
      };
    } = SecurityStateExplanation
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
    } = InsecureContentStatus
    and CertificateErrorAction: {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    } = CertificateErrorAction;
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
        scriptLastModified: float, /* The Last-Modified header value of the main script. */
        scriptResponseTime: float, /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        controlledClients: array(Target.Types.TargetID.t), /* No description provided */
        targetId: Target.Types.TargetID.t /* No description provided */,
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
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
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
        scriptLastModified: float, /* The Last-Modified header value of the main script. */
        scriptResponseTime: float, /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        controlledClients: array(Target.Types.TargetID.t), /* No description provided */
        targetId: Target.Types.TargetID.t /* No description provided */,
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
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    };
  } = {
    module rec RegistrationID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = RegistrationID
    and ServiceWorkerRegistration: {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {
        registrationId: RegistrationID.t, /* No description provided */
        scopeURL: string, /* No description provided */
        isDeleted: bool /* No description provided */,
      };
    } = ServiceWorkerRegistration
    and ServiceWorkerVersionRunningStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ServiceWorkerVersionRunningStatus
    and ServiceWorkerVersionStatus: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = ServiceWorkerVersionStatus
    and ServiceWorkerVersion: {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {
        versionId: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        scriptURL: string, /* No description provided */
        runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
        status: ServiceWorkerVersionStatus.t, /* No description provided */
        scriptLastModified: float, /* The Last-Modified header value of the main script. */
        scriptResponseTime: float, /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
        controlledClients: array(Target.Types.TargetID.t), /* No description provided */
        targetId: Target.Types.TargetID.t /* No description provided */,
      };
    } = ServiceWorkerVersion
    and ServiceWorkerErrorMessage: {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {
        errorMessage: string, /* No description provided */
        registrationId: RegistrationID.t, /* No description provided */
        versionId: string, /* No description provided */
        sourceURL: string, /* No description provided */
        lineNumber: int, /* No description provided */
        columnNumber: int /* No description provided */,
      };
    } = ServiceWorkerErrorMessage;
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
    } = StorageType
    and UsageForType: {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {
        storageType: StorageType.t, /* Name of storage type. */
        usage: float /* Storage usage (bytes). */,
      };
    } = UsageForType
    and TrustTokens: {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {
        issuerOrigin: string, /* No description provided */
        count: float /* No description provided */,
      };
    } = TrustTokens;
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
        subSysId: float, /* Sub sys ID of the GPU, only available on Windows. */
        revision: float, /* Revision of the GPU, only available on Windows. */
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
        width: int, /* Width in pixels. */
        height: int /* Height in pixels. */,
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
        maxFramerateNumerator: int, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: int /* No description provided */,
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
        auxAttributes: {.}, /* An optional dictionary of additional GPU related attributes. */
        featureStatus: {.}, /* An optional dictionary of graphics features and their status. */
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
        type_: string, /* Specifies process type. */
        id: int, /* Specifies process id. */
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
        subSysId: float, /* Sub sys ID of the GPU, only available on Windows. */
        revision: float, /* Revision of the GPU, only available on Windows. */
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
        width: int, /* Width in pixels. */
        height: int /* Height in pixels. */,
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
        maxFramerateNumerator: int, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: int /* No description provided */,
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
        auxAttributes: {.}, /* An optional dictionary of additional GPU related attributes. */
        featureStatus: {.}, /* An optional dictionary of graphics features and their status. */
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
        type_: string, /* Specifies process type. */
        id: int, /* Specifies process id. */
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
        subSysId: float, /* Sub sys ID of the GPU, only available on Windows. */
        revision: float, /* Revision of the GPU, only available on Windows. */
        vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
        deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
        driverVendor: string, /* String description of the GPU driver vendor. */
        driverVersion: string /* String description of the GPU driver version. */,
      };
    } = GPUDevice
    and Size: {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {
        width: int, /* Width in pixels. */
        height: int /* Height in pixels. */,
      };
    } = Size
    and VideoDecodeAcceleratorCapability: {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
      };
    } = VideoDecodeAcceleratorCapability
    and VideoEncodeAcceleratorCapability: {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {
        profile: string, /* Video codec profile that is supported, e.g H264 Main. */
        maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
        maxFramerateNumerator: int, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
        maxFramerateDenominator: int /* No description provided */,
      };
    } = VideoEncodeAcceleratorCapability
    and SubsamplingFormat: {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    } = SubsamplingFormat
    and ImageType: {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    } = ImageType
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
    } = ImageDecodeAcceleratorCapability
    and GPUInfo: {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {
        devices: array(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
        auxAttributes: {.}, /* An optional dictionary of additional GPU related attributes. */
        featureStatus: {.}, /* An optional dictionary of graphics features and their status. */
        driverBugWorkarounds: array(string), /* An optional array of GPU driver bug workarounds. */
        videoDecoding: array(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
        videoEncoding: array(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
        imageDecoding: array(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
      };
    } = GPUInfo
    and ProcessInfo: {
      /* Represents process info. */
      [@deriving yojson]
      type t = {
        type_: string, /* Specifies process type. */
        id: int, /* Specifies process id. */
        cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
      };
    } = ProcessInfo;
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
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        openerId: TargetID.t, /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        openerFrameId: Page.Types.FrameId.t, /* Frame id of originating window (is only set if target has an opener). */
        browserContextId: Browser.Types.BrowserContextID.t /* No description provided */,
      };
    }
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: int /* No description provided */,
      };
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
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        openerId: TargetID.t, /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        openerFrameId: Page.Types.FrameId.t, /* Frame id of originating window (is only set if target has an opener). */
        browserContextId: Browser.Types.BrowserContextID.t /* No description provided */,
      };
    }
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: int /* No description provided */,
      };
    };
  } = {
    module rec TargetID: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = TargetID
    and SessionID: {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    } = SessionID
    and TargetInfo: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        targetId: TargetID.t, /* No description provided */
        type_: string, /* No description provided */
        title: string, /* No description provided */
        url: string, /* No description provided */
        attached: bool, /* Whether the target has an attached client. */
        openerId: TargetID.t, /* Opener target Id */
        canAccessOpener: bool, /* Whether the target has access to the originating window. */
        openerFrameId: Page.Types.FrameId.t, /* Frame id of originating window (is only set if target has an opener). */
        browserContextId: Browser.Types.BrowserContextID.t /* No description provided */,
      };
    } = TargetInfo
    and RemoteLocation: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        host: string, /* No description provided */
        port: int /* No description provided */,
      };
    } = RemoteLocation;
  };
}
and Tethering: {} = {}
and Tracing: {
  module Types: {
    module rec MemoryDumpConfig: {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = {.};
    }
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        recordMode: string, /* Controls how the trace buffer stores data. */
        enableSampling: bool, /* Turns on JavaScript stack sampling. */
        enableSystrace: bool, /* Turns on system tracing. */
        enableArgumentFilter: bool, /* Turns on argument filter. */
        includedCategories: array(string), /* Included category filters. */
        excludedCategories: array(string), /* Excluded category filters. */
        syntheticDelays: array(string), /* Configuration to synthesize the delays in tracing. */
        memoryDumpConfig: MemoryDumpConfig.t /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
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
} = {
  module Types: {
    module rec MemoryDumpConfig: {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = {.};
    }
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        recordMode: string, /* Controls how the trace buffer stores data. */
        enableSampling: bool, /* Turns on JavaScript stack sampling. */
        enableSystrace: bool, /* Turns on system tracing. */
        enableArgumentFilter: bool, /* Turns on argument filter. */
        includedCategories: array(string), /* Included category filters. */
        excludedCategories: array(string), /* Excluded category filters. */
        syntheticDelays: array(string), /* Configuration to synthesize the delays in tracing. */
        memoryDumpConfig: MemoryDumpConfig.t /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
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
      type t = {.};
    } = MemoryDumpConfig
    and TraceConfig: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        recordMode: string, /* Controls how the trace buffer stores data. */
        enableSampling: bool, /* Turns on JavaScript stack sampling. */
        enableSystrace: bool, /* Turns on system tracing. */
        enableArgumentFilter: bool, /* Turns on argument filter. */
        includedCategories: array(string), /* Included category filters. */
        excludedCategories: array(string), /* Excluded category filters. */
        syntheticDelays: array(string), /* Configuration to synthesize the delays in tracing. */
        memoryDumpConfig: MemoryDumpConfig.t /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
      };
    } = TraceConfig
    and StreamFormat: {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    } = StreamFormat
    and StreamCompression: {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    } = StreamCompression
    and MemoryDumpLevelOfDetail: {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    } = MemoryDumpLevelOfDetail
    and TracingBackend: {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    } = TracingBackend;
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
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: Network.Types.ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        requestStage: RequestStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
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
        source: string, /* Source of the authentication challenge. */
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
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
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
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: Network.Types.ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        requestStage: RequestStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
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
        source: string, /* Source of the authentication challenge. */
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
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    };
  } = {
    module rec RequestId: {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    } = RequestId
    and RequestStage: {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    } = RequestStage
    and RequestPattern: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        urlPattern: string, /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
        resourceType: Network.Types.ResourceType.t, /* If set, only requests for matching resource types will be intercepted. */
        requestStage: RequestStage.t /* Stage at which to begin intercepting requests. Default is Request. */,
      };
    } = RequestPattern
    and HeaderEntry: {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = HeaderEntry
    and AuthChallenge: {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {
        source: string, /* Source of the authentication challenge. */
        origin: string, /* Origin of the challenger. */
        scheme: string, /* The authentication scheme used, such as basic or digest */
        realm: string /* The realm of the challenge. May be empty. */,
      };
    } = AuthChallenge
    and AuthChallengeResponse: {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {
        response: string, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
        username: string, /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
        password: string /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
      };
    } = AuthChallengeResponse;
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
        realtimeData: ContextRealtimeData.t, /* No description provided */
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
        realtimeData: ContextRealtimeData.t, /* No description provided */
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
    } = GraphObjectId
    and ContextType: {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    } = ContextType
    and ContextState: {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    } = ContextState
    and NodeType: {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    } = NodeType
    and ChannelCountMode: {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    } = ChannelCountMode
    and ChannelInterpretation: {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    } = ChannelInterpretation
    and ParamType: {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    } = ParamType
    and AutomationRate: {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    } = AutomationRate
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
    } = ContextRealtimeData
    and BaseAudioContext: {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {
        contextId: GraphObjectId.t, /* No description provided */
        contextType: ContextType.t, /* No description provided */
        contextState: ContextState.t, /* No description provided */
        realtimeData: ContextRealtimeData.t, /* No description provided */
        callbackBufferSize: float, /* Platform-dependent callback buffer size. */
        maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
        sampleRate: float /* Context sample rate. */,
      };
    } = BaseAudioContext
    and AudioListener: {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {
        listenerId: GraphObjectId.t, /* No description provided */
        contextId: GraphObjectId.t /* No description provided */,
      };
    } = AudioListener
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
    } = AudioNode
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
    } = AudioParam;
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
        ctap2Version: Ctap2Version.t, /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        hasResidentKey: bool, /* Defaults to false. */
        hasUserVerification: bool, /* Defaults to false. */
        hasLargeBlob: bool, /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        hasCredBlob: bool, /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        automaticPresenceSimulation: bool, /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        isUserVerified: bool /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    }
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        rpId: string, /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        userHandle: string, /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: int, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        largeBlob: string /* The large blob associated with the credential.
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
        ctap2Version: Ctap2Version.t, /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        hasResidentKey: bool, /* Defaults to false. */
        hasUserVerification: bool, /* Defaults to false. */
        hasLargeBlob: bool, /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        hasCredBlob: bool, /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        automaticPresenceSimulation: bool, /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        isUserVerified: bool /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    }
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        rpId: string, /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        userHandle: string, /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: int, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        largeBlob: string /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    };
  } = {
    module rec AuthenticatorId: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = AuthenticatorId
    and AuthenticatorProtocol: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = AuthenticatorProtocol
    and Ctap2Version: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = Ctap2Version
    and AuthenticatorTransport: {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    } = AuthenticatorTransport
    and VirtualAuthenticatorOptions: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        protocol: AuthenticatorProtocol.t, /* No description provided */
        ctap2Version: Ctap2Version.t, /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
        transport: AuthenticatorTransport.t, /* No description provided */
        hasResidentKey: bool, /* Defaults to false. */
        hasUserVerification: bool, /* Defaults to false. */
        hasLargeBlob: bool, /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
        hasCredBlob: bool, /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
        automaticPresenceSimulation: bool, /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
        isUserVerified: bool /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
      };
    } = VirtualAuthenticatorOptions
    and Credential: {
      /* No description provided */
      [@deriving yojson]
      type t = {
        credentialId: string, /* No description provided */
        isResidentCredential: bool, /* No description provided */
        rpId: string, /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
        privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
        userHandle: string, /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
        signCount: int, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
        largeBlob: string /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
      };
    } = Credential;
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
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
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
    } = PlayerId
    and Timestamp: {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    } = Timestamp
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
    } = PlayerMessage
    and PlayerProperty: {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {
        name: string, /* No description provided */
        value: string /* No description provided */,
      };
    } = PlayerProperty
    and PlayerEvent: {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {
        timestamp: Timestamp.t, /* No description provided */
        value: string /* No description provided */,
      };
    } = PlayerEvent
    and PlayerError: {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {
        type_: string, /* No description provided */
        errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
      };
    } = PlayerError;
  };
};
