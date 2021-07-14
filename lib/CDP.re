module rec Accessibility: {} = {
  module Types = {
    module rec AXNodeId: {} = {
      /* Unique accessibility node identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueType: {} = {
      /* Enum of possible property types. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSourceType: {} = {
      /* Enum of possible property sources. */
      [@deriving yojson]
      type t = string;
    }
    and AXValueNativeSourceType: {} = {
      /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
      [@deriving yojson]
      type t = string;
    }
    and AXValueSource: {} = {
      /* A single source for a computed AX property. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AXRelatedNode: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and AXProperty: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and AXValue: {} = {
      /* A single computed AX property. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AXPropertyName: {} = {
      /* Values of AXProperty name:
         - from 'busy' to 'roledescription': states which apply to every AX node
         - from 'live' to 'root': attributes which apply to nodes in live regions
         - from 'autocomplete' to 'valuetext': attributes which apply to widgets
         - from 'checked' to 'selected': states which apply to widgets
         - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
      [@deriving yojson]
      type t = string;
    }
    and AXNode: {} = {
      /* A node in the accessibility tree. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Animation: {} = {
  module Types = {
    module rec Animation: {} = {
      /* Animation instance. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AnimationEffect: {} = {
      /* AnimationEffect instance */
      [@deriving yojson]
      type t = {test: string};
    }
    and KeyframesRule: {} = {
      /* Keyframes Rule */
      [@deriving yojson]
      type t = {test: string};
    }
    and KeyframeStyle: {} = {
      /* Keyframe Style */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and ApplicationCache: {} = {
  module Types = {
    module rec ApplicationCacheResource: {} = {
      /* Detailed application cache resource information. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ApplicationCache: {} = {
      /* Detailed application cache information. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FrameWithManifest: {} = {
      /* Frame identifier - manifest URL pair. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Audits: {} = {
  module Types = {
    module rec AffectedCookie: {} = {
      /* Information about a cookie that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AffectedRequest: {} = {
      /* Information about a request that is affected by an inspector issue. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AffectedFrame: {} = {
      /* Information about the frame affected by an inspector issue. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SameSiteCookieExclusionReason: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieWarningReason: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieOperation: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SameSiteCookieIssueDetails: {} = {
      /* This information is currently necessary, as the front-end has a difficult
         time finding a specific cookie. With this, we can convey specific error
         information without the cookie. */
      [@deriving yojson]
      type t = {test: string};
    }
    and MixedContentResolutionStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentResourceType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MixedContentIssueDetails: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and BlockedByResponseReason: {} = {
      /* Enum indicating the reason a response has been blocked. These reasons are
         refinements of the net error BLOCKED_BY_RESPONSE. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedByResponseIssueDetails: {} = {
      /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
         code. Currently only used for COEP/COOP, but may be extended to include
         some CSP errors in the future. */
      [@deriving yojson]
      type t = {test: string};
    }
    and HeavyAdResolutionStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdReason: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HeavyAdIssueDetails: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and ContentSecurityPolicyViolationType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SourceCodeLocation: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and ContentSecurityPolicyIssueDetails: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and SharedArrayBufferIssueType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SharedArrayBufferIssueDetails: {} = {
      /* Details for a issue arising from an SAB being instantiated in, or
         transferred to a context that is not cross-origin isolated. */
      [@deriving yojson]
      type t = {test: string};
    }
    and TwaQualityEnforcementViolationType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TrustedWebActivityIssueDetails: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and LowTextContrastIssueDetails: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CorsIssueDetails: {} = {
      /* Details for a CORS related issue, e.g. a warning or error related to
         CORS RFC1918 enforcement. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AttributionReportingIssueType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AttributionReportingIssueDetails: {} = {
      /* Details for issues around "Attribution Reporting API" usage.
         Explainer: https://github.com/WICG/conversion-measurement-api */
      [@deriving yojson]
      type t = {test: string};
    }
    and QuirksModeIssueDetails: {} = {
      /* Details for issues about documents in Quirks Mode
         or Limited Quirks Mode that affects page layouting. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InspectorIssueCode: {} = {
      /* A unique identifier for the type of issue. Each type may use one of the
         optional fields in InspectorIssueDetails to convey more specific
         information about the kind of issue. */
      [@deriving yojson]
      type t = string;
    }
    and InspectorIssueDetails: {} = {
      /* This struct holds a list of optional fields with additional information
         specific to the kind of issue. When adding a new issue code, please also
         add a new optional field to this type. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InspectorIssue: {} = {
      /* An inspector issue reported from the back-end. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and BackgroundService: {} = {
  module Types = {
    module rec ServiceName: {} = {
      /* The Background Service that will be associated with the commands/events.
         Every Background Service operates independently, but they share the same
         API. */
      [@deriving yojson]
      type t = string;
    }
    and EventMetadata: {} = {
      /* A key-value pair for additional event information to pass along. */
      [@deriving yojson]
      type t = {test: string};
    }
    and BackgroundServiceEvent: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Browser: {} = {
  module Types = {
    module rec BrowserContextID: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and WindowID: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = int;
    }
    and WindowState: {} = {
      /* The state of the browser window. */
      [@deriving yojson]
      type t = string;
    }
    and Bounds: {} = {
      /* Browser window bounds information */
      [@deriving yojson]
      type t = {test: string};
    }
    and PermissionType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionSetting: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionDescriptor: {} = {
      /* Definition of PermissionDescriptor defined in the Permissions API:
         https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
      [@deriving yojson]
      type t = {test: string};
    }
    and BrowserCommandId: {} = {
      /* Browser command ids used by executeBrowserCommand. */
      [@deriving yojson]
      type t = string;
    }
    and Bucket: {} = {
      /* Chrome histogram bucket. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Histogram: {} = {
      /* Chrome histogram. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and CSS: {} = {
  module Types = {
    module rec StyleSheetId: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and StyleSheetOrigin: {} = {
      /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
         stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
         inspector" rules), "regular" for regular stylesheets. */
      [@deriving yojson]
      type t = string;
    }
    and PseudoElementMatches: {} = {
      /* CSS rule collection for a single pseudo style. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InheritedStyleEntry: {} = {
      /* Inherited CSS rule collection from ancestor node. */
      [@deriving yojson]
      type t = {test: string};
    }
    and RuleMatch: {} = {
      /* Match data for a CSS rule. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Value: {} = {
      /* Data for a simple selector (these are delimited by commas in a selector list). */
      [@deriving yojson]
      type t = {test: string};
    }
    and SelectorList: {} = {
      /* Selector list data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSStyleSheetHeader: {} = {
      /* CSS stylesheet metainformation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSRule: {} = {
      /* CSS rule representation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and RuleUsage: {} = {
      /* CSS coverage information. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SourceRange: {} = {
      /* Text range within a resource. All numbers are zero-based. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ShorthandEntry: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSComputedStyleProperty: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSStyle: {} = {
      /* CSS style representation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSProperty: {} = {
      /* CSS property declaration data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSMedia: {} = {
      /* CSS media rule descriptor. */
      [@deriving yojson]
      type t = {test: string};
    }
    and MediaQuery: {} = {
      /* Media query descriptor. */
      [@deriving yojson]
      type t = {test: string};
    }
    and MediaQueryExpression: {} = {
      /* Media query expression descriptor. */
      [@deriving yojson]
      type t = {test: string};
    }
    and PlatformFontUsage: {} = {
      /* Information about amount of glyphs that were rendered with given font. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FontVariationAxis: {} = {
      /* Information about font variation axes for variable fonts */
      [@deriving yojson]
      type t = {test: string};
    }
    and FontFace: {} = {
      /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
         and additional information such as platformFontFamily and fontVariationAxes. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSKeyframesRule: {} = {
      /* CSS keyframes rule representation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSKeyframeRule: {} = {
      /* CSS keyframe rule representation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and StyleDeclarationEdit: {} = {
      /* A descriptor of operation to mutate style declaration text. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and CacheStorage: {} = {
  module Types = {
    module rec CacheId: {} = {
      /* Unique identifier of the Cache object. */
      [@deriving yojson]
      type t = string;
    }
    and CachedResponseType: {} = {
      /* type of HTTP response cached */
      [@deriving yojson]
      type t = string;
    }
    and DataEntry: {} = {
      /* Data entry. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Cache: {} = {
      /* Cache identifier. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Header: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CachedResponse: {} = {
      /* Cached response */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Cast: {} = {
  module Types = {
    module rec Sink: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and DOM: {} = {
  module Types = {
    module rec NodeId: {} = {
      /* Unique DOM node identifier. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNodeId: {} = {
      /* Unique DOM node identifier used to reference a node that may not have been pushed to the
         front-end. */
      [@deriving yojson]
      type t = int;
    }
    and BackendNode: {} = {
      /* Backend node with a friendly name. */
      [@deriving yojson]
      type t = {test: string};
    }
    and PseudoType: {} = {
      /* Pseudo element type. */
      [@deriving yojson]
      type t = string;
    }
    and ShadowRootType: {} = {
      /* Shadow root type. */
      [@deriving yojson]
      type t = string;
    }
    and CompatibilityMode: {} = {
      /* Document compatibility mode. */
      [@deriving yojson]
      type t = string;
    }
    and Node: {} = {
      /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
         DOMNode is a base node mirror type. */
      [@deriving yojson]
      type t = {test: string};
    }
    and RGBA: {} = {
      /* A structure holding an RGBA color. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Quad: {} = {
      /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
      [@deriving yojson]
      type t = array(int);
    }
    and BoxModel: {} = {
      /* Box model. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ShapeOutsideInfo: {} = {
      /* CSS Shape Outside details. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Rect: {} = {
      /* Rectangle. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CSSComputedStyleProperty: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and DOMDebugger: {} = {
  module Types = {
    module rec DOMBreakpointType: {} = {
      /* DOM breakpoint type. */
      [@deriving yojson]
      type t = string;
    }
    and CSPViolationType: {} = {
      /* CSP Violation type. */
      [@deriving yojson]
      type t = string;
    }
    and EventListener: {} = {
      /* Object event listener. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and DOMSnapshot: {} = {
  module Types = {
    module rec DOMNode: {} = {
      /* A Node in the DOM tree. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InlineTextBox: {} = {
      /* Details of post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {test: string};
    }
    and LayoutTreeNode: {} = {
      /* Details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ComputedStyle: {} = {
      /* A subset of the full ComputedStyle as defined by the request whitelist. */
      [@deriving yojson]
      type t = {test: string};
    }
    and NameValue: {} = {
      /* A name/value pair. */
      [@deriving yojson]
      type t = {test: string};
    }
    and StringIndex: {} = {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = int;
    }
    and ArrayOfStrings: {} = {
      /* Index of the string in the strings table. */
      [@deriving yojson]
      type t = array(int);
    }
    and RareStringData: {} = {
      /* Data that is only present on rare nodes. */
      [@deriving yojson]
      type t = {test: string};
    }
    and RareBooleanData: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and RareIntegerData: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and Rectangle: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = array(int);
    }
    and DocumentSnapshot: {} = {
      /* Document snapshot. */
      [@deriving yojson]
      type t = {test: string};
    }
    and NodeTreeSnapshot: {} = {
      /* Table containing nodes. */
      [@deriving yojson]
      type t = {test: string};
    }
    and LayoutTreeSnapshot: {} = {
      /* Table of details of an element in the DOM tree with a LayoutObject. */
      [@deriving yojson]
      type t = {test: string};
    }
    and TextBoxSnapshot: {} = {
      /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
         stable and may change between versions. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and DOMStorage: {} = {
  module Types = {
    module rec StorageId: {} = {
      /* DOM Storage identifier. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Item: {} = {
      /* DOM Storage item. */
      [@deriving yojson]
      type t = array(int);
    };
  };
}
and Database: {} = {
  module Types = {
    module rec DatabaseId: {} = {
      /* Unique identifier of Database object. */
      [@deriving yojson]
      type t = string;
    }
    and Database: {} = {
      /* Database object. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Error: {} = {
      /* Database error. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and DeviceOrientation: {} = {}
and Emulation: {} = {
  module Types = {
    module rec ScreenOrientation: {} = {
      /* Screen orientation. */
      [@deriving yojson]
      type t = {test: string};
    }
    and DisplayFeature: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and MediaFeature: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and VirtualTimePolicy: {} = {
      /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
         allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
         pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
         resource fetches. */
      [@deriving yojson]
      type t = string;
    }
    and UserAgentBrandVersion: {} = {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
      [@deriving yojson]
      type t = {test: string};
    }
    and UserAgentMetadata: {} = {
      /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
         Missing optional values will be filled in by the target with what it would normally use. */
      [@deriving yojson]
      type t = {test: string};
    }
    and DisabledImageType: {} = {
      /* Enum of image types that can be disabled. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and HeadlessExperimental: {} = {
  module Types = {
    module rec ScreenshotParams: {} = {
      /* Encoding options for a screenshot. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and IO: {} = {
  module Types = {
    module rec StreamHandle: {} = {
      /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
         `&lt;uuid&gt` is an UUID of a Blob. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and IndexedDB: {} = {
  module Types = {
    module rec DatabaseWithObjectStores: {} = {
      /* Database with an array of object stores. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ObjectStore: {} = {
      /* Object store. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ObjectStoreIndex: {} = {
      /* Object store index. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Key: {} = {
      /* Key. */
      [@deriving yojson]
      type t = {test: string};
    }
    and KeyRange: {} = {
      /* Key range. */
      [@deriving yojson]
      type t = {test: string};
    }
    and DataEntry: {} = {
      /* Data entry. */
      [@deriving yojson]
      type t = {test: string};
    }
    and KeyPath: {} = {
      /* Key path. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Input: {} = {
  module Types = {
    module rec TouchPoint: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and GestureSourceType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and MouseButton: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {} = {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and DragDataItem: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and DragData: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Inspector: {} = {}
and LayerTree: {} = {
  module Types = {
    module rec LayerId: {} = {
      /* Unique Layer identifier. */
      [@deriving yojson]
      type t = string;
    }
    and SnapshotId: {} = {
      /* Unique snapshot identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ScrollRect: {} = {
      /* Rectangle where scrolling happens on the main thread. */
      [@deriving yojson]
      type t = {test: string};
    }
    and StickyPositionConstraint: {} = {
      /* Sticky position constraints. */
      [@deriving yojson]
      type t = {test: string};
    }
    and PictureTile: {} = {
      /* Serialized fragment of layer picture along with its offset within the layer. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Layer: {} = {
      /* Information about a compositing layer. */
      [@deriving yojson]
      type t = {test: string};
    }
    and PaintProfile: {} = {
      /* Array of timings, one per paint step. */
      [@deriving yojson]
      type t = array(int);
    };
  };
}
and Log: {} = {
  module Types = {
    module rec LogEntry: {} = {
      /* Log entry. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ViolationSetting: {} = {
      /* Violation configuration setting. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Memory: {} = {
  module Types = {
    module rec PressureLevel: {} = {
      /* Memory pressure level. */
      [@deriving yojson]
      type t = string;
    }
    and SamplingProfileNode: {} = {
      /* Heap profile sample. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SamplingProfile: {} = {
      /* Array of heap profile samples. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Module: {} = {
      /* Executable module information */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Network: {} = {
  module Types = {
    module rec ResourceType: {} = {
      /* Resource type as it was perceived by the rendering engine. */
      [@deriving yojson]
      type t = string;
    }
    and LoaderId: {} = {
      /* Unique loader identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestId: {} = {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and InterceptionId: {} = {
      /* Unique intercepted request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and ErrorReason: {} = {
      /* Network level fetch failure reason. */
      [@deriving yojson]
      type t = string;
    }
    and TimeSinceEpoch: {} = {
      /* UTC time in seconds, counted from January 1, 1970. */
      [@deriving yojson]
      type t = float;
    }
    and MonotonicTime: {} = {
      /* Monotonically increasing time in seconds since an arbitrary point in the past. */
      [@deriving yojson]
      type t = float;
    }
    and Headers: {} = {
      /* Request / response headers as keys / values of JSON object. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ConnectionType: {} = {
      /* The underlying connection technology that the browser is supposedly using. */
      [@deriving yojson]
      type t = string;
    }
    and CookieSameSite: {} = {
      /* Represents the cookie's 'SameSite' status:
         https://tools.ietf.org/html/draft-west-first-party-cookies */
      [@deriving yojson]
      type t = string;
    }
    and CookiePriority: {} = {
      /* Represents the cookie's 'Priority' status:
         https://tools.ietf.org/html/draft-west-cookie-priority-00 */
      [@deriving yojson]
      type t = string;
    }
    and CookieSourceScheme: {} = {
      /* Represents the source scheme of the origin that originally set the cookie.
         A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
         This is a temporary ability and it will be removed in the future. */
      [@deriving yojson]
      type t = string;
    }
    and ResourceTiming: {} = {
      /* Timing information for the request. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ResourcePriority: {} = {
      /* Loading priority of a resource request. */
      [@deriving yojson]
      type t = string;
    }
    and PostDataEntry: {} = {
      /* Post data entry for HTTP request */
      [@deriving yojson]
      type t = {test: string};
    }
    and Request: {} = {
      /* HTTP request data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SignedCertificateTimestamp: {} = {
      /* Details of a signed certificate timestamp (SCT). */
      [@deriving yojson]
      type t = {test: string};
    }
    and SecurityDetails: {} = {
      /* Security details about a request. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CertificateTransparencyCompliance: {} = {
      /* Whether the request complied with Certificate Transparency policy. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedReason: {} = {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsError: {} = {
      /* The reason why request was blocked. */
      [@deriving yojson]
      type t = string;
    }
    and CorsErrorStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and ServiceWorkerResponseSource: {} = {
      /* Source of serviceworker response. */
      [@deriving yojson]
      type t = string;
    }
    and TrustTokenParams: {} = {
      /* Determines what type of Trust Token operation is executed and
         depending on the type, some additional parameters. The values
         are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
      [@deriving yojson]
      type t = {test: string};
    }
    and TrustTokenOperationType: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Response: {} = {
      /* HTTP response data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and WebSocketRequest: {} = {
      /* WebSocket request data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and WebSocketResponse: {} = {
      /* WebSocket response data. */
      [@deriving yojson]
      type t = {test: string};
    }
    and WebSocketFrame: {} = {
      /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CachedResource: {} = {
      /* Information about the cached resource. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Initiator: {} = {
      /* Information about the request initiator. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Cookie: {} = {
      /* Cookie object */
      [@deriving yojson]
      type t = {test: string};
    }
    and SetCookieBlockedReason: {} = {
      /* Types of reasons why a cookie may not be stored from a response. */
      [@deriving yojson]
      type t = string;
    }
    and CookieBlockedReason: {} = {
      /* Types of reasons why a cookie may not be sent with a request. */
      [@deriving yojson]
      type t = string;
    }
    and BlockedSetCookieWithReason: {} = {
      /* A cookie which was not stored from a response with the corresponding reason. */
      [@deriving yojson]
      type t = {test: string};
    }
    and BlockedCookieWithReason: {} = {
      /* A cookie with was not sent with a request with the corresponding reason. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CookieParam: {} = {
      /* Cookie parameter object */
      [@deriving yojson]
      type t = {test: string};
    }
    and AuthChallenge: {} = {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AuthChallengeResponse: {} = {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InterceptionStage: {} = {
      /* Stages of the interception to begin intercepting. Request will intercept before the request is
         sent. Response will intercept after the response is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {} = {
      /* Request pattern for interception. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SignedExchangeSignature: {} = {
      /* Information about a signed exchange signature.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
      [@deriving yojson]
      type t = {test: string};
    }
    and SignedExchangeHeader: {} = {
      /* Information about a signed exchange header.
         https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
      [@deriving yojson]
      type t = {test: string};
    }
    and SignedExchangeErrorField: {} = {
      /* Field type for a signed exchange related error. */
      [@deriving yojson]
      type t = string;
    }
    and SignedExchangeError: {} = {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SignedExchangeInfo: {} = {
      /* Information about a signed exchange response. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ContentEncoding: {} = {
      /* List of content encodings supported by the backend. */
      [@deriving yojson]
      type t = string;
    }
    and PrivateNetworkRequestPolicy: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and IPAddressSpace: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientSecurityState: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CrossOriginOpenerPolicyValue: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginOpenerPolicyStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and CrossOriginEmbedderPolicyValue: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginEmbedderPolicyStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and SecurityIsolationStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and LoadNetworkResourcePageResult: {} = {
      /* An object providing the result of a network resource load. */
      [@deriving yojson]
      type t = {test: string};
    }
    and LoadNetworkResourceOptions: {} = {
      /* An options object that may be extended later to better support CORS,
         CORB and streaming. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Overlay: {} = {
  module Types = {
    module rec SourceOrderConfig: {} = {
      /* Configuration data for drawing the source order of an elements children. */
      [@deriving yojson]
      type t = {test: string};
    }
    and GridHighlightConfig: {} = {
      /* Configuration data for the highlighting of Grid elements. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FlexContainerHighlightConfig: {} = {
      /* Configuration data for the highlighting of Flex container elements. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FlexItemHighlightConfig: {} = {
      /* Configuration data for the highlighting of Flex item elements. */
      [@deriving yojson]
      type t = {test: string};
    }
    and LineStyle: {} = {
      /* Style information for drawing a line. */
      [@deriving yojson]
      type t = {test: string};
    }
    and BoxStyle: {} = {
      /* Style information for drawing a box. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ContrastAlgorithm: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and HighlightConfig: {} = {
      /* Configuration data for the highlighting of page elements. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ColorFormat: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and GridNodeHighlightConfig: {} = {
      /* Configurations for Persistent Grid Highlight */
      [@deriving yojson]
      type t = {test: string};
    }
    and FlexNodeHighlightConfig: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and ScrollSnapContainerHighlightConfig: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and ScrollSnapHighlightConfig: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and HingeConfig: {} = {
      /* Configuration for dual screen hinge */
      [@deriving yojson]
      type t = {test: string};
    }
    and InspectMode: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    };
  };
}
and Page: {} = {
  module Types = {
    module rec FrameId: {} = {
      /* Unique frame identifier. */
      [@deriving yojson]
      type t = string;
    }
    and AdFrameType: {} = {
      /* Indicates whether a frame has been identified as an ad. */
      [@deriving yojson]
      type t = string;
    }
    and SecureContextType: {} = {
      /* Indicates whether the frame is a secure context and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and CrossOriginIsolatedContextType: {} = {
      /* Indicates whether the frame is cross-origin isolated and why it is the case. */
      [@deriving yojson]
      type t = string;
    }
    and GatedAPIFeatures: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyFeature: {} = {
      /* All Permissions Policy features. This enum should match the one defined
         in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockReason: {} = {
      /* Reason for a permissions policy feature to be disabled. */
      [@deriving yojson]
      type t = string;
    }
    and PermissionsPolicyBlockLocator: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and PermissionsPolicyFeatureState: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and OriginTrialTokenStatus: {} = {
      /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
         Status for an Origin Trial token. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialStatus: {} = {
      /* Status for an Origin Trial. */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialUsageRestriction: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and OriginTrialToken: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and OriginTrialTokenWithStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and OriginTrial: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and Frame: {} = {
      /* Information about the Frame on the page. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FrameResource: {} = {
      /* Information about the Resource on the page. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FrameResourceTree: {} = {
      /* Information about the Frame hierarchy along with their cached resources. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FrameTree: {} = {
      /* Information about the Frame hierarchy. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ScriptIdentifier: {} = {
      /* Unique script identifier. */
      [@deriving yojson]
      type t = string;
    }
    and TransitionType: {} = {
      /* Transition type. */
      [@deriving yojson]
      type t = string;
    }
    and NavigationEntry: {} = {
      /* Navigation history entry. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ScreencastFrameMetadata: {} = {
      /* Screencast frame metadata. */
      [@deriving yojson]
      type t = {test: string};
    }
    and DialogType: {} = {
      /* Javascript dialog type. */
      [@deriving yojson]
      type t = string;
    }
    and AppManifestError: {} = {
      /* Error while paring app manifest. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AppManifestParsedProperties: {} = {
      /* Parsed app manifest properties. */
      [@deriving yojson]
      type t = {test: string};
    }
    and LayoutViewport: {} = {
      /* Layout viewport position and dimensions. */
      [@deriving yojson]
      type t = {test: string};
    }
    and VisualViewport: {} = {
      /* Visual viewport position, dimensions, and scale. */
      [@deriving yojson]
      type t = {test: string};
    }
    and Viewport: {} = {
      /* Viewport for capturing screenshot. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FontFamilies: {} = {
      /* Generic font families collection. */
      [@deriving yojson]
      type t = {test: string};
    }
    and FontSizes: {} = {
      /* Default font sizes. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ClientNavigationReason: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ClientNavigationDisposition: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and InstallabilityErrorArgument: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and InstallabilityError: {} = {
      /* The installability error */
      [@deriving yojson]
      type t = {test: string};
    }
    and ReferrerPolicy: {} = {
      /* The referring-policy used for the navigation. */
      [@deriving yojson]
      type t = string;
    }
    and CompilationCacheParams: {} = {
      /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
      [@deriving yojson]
      type t = {test: string};
    }
    and NavigationType: {} = {
      /* The type of a frameNavigated event. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and Performance: {} = {
  module Types = {
    module rec Metric: {} = {
      /* Run-time execution metric. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and PerformanceTimeline: {} = {
  module Types = {
    module rec LargestContentfulPaint: {} = {
      /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
      [@deriving yojson]
      type t = {test: string};
    }
    and LayoutShiftAttribution: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and LayoutShift: {} = {
      /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
      [@deriving yojson]
      type t = {test: string};
    }
    and TimelineEvent: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Security: {} = {
  module Types = {
    module rec CertificateId: {} = {
      /* An internal certificate ID value. */
      [@deriving yojson]
      type t = int;
    }
    and MixedContentType: {} = {
      /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
         https://www.w3.org/TR/mixed-content/#categories */
      [@deriving yojson]
      type t = string;
    }
    and SecurityState: {} = {
      /* The security level of a page or resource. */
      [@deriving yojson]
      type t = string;
    }
    and CertificateSecurityState: {} = {
      /* Details about the security state of the page certificate. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SafetyTipStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SafetyTipInfo: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and VisibleSecurityState: {} = {
      /* Security state information about the page. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SecurityStateExplanation: {} = {
      /* An explanation of an factor contributing to the security state. */
      [@deriving yojson]
      type t = {test: string};
    }
    and InsecureContentStatus: {} = {
      /* Information about insecure content on the page. */
      [@deriving yojson]
      type t = {test: string};
    }
    and CertificateErrorAction: {} = {
      /* The action to take when a certificate error occurs. continue will continue processing the
         request and cancel will cancel the request. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and ServiceWorker: {} = {
  module Types = {
    module rec RegistrationID: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerRegistration: {} = {
      /* ServiceWorker registration. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ServiceWorkerVersionRunningStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersionStatus: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and ServiceWorkerVersion: {} = {
      /* ServiceWorker version. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ServiceWorkerErrorMessage: {} = {
      /* ServiceWorker error message. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Storage: {} = {
  module Types = {
    module rec StorageType: {} = {
      /* Enum of possible storage types. */
      [@deriving yojson]
      type t = string;
    }
    and UsageForType: {} = {
      /* Usage for a storage type. */
      [@deriving yojson]
      type t = {test: string};
    }
    and TrustTokens: {} = {
      /* Pair of issuer origin and number of available (signed, but not used) Trust
         Tokens from that issuer. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and SystemInfo: {} = {
  module Types = {
    module rec GPUDevice: {} = {
      /* Describes a single graphics processor (GPU). */
      [@deriving yojson]
      type t = {test: string};
    }
    and Size: {} = {
      /* Describes the width and height dimensions of an entity. */
      [@deriving yojson]
      type t = {test: string};
    }
    and VideoDecodeAcceleratorCapability: {} = {
      /* Describes a supported video decoding profile with its associated minimum and
         maximum resolutions. */
      [@deriving yojson]
      type t = {test: string};
    }
    and VideoEncodeAcceleratorCapability: {} = {
      /* Describes a supported video encoding profile with its associated maximum
         resolution and maximum framerate. */
      [@deriving yojson]
      type t = {test: string};
    }
    and SubsamplingFormat: {} = {
      /* YUV subsampling type of the pixels of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageType: {} = {
      /* Image format of a given image. */
      [@deriving yojson]
      type t = string;
    }
    and ImageDecodeAcceleratorCapability: {} = {
      /* Describes a supported image decoding profile with its associated minimum and
         maximum resolutions and subsampling. */
      [@deriving yojson]
      type t = {test: string};
    }
    and GPUInfo: {} = {
      /* Provides information about the GPU(s) on the system. */
      [@deriving yojson]
      type t = {test: string};
    }
    and ProcessInfo: {} = {
      /* Represents process info. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Target: {} = {
  module Types = {
    module rec TargetID: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and SessionID: {} = {
      /* Unique identifier of attached debugging session. */
      [@deriving yojson]
      type t = string;
    }
    and TargetInfo: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and RemoteLocation: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Tethering: {} = {}
and Tracing: {} = {
  module Types = {
    module rec MemoryDumpConfig: {} = {
      /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
      [@deriving yojson]
      type t = {test: string};
    }
    and TraceConfig: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and StreamFormat: {} = {
      /* Data format of a trace. Can be either the legacy JSON format or the
         protocol buffer format. Note that the JSON format will be deprecated soon. */
      [@deriving yojson]
      type t = string;
    }
    and StreamCompression: {} = {
      /* Compression type to use for traces returned via streams. */
      [@deriving yojson]
      type t = string;
    }
    and MemoryDumpLevelOfDetail: {} = {
      /* Details exposed when memory request explicitly declared.
         Keep consistent with memory_dump_request_args.h and
         memory_instrumentation.mojom */
      [@deriving yojson]
      type t = string;
    }
    and TracingBackend: {} = {
      /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
         tracing service and is supported on all platforms. `system` is only
         supported on Chrome OS and uses the Perfetto system tracing service.
         `auto` chooses `system` when the perfettoConfig provided to Tracing.start
         specifies at least one non-Chrome data source; otherwise uses `chrome`. */
      [@deriving yojson]
      type t = string;
    };
  };
}
and Fetch: {} = {
  module Types = {
    module rec RequestId: {} = {
      /* Unique request identifier. */
      [@deriving yojson]
      type t = string;
    }
    and RequestStage: {} = {
      /* Stages of the request to handle. Request will intercept before the request is
         sent. Response will intercept after the response is received (but before response
         body is received. */
      [@deriving yojson]
      type t = string;
    }
    and RequestPattern: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and HeaderEntry: {} = {
      /* Response HTTP header entry */
      [@deriving yojson]
      type t = {test: string};
    }
    and AuthChallenge: {} = {
      /* Authorization challenge for HTTP status code 401 or 407. */
      [@deriving yojson]
      type t = {test: string};
    }
    and AuthChallengeResponse: {} = {
      /* Response to an AuthChallenge. */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and WebAudio: {} = {
  module Types = {
    module rec GraphObjectId: {} = {
      /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
      [@deriving yojson]
      type t = string;
    }
    and ContextType: {} = {
      /* Enum of BaseAudioContext types */
      [@deriving yojson]
      type t = string;
    }
    and ContextState: {} = {
      /* Enum of AudioContextState from the spec */
      [@deriving yojson]
      type t = string;
    }
    and NodeType: {} = {
      /* Enum of AudioNode types */
      [@deriving yojson]
      type t = string;
    }
    and ChannelCountMode: {} = {
      /* Enum of AudioNode::ChannelCountMode from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ChannelInterpretation: {} = {
      /* Enum of AudioNode::ChannelInterpretation from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ParamType: {} = {
      /* Enum of AudioParam types */
      [@deriving yojson]
      type t = string;
    }
    and AutomationRate: {} = {
      /* Enum of AudioParam::AutomationRate from the spec */
      [@deriving yojson]
      type t = string;
    }
    and ContextRealtimeData: {} = {
      /* Fields in AudioContext that change in real-time. */
      [@deriving yojson]
      type t = {test: string};
    }
    and BaseAudioContext: {} = {
      /* Protocol object for BaseAudioContext */
      [@deriving yojson]
      type t = {test: string};
    }
    and AudioListener: {} = {
      /* Protocol object for AudioListener */
      [@deriving yojson]
      type t = {test: string};
    }
    and AudioNode: {} = {
      /* Protocol object for AudioNode */
      [@deriving yojson]
      type t = {test: string};
    }
    and AudioParam: {} = {
      /* Protocol object for AudioParam */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and WebAuthn: {} = {
  module Types = {
    module rec AuthenticatorId: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorProtocol: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and Ctap2Version: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and AuthenticatorTransport: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = string;
    }
    and VirtualAuthenticatorOptions: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    }
    and Credential: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = {test: string};
    };
  };
}
and Media: {} = {
  module Types = {
    module rec PlayerId: {} = {
      /* Players will get an ID that is unique within the agent context. */
      [@deriving yojson]
      type t = string;
    }
    and Timestamp: {} = {
      /* No description provided */
      [@deriving yojson]
      type t = float;
    }
    and PlayerMessage: {} = {
      /* Have one type per entry in MediaLogRecord::Type
         Corresponds to kMessage */
      [@deriving yojson]
      type t = {test: string};
    }
    and PlayerProperty: {} = {
      /* Corresponds to kMediaPropertyChange */
      [@deriving yojson]
      type t = {test: string};
    }
    and PlayerEvent: {} = {
      /* Corresponds to kMediaEventTriggered */
      [@deriving yojson]
      type t = {test: string};
    }
    and PlayerError: {} = {
      /* Corresponds to kMediaError */
      [@deriving yojson]
      type t = {test: string};
    };
  };
};
